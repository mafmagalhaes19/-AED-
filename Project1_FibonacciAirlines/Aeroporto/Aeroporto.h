//
// Created by Matilde Sequeira on 05/12/2021.
//
/**
 * \file Aeroporto.h
 * Ficheiro de header da classe Aeroporto
 */
#ifndef AED_G32_AEROPORTO_H
#define AED_G32_AEROPORTO_H

#include <list>
#include <queue>


#include "../Aviao/Aviao.h"
#include "../Voo/Voo.h"
#include "../Servico/Servico.h"
#include "../LocaisTransporte/LocaisTransporte.h"
#include "../BST/binaryTree.h"
#include "../BST/bst.h"
#include "../FibonacciAirlines/Macros.h"

/**
 * \class Aeroporto
 * \brief Contém todas as informações sobre um aeroporto.
 */
class Aeroporto {

private:

    /**
     * \brief Nome do aeroporto.
     */
    string _nome;

    /**
     * \brief Binary Seach Tree (BST) que contém os LocaisTransporte associados ao Aeroporto.
     */
    BST<LocaisTransporte> _locaisTransporte;

public:
    Aeroporto(string nome, BST<LocaisTransporte> locaisTransporte1);
    string getNome();
    BST<LocaisTransporte> getLocaisTransporte();

    void setNome(string nome);
    void setLocaisTransporte (BST<LocaisTransporte> & locaisTransporte);

    friend ostream& operator<<(ostream& out, const Aeroporto & aeroporto);
    void showAirportInformation();
    void addLocalTransporte(LocaisTransporte &local);
    void removeLocalTransporte();
    void showClosestTransport(Aeroporto aeroporto);

    void saveData(Aeroporto& aeroporto, ofstream& fLocaisTransporte);

};


#endif //AED_G32_AEROPORTO_H
