//
// Created by mafim on 05/12/2021.
//

#include "LocaisTransporte.h"

LocaisTransporte::LocaisTransporte() {
    _distancia = 0;
}

LocaisTransporte::LocaisTransporte(TipoTransporte tipoTransporte, int distancia, list<Horario> horarios): _tipoTransporte(tipoTransporte), _distancia(distancia), _horarios(horarios) {
}

TipoTransporte LocaisTransporte::getTipoTransporte() {
    return _tipoTransporte;
}

int LocaisTransporte::getDistancia() {
    return _distancia;
}

list<Horario> LocaisTransporte::getHorarios() {
    return _horarios;
}

void LocaisTransporte::setTipoTransporte(TipoTransporte tipoTransporte) {
    _tipoTransporte = tipoTransporte;
}

void LocaisTransporte::setDistancia(int distancia) {
    _distancia = distancia;
}

void LocaisTransporte::setHorarios(list<Horario> horarios){
    _horarios = horarios;
}

bool LocaisTransporte::operator==(const LocaisTransporte &l2) const {
    if (_tipoTransporte == l2._tipoTransporte && _distancia == l2._distancia){
        return true;
    }
    return false;
}

bool LocaisTransporte::operator<(const LocaisTransporte &l2) const{
    bool aux = false;
    if (_distancia != l2._distancia) {
        aux = _distancia < l2._distancia;
    }
    else{
        if(_tipoTransporte == METRO){
            aux = true;
        }
        else if(l2._tipoTransporte == METRO){
            aux = false;
        }
        else if(_tipoTransporte == COMBOIO){
            aux = true;
        }
        else{
            aux = false;
        }
    }
     return aux;
}

bool LocaisTransporte::operator>(const LocaisTransporte &l2) const {
    return ( !(*this < l2) && !(*this == l2));
}

ostream &operator<<(ostream &out, const LocaisTransporte &local) {
    out << local.getTipoTransporteAsString() << endl;
    out << local._distancia << endl;

    list<Horario>::const_iterator it;
    for(it = local._horarios.begin(); it != local._horarios.end(); it++){
        out << *it;
    }
    return out;
}

void LocaisTransporte::showData() const {
    cout << *this;
}

void LocaisTransporte::addHorario(Horario &horario) {
    _horarios.push_back(horario);
}

string LocaisTransporte::getTipoTransporteAsString() const{
    string tipoTransporte = "";
    if(_tipoTransporte == METRO){
        tipoTransporte = "Metro";
    }
    else if(_tipoTransporte == COMBOIO){
        tipoTransporte = "Comboio";
    }
    else if(_tipoTransporte == AUTOCARRO){
        tipoTransporte = "Autocarro";
    }
    return tipoTransporte;
}

void LocaisTransporte::proximaViagem(string diaSemana, int hora) {
    bool found = false;
    list<Horario>::iterator it;
    for( it = _horarios.begin(); it != _horarios.end(); it++){
        if (it->getDia() == diaSemana){
            it->proximaViagem(hora);
            found = true;
        }
    }
    if(!found){
        cout << "O dia da semana nao e valido!" << endl;
    }

}


