#include <iostream>
#include "../Menu/Menu.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Macros.h"
#include "../Data/Data.h"


using namespace std;

int main() {

    Data data1;

    cout << endl;
    cout << endl;
    cout << "Por favor indique a data atual." << endl;
    cout << "Dia: ";
    string dia;
    cin.clear();
    cin >> dia;
    while (true) {
        if (dia.empty() || !all_of(dia.begin(), dia.end(), ::isdigit) || cin.fail() || stoi(dia) < 0 || stoi(dia) > 31) {
            cout << "Input invalido, por favor tente outra vez: ";
            cin.clear();
            cin >> dia;
        } else {
            data1.setDia(stoi(dia));
            break;
        }
    }
    cout << "Mes: ";
    string mes;
    cin.clear();
    cin >> mes;
    while (true) {
        if (mes.empty() || !all_of(mes.begin(), mes.end(), ::isdigit) || cin.fail() || stoi(mes) < 0 || stoi(mes) > 12) {
            cout << "Input invalido, por favor tente outra vez: ";
            cin.clear();
            cin >> mes;
        } else {
            data1.setMes(stoi(mes));
            break;
        }
    }
    cout << "Ano: ";
    string ano;
    cin.clear();
    cin >> ano;
    while (true) {
        if (ano.empty() || !all_of(ano.begin(), ano.end(), ::isdigit) || cin.fail() || stoi(ano) < 0) {
            cout << "Input invalido, por favor tente outra vez: ";
            cin.clear();
            cin >> ano;
        } else {
            data1.setAno(stoi(ano));
            break;
        }
    }
    cout << endl;
    cout << endl;

    FibonacciAirlines fibonacci (data1);
    Menu menu(fibonacci);
    menu.mainMenu();
    return 0;
}
