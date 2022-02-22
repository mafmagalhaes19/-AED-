//
// Created by Matilde Sequeira on 04/12/2021.
//

#include "Aviao.h"

Aviao::Aviao() {
    this -> matricula = "";
    this -> capacidade = 0;
    this -> planoVoo = {};
}

Aviao::Aviao(string matricula, int capacidade, vector<Voo> planoVoo) {
    this -> matricula = matricula;
    this -> capacidade = capacidade;
    this -> planoVoo = planoVoo;
}

void Aviao::set_matricula(string matricula) {
    this -> matricula = matricula;
}

void Aviao::set_capacidade(int capacidade) {
    this -> capacidade = capacidade;
}

void Aviao::set_planoVoo(vector<Voo> planoVoo) {
    this -> planoVoo = planoVoo;
}

string Aviao::get_matricula() {
    return matricula;
}

int Aviao::get_capacidade() {
    return capacidade;
}

vector<Voo> Aviao::get_planoVoo() {
    return planoVoo;
}

ostream& operator<<(ostream &out, const Aviao &aviao) {
    out << "Matricula: " << aviao.matricula << "  Capacidade: " << aviao.capacidade << endl;
    out << "Plano de Voo: " << endl;
    for (int i = 0; i < aviao.planoVoo.size(); i++){
        out << to_string(i+1) << ") " << aviao.planoVoo.at(i) << endl;
    }
    return out;
}
