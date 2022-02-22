//
// Created by Vasco Enes on 27/01/2022.
//

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "STCPMap.h"
#include "Paragem/Paragem.h"
#include "Graph/Graph.h"
#include "Linha/Linha.h"

using namespace std;

void STCPMap::readParagens() {

        string  path = "../Parte2/Dataset/stops.csv";
        string line;
        string code, name, zone, lat, longi;
        ifstream file(path);
        Paragem paragem;


        if(file.is_open()){
            getline(file, line);

            while (getline(file,line)){
                stringstream ss(line);
                getline(ss, code, ',');
                getline(ss, name, ',');
                getline(ss, zone, ',');
                getline(ss, lat, ',');
                getline(ss, longi, ',');


                paragem = Paragem(code,name,zone, ::strtod(lat.c_str(), nullptr),::strtod(longi.c_str(),nullptr));
                mapaParagens.addNode(paragem);
            }
            file.close();
            mapaParagens.sortNodes();
        } else {
            cout << "Erro ao abrir ficheiro das paragens." << endl;
        }

}

Paragem STCPMap::getParagemByCode(const string& code) {
    return mapaParagens.getNodeByCode(code).paragem;
}

void STCPMap::readListaLinhas() {

    string path = "../Parte2/Dataset/lines.csv";
    string code;
    string name;
    string line;
    ifstream file(path);

    if(file.is_open()){
        getline(file, line);

        while(getline(file, line)){
            stringstream ss(line);
            getline(ss, code, ',');
            getline(ss, name, ',');

            readLinha(code, name);
        }
        file.close();
    }
}

void STCPMap::readLinha(const string& code, const string& name) {

    readLinha_aux(code, name, "0");
    readLinha_aux(code, name, "1");

}

void STCPMap::readLinha_aux(const string& code, const string& name, const string& sentido) {

    string path = "../Parte2/Dataset/line_"+ code + "_" + sentido + ".csv";

    ifstream file(path);
    string number, paragem1, paragem2;
    int indexParagem1, indexParagem2;
    Linha linha;

    linha.setCode(code + "_" + sentido);
    linha.setName(name);


    if(file.is_open()){
        getline(file, number);
        getline(file, paragem1);

        if(number != "0"){

            while(!file.eof()){
                getline(file, paragem2);

                indexParagem1 = mapaParagens.getNodeIndexByCode(paragem1);
                indexParagem2 = mapaParagens.getNodeIndexByCode(paragem2);

                if(indexParagem1 > -1 && indexParagem2 > -1){
                    mapaParagens.addEdge(indexParagem1, indexParagem2, code);
                    linha.addParagem(paragem1);
                }
                paragem1 = paragem2;
            }
            linha.addParagem(paragem1);
            listaLinhas.push_back(linha);
            file.close();
        }
    } else {
        cout << "Erro ao abrir ficheiro da linha " << code << "." << endl;
    }
}

Graph STCPMap::getGraph() {
    return mapaParagens;
}

double STCPMap::getDistanciaPedonal() {
    return distanciaPedonal;
}

void STCPMap::addWalkingEdges() {
    Linha linhaPedonal;
    linhaPedonal.setCode("12345");
    linhaPedonal.setName("12345 - Caminhos a pe");
    mapaParagens.addWalkingEdges(distanciaPedonal);
}

void STCPMap::addEdgesToNewSourceStop() {
    mapaParagens.addEdgesToNewSourceStop(distanciaPedonal, origemUtilizador);
}

void STCPMap::addEdgesToNewDestinationStop() {
    mapaParagens.addEdgesToNewDestinationStop(distanciaPedonal, destinoUtilizador);
}


void STCPMap::setOrigemUtilizador(const Paragem &newOrigemUtilizador) {
    STCPMap::origemUtilizador = newOrigemUtilizador;
}

void STCPMap::setDestinoUtilizador(const Paragem &newDestinoUtilizador) {
    STCPMap::destinoUtilizador = newDestinoUtilizador;
}

void STCPMap::setCodigoParagemExistente(const string &newCodigoParagemExistente) {
    STCPMap::codigoParagemExistente = newCodigoParagemExistente;
}

void STCPMap::setDestinoParagemExistente(const string &newDestinoParagemExistente) {
    STCPMap::destinoParagemExistente = newDestinoParagemExistente;
}


void STCPMap::setDistanciaPedonal(double distancia) {
    distanciaPedonal = distancia;
}

void STCPMap::bfsLessStops() {
    mapaParagens.printBFSLessStops(mapaParagens.getNodeIndexByCode(origemUtilizador.getCode()),mapaParagens.getNodeIndexByCode(destinoUtilizador.getCode()));
}

void STCPMap::dijkstra() {
    mapaParagens.printDijkstra(mapaParagens.getNodeIndexByCode(origemUtilizador.getCode()),mapaParagens.getNodeIndexByCode(destinoUtilizador.getCode()));
}

void STCPMap::bfsLessZones() {
    mapaParagens.printBFSLessZones(mapaParagens.getNodeIndexByCode(origemUtilizador.getCode()),mapaParagens.getNodeIndexByCode(destinoUtilizador.getCode()));
}

void STCPMap::bfsLessLines() {
    mapaParagens.printBFSLessLines(mapaParagens.getNodeIndexByCode(origemUtilizador.getCode()),mapaParagens.getNodeIndexByCode(destinoUtilizador.getCode()));
}

void STCPMap::addParagem(Paragem paragem) {
    mapaParagens.addNode(paragem);
    mapaParagens.incrementNodesNum();
    mapaParagens.sortNodes();

}

STCPMap::STCPMap() = default;
