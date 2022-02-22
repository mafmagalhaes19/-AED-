//
// Created by mafim on 05/12/2021.
//
/**
 * \file LocaisTransporte.h
 * \brief Ficheiro header da classe LocaisTransporte
 */

#ifndef AED_G32_LOCAISTRANSPORTE_H
#define AED_G32_LOCAISTRANSPORTE_H

#include "Horario.h"
#include <list>
#include <iostream>

using namespace std;

/**
 * \enum TipoTransporte
 * \brief Define o tipo de transporte que passa pelo LocaisTransporte.
 */
enum TipoTransporte {METRO, AUTOCARRO, COMBOIO};


/**
 * \class LocaisTransporte
 * \brief Contém toda a informação que caracteriza um local de transporte.
 */
class LocaisTransporte {
private:

    /**
     * \brief Tipo de transporte.
     */
    TipoTransporte _tipoTransporte;

    /**
     * \brief Distancia para o aeroporto.
     */
    int _distancia;

    /**
     * \brief Horarios de passagem de transportes.
     */
    list<Horario> _horarios;

public:

    /**
     *\brief Construtor default.
     */
    LocaisTransporte();

    /**
     * \brief Construtor parametrizado da classe.
     * @param tipoTransporte Tipo de transporte do LocaisTransporte
     * @param distancia Distancia ao Aeroporto
     * @param horarios Horarios do local de transporte
     */
    LocaisTransporte(TipoTransporte tipoTransporte, int distancia, list<Horario> horarios);

    /**
     * \brief Retorna o tipo de transporte.
     * @return Tipo de transporte.
     */
    TipoTransporte getTipoTransporte();

    /**
     * \brief Retorna a distância ao Aeroporto.
     * @return Distância ao Aeroporto.
     */
    int getDistancia();

    /**
     * \brief Retorna o horario do LocaisTransporte
     * @return Horario
     */
    list<Horario> getHorarios();

    /**
     * \brief Altera o tipo de transporte para o valor passado no parâmetro.
     * @param tipoTransporte Novo tipo de transporte.
     */
    void setTipoTransporte(TipoTransporte tipoTransporte);

    /**
     * \brief Altera a distância para o Aeroporto.
     * @param distancia Nova distância
     */
    void setDistancia(int distancia);

    /**
     * \brief Altera a lista de Horario
     * @param horarios Nova lista de Horario
     */
    void setHorarios(list<Horario> horarios);

    bool operator ==(const LocaisTransporte &l2) const;
    bool operator <(const LocaisTransporte &l2) const;
    bool operator >(const LocaisTransporte &l2) const;
    friend ostream& operator<<(ostream& out, const LocaisTransporte & local);
    void showData() const;

    /**
     * \brief Adiciona um novo Horario.
     * @param horario Horario a adicionar.
     */
    void addHorario(Horario &horario);

    /**
     * \brief Converte o tipo de transporte numa string e retorna.
     * @return String correspondente ao tipo de transporte
     */
    string getTipoTransporteAsString() const;

    /**
     * \brief Retorna a próxima viagem para um certo dia e hora
     * @param diaSemana Dia
     * @param hora Hora
     */
    void proximaViagem(string diaSemana, int hora);

};

#endif //AED_G32_LOCAISTRANSPORTE_H
