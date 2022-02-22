//
// Created by mafim on 18/12/2021.
//

/**
 * \file Horario.h
 */

#ifndef AED_G32_HORARIO_H
#define AED_G32_HORARIO_H

#include  <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * \class Horario
 * \brief Classe que representa um horario de transportes.
 */
class Horario {

private:

    /**
     * Dia a que se refere o horário.
     */
    string _dia;

    /**
     * Viagens que ocorrem nesse dia.
     */
    vector<int> _viagens;

public:

    /**
     * \brief Construtor default.
     */
    Horario();

    /**
     * \brief Construtor parametrizado.
     * @param dia Dia da semana.
     * @param viagens Viagens que ocorrem nesse dia.
     */
    Horario(string dia, vector<int> viagens);

    /**
     *
     * @return Dia da semana.
     */
    string getDia();

    /**
     *
     * @return Vector com as viagens desse dia.
     */
    vector<int> getViagens();

    /**
     * \brief Altera o dia da semana.
     * @param dia Novo dia da semana.
     */
    void setDia(string dia);

    /**
     * \brief Altera o vetor viagens.
     * @param viagens Novo vetor.
     */
    void setViagens(vector<int> viagens);

    friend ostream& operator<<(ostream& out, const Horario & horario);
    void showHorario() const;

    /**
     * \brief Indica a proxima viagem a uma dada hora.
     * @param hora
     */
    void proximaViagem(int hora);

};


#endif //AED_G32_HORARIO_H
