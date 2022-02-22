//
// Created by Vasco Enes on 03/12/2021.
//

/**
 * \file Bagagem.h
 */

#ifndef AED_G32_BAGAGEM_H
#define AED_G32_BAGAGEM_H


#include <string>
#include "../Cliente/Cliente.h"

using namespace std;

/**
 * \class Bagagem
 * \brief Classe que representa bagagem
 */
class Bagagem {
public:

    /**
     * \brief Construtor da classe bagagem.
     * Recebe um cliente que será o dono da bagagem
     * @param cliente Dono da bagagem.
     */
    Bagagem(Cliente &cliente);

    /**
     * \brief Altera o dono da bagagem.
     * @param cliente Novo dono da bagagem.
     */
    void setDonoDaMala(Cliente &cliente);

    /**
     *\brief Retorna o apontador para o Cliente que é dono da mala (donoDaMala).
     * @return Apontador para Cliente.
     */
    Cliente* getDonoDaMala();

private:

    /**
     * \brief Apontador para o Cliente dono da mala.
     */
    Cliente* donoDaMala; //é suposto ser um apontador para o Cliente
};


#endif //AED_G32_BAGAGEM_H
