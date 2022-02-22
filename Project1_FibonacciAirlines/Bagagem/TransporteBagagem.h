//
// Created by Vasco Enes on 03/12/2021.
//
/**
 * \file TransporteBagagem.h
 * Ficheiro header da classe TransporteBagagem
 */

#ifndef AED_G32_TRANSPORTEBAGAGEM_H
#define AED_G32_TRANSPORTEBAGAGEM_H


#include "Bagagem.h"
#include "../Aviao/Aviao.h"
#include <stack>
#include <list>

/**
 * \brief Classe que representa o sistema de transporte de bagagem do aeroporto
 */
class TransporteBagagem {

public:

    /**
     * Construtor da classe
     * @param aviao Aviao onde a bagagem deverá ser descarregada
     * @param numCarr número de carruagens do carrinho
     * @param numPilhas número de pilhas de Bagagem em cada carruagem
     * @param capacidadePilhas número máximo de malas por cada pilha
     */
    TransporteBagagem(Aviao &aviao, int numCarr, int numPilhas, int capacidadePilhas);

    /**
     * Retorna a pilha de índice 'numPilha' na carruagem de índice 'numCarruagem'.
     * @param numCarruagem índice da carruagem
     * @param numPilha índice da pilha
     * @return Pilha correspondente
     */
    stack<Bagagem> getPilhaAt(int numCarruagem, int numPilha);

    /**
     * Retorna a carruagem de índice 'numCarruagem'
     * @param numCarruagem
     * @return
     */
    list<stack<Bagagem>> getCarruagemAt(int numCarruagem);

    /**
     * Retorna o carrinho de transporte
     * @return
     */
    list<list<stack<Bagagem>>> getCarrinhoTransporte();

    /**
     *
     * @return Retorna o número de carruagens do carrinho
     */
    int getNumCarruagens();

    /**
     *
     * @return Número de pilhas em cada carruagem
     */
    int getNumPilhas();

    /**
     *
     * @return Número máximo de bagagens em cada pilha
     */
    int getCapacidadePilhas();

    /**
     * Adiciona uma bagagem ao carrinho e retorna true no caso de ser adicionada com sucesso
     * @param bagagem Bagagem a ser adicionada
     * @return True se a bagagem for adicionada com sucesso, false se não for adicionada.
     */
    bool adicionaBagagem(Bagagem bagagem);
  //  void carregaBagagemAviao();


private:

    /**
     * Aviao a que a bagagem pertence
     */
    Aviao *aviao;

    /**
     * Número de carruagens do carrinho
     */
    int numCarruagens;

    /**
     * Número de pilhas em cada carruagem
     */
    int numPilhas;

    /**
     * Capacidade máxima de cada pilha
     */
    int capacidadePilhas;

    /**
     * Carrinho onde estão as carruagens com pilhas de bagagens
     */
    list<list<stack<Bagagem>>> carrinhoDeTransporte;

    /**
     * Função que constrói a representação do carrinho com numCarruagens carruagens e numPilhas de pilhas em cada carruagem
     */
    void constroiCarrinhoTransporte();

};


#endif //AED_G32_TRANSPORTEBAGAGEM_H
