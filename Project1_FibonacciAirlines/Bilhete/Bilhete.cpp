//
// Created by mafim on 05/12/2021.
//

#include "Bilhete.h"



Bilhete::Bilhete(bool bagagem, Voo &voo) {
    this->voo = &voo;
    this->bagagem = bagagem;
}

Voo Bilhete::getVoo() {
    return *this->voo;
}

bool Bilhete::hasBagagem() {
    return this->bagagem;
}

void Bilhete::setVoo(Voo &voo) {
    this->voo = &voo;
}

void Bilhete::setBagagem(bool bagagem) {
    this->bagagem = bagagem;
}
