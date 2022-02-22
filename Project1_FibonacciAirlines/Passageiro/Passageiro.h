//
// Created by Matilde Sequeira on 08/12/2021.
//

/**
 * \file Passageiro.h
 */

#ifndef AED_G32_PASSAGEIRO_H
#define AED_G32_PASSAGEIRO_H


#include "../Cliente/Cliente.h"

/**
 * \class Passageiro
 * \brief Classe que representa um passageiro.
 */
class Passageiro {
private:

    /**
     * \brief O Passageiro é este Cliente
     */
    Cliente cliente;

    /**
     * Bool que indica se o Passageiro tem Bagagem ou não.
     */
    bool bagagem;

public:

    /**
     * \brief Construtor default.
     */
    Passageiro();

    /**
     * \brief Construtor parametrizado.
     * @param cliente Cliente que será passagiro.
     * @param bagagem Tem ou não Bagagem.
     */
    Passageiro(Cliente cliente, bool bagagem);

    /**
     * \brief Altera o Cliente.
     * @param cliente Novo Cliente.
     */
    void setCliente(Cliente cliente);

    /**
     * \brief Altera o valor bagagem.
     * @param bagagem Novo valor.
     */
    void setBagagem(bool bagagem);

    /**
     * \brief Retorna o cliente.
     * @return Cliente.
     */
    Cliente getCliente();

    /**
     * \brief Retorna bagagem.
     * @return True/False.
     */
    bool getBagagem();

    friend ostream& operator<<(ostream& out, const Passageiro &passageiro);


};


#endif //AED_G32_PASSAGEIRO_H
