#include <iostream>
#include "STCPMap.h"
#include "Graph/Graph.h"
#include "Menu/Menu.h"

int main() {

    STCPMap stcpMap;
    Paragem paragem, paragem1;
    stcpMap.readParagens();
    stcpMap.readListaLinhas();

    Menu menu = Menu(stcpMap);

    menu.mainMenu();


    return 0;
}
