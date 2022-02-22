//
// Created by Vasco Enes on 28/01/2022.
//

#include "Linha.h"

const string &Linha::getCode() const {
    return code;
}

void Linha::setCode(const string &code) {
    Linha::code = code;
}

const string &Linha::getName() const {
    return name;
}

void Linha::setName(const string &name) {
    Linha::name = name;
}

const vector<string> &Linha::getParagens() const {
    return paragens;
}

void Linha::setParagens(const vector<string> &paragens) {
    Linha::paragens = paragens;
}
