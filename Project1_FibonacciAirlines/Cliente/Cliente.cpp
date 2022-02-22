//
// Created by Matilde Sequeira on 04/12/2021.
//

#include "Cliente.h"


using namespace std;

Cliente::Cliente() {
    this -> nome = "";
    this -> dataNasc = "";
    this -> nif = 0;
    this -> email = "";
    this -> telefone = 0;
    this -> id = 0;
}

Cliente::Cliente(string nome, string dataNasc, int nif, string email, int telefone, int id) {
    this -> nome = nome;
    this -> dataNasc = dataNasc;
    this -> nif = nif;
    this -> email = email;
    this -> telefone = telefone;
    this -> id = id;
}

string Cliente::getDataNasc() {
    return dataNasc;
}

string Cliente::getEmail() {
    return email;
}

int Cliente::getNif() {
    return nif;
}

string Cliente::getNome() {
    return nome;
}

int Cliente::getTelefone() {
    return telefone;
}

int Cliente::getId() {
    return id;
}


void Cliente::setDataNasc(string dataNasc) {
    this -> dataNasc = dataNasc;
}

void Cliente::setEmail(string email) {
    this -> email = email;
}

void Cliente::setNif(int nif) {
    this -> nif = nif;
}

void Cliente::setNome(string nome) {
    this -> nome = nome;
}

void Cliente::setId(int id) {
    this -> id = id;
}


void Cliente::setTelefone(int telefone) {
    this -> telefone = telefone;
}

ostream& operator<<(ostream& out, const Cliente & cliente)
{
    out << to_string(cliente.id) << endl;
    out << cliente.nome << endl;
    out << cliente.dataNasc << endl;
    out << to_string(cliente.nif) << endl;
    out << cliente.email << endl;
    out << to_string(cliente.telefone) << endl;

    return out;
}

void Cliente::showClientsInformation() {
    cout << *this;
}





