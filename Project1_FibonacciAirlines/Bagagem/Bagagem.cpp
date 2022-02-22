//
// Created by Vasco Enes on 03/12/2021.
//

#include "Bagagem.h"


Bagagem::Bagagem(Cliente &cliente) {
    donoDaMala = &cliente;
}

Cliente* Bagagem::getDonoDaMala() {
    return this->donoDaMala;
}

void Bagagem::setDonoDaMala(Cliente &cliente) {
    this->donoDaMala = &cliente;
}

