//
// Created by Vasco Enes on 03/12/2021.
//

/**
 * \file Servico.h
 * \brief Ficheiro de header da classe Servico
 */

#ifndef AED_G32_SERVICO_H
#define AED_G32_SERVICO_H
#include "string"
#include "../Data/Data.h"
#include "../Aviao/Aviao.h"

using namespace std;

/**
 * \enum TipoServico
 * \brief Tipos de serviço disponíveis.
 */
enum TipoServico {LIMPEZA, MANUTENCAO};

/**
 * \class Servico
 * \brief Classe que contém a informação que caracteriza um Servico.
 */
class Servico {
public:
    /**
     * \brief Construtor default.
     */
    Servico();

    /**
     * \brief Construtor parametrizado.
     * @param tipoServico Tipo de serviço.
     * @param data Data do serviço.
     * @param funcionario Funcionário que irá realizar o serviço.
     * @param aviao Aviao que irá receber o serviço.
     */
    Servico(TipoServico tipoServico, Data data, string funcionario, Aviao &aviao);

    /**
     *
     * @return  Tipo de serviço.
     */
    TipoServico getTipoServico();

    /**
     *
     * @return Data.
     */
    Data getData();

    /**
     *
     * @return Funcionário.
     */
    string getFuncionario();

    /**
     * \brief Altera o tipo de serviço.
     * @param tipoServico Novo tipo de serviço.
     */
    void setTipoServico(TipoServico tipoServico);

    /**
     * \brief Altera o funcionario
     * @param funcionario Novo funcionario
     */
    void setFuncionario(string funcionario);

    /**
     * \brief Altera o aviao a que o Servico está associado.
     * @param aviao Novo Aviao
     */
    void setAviao(Aviao aviao);

    /**
     * \brief Altera a data do Servico
     * @param data Nova Data
     */
    void setData(Data data);

    /**
     * \brief Retorna o Aviao
     * @return Aviao a que o Servico está atribuído.
     */
    Aviao getAviao();

    /**
     * \brief Retorna a matrícula do Aviao.
     * @return Matrícula do Aviao.
     */
    string getAviaoMatricula();

    /**
     * \brief Retorna o tipo de serviço como uma string.
     * @return Tipo de serviço.
     */
    string getTipoServicoAsString();
    friend ostream& operator<<(ostream& out, const Servico & servico);
    bool operator<(Servico const &rhs) const;


private:

    /**
     * Tipo de servico
     */
    TipoServico tipoServico;

    /**
     * Data do Servico
     */
    Data data;

    /**
     * Funcionário que irá realizar/realizou o Servico
     */
    string funcionario;

    /**
     * Aviao que irá receber/recebeu o Servico
     */
    Aviao aviao;

};




#endif //AED_G32_SERVICO_H
