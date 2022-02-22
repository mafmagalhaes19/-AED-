//
// Created by Matilde Sequeira on 04/12/2021.
//

/**
 * \file Voo.h
 * \brief Ficheiro de header da classe Voo.
 */

#ifndef AED_G32_VOO_H
#define AED_G32_VOO_H

#include "../Cliente/Cliente.h"
#include "../Data/Data.h"
#include "../Passageiro/Passageiro.h"

#include <string>
#include <list>
using namespace std;

/**
 * \class Voo
 * \brief Classe que caracteriza um voo.
 */
class Voo {

private:

    /**
     * Identificador do voo.
     */
    int numVoo;

    /**
     * Data em que Voo se irá realizar.
     */
    Data data;

    /**
     * Duração do voo.
     */
    int duracao;

    /**
     * Local de origem do Voo.
     */
    string origem;

    /**
     * Destino do Voo.
     */
    string destino;

    /**
     * Lista de Passageiro do Voo
     */
    list<Passageiro> passageiros;

    /**
     * Lugares disponíveis no Voo.
     */
    int disponivel;

    string aviao;
    int total;

public:
    /**
     * \brief Construtor default.
     * Cria um Voo com todos os atributo nulos ou vazios.
     */
    Voo();

    /**
     * \brief Construtor parametrizado.
     * @param num_voo Identificador do Voo.
     * @param data Data do Voo.
     * @param duracao Duração do Voo
     * @param origem Origem do Voo.
     * @param destino Destino do Voo.
     * @param passageiros Lista de passageiros do Voo.
     */
    Voo(int num_voo, Data data, int duracao, string origem, string destino, list<Passageiro> passageiros);

    /**
     * \brief Altera o identificador do Voo.
     * @param numVoo Novo identificador.
     */
    void set_numVoo(int numVoo);

    /**
     * \brief Altera a data do Voo.
     * @param data Nova data do Voo.
     */
    void set_data(Data data);

    /**
     * \brief Altera a duração do Voo.
     * @param duracao Nova duração.
     */
    void set_duracao(int duracao);

    /**
     * \brief Altera a origem do Voo.
     * @param origem Nova origem.
     */
    void set_origem(string origem);

    /**
     * \brief Altera o destindo do Voo.
     * @param destino Novo destino.
     */
    void set_destino(string destino);

    /**
     * \brief Altera a lista de passageiros do Voo.
     * @param passageiros Nova lista de passageiros.
     */
    void set_passageiros(list<Passageiro> passageiros);
    void set_aviao(string matricula);
    void set_aviaoTotal(string aviao, int total);
    void setDisponiveis(int disponiveis);
    void setTotal(int total);

    /**
     * \brief Retorna o identificador do Voo.
     * @return Identificador do Voo.
     */
    int get_numVoo();

    /**
     * \brief Retorna a Data do Voo.
     * @return Data do Voo.
     */
    Data get_data();

    /**
     * \brief Retorna a duração do Voo.
     * @return Duração do Voo.
     */
    int get_duracao();

    /**
     * \brief Retorna a origem do Voo.
     * @return Origem do Voo.
     */
    string get_origem();

    /**
     * \brief Retorna o destino do Voo.
     * @return Destino do Voo.
     */
    string get_destino();

    /**
     * \brief Retorna a lista de passageiros.
     * @return Lista de passageiros.
     */
    list<Passageiro> get_passageiros();

    /**
     * \brief Retorna o número de lugares disponíveis.
     * @return Lugares disponíveis.
     */
    int getDisponiveis();

    /**
     * \brief Retorna o Aviao que irá realizar o Voo.
     * @return Aviao que realiza o Voo.
     */
    string get_aviao();

    /**
     * \brief Adiciona um passageiro à lista de passageiros do Voo.
     * @param passsageiro Passageiro a adicionar.
     */
    void addPassageiro(Passageiro passsageiro);

    friend ostream& operator<<(ostream& out, const Voo & voo);



};


#endif //AED_G32_VOO_H
