//
// Created by mafim on 08/12/2021.
//

#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

Menu::Menu(FibonacciAirlines &fibonacci): _fibonacci(fibonacci) {
}

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

    cout << "MENU PRINCIPAL\n"
         << "1. Menu de Clientes\n"
         << "2. Menu de Aeroportos\n"
         << "3. Menu de Avioes\n"
         << "4. Menu de Voos\n"
         << "5. Comprar bilhetes \n"
         << "6. Gravar \n"
         << "7. Sair\n";

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
                showClientesMenu();
                break;
            case 2:
                showAeroportosMenu();
                break;
            case 3:
                 showAvioesMenu();
                 break;
            case 4:
                showVoosMenu();
                break;
            case 5:
                showComprarBilhetesMenu();
                break;
            case 6:
                _fibonacci.saveData();
                break;
            case 7:
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
            }
        if(input != -1 && input != 7){
            cout << endl;
            cout << "MENU PRINCIPAL\n"
                 << "1. Menu de Clientes\n"
                 << "2. Menu de Aeroportos\n"
                 << "3. Menu de Avioes\n"
                 << "4. Menu de Voos\n"
                 << "5. Comprar bilhetes \n"
                 << "6. Gravar \n"
                 << "7. Sair\n";

        }


    } while (input != 7);
    return 0;
}

void Menu::showClientesMenu() {
    string choice;
    int input;
    cout << "MENU DE CLIENTES \n"
         << "1. Visualizar informacao de um cliente \n"
         << "2. Visualizar informacao de todos os clientes da companhia Fibonacci \n"
         << "3. Gerir clientes \n"
         << "4. Voltar ao menu principal \n";
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
                _fibonacci.showSpecificClient();
                break;
            case 2:
                _fibonacci.showClients();
                break;
            case 3:
                showClientesManagementMenu();
                break;
            case 4:
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 4){
            cout << endl;
            cout << "MENU DE CLIENTES \n"
                 << "1. Visualizar informacao de um cliente \n"
                 << "2. Visualizar informacao de todos os clientes da companhia Fibonacci \n"
                 << "3. Gerir clientes \n"
                 << "4. Voltar ao menu principal \n";

        }


    } while (input != 4);

}


void Menu::showClientesManagementMenu(){
    string choice;
    int input;
    cout << "GESTAO DE CLIENTES \n"
         << "1. Criar um cliente \n"
         << "2. Alterar um cliente \n"
         << "3. Remover um cliente \n"
         << "4. Voltar ao menu de clientes \n";
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
                _fibonacci.createClient();
                break;
            case 2:
                _fibonacci.changeClient();
                break;
            case 3:
                _fibonacci.removeClient();
                break;
            case 4:
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 4){
            cout << endl;
            cout << "GESTAO DE CLIENTES \n"
                 << "1. Criar um cliente \n"
                 << "2. Alterar um cliente \n"
                 << "3. Remover um cliente \n"
                 << "4. Voltar ao menu de clientes \n";

        }


    } while (input != 4);

}

void Menu::showAeroportosMenu() {
    string choice;
    int input;
    cout << "AEROPORTOS\n"
         << "1. Aeroportos disponiveis\n"
         << "2. Informacao sobre um aeroporto\n"
         << "3. Gerir Aeroportos\n"
         << "4. Local de Transporte mais proximo\n"
         << "5. Voltar\n";
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
                _fibonacci.showAirports();
                break;
            case 2:
                _fibonacci.showSpecificAirport();
                break;
            case 3:
                showAeroportosManagementMenu();
                break;
            case 4:
                _fibonacci.showClosestTransport();
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
            cout << "AEROPORTOS\n"
                    << "1. Aeroportos disponiveis\n"
                    << "2. Informacao sobre um aeroporto\n"
                    << "3. Gerir Aeroportos\n"
                    << "4. Local de Transporte mais proximo\n"
                    << "5. Voltar\n";
        }
    } while (input != 5);

}

void Menu::showAeroportosManagementMenu(){
    string choice;
    int input;
    cout << "GESTAO DE AEROPORTOS \n"
         << "1. Criar um aeroporto \n"
         << "2. Alterar um aeroporto \n"
         << "3. Remover um aeroporto \n"
         << "4. Voltar ao menu de aeroportos \n";
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
                _fibonacci.createAirport();
                break;
            case 2:
                _fibonacci.changeAirport();
                break;
            case 3:
                _fibonacci.removeAirport();
                break;
            case 4:
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 4){
            cout << endl;
            cout << "GESTAO DE AEROPORTOS \n"
                 << "1. Criar um aeroporto \n"
                 << "2. Alterar um aeroporto \n"
                 << "3. Remover um aeroporto \n"
                 << "4. Voltar ao menu de aeroportos \n";

        }


    } while (input != 4);

}

void Menu::showAvioesMenu() {
    string choice;
    int input;
    cout << "AVIOES\n"
         << "1. Avioes disponiveis\n"
         << "2. Servicos de Manutencao e Limpeza\n"
         << "3. Gerir Avioes\n"
         << "4. Voltar\n";
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
                showAvioesdisponiveisMenu();
                break;
            case 2:
                showServicosMLMenu();

                break;
            case 3:
                showAvioesManagement();
                break;
            case 4:
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 4){
            cout << endl;
            cout << "AVIOES\n"
                 << "1. Avioes disponiveis\n"
                 << "2. Servicos de Manutencao e Limpeza\n"
                 << "3. Gerir Avioes\n"
                 << "4. Voltar\n";
        }
    } while (input != 4);
}

void Menu::showAvioesdisponiveisMenu() {

    string choice;
    int input;
    cout << "AVIOES DISPONIVEIS\n"
         << "1. Ver todos Avioes\n"
         << "2. Procurar por Matricula\n"
         << "3. Procurar por Capacidade\n"
         << "4. Voltar\n";
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
                _fibonacci.showAllAvioes();
                break;
            case 2:
                _fibonacci.showByMatricula();
                break;
            case 3:
                _fibonacci.showByCapacidade();
                break;
            case 4:
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 4){
            cout << endl;
            cout << "AVIOES DISPONIVEIS\n"
                 << "1. Ver todos Avioes\n"
                 << "2. Procurar por Matricula\n"
                 << "3. Procurar por Capacidade\n"
                 << "4. Voltar\n";
        }
    } while (input != 4);

}

void Menu::showServicosMLMenu() {

    string choice;
    int input;
    cout << "SERVICOS\n"
         << "1. Limpeza\n"
         << "2. Manutencao\n"
         << "3. Manutencao e Limpeza\n"
         << "4. Adicionar Servico\n"
         << "5. Eliminar Servico\n"
         << "6. Voltar\n";
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
                showTipoServico(1);
                break;
            case 2:
                showTipoServico(2);
                break;
            case 3:
                showTipoServico(3);
                break;
            case 4:
                _fibonacci.addServico();
                break;
            case 5:
                _fibonacci.eliminarServico();
                break;
            case 6:
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 6){
            cout << endl;
            cout << "SERVICOS\n"
                 << "1. Limpeza\n"
                 << "2. Manutencao\n"
                 << "3. Manutencao e Limpeza\n"
                 << "4. Adicionar Servico\n"
                 << "5. Eliminar Servico\n"
                 << "6. Voltar\n";
        }
    } while (input != 6);


}
void Menu::showTipoServico(int c) {
    string tipo;
    TipoServico t;
    if(c == 1){
        tipo = "LIMPEZA";
        t = LIMPEZA;
    } else if(c == 2){
        tipo = "MANUTENCAO";
        t = MANUTENCAO;
    }else if(c==3){
        tipo = "MANUTENCAO E LIMPEZA";
    }else{
        return;
    }
    string choice;
    int input;
    cout << tipo << '\n'
         << "1. Por aviao\n"
         << "2. Todos avioes\n"
         << "3. Voltar\n";
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
                _fibonacci.showServicos(1,t);
                break;
            case 2:
                _fibonacci.showServicos(2,t);
                break;
            case 3:
                break;

            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 3){
            cout << endl;
            cout <<  tipo << '\n'
                 << "1. Por aviao\n"
                 << "2. Todos avioes\n"
                 << "3. Voltar\n";
        }
    } while (input != 3);

}

void Menu::showAvioesManagement() {

    string choice;
    int input;
    cout << "GESTAO DE AVIOES\n"
         << "1. Adicionar\n"
         << "2. Eliminar\n"
         << "3. Alterar\n"
         << "4. Voltar\n";
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
                _fibonacci.addAviao();
                break;
            case 2:
                _fibonacci.eraseAviao();
                break;
            case 3:
                _fibonacci.alterarAviao();
                break;
            case 4:
                break;

            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 4){
            cout << endl;
            cout << "GESTAO DE AVIOES\n"
                 << "1. Adicionar\n"
                 << "2. Eliminar\n"
                 << "3. Alterar\n"
                 << "4. Voltar\n";
        }
    } while (input != 4);

}

void Menu::showVoosMenu() {
    string choice;
    int input;
    cout << "VOOS\n"
         << "1. Proximos voos\n"
         << "2. Todos os voos\n"
         << "3. Consultar passageiros\n"
         << "4. Embarque e bagagens\n"
         << "5. Gerir Voos\n"
         << "6. Voltar\n";
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
            {
                _fibonacci.showProximosVoos();
                break;
            }
            case 2:
                _fibonacci.showTodosVoos();
                break;

            case 3:
                _fibonacci.showPassageiros();
                break;
            case 4:
                //TODO
                break;
            case 5:
                showVoosManagement();
                break;
            case 6:
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 6){
            cout << endl;
            cout << "VOOS\n"
                 << "1. Proximos voos\n"
                 << "2. Todos os voos\n"
                 << "3. Consultar passageiros\n"
                 << "4. Embarque e bagagens\n"
                 << "5. Gerir Voos\n"
                 << "6. Voltar\n";
        }
    } while (input != 6);


}

void Menu::showVoosManagement() {

    string choice;
    int input;
    cout << "GESTAO DE VOOS\n"
         << "1. Adicionar\n"
         << "2. Eliminar\n"
         << "3. Alterar\n"
         << "4. Voltar\n";
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
                _fibonacci.addVoo();
                break;
            case 2:
                _fibonacci.eraseVoo();
                break;
            case 3:
                _fibonacci.alterarVoo();
                break;
            case 4:
                break;

            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if(input != -1 && input != 4){
            cout << endl;
            cout << "GESTAO DE VOOS\n"
                 << "1. Adicionar\n"
                 << "2. Eliminar\n"
                 << "3. Alterar\n"
                 << "4. Voltar\n";
        }
    } while (input != 4);
}

void Menu::showComprarBilhetesMenu() {
    string choice;
    int input;
    cout << "COMPRAR BILHETES \n"
         << "1. Bilhete Individual \n"
         << "2. Bilhete de Grupo \n"
         << "3. Voltar\n";
    do {
        input = -1;
        cin >> choice;
        if (!cin.fail() && cin.peek() == '\n') {
            input = validadeInput(choice);
        }

        switch (input) {
            case 1:
                _fibonacci.buyOneTicket();
                break;
            case 2:
                _fibonacci.buyGroupTicket();
                break;
            case 3:
                break;
            default:
                input = -1;
                cout << "Input invalido, por favor tente outra vez:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                break;
        }
        if (input != -1 && input != 3) {
            cout << endl;
            cout << "COMPRAR BILHETES \n"
                 << "1. Bilhete Individual \n"
                 << "2. Bilhete de Grupo \n"
                 << "3. Voltar \n";
        }

    } while (input != 3);

}






