//
// Created by Matilde Sequeira on 04/12/2021.
//
/**
 * \file Cliente.h
 * Ficheiro header da classe Cliente
 */

#ifndef AED_G32_CLIENTE_H
#define AED_G32_CLIENTE_H

#include <string>
#include <iostream>

using namespace std;

/**
 * \class Cliente
 * \brief Tem todas as informações sobre um cliente.
 */
class Cliente {
private:
    string nome;
    string dataNasc;
    int nif;
    string email;
    int telefone;
    int id;


public:

    /**
     * \brief Construtor default da classe Client.
     * Instancia um cliente com nome "", data de nascimento "", nif = 0, email "", telefone 0 e id = 0.
     */
    Cliente();

    /**
     * Instancia um cliente com atributos definidos pelos parâmetros da função.
     * @param nome Nome do cliente.
     * @param dataNasc Data de nascimento do cliente.
     * @param nif NIF do cliente.
     * @param email Email do cliente.
     * @param telefone Telefone do cliente.
     * @param id Id do cliente.
     */
    Cliente(string nome, string dataNasc, int nif, string email, int telefone, int id);

    /**
     * Altera o valor do ID do cliente.
     * @param id Novo valor do ID.
     */
    void setId(int id);

    /**
     * Altera o nome do cliente.
     * @param nome Novo nome.
     */
    void setNome(string nome);

    /**
     * Altera a data de nascimento do cliente.
     * @param dataNasc Nova data de nascimento.
     */
    void setDataNasc(string dataNasc);

    /**
     * Altera o NIF do cliente.
     * @param nif Novo NIF
     */
    void setNif(int nif);

    /**
     * Altera o email do cliente.
     * @param email Novo email.
     */
    void setEmail(string email);

    /**
     * Altera o número de telefone do cliente.
     * @param telefone novo número de telefone.
     */
    void setTelefone(int telefone);

    /**
     * Retorna o nome do cliente.
     * @return Nome do cliente.
     */
    string getNome();

    /**
     * Retorna a data de nascimento do cliente.
     * @return Data de nascimento do cliente.
     */
    string getDataNasc();

    /**
     * Retorna o NIF do cliente.
     * @return NIF do cliente.
     */
    int getNif();

    /**
     * Retorna o email do cliente.
     * @return Email do cliente
     */
    string getEmail();

    /**
     * Retorna o número de telefone do cliente
     * @return Número de telefone do cliente
     */
    int getTelefone();

    /**
     * Retorna o ID do cliente
     * @return ID do cliente
     */
    int getId();

    /**
     * Define como é feito o output de um objeto da classe Cliente.
     * @param out output stream
     * @param cliente Cliente a ser passado ao output stream
     * @return retorna o 'out' com o conteúdo de 'cliente' no buffer.
     */
    friend ostream& operator<<(ostream& out, const Cliente & cliente);

    /**
     * Faz o output das informações do cliente para a consola
     */
    void showClientsInformation();


};


#endif //AED_G32_CLIENTE_H
