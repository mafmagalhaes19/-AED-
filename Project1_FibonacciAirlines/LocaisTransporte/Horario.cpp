//
// Created by mafim on 18/12/2021.
//

#include "Horario.h"

Horario::Horario(): _dia("") {
}

Horario::Horario(string dia, vector<int> viagens): _dia (dia), _viagens(viagens) {
}

string Horario::getDia() {
    return _dia;
}

vector<int> Horario::getViagens() {
    return _viagens;
}

void Horario::setDia(string dia) {
    _dia = dia;
}

void Horario::setViagens(vector<int> viagens) {
    _viagens = viagens;
}

ostream &operator<<(ostream &out, const Horario &horario) {
    out << horario._dia << endl;
    for(int i = 0; i < horario._viagens.size(); i++){
        out << horario._viagens[i] << '/';
    }
    out << endl;
    return out;
}

void Horario::showHorario() const {
    cout << *this;
}

//Binary search
void Horario::proximaViagem(int hora) {
    cout << "Proxima viagem: ";
    int left = 0;
    int right = _viagens.size() -1;
    int middle = (left + right) / 2;
    bool enter = true;

    if ((hora == _viagens[right]) || (hora > _viagens[right])){
        cout << _viagens[0];
        enter = false;
    }
    else if ( 0 < hora < _viagens[left]){
        cout << _viagens[left];
        enter = false;
    }
    else if(hora == _viagens[left]){
        cout << _viagens[left+1];
        enter = false;
    }

    while (left <= right && enter) {
        if (hora == _viagens[middle]) {
            cout << _viagens[middle+1];
            break;
        }
        else if ((middle == left+1) && hora < _viagens[middle] ){
            cout << _viagens[middle];
            break;
        }
        else if ((middle == right-1) && (_viagens[middle] < hora < _viagens[right])){
            cout << _viagens[middle];
            break;
        }
        else if (hora < _viagens[middle]) {
            right = middle;
            middle = (left + right) / 2;
        }
        else {
            left = middle;
            middle = (left + right) / 2;
        }
    }
}









