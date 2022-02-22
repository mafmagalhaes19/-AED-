//
// Created by Vasco Enes on 29/01/2022.
//

#include "Menu.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

Menu::Menu(STCPMap stcpMap): _stcpMap(stcpMap), newDestination(false), newSource(false){}

int Menu::validadeInput(string input) {
    if(input.length() == 1 && isdigit(input[0])){
        stringstream ss(input);
        int number;
        ss >> number;
        return number;
    }else{return -1;}
}

unsigned Menu::mainMenu() {
    string choice;
    int input;
    double distanciaMax;

    //Choose source
    inputTipoDeOrigemDestino(false);
    //Choose destination
    inputTipoDeOrigemDestino(true);

    cout << "Introduza a distancia maxima que pretende andar entre paragens (em km) : " << endl;

    cin >> distanciaMax;
    _stcpMap.setDistanciaPedonal(distanciaMax);
    //Add new edges according to the distance that the user chose
    _stcpMap.addWalkingEdges();
    if(newSource){
        _stcpMap.addEdgesToNewSourceStop();
    }
    if(newDestination){
        _stcpMap.addEdgesToNewDestinationStop();
    }


    cin.clear();

    cout << "MENU PRINCIPAL\n"
         << "1. Percurso com menos paragens\n"
         << "2. Percurso mais barato (menos zonas)\n"
         << "3. Percurso mais curto\n"
         << "4. Percurso com menos mudancas de linha\n"
         << "5. Sair\n";

    do
    {
        input = -1;
        cin >> choice;
        if (!cin.fail() && cin.peek() == '\n'){
            input = validadeInput(choice);
        }

        switch (input)
        {
            case 1:
                _stcpMap.bfsLessStops();
                break;
            case 2:
                _stcpMap.bfsLessZones();
                break;
            case 3:
                _stcpMap.dijkstra();
                break;
            case 4:
                _stcpMap.bfsLessLines();
                break;
            case 5:
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 5){
            cout << endl;
            cout << "MENU PRINCIPAL\n"
                 << "1. Percurso com menos paragens\n"
                 << "2. Percurso mais barato (menos zonas)\n"
                 << "3. Percurso mais curto\n"
                 << "4. Percurso com menos mudancas de linha\n"
                 << "5. Sair\n";

        }


    } while (input != 5);
    return 0;
}

void Menu::inputTipoDeOrigemDestino(bool isDestino) {
    string choice;
    int input;
    cout << "TIPO DE " <<  (isDestino ? "DESTINO" : "ORIGEM") <<  "\n"
         << "1. Paragem \n"
         << "2. Coordenadas\n";
    do
    {
        input = -1;
        cin >> choice;
        if (!cin.fail() && cin.peek() == '\n'){
            input = validadeInput(choice);
        }

        switch (input)
        {
            case 1:
                inputParagemDeOrigemDestino(isDestino);
                break;
            case 2:
                inputCoordenadasDeOrigemDestino(isDestino);
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input == -1){
            cout << endl;
            cout << "TIPO DE " << (isDestino ? "DESTINO" : "ORIGEM") << "\n"
                 << "1. Paragem \n"
                 << "2. Coordenadas\n";

        }


    } while (input != 1 && input != 2);

}

void Menu::inputParagemDeOrigemDestino(bool isDestino) {

    bool isValidStop;
    string codigoParagem;

    do{
        cout <<  "Introduza o codigo da paragem de ";
        cout << (isDestino ? "destino: " : "origem: ") << endl;

        cin >> codigoParagem;

        if(_stcpMap.getGraph().getNodeIndexByCode(codigoParagem) != -1){
            if(isDestino){
                _stcpMap.setDestinoParagemExistente(codigoParagem);
                _stcpMap.setDestinoUtilizador(_stcpMap.getParagemByCode(codigoParagem));
                isValidStop = true;
            } else {
                _stcpMap.setCodigoParagemExistente(codigoParagem);
                _stcpMap.setOrigemUtilizador(_stcpMap.getParagemByCode(codigoParagem));
                isValidStop = true;
            }
        }

    } while(!isValidStop);
}

void Menu::inputCoordenadasDeOrigemDestino(bool isDestino) {

    double lat, longi;
    Paragem paragem;

    cout <<  "Introduza o as coordenadas de ";
    cout << (isDestino ? "destino: " : "origem: ") << "(latitude / longitude)" << endl;

    cin >> lat;
    cin >> longi;

    paragem = Paragem((isDestino ? "DESTINO" : "ORIGEM"), "Utilizador", "streetLocation", lat, longi);


    if(isDestino){
        newDestination = true;
        _stcpMap.addParagem(paragem);
        _stcpMap.setDestinoUtilizador(paragem);
        _stcpMap.setDestinoParagemExistente(paragem.getCode());

    } else {
        newSource = true;
        _stcpMap.addParagem(paragem);
        _stcpMap.setOrigemUtilizador(paragem);
        _stcpMap.setCodigoParagemExistente(paragem.getCode());
    }

}




