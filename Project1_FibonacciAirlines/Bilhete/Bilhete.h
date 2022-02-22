//
// Created by mafim on 05/12/2021.
//

/**
 * \file Bilhete.h
 * Ficheiro header da classe Bilhete
 */

#ifndef AED_G32_BILHETE_H
#define AED_G32_BILHETE_H

#include "../Voo/Voo.h"

using namespace std;

/**
 * \class Bilhete
 * \brief Representa um bilhete
 */
class Bilhete {
public:

    /**
     * Construtor da classe bilhete.
     * Instancia um bilhete associado ao 'Voo' que pode ou não ter bagagem.
     * @param bagagem Indica se o bilhete a ser criado tem ou não direito a bagagem.
     * @param voo O voo a que o bilhete está associado
     */
    Bilhete(bool bagagem, Voo &voo);

    /**
     *
     * @return O Voo a que o bilhete está associado.
     */
    Voo getVoo();

    /**
     *
     * @return Retorna se o bilhete tem ou não direito a bagagem
     */
    bool hasBagagem();

    /**
     * Altera o Voo a que o bilhete está associado
     * @param voo O novo voo
     */
    void setVoo(Voo &voo);

    /**
     * Altera o valor de 'bagagem'
     * @param bagagem novo valor a atribuir
     */
    void setBagagem(bool bagagem);

private:

    /**
     * Cliente a que o bilhete pertence.
     */
    Cliente* cliente;

    /**
     * Voo a que o bilhete está associado.
     */
    Voo* voo;

    /**
     * Valor que define se o bilhete tem ou não direito a bagagem.
     */
    bool bagagem;

};

#endif //AED_G32_BILHETE_H
