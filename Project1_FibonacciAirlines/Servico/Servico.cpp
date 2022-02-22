//
// Created by Vasco Enes on 03/12/2021.
//

#include "Servico.h"

Servico::Servico() {}

Servico::Servico(TipoServico tipoServico, Data data, string func, Aviao &aviao) {
    this->aviao = aviao;
    this->tipoServico = tipoServico;
    this->data = data;
    this->funcionario = func;
    this -> aviao = aviao;
}

TipoServico Servico::getTipoServico() {
    return this->tipoServico;
}

string Servico::getFuncionario() {
    return this->funcionario;
}

Data Servico::getData() {
    return this->data;
}

void Servico::setTipoServico(TipoServico tServico) {
    this->tipoServico = tServico;
}

void Servico::setFuncionario(string func) {
    this->funcionario = func;
}

Aviao Servico::getAviao() {
    return aviao;
}

string Servico::getAviaoMatricula(){
    return aviao.get_matricula();
}

string Servico::getTipoServicoAsString(){
    string servico = "";
    if(tipoServico == LIMPEZA){
        servico = "limpeza";
    }
    else if(tipoServico == MANUTENCAO){
        servico = "manutencao";
    }
    return servico;
}


void Servico::setAviao(Aviao aviao) {
    this -> aviao = aviao;
}

ostream& operator<<(ostream &out, const Servico & servico){
    out << "Data: " << servico.data << "   Funcionario: " << servico.funcionario << endl;
    return out;
}

bool Servico::operator<(Servico const &rhs) const {
    return this->data < rhs.data;
}

void Servico::setData(Data data) {
    this -> data = data;
}