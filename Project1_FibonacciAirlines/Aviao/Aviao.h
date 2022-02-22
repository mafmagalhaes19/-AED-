//
// Created by Matilde Sequeira on 04/12/2021.
//

/**
 * \file Aviao.h
 * \brief Ficheiro header da classe Aviao
 */

#ifndef AED_G32_AVIAO_H
#define AED_G32_AVIAO_H

#include "../Voo/Voo.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;


/**
 * \class Aviao
 * \brief Classe que contém a informação que descreve um avião.
 */
class Aviao {

private:

    /**
     * \brief Matrícula que identifica o avião.
     */
    string matricula;

    /**
     * \brief Número máximo de passageiros que o avião pode transportar.
     */
    int capacidade;

    /**
     *\brief Voos planeados para este avião.
     */
    vector<Voo> planoVoo;

public:

    /**
     * \brief Construtor default da classe Aviao.
     * Constrói um Aviao com matrícula '', capacidade = 0 e plano de voo {}.
     */
    Aviao();

    /**
     * \brief Construtor parametrizado da classe Aviao.
     * Cria um Aviao com os valores passados pelos parâmetros
     * @param matricula Matrícula do Aviao
     * @param capacidade Capacidade máxima do Aviao
     * @param planoVoo Plano de voo do Aviao, se omitido será {}.
     */
    Aviao(string matricula, int capacidade, vector<Voo> planoVoo = {});

    /**
     * \brief Altera a matrícula do Aviao para o valor passado pelo parâmetro.
     * @param matricula Valor novo a atribuir.
     */
    void set_matricula(string matricula);

    /**
     * \brief Altera a capacidade do Aviao para o valor passado pelo parâmetro.
     * @param capacidade Nova capacidade.
     */
    void set_capacidade(int capacidade);

    /**
     * \brief Altera o plano de voo do Aviao para a lista passada pelo parâmetro.
     * @param planoVoo Novo plano de Voo
     */
    void set_planoVoo(vector<Voo> planoVoo);

    /**
     * \brief Retorna a matricula do Aviao.
     * @return Matricula do Aviao
     */
    string get_matricula();

    /**
     * \brief Retorna a capacidade do Aviao.
     * @return Capacidade do Aviao.
     */
    int get_capacidade();

    /**
     * \brief Retorna o plano de Voo do Aviao
     * @return Plano de Voo do Aviao
     */
    vector<Voo> get_planoVoo();

    /**
     * \brief Prepara um output stream para fazer output de um Aviao.
     * @param out Output stream a ser alterado.
     * @param aviao Aviao a ser exibido.
     * @return Output stream com a string preparada para ser exibida.
     */
    friend ostream& operator<<(ostream& out, const Aviao & aviao);


};


#endif //AED_G32_AVIAO_H
