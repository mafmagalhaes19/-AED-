//
// Created by Vasco Enes on 03/12/2021.
//

#include "TransporteBagagem.h"
#include <list>
#include <exception>

TransporteBagagem::TransporteBagagem(Aviao &aviao, int numCarr, int numPilhas, int capacidadePilhas) {

    this->aviao = &aviao;
    this->numCarruagens = numCarr;
    this->numPilhas = numPilhas;
    this->capacidadePilhas = capacidadePilhas;

    constroiCarrinhoTransporte();

}

void TransporteBagagem::constroiCarrinhoTransporte() {
    this->carrinhoDeTransporte = list<list<stack<Bagagem>>>();
    list<stack<Bagagem>> carruagem = list<stack<Bagagem>>();
    stack<Bagagem> pilhaBagagem = stack<Bagagem>();

    for(int i = 0; i < this->numCarruagens; i++){
        for(int j = 0; j < numPilhas; j++){
            carruagem.push_back(pilhaBagagem);
        }

        carrinhoDeTransporte.push_back(carruagem);
    }
}

bool TransporteBagagem::adicionaBagagem(Bagagem bagagem) {

    for(list<stack<Bagagem>> const &carruagem : carrinhoDeTransporte){
        for(stack<Bagagem> pilha : carruagem){
            if(pilha.size() < capacidadePilhas){
                pilha.push(bagagem);
                return true;
            } else continue;
        }
    }
    return false;
}

list<list<stack<Bagagem>>> TransporteBagagem::getCarrinhoTransporte() {
    return this->carrinhoDeTransporte;
}

int TransporteBagagem::getNumCarruagens() {
    return this->numCarruagens;
}

int TransporteBagagem::getNumPilhas() {
    return this->numPilhas;
}

int TransporteBagagem::getCapacidadePilhas() {
    return this->capacidadePilhas;
}

list<stack<Bagagem>> TransporteBagagem::getCarruagemAt(int numCarruagem) {
    list<stack<Bagagem>> temp;
    int index = 0;

    if(numCarruagem >= carrinhoDeTransporte.size() || numCarruagem < 0){
        throw invalid_argument("Index out of bounds");
    }

    for(auto & it : carrinhoDeTransporte){
        if(index == numCarruagem){
            return it;
        }
        index++;
    }

    return {};
}

stack<Bagagem> TransporteBagagem::getPilhaAt(int numCarruagem, int numPilha) {

    list<stack<Bagagem>> carruagem;
    int index = 0;

    try {
        carruagem = getCarruagemAt(numCarruagem);

        if(numPilha >= carruagem.size() || numPilha < 0){
            throw invalid_argument("Index out of bounds.");
        }

        for(stack<Bagagem> &pilha : carruagem){
            if(index == numPilha){
                return pilha;
            }
        }

        return {};
    } catch (exception &e){
        throw e;
    }
}
