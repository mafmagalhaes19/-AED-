//
// Created by Vasco Enes on 29/01/2022.
//

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include <string>
#include "../STCPMap.h"

using namespace std;

/**
* \class Menu
* \brief Classe que efetua o display dos menus e recebe input do utilizador
*/
class Menu {

private:

    /**
    * Membro que contém os dados a serem exibidos pelos menus
    */
    STCPMap _stcpMap;
    bool newSource;
    bool newDestination;

public:

    /**
    * \brief Construtor parametrizado
    * @param stcpMap Contém os dados a serem exibidos pelos menus
    */
    Menu(STCPMap stcpMap);


    /**
    * \brief Função que verifica se o input do utilizador é válido (tamanho 1 e ser um número)
    * @param input Input do utilizador
    * @return Retorna o próprio input se este for válido, -1 caso contrário
    */
    int validadeInput(string input);

    /**
    * \brief Função que gere o menu principal. Tem os prints e recebe o input do utilizador para selecionar as opções, que chamam outros menus
    * @return Retorna sempre 0, quando o utilizador escolhe sair do menu
    */
    unsigned mainMenu();

    /**
    * \brief Função de menu secundário que permite ao utlizador escolher se o destino é uma paragem ou coordenadas, e o mesmo para a origem
    * @param isDestino se for true o utilizador está a selecionar o destino, se for false seleciona a origem
    */
    void inputTipoDeOrigemDestino(bool isDestino);


    /**
    * \brief Função de menu secundário que permite ao utilizador escolher o código da paragem do seu destino ou origem
    * @param isDestino se for true o utilizador está a escolher o código do destino, caso contrário escolhe o código da paragem de origem
    */
    void inputParagemDeOrigemDestino(bool isDestino);

    /**
    * \brief Função de menu secundário que permite ao utilizador escolher as coordenadas da sua origem ou do seu destini
    * @param isDestino se for true o utilizador está a escolher as coordenadas do destino, caso contrário escolhe as coordenadas da paragem de origem
    */
    void inputCoordenadasDeOrigemDestino(bool isDestino);


};


#endif //UNTITLED_MENU_H
