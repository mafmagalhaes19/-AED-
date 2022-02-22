//
// Created by Vasco Enes on 27/01/2022.
//

#include "Graph.h"

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <climits>

#define INF (INT_MAX/2)

using namespace std;

int Graph::binarySearch(int l, int r, string code)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (nodes[mid].paragem.getCode() == code)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (nodes[mid].paragem.getCode() > code)
            return binarySearch(l, mid - 1, code);

        // Else the element can only be present
        // in right subarray
        return binarySearch(mid + 1, r, code);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

Graph::Node Graph::getNodeByCode(const string& code) {
    int index = binarySearch(0, nodes.size()-1, code);

    return nodes[index];
}


void Graph::addNode(Paragem paragem) {
    Node node;
    node.paragem = std::move(paragem);
    node.adj = {};

    nodes.push_back(node);

}

Graph::Graph(int nodes, bool dir) {
    this->n = nodes;
    this->hasDir = dir;
    zoneBFS = 0;
    linesBFS = 0;
}

void Graph::setZoneBFS(int number){
    zoneBFS = number;
}

void Graph::setLinesBFS(int number){
    linesBFS = number;
}

void Graph::addEdge(int src, int dest, string code) {

    Edge edge;
    edge.dest = dest;
    edge.codigoLinha = code;
    Paragem destino, inicio;

    if(src < 0 || src >= nodes.size() || dest < 0 || dest >= nodes.size()){
        return;
    }

    destino = nodes[dest].paragem;
    inicio = nodes[src].paragem;

    edge.distance = Paragem::distanciaEntreParagens(inicio, destino);

    nodes[src].adj.push_back(edge);
}

void Graph::sortNodes() {
    std::sort(nodes.begin(), nodes.end());
}

int Graph::getNodeIndexByCode(const string &code) {
    return binarySearch(0, nodes.size()-1, code);
}

bool Graph::Node::operator<(const Graph::Node &rhs) const {
    return paragem < rhs.paragem;
}


void Graph::addWalkingEdges(double distanciaPedonal) {
    //For each stop, see if there are any stops close enough to walk between them, and add an edge between those stops
    for (int v=0; v<n; v++){
        for (int u=0; u < n; u++){
            Paragem origem = nodes[v].paragem;
            Paragem destino = nodes[u].paragem;
            if(Paragem::distanciaEntreParagens(origem, destino) < distanciaPedonal && u!=v && Paragem::distanciaEntreParagens(origem, destino) > 0){
                this->addEdge(v, u, "12345");
            }
        }
    }
}


void Graph::addEdgesToNewSourceStop(double distanciaPedonal, Paragem origemUtilizador) {
    int origem = getNodeIndexByCode(origemUtilizador.getCode());
    for (int v = 0; v < n; v++){
        Paragem destino = nodes[v].paragem;
        if(Paragem::distanciaEntreParagens(origemUtilizador, destino) < distanciaPedonal && Paragem::distanciaEntreParagens(origemUtilizador, destino) > 0){
            this->addEdge(origem, v, "12345");
        }
    }
}


void Graph::addEdgesToNewDestinationStop(double distanciaPedonal, Paragem destinoUtilizador) {
    int destino = getNodeIndexByCode(destinoUtilizador.getCode());
    for (int v = 0; v < n; v++){
        Paragem origem = nodes[v].paragem;
        if(Paragem::distanciaEntreParagens(origem, destinoUtilizador) < distanciaPedonal && Paragem::distanciaEntreParagens(origem, destinoUtilizador) > 0){
            this->addEdge(v, destino, "12345");
        }
    }
}


void Graph::printBFSLessStops( int s, int dest)
{
    if (!bfsLS(s, dest)) {
        cout << "Nao existe nenhuma ligacao possivel entre a origem e o destino que escolheu." << endl;
        return;
    }

    // vector path stores the shortest path
    vector<Node> path;
    Node crawl = nodes[dest];
    Node source = nodes[s];
    path.push_back(crawl);
    while (!crawl.paragem.operator==(source.paragem)) {
        path.push_back(nodes[crawl.predBFS]);
        crawl = nodes[crawl.predBFS];
    }

    // printing path from source to destination
    cout << "O caminho que tem de fazer e: " << endl;
    for (int i = path.size() - 1; i >= 0; i--){
        if(i>0){
            cout << path[i].paragem.getCode()  << " - " << path[i].paragem.getName() << " --> ";
        }
        else{
            cout << path[i].paragem.getCode()  << " - " << path[i].paragem.getName() <<endl;
        }
    }

    // distance from source is in distance array
    cout << "A distancia total e de " << nodes[dest].distanceBFS + 1 << " paragens." << endl;
}

bool Graph::bfsLS(int s, int d) {
    // initialize all nodes as unvisited
    for ( int v=0; v<n; v++) {
        nodes[v].visitedBFS = false ;
    }
    queue<int> q; // queue of unvisited nodes
    q.push(s);
    nodes[s].distanceBFS = 0;
    nodes[s].visitedBFS = true;
    while (!q.empty()) { // while there are still unprocessed nodes
        int u = q.front();
        q.pop(); // remove first element of q
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visitedBFS) { // new node!
                q.push(w);
                nodes[w].visitedBFS = true ;
                nodes[w].distanceBFS = nodes[u].distanceBFS + 1;
                nodes[w].predBFS = u;
                if(w == d){
                    return true;
                }
            }
        }
    }
    return false;
}

double Graph::dijkstra_distance(int a, int b){
    dijkstra(a);
    //There is no path from a to b
    if(nodes[b].dist == INF){
        return -1;
    }
    return nodes[b].dist;
}


list<int> Graph::dijkstra_path(int a, int b){
    dijkstra(a);
    list<int> path;
    if(nodes[b].dist == INF){
        return path;
    }
    path.push_back(b);
    int v = b;
    while( v != a){
        v = nodes[v].pred;
        path.push_front(v);
    }
    return path;
}

void Graph::dijkstra(int s){
    //Priority Queue (n - number of maximum elements, -1 - returned value if key not found)
    MinHeap<int, int> q(n, -1);
    for(int v=0; v<n; v++){
        nodes[v].dist = INF;
        q.insert(v, INF);
        nodes[v].visited = false;
    }
    nodes[s].dist = 0;
    //Changes the value of s in the priority queue
    q.decreaseKey(s, 0);
    nodes[s].pred = s;
    while(q.getSize()>0){
        //Removes the key with the smallest value
        int u = q.removeMin();
        // cout << "Node " << u << "with dist = " << nodes[u].dist << endl;
        nodes[u].visited = true;
        //Cycle that goes through all adjcent nodes of u
        for(auto e : nodes[u].adj){
            int v = e.dest;
            double w = e.distance;
            if(!nodes[v].visited && (nodes[u].dist + w < nodes[v].dist) ){
                nodes[v].dist = nodes[u].dist + w;
                //Queue needs to have the same values that are stored in nodes[].dist
                q.decreaseKey(v, nodes[v].dist);
                nodes[v].pred = u;
            }
        }
    }
}

void Graph::printDijkstra(int source, int dest) {
    double distance = dijkstra_distance(source, dest);
    if(distance == -1){
        cout << "Nao existe nenhuma ligacao possivel entre a origem e o destino que escolheu." << endl;
        return;
    }
    list<int> path = dijkstra_path(source, dest);

    // printing path from source to destination
    cout << "O caminho que tem de fazer e: " << endl;
    list<int>::iterator it = path.begin();
    int aux = path.size();
    while(it != path.end()){
        if(aux>1){
            cout << nodes[*it].paragem.getCode()  << " - " << nodes[*it].paragem.getName() << " --> ";
        }
        else{
            cout << nodes[*it].paragem.getCode()  << " - " << nodes[*it].paragem.getName() <<endl;
        }
        it++;
        aux--;
    }

    // distance from source is in distance array
    cout << "A distancia total e de " << distance << " km." << endl;
}

void Graph::printBFSLessZones(int s, int dest) {
    if (!bfsLZ(s, dest)) {
        cout << "Nao existe nenhuma ligacao possivel entre a origem e o destino que escolheu." << endl;
        return;
    }

    // vector path stores the shortest path
    vector<Node> path;
    Node crawl = nodes[dest];
    Node source = nodes[s];
    path.push_back(crawl);
    while (!crawl.paragem.operator==(source.paragem)) {
        path.push_back(nodes[crawl.predBFS]);
        crawl = nodes[crawl.predBFS];
    }

    // printing path from source to destination
    cout << "O caminho que tem de fazer e: " << endl;
    for (int i = path.size() - 1; i >= 0; i--){
        if(i>0){
            cout << path[i].paragem.getCode()  << " - " << path[i].paragem.getName() << " -> ";
        }
        else{
            cout << path[i].paragem.getCode()  << " - " << path[i].paragem.getName() <<endl;
            this->setZoneBFS( (path[i].distanceBFS - path.size()) + 2);
        }
    }

    // distance from source is in distance array
    cout << "Neste percurso passa por " << this->zoneBFS << " zonas e " << path.size() << " paragens." << endl;
}

bool Graph::bfsLZ(int s, int d) {
    this->setZoneBFS(1);
    // initialize all nodes as unvisited
    for ( int v=0; v<n; v++) {
        nodes[v].visitedBFS = false;
    }
    queue<int> q; // queue of unvisited nodes
    q.push(s);
    nodes[s].distanceBFS = 0;
    nodes[s].visitedBFS = true;
    while (!q.empty()) { // while there are still unprocessed nodes
        int u = q.front();
        q.pop(); // remove first element of q
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visitedBFS) { // new node!
                q.push(w);
                nodes[w].visitedBFS = true ;
                nodes[w].distanceBFS = nodes[u].distanceBFS + 1;
                //if there is a change of zones, we increase the distance by 1
                if(nodes[u].paragem.getZone() != nodes[w].paragem.getZone()){
                    nodes[w].distanceBFS++;
                }
                nodes[w].predBFS = u;
                if(w == d){
                    return true;
                }
            }
        }
    }
    return false;
}

void Graph::printBFSLessLines(int s, int dest) {
    if (!bfsLL(s, dest)) {
        cout << "Nao existe nenhuma ligacao possivel entre a origem e o destino que escolheu." << endl;
        return;
    }

    // vector path stores the shortest path - less lines
    vector<Node> path;
    Node crawl = nodes[dest];
    Node source = nodes[s];
    path.push_back(crawl);
    while (!crawl.paragem.operator==(source.paragem)) {
        path.push_back(nodes[crawl.predBFS]);
        crawl = nodes[crawl.predBFS];
    }

    // printing path from source to destination
    cout << "O caminho que tem de fazer e: " << endl;
    for (int i = path.size() - 1; i >= 0; i--){
        if(i>0){
            cout << path[i].paragem.getCode()  << " - " << path[i].paragem.getName() << " --> ";
        }
        else{
            cout << path[i].paragem.getCode()  << " - " << path[i].paragem.getName() <<endl;
            this->setLinesBFS( (path[i].distanceBFS - path.size()) + 2);
        }
    }

    cout << "Neste percurso passa por " << this->linesBFS << " linhas e " << path.size() << " paragens." << endl;
}

bool Graph::bfsLL(int s, int d) {
    this->setLinesBFS(1);
    // initialize all nodes as unvisited
    for ( int v=0; v<n; v++) {
        nodes[v].visitedBFS = false;
    }
    queue<int> q; // queue of unvisited nodes
    q.push(s);
    nodes[s].distanceBFS = 0;
    nodes[s].visitedBFS = true;
    while (!q.empty()) { // while there are still unprocessed nodes
        int u = q.front();
        q.pop(); // remove first element of q
        string linha1 = nodes[u].adj.begin()->codigoLinha;
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            string linha2 = e.codigoLinha;
            if (!nodes[w].visitedBFS) { // new node!
                q.push(w);
                nodes[w].visitedBFS = true ;
                nodes[w].distanceBFS = nodes[u].distanceBFS + 1;
                //if there is a change of zones, we increase the distance by 1
                if(linha1 != linha2){
                    nodes[w].distanceBFS++;
                }
                nodes[w].predBFS = u;
                linha1 = e.codigoLinha;
                if(w == d){
                    return true;
                }
            }
        }
    }
    return false;
}

void Graph::incrementNodesNum() {
    n++;
}


