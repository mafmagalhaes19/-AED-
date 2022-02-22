//
// Created by Matilde Sequeira on 07/12/2021.
//

#include "Data.h"

Data::Data() {
    this -> dia = 1;
    this -> mes = 1;
    this -> ano = 2000;
}

Data::Data(string data) {
    string diaString = data.substr(0,data.find(" "));
    data.erase(0, data.find(" ") + 1);
    this -> dia = stoi(diaString);

    string  mesString = data.substr(0, data.find(" "));
    data.erase(0, data.find(" ") + 1);
    this -> mes = stoi(mesString);

    this -> ano = stoi(data);

}

Data::Data(int dia, int mes, int ano) {
    this -> dia = dia;
    this -> mes = mes;
    this -> ano = ano;
}

void Data::setDia(int dia) {
    this -> dia = dia;
}

void Data::setMes(int mes) {
    this -> mes = mes;
}

void Data::setAno(int ano) {
    this -> ano = ano;
}

int Data::getDia() {
    return dia;
}

int Data::getMes() {
    return mes;
}

int Data::getAno() {
    return ano;
}

bool Data::operator<(const Data &d1) const{
    if (ano == d1.ano){
        if (mes == d1.mes){
            return dia < d1.dia;
        }else{
            return mes < d1.mes;
        }
    }else{
        return ano < d1.ano;
    }
}

bool Data::operator == (const Data & d1) const{
    if (ano == d1.ano){
        if(mes == d1.mes){
            if(dia == d1.dia){
                return true;
            }
        }
    }
    return false;
}

ostream& operator<<(ostream& out, const Data & data){
    out << data.dia << '/' << data.mes << '/' << data.ano;
    return out;
}