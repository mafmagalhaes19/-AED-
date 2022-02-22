//
// Created by mafim on 08/12/2021.
//
/**
 * \file Menu.h
 * \brief Ficheiro header da classe Menu.
 */

#ifndef AED_G32_MENU_H
#define AED_G32_MENU_H

#include "../FibonacciAirlines/FibonacciAirlines.h"


/**
 * \class Menu
 *  \brief Classe que efetua o display dos menus e recebe inputs do utilizador.
 */
class Menu {
private:

    /**
     * Membro que contém todos os dados a serem exibidos nos menus.
     */
    FibonacciAirlines _fibonacci;
public:

    /**
     * \brief Construtor parametrizado. Recebe um objeto FibonacciAirlines.
     * @param fibonacci Contém toda a informação que será mostrada nos menus.
     */
    Menu(FibonacciAirlines &fibonacci);

    /**
     * \brief Função que verifica a validade dos inputs do utilizador.
     * @param input Input do utilizador.
     * @return Se o input for de tamanho 1 e for um digito, retorna esse dígito. Caso contrário retorna -1.
     */
    int validadeInput(string input);

    /**
     * \brief Função que exibe o menu principal.
     * @return
     */
    unsigned mainMenu();

    /**
     * \brief Função que exibe o menu de clientes.
     */
    void showClientesMenu();

    /**
     * \brief Função que exibe o menu de gestão de clientes
     */
    void showClientesManagementMenu();

    /**
     * \brief Função que exibe o menu dos aeroportos.
     */
    void showAeroportosMenu();

    /**
     * \brief Função que exibe o menu de gestão de aeroportos.
     */
    void showAeroportosManagementMenu();


    /**
     * \brief Função que exibe o menu de avioes.
     */
    void showAvioesMenu();
    /**
     * \brief Função que exibe o menu de Avioes disponíveis.
     */
    void showAvioesdisponiveisMenu();

    /**
     * \brief Função que mostra o menu de serviços.
     */
    void showServicosMLMenu();

    /**
     * \brief Função que exibe os serviços do tipo 'c'.
     * @param c Tipo de serviço.
     */
    void showTipoServico(int c);

    /**
     * \brief Função que exibe o menu de gestão de aviões.
     */
    void showAvioesManagement();

    /**
     * \brief Função que mostra o menu de voos.
     */
    void showVoosMenu();

    /**
     * \brief Menu de gestão de voos.
     */
    void showVoosManagement();

    /**
     * \brief Menu de compra de bilhetes.
     */
    void showComprarBilhetesMenu();


};


#endif //AED_G32_MENU_H
