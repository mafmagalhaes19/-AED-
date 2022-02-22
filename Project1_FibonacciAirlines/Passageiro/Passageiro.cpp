//
// Created by Matilde Sequeira on 08/12/2021.
//

#include "Passageiro.h"

Passageiro::Passageiro() {
    this -> bagagem = false;
}


Passageiro::Passageiro(Cliente cliente, bool bagagem) {
    this -> cliente = cliente;
    this -> bagagem = bagagem;
}


Cliente Passageiro::getCliente() {
    return cliente;
}

bool Passageiro::getBagagem() {
    return bagagem;
}

void Passageiro::setBagagem(bool bagagem) {
    this -> bagagem = bagagem;
}

void Passageiro::setCliente(Cliente cliente) {
    this -> cliente = cliente;
}

ostream& operator<<(ostream& out, const Passageiro &passageiro){
        out <<"Cliente: \n" <<  passageiro.cliente;
        out << "Bagagem? ";
        if (passageiro.bagagem){ out << "Sim";}
        else {out << "Nao";}
        return out;
}
