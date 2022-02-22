//
// Created by Vasco Enes on 27/01/2022.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#include <list>
#include <vector>
#include "../Paragem/Paragem.h"
#include "minHeap.h"

using namespace std;

class Graph {

        struct Edge {
            int dest; // Destination node
            string codigoLinha; // Linha a que se refere a aresta
            double distance; // An integer weight
        };

        struct Node {
            Paragem paragem;
            //The list of outgoing edges (to adjacent nodes)
            list <Edge > adj;
            bool operator<(const Node &rhs) const;

            //BFS algorithm
            int distanceBFS;
            bool visitedBFS;
            int predBFS;

            //Dijkstra Algorithm
            double dist;
            int pred;
            bool visited;
        };

        int n; // Graph size (vertices are numbered from 1 to n)
        bool hasDir; // false: undirect; true: directed
        vector <Node> nodes; // The list of nodes being represented
        int zoneBFS;
        int linesBFS;

        public:

        /**
         * \brief Constructor- nr nodes and direction (default: undirected)
         * @param nodes number of nodes of the graph
         * @param dir true if directed false if not
         */
        Graph(int nodes , bool dir = false );

        /**
         * \brief set the int zone
         * @param number new number stored in zone
         */
        void setZoneBFS(int number);

        /**
         * \brief set the int line
         * @param number new number stored in line
         */
        void setLinesBFS(int number);

        // Add edge from source to destination with a certain weight
        /**
         * \brief adds a new edge from osurce to destination
         * @param src source of the edge
         * @param dest destination of the edge
         * @param code code of the line in which th edge is inserted
         */
        void addEdge(int src, int dest, string code);

        /**
         * \brief adds a node to the graph
         * @param paragem node to be added
         */
        void addNode(Paragem paragem);

        /**
         * \brief sorts the nodes stored in graph
         */
        void sortNodes();

        /**
         * \brief Converter of code in node
         * @param code code of the node that we want
         * @return the node that has the given code
         */
        Node getNodeByCode(const string& code);

        /**
         * \brief performs a binary search using the code of the node
         * @param l left pointer
         * @param r right pointer
         * @param code code of the node that we are looking for
         * @return index of the node wanted
         */
        int binarySearch(int l, int r, string code);

        /**
         * \brief Converter of code in an index
         * @param code code of the node that we want
         * @return the index of the wanted node
         */
        int getNodeIndexByCode(const string& code);

        /**
         * \brief adds the edges between stops that are close enough to walk from one to the other
         * @param distanciaPedonal maximum distance between walking stops
         */
        void addWalkingEdges(double distanciaPedonal);

        /**
         * \brief adds edges between the new source stop and other stops that are close enough to walk to
         * @param distanciaPedonal maximum distance between walking stops
         * @param origemUtilizador source stop
         */
        void addEdgesToNewSourceStop (double distanciaPedonal, Paragem origemUtilizador);

        /**
         * \brief adds edges between the new source stop and other stops that are close enough to walk from
         * @param distanciaPedonal maximum distance between walking stops
         * @param destinoUtilizador destination stop
         */
        void addEdgesToNewDestinationStop(double distanciaPedonal, Paragem destinoUtilizador);

        //BFS less stops
        /**
         * \brief prints the path from source to destination that has less stops (BFS Algortihm)
         * @param source index of the source node
         * @param dest index of the destination node
         */
        void printBFSLessStops(int source, int dest);
        /**
         * \brief computes the BFS from source to destination according to the stops of the map
         * @param s index of the source node
         * @param d index of the destination node
         * @return true if there is a path from source to destination
         */
        bool bfsLS(int s, int d);

         //BFS cheaper - less zones
        /**
         * \brief prints the path from source to destination that has less zones (BFS Algortihm)
         * @param source index of the source node
         * @param dest index of the destination node
         */
        void printBFSLessZones(int source, int dest);
        /**
         * \brief computes the BFS from source to destination according to the zones of the map
         * @param s index of the source node
         * @param d index of the destination node
         * @return true if there is a path from source to destination
         */
        bool bfsLZ(int s, int d);

        //BFS less lines
        /**
         * \brief prints the path from source to destination that has less lines (BFS Algortihm)
         * @param source index of the source node
         * @param dest index of the destination node
         */
        void printBFSLessLines(int source, int dest);
        /**
         * \brief computes the BFS from source to destination according to the lines of the map
         * @param s index of the source node
         * @param d index of the destination node
         * @return true if there is a path from source to destination
         */
        bool bfsLL(int s, int d);

        //Dijkstra Algorithm
        /**
         * \brief Finds distance from source to destination
         * @param a index of the source node
         * @param b index of the destination node
         * @return distance between source and destination
         */
        double dijkstra_distance(int a, int b);
        /**
         * \brief Computes dijkstra for all nodes
         * @param s index of source node
         */
        void dijkstra(int s);
        /**
         * \brief Stores path from source to destination
         * @param a index of the source node
         * @param b index of the destination node
         * @return a list with all the indexes of the nodes of the path
         */
        list<int> dijkstra_path(int a, int b);
        /**
         * \brief Prints the result expected
         * @param source index of the source node
         * @param dest index of the destination node
         */
        void printDijkstra(int source, int dest);

    void incrementNodesNum();
};



#endif //UNTITLED_GRAPH_H
