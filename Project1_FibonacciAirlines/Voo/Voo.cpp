//
// Created by Matilde Sequeira on 04/12/2021.
//

#include "Voo.h"

Voo::Voo() {
    this -> numVoo = 0;
    this -> duracao = 0;
    this -> origem = "";
    this -> destino = "";
    this -> passageiros = {};
    aviao = "";
    total = 0;
    disponivel = 0;
}

Voo::Voo(int num_voo, Data data, int duracao, string origem, string destino, list<Passageiro> passageiros) {
    this -> numVoo = num_voo;
    this -> duracao = duracao;
    this -> data = data;
    this -> origem = origem;
    this -> destino = destino;
    this -> passageiros = passageiros;
    aviao = "";
    total = 0;
    disponivel = 0;
}

void Voo::set_numVoo(int numVoo) {
    this ->numVoo = numVoo;
}

void Voo::set_duracao(int duracao) {
    this -> duracao = duracao;
}

void Voo::set_data(Data data) {
    this -> data = data;
}

void Voo::set_origem(string origem) {
    this -> origem = origem;
}

void Voo::set_destino(string destino) {
    this -> destino = destino;
}


void Voo::set_passageiros(list<Passageiro> passageiros) {
    this -> passageiros = passageiros;
}
void Voo::set_aviao(string matricula){
    aviao = matricula;
}

void Voo::set_aviaoTotal(string aviao, int total){
    this -> aviao = aviao;
    this -> total = total;
    disponivel = total;
}

void Voo::setDisponiveis(int disponiveis) {
    this -> disponivel = disponiveis;
}

void Voo::setTotal(int total) {
    this -> total = total;
    disponivel = total;
}

string Voo::get_origem() {
    return origem;
}

Data Voo::get_data() {
    return data;
}

string Voo::get_destino() {
    return destino;
}

int Voo::get_duracao() {
    return duracao;
}

int Voo::get_numVoo() {
    return numVoo;
}

int Voo::getDisponiveis(){
    return disponivel;
}

list<Passageiro> Voo::get_passageiros() {
    return passageiros;
}

string Voo::get_aviao(){
    return aviao;
}

void Voo::addPassageiro(Passageiro passageiro){
    passageiros.push_back(passageiro);
}

ostream& operator<<(ostream& out, const Voo& voo){
    out << "Numero de Voo: " << voo.numVoo <<'\n' << "       Origem: " << voo.origem <<'\n'<< "      Destino: " << voo.destino << endl;
    out << "Data: " << voo.data << "   Duracao: " << voo.duracao << endl;
    out << "Aviao: " << voo.aviao << "    Lugares disponiveis: " << voo.disponivel;
    return out;
}
