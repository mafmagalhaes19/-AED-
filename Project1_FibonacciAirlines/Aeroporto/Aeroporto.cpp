//
// Created by Matilde Sequeira on 05/12/2021.
//

#include <fstream>
#include "Aeroporto.h"


Aeroporto::Aeroporto(string nome, BST<LocaisTransporte> locaisTransporte1)
        : _nome(nome), _locaisTransporte(locaisTransporte1) {
}

string Aeroporto::getNome() {
    return _nome;
}

BST<LocaisTransporte> Aeroporto::getLocaisTransporte() {
    return _locaisTransporte;
}

void Aeroporto::setNome(string nome) {
    _nome = nome;
}

void Aeroporto::setLocaisTransporte(BST<LocaisTransporte> &locaisTransporte) {
    _locaisTransporte = locaisTransporte;
}

ostream& operator<<(ostream& out, const Aeroporto & aeroporto)
{
    out << aeroporto._nome << endl;
    BSTItrIn<LocaisTransporte> it(aeroporto._locaisTransporte);
    while(!it.isAtEnd()){
        LocaisTransporte local = it.retrieve();
        out << local;
        it.advance();
    }

    return out;
}

void Aeroporto::showAirportInformation() {
    cout << *this;
}

void Aeroporto::addLocalTransporte(LocaisTransporte &local) {
    _locaisTransporte.insert(local);
}

void Aeroporto::removeLocalTransporte() {
    string aux;
    BSTItrIn<LocaisTransporte> itBST(_locaisTransporte);
    cout << "--------------------" << endl;

    while(!itBST.isAtEnd()){
        cout << "LOCAL DE TRANSPORTE" << endl;
        LocaisTransporte localAux = itBST.retrieve();
        cout << "Tipo de Transporte: " << localAux.getTipoTransporteAsString() << endl;
        cout << "Distancia: " << localAux.getDistancia() << endl;
        itBST.advance();
    }

    LocaisTransporte remove;
    bool found = false;
    cout << endl;
    cout << "Nome do Tipo de Transporte do Local a remover: " ;
    getline(cin, aux);

    if(aux == "Metro"){
        remove.setTipoTransporte(METRO);
        found = true;
    }
    else if(aux == "Comboio"){
        remove.setTipoTransporte(COMBOIO);
        found = true;
    }
    else if(aux == "Autocarro"){
        remove.setTipoTransporte(AUTOCARRO);
        found = true;
    }

    int distancia;
    cout << "Distancia do Local a remover: ";
    cin >> aux;
    cin.ignore();
    distancia = stoi(aux);
    remove.setDistancia(distancia);

    if(found){
        _locaisTransporte.remove(remove);
        cout << endl;
        cout << "Local de Transporte removido com sucesso!" << endl;
    }

    else if (!found){
        cout << endl;
        cout << "Local de Transporte nao encontrado." << endl;
        cout << endl;
    }


}

void Aeroporto::showClosestTransport(Aeroporto aeroporto) {
    BSTItrIn<LocaisTransporte> it(aeroporto._locaisTransporte);
    LocaisTransporte localAux = it.retrieve();
    LocaisTransporte closestTransport;
    int minDistancia = localAux.getDistancia();
    string aux;
    string diaSemana;
    int hora = 0;
    bool empty = true;

    while(!it.isAtEnd()){
        localAux = it.retrieve();
        if(minDistancia > localAux.getDistancia()){
            closestTransport.setTipoTransporte(localAux.getTipoTransporte());
            closestTransport.setDistancia(localAux.getDistancia());
            closestTransport.setHorarios(localAux.getHorarios());
            empty = false;
        }
        else if((minDistancia == localAux.getDistancia()) && empty){
            closestTransport.setTipoTransporte(localAux.getTipoTransporte());
            closestTransport.setDistancia(localAux.getDistancia());
            closestTransport.setHorarios(localAux.getHorarios());
            empty = false;
        }
        else if((minDistancia == localAux.getDistancia()) && (!empty) && (closestTransport.getTipoTransporteAsString()!="Metro")){
            if(localAux.getTipoTransporteAsString() == "Metro"){
                closestTransport.setTipoTransporte(localAux.getTipoTransporte());
                closestTransport.setDistancia(localAux.getDistancia());
                closestTransport.setHorarios(localAux.getHorarios());
            }
            else if(localAux.getTipoTransporteAsString() == "Comboio" && closestTransport.getTipoTransporteAsString()!="Comboio"){
                closestTransport.setTipoTransporte(localAux.getTipoTransporte());
                closestTransport.setDistancia(localAux.getDistancia());
                closestTransport.setHorarios(localAux.getHorarios());
            }
        }
        it.advance();
    }

    cout << "----------------" << endl;
    cout << "LOCAL DE TRANSPORTE MAIS PROXIMO" << endl;
    cout << closestTransport.getTipoTransporteAsString() << " (" << closestTransport.getDistancia() << " m de distancia)" << endl;
    cout << endl;
    cout << "Indique o dia da semana (ex: segunda): ";
    cin >> diaSemana;
    cin.ignore();
    cout << "Indique a hora atual (apenas um inteiro entre 0 e 23): " ;
    cin >> aux;
    cin.ignore();
    hora = stoi(aux);
    closestTransport.proximaViagem(diaSemana, hora);
    cout << endl;

}

void Aeroporto::saveData(Aeroporto& aeroporto, ofstream& fLocaisTransporte) {
    BSTItrIn<LocaisTransporte> it(_locaisTransporte);
    bool first = true;
    while(!it.isAtEnd()){
        if(!first){
            fLocaisTransporte << endl;
        }
        LocaisTransporte local = it.retrieve();
        fLocaisTransporte << aeroporto.getNome() << endl;
        fLocaisTransporte << (local);
        fLocaisTransporte << "----";
        first = false;
        it.advance();
    }


}






