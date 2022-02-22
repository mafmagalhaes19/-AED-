//
// Created by Vasco Enes on 27/01/2022.
//

#ifndef UNTITLED_STCPMAP_H
#define UNTITLED_STCPMAP_H


#include "Graph/Graph.h"
#include "Linha/Linha.h"

class STCPMap {

public:

    /**
     * \brief Constructor of the class
     */
    STCPMap();

    /**
     * \brief Reads the stops.csv
     */
    void readParagens();
    /**
     * \brief reads the file lines.cvs
     */
    void readListaLinhas();
    /**
     * \brief reads a file that belongs to a certain line
     * @param code code of the line
     * @param name name of the line
     */
    void readLinha(const string& code, const string& name);
    /**
     * \brief reads a file that belongs to a certain line
     * @param code code of the line
     * @param name name of the line
     */
    void readLinha_aux(const string& code, const string& name, const string& sentido);

    /**
     * \brief Converter of code in stop
     * @param code code of the stop that we are looking for
     * @return the stop that we are looking for
     */
    Paragem getParagemByCode(const string& code);

    /**
     * \brief getter of the graph
     * @return the graph owned by this class
     */
    Graph getGraph();

    /**
     * \brief getter of the walking distance
     * @return walking distance
     */
    double getDistanciaPedonal();

    /**
     * \brief Setter of walking distance
     * @param distancia walking distance between stops
     */
    void setDistanciaPedonal(double distancia);
    /**
     * \brief Setter of the code of the existing stop
     * @param newCodigoParagemExistente code of the existing stop
     */
    void setCodigoParagemExistente(const string &newCodigoParagemExistente);
    /**
     * \brief Setter of the code of the detination existing stop
     * @param newDestinoParagemExistente  code of the detination existing stop
     */
    void setDestinoParagemExistente(const string &newDestinoParagemExistente);

    /**
     * \brief adds the edges between stops that are close enough to walk from one to the other
     */
    void addWalkingEdges();

    /**
     * \brief If the user starts its journey from a location that isn't a stop, we need to add new edges between his location and the stops close enough to walk to
     */
    void addEdgesToNewSourceStop();
    /**
     * \brief If the user end is its journey in a location that isn't a stop, we need to add new edges between this location and the stops close enough to walk from
     */
    void addEdgesToNewDestinationStop();
    /**
     * \brief setter of the source stop
     * @param newOrigemUtilizador source stop
     */
    void setOrigemUtilizador(const Paragem &newOrigemUtilizador);
    /**
     * |brief setter of the destination stop
     * @param newDestinoUtilizador destination stop
     */
    void setDestinoUtilizador(const Paragem &newDestinoUtilizador);
    /**
     * \brief computes the bfs that finds the shortest path according to the number of stops
     */
    void bfsLessStops();
    /**
     * \brief computes the dijkstra algorithm to find the shortest path according to the distance between stops
     */
    void dijkstra();
    /**
     * \brief computes the bfs that finds the shortest path according to the number of zones
     */
    void bfsLessZones();
    /**
     * \brief computes the bfs that finds the shortest path according to the number of lines
     */
    void bfsLessLines();

    void addParagem(Paragem paragem);

private:

    Graph mapaParagens = Graph(2487, true);
    vector<Linha> listaLinhas;

    //User's willing to walk between stops
    double distanciaPedonal;

    Paragem origemUtilizador;
    string codigoParagemExistente;

    Paragem destinoUtilizador;
    string destinoParagemExistente;


};


#endif //UNTITLED_STCPMAP_H
