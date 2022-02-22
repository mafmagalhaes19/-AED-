//
// Created by Matilde Sequeira on 07/12/2021.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "FibonacciAirlines.h"
#include "Macros.h"
#include "../Aviao/Aviao.h"
#include "../Voo/Voo.h"
#include "../Data/Data.h"
#include <map>
#include "../BST/bst.h"
#include <algorithm>


FibonacciAirlines::FibonacciAirlines(Data dataAtual){
    data_atual = dataAtual;
    readAeroportoFile();
    readClientesFile();
    readVoosFile();
    readAvioesFile();
    readLocaisTransporteFile();
    readServicosFile();
    updateAvailable();

}


list<Aviao> FibonacciAirlines::getAvioes(){
    return avioes;
}

list<Aeroporto> FibonacciAirlines::getAeroportos(){
    return aeroportos;
}

list<Voo> FibonacciAirlines::getVoos(){
    return voos;
}

list<Cliente> FibonacciAirlines::getClientes(){
    return clientes;
}

queue<Servico> FibonacciAirlines::getServicos(){
    return servicosPorRealizar;
}
Data FibonacciAirlines::getData(){
    return data_atual;
}

void FibonacciAirlines::setAvioes(list<Aviao> &avioes){
    this -> avioes = avioes;
}

void FibonacciAirlines::setAeroportos(list<Aeroporto> &aeroportos){
    this -> aeroportos = aeroportos;
}

void FibonacciAirlines::setVoos(list<Voo> &voos){
    this -> voos = voos;
}

void FibonacciAirlines::setClients(list<Cliente> &clientes){
    this -> clientes = clientes;
}

void FibonacciAirlines::setServicos(queue<Servico> &servicos){
    this -> servicosPorRealizar = servicos;
}

void FibonacciAirlines::setData(Data &data){
    data_atual = data;
}

void FibonacciAirlines::readAeroportoFile(){
    ifstream f(FICHEIRO_AEROPORTOS);

    if (f.fail())
    {
        cerr << "Nao existe nenhum ficheiro de aeroportos com o nome: " << FICHEIRO_AEROPORTOS << endl;
    }

    string aux;

    list<Aeroporto> aeroportosAdicionados;

    while (f.peek() != -1)
    {
        const LocaisTransporte &local = LocaisTransporte();
        BST<LocaisTransporte> locais(local);
        Aeroporto aeroporto("", locais);

        getline(f, aux);
        aeroporto.setNome(aux);

        aeroportosAdicionados.push_back(aeroporto);

        getline(f, aux);
    }

    f.close();

    setAeroportos(aeroportosAdicionados);

}

void FibonacciAirlines::readAvioesFile() {
    ifstream ifstream1(FICHEIRO_AVIOES);

    if(ifstream1.fail()){
        cerr << "Nao existe nenhum ficheiro de avioes com o nome: " << FICHEIRO_AVIOES << endl;
    }else{

        string aux;
        while (ifstream1.peek() != -1){

            Aviao aviao;

            getline(ifstream1,aux);
            aviao.set_matricula(aux);

            int capacidade = 0;
            getline(ifstream1,aux);
            capacidade = stoi(aux);
            aviao.set_capacidade(capacidade);

            vector<Voo> planoVoo;

            getline(ifstream1,aux);

            while(aux.length() > 0){
                size_t  pos = aux.find('/');
                string s = aux.substr(0,pos);
                if(pos == string::npos){ aux= "";}
                else{aux.erase(0,aux.find('/') + 1);}
                int numVoo = stoi(s);
                for(list<Voo>::iterator it = voos.begin(); it != voos.end(); it++){
                    if((*it).get_numVoo() == numVoo){
                        it->setTotal(capacidade);
                        planoVoo.push_back(*it);
                        break;
                    }
                }
            }
            aviao.set_planoVoo(planoVoo);
            avioes.push_back(aviao);

            getline(ifstream1,aux);

        }
        ifstream1.close();
    }

}

void FibonacciAirlines::readClientesFile() {
    ifstream f(FICHEIRO_CLIENTES);

    if (f.fail())
    {
        cerr << "Nao existe nenhum ficheiro de clientes com o nome: " << FICHEIRO_CLIENTES << endl;
    }

    string aux;
    list<Cliente> clients;


    while (f.peek() != -1)
    {
        Cliente cliente;
        getline(f, aux);
        cliente.setId(stoi(aux));

        getline(f, aux);
        cliente.setNome(aux);

        getline(f, aux);
        cliente.setDataNasc(aux);

        getline(f, aux);
        cliente.setNif(stoi(aux));

        getline(f, aux);
        cliente.setEmail(aux);

        getline(f, aux);
        cliente.setTelefone(stoi(aux));

        clients.push_back(cliente);

        getline(f, aux);
    }

    f.close();

    setClients(clients);

}

void FibonacciAirlines::readVoosFile() {

    ifstream file (FICHEIRO_VOO);

    if(file.fail()){
        cerr << "Nao existe nenhum ficheiro de voos com o nome: "<< FICHEIRO_VOO << endl;
    }else{

        string aux;
        while (file.peek() != -1){
            Voo voo;
            getline(file,aux);
            voo.set_numVoo(stoi(aux));

            getline(file,aux);
            Aviao aviao = getAviao(aux);
            voo.set_aviao(aux);
            if(aviao.get_matricula() != ""){
                voo.set_aviaoTotal(aviao.get_matricula(), aviao.get_capacidade());
            }

            getline(file,aux);
            voo.set_data(Data(aux));

            getline(file,aux);
            voo.set_duracao(stoi(aux));

            getline(file, aux);
            voo.set_origem(aux);

            getline(file,aux);
            voo.set_destino(aux);


            getline(file,aux);
            aux.erase(remove(aux.begin(), aux.end(), ' '), aux.end());

            list<Passageiro> passageiros;

            while(!aux.empty()){
                string cliente = aux.substr(0, aux.find_first_of('/'));
                aux.erase(0, aux.find_first_of('/') + 1);
                string bagagem = aux.substr(0, aux.find_first_of('/'));
                aux.erase(0, aux.find_first_of('/') + 1);

                Passageiro p1;

                Cliente c1;
                for(auto it = clientes.begin(); it != clientes.end(); it++){
                    if((*it).getId() == stoi(cliente)){
                        c1 = (*it);
                        break;
                    }
                }
                p1.setCliente(c1);

                if(bagagem == "sim"){p1.setBagagem(true);}
                else{ p1.setBagagem(false);}

                passageiros.push_back(p1);
            }

            voo.set_passageiros(passageiros);

            getline(file, aux);

            voos.push_back(voo);

        }

        file.close();

    }

}

void FibonacciAirlines::readLocaisTransporteFile(){
    ifstream f(FICHEIRO_LOCAISTRANSPORTE);

    if (f.fail())
    {
        cerr << "Nao existe nenhum ficheiro de locais de transporte com o nome: " << FICHEIRO_LOCAISTRANSPORTE << endl;
    }

    string aux = "";
    string name = "";
    string tipoTransporte ="";
    int distancia = 0;

    while (f.peek() != -1)
    {
        getline(f, name);
        LocaisTransporte local;
        list<Aeroporto>::iterator it;
        for(it = aeroportos.begin(); it != aeroportos.end(); it++){
            if(it->getNome() == name){
                getline(f, tipoTransporte);
                getline(f, aux);
                distancia = stoi(aux);
                list<Horario> horarios;
                for(int i = 0; i < 7; i++){
                    string dia;
                    getline(f, dia);
                    vector<int> viagens;
                    int viagem = 0;
                    getline(f, aux);

                    while(!aux.empty()){
                        viagem = stoi(aux.substr(0, aux.find_first_of('/')));
                        aux.erase(0, aux.find_first_of('/') + 1);
                        viagens.push_back(viagem);
                    }
                    Horario horario(dia, viagens);
                    horarios.push_back(horario);
                }
                if(tipoTransporte == "Metro"){
                    local.setTipoTransporte(METRO);
                    local.setDistancia(distancia);
                    local.setHorarios(horarios);
                    it->addLocalTransporte(local);
                }
                else if(tipoTransporte == "Comboio"){
                    local.setTipoTransporte(COMBOIO);
                    local.setDistancia(distancia);
                    local.setHorarios(horarios);
                    it->addLocalTransporte(local);
                }
                else{
                    local.setTipoTransporte(AUTOCARRO);
                    local.setDistancia(distancia);
                    local.setHorarios(horarios);
                    it->addLocalTransporte(local);
                }
            }
        }
        getline(f, aux);
    }

    f.close();

}

Aviao* FibonacciAirlines::encontraAviaoMatricula(string matricula_aviao){
    for(auto it = avioes.begin(); it != avioes.end(); it++){
        if((*it).get_matricula() == matricula_aviao){
            return &it.operator*();
        }
    }

    return nullptr;
}

void FibonacciAirlines::readServicosFile() {
    ifstream  f = ifstream(FICHEIRO_SERVICOS);
    TipoServico tipoServico;
    string data, funcionario, matricula_aviao, tipoServicoStr, dummy;
    Servico servicoTemp;
    Aviao aviao;
    list<Servico> servicosPorRealizarTemp;

    if(f.fail()){
        cerr << "Nao existe nenhum ficheiro chamado " << FICHEIRO_SERVICOS << endl;
    } else {
        while(!f.eof()){

            getline(f, matricula_aviao);
            getline(f, tipoServicoStr);
            getline(f, data);
            getline(f, funcionario);

            if(tipoServicoStr == "limpeza"){
                tipoServico = LIMPEZA;
            } else tipoServico = MANUTENCAO;

            aviao = *encontraAviaoMatricula(matricula_aviao);

            servicoTemp = Servico(tipoServico, Data(data), funcionario, aviao);

            if(servicoTemp.getData() < data_atual){
                this->servicosRealizados.push_back(servicoTemp);

            } else servicosPorRealizarTemp.push_back(servicoTemp);


            getline(f, dummy);
        }

        servicosPorRealizarTemp.sort();

        for(Servico const &ser : servicosPorRealizarTemp){
            this->servicosPorRealizar.push(ser);
        }

        f.close();
    }
}

void FibonacciAirlines::updateAvailable(){
    list<Voo>::iterator it;
    for(it = voos.begin(); it != voos.end(); it++){
        it->setDisponiveis(it->getDisponiveis()-it->get_passageiros().size());
    }
}

void FibonacciAirlines::showSpecificClient(){
    bool found = false;
    unsigned int aux;

    cout << endl;
    cout << "NIF do cliente: ";
    cin >> aux;
    cin.ignore();

    list<Cliente>::iterator it;
    for (it = clientes.begin(); it != clientes.end(); it++)
    {
        if (it->getNif() == aux)
        {
            cout << endl;
            it -> showClientsInformation();
            found = true;
            cout << endl;
            break;
        }
    }
    if(!found) {
        cout << "Lamentamos, mas nao existe nenhum cliente com esse nif." << endl;
    }
}

void FibonacciAirlines::showClients(){
    cout << endl;
    cout << endl;
    int aux;
    aux = clientes.size();
    list<Cliente>::iterator it;
    for (it =clientes.begin(); it != clientes.end(); it++)
    {
       it->showClientsInformation();
        if (aux > 1)
        {
            cout << "----" << endl;
            aux--;
        }
        else{
            cout << endl;
            cout << endl;
        }
    }
}

void FibonacciAirlines::createClient(){
    Cliente cliente;
    string aux;

    int newId = clientes.back().getId() +1;
    cliente.setId(newId);
    cout << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, aux);
    cliente.setNome(aux);

    cout << "Data de nascimento (formato: dia mes ano): ";
    cin >> aux;
    cin.ignore();
    getline(cin, aux);
    cliente.setDataNasc(aux);

    cout << "NIF: ";
    cin >> aux;
    cin.ignore();
    int nif = stoi(aux);

    // Valida o NIF do cliente
    bool bExistingClient = false;
    list<Cliente>::iterator it;
    for (it = clientes.begin(); it != clientes.end(); it++) {
        if (it->getNif() == nif)
        {
            bExistingClient = true;
        }
    }
    if (bExistingClient)
    {
        cout << endl;
        cout << "Ja existe um cliente com o NIF fornecido." << endl;
        cout << "Escolha a opcao de alterar dados de cliente." << endl;
        cout << endl;
    }
    else {
        cliente.setNif(nif);

        cout << "Email: ";
        cin.ignore();
        getline(cin, aux);
        cliente.setEmail(aux);

        cout << "Telefone: ";
        cin >> aux;
        cin.ignore();
        int telefone = stoi(aux);
        cliente.setTelefone(telefone);

        cout << endl;
        cout << "Novo cliente: " << endl;

        cliente.showClientsInformation();

        char sel;

        do
        {
            cout << "Adicionar? (Y or N) ";

            cin >> sel;

            if (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n')
                cout << "A sua escolha nao e valida \n";

        } while (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n');

        if (sel == 'Y' || sel == 'y')
        {
            clientes.push_back(cliente);

            cout << "Cliente adicionado" << endl;
        }
    }
}

void FibonacciAirlines::changeClient(){
    unsigned int aux, selection;
    string temp;

    cout << endl;
    cout << "NIF do cliente a alterar ('0' para voltar): ";
    cin >> aux;
    bool bFound = false;
    if (aux != 0)
    {
        list<Cliente>::iterator it;
        for (it = clientes.begin(); it != clientes.end(); it++)
        {
            if (it->getNif() == aux)
            {
                bFound = true;
                cout << endl;
                cout << "Informacao a alterar:" << endl;
                cout << "1. Nome" << endl;
                cout << "2. Data de nascimento" << endl;
                cout << "3. NIF" << endl;
                cout << "4. Email" << endl;
                cout << "5. Telefone" << endl;
                cout << "0. Voltar" << endl;
                cin >> selection;
                cin.ignore();

                switch (selection)
                {
                    case(1):
                        cout << "Novo nome: ";
                        getline(cin, temp);
                        it->setNome(temp);

                        cout << endl << "Nome alterado" << endl;

                        break;

                    case(2):
                        cout << endl;
                        cout << "Nova data de nascimento: ";
                        getline(cin, temp);
                        it->setDataNasc(temp);
                        break;

                    case(3):
                        cout << endl;
                        cout << "Novo NIF: ";
                        cin >> temp;
                        it->setNif(stoi(temp));
                        break;

                    case(4):
                        cout << endl;
                        cout << "Novo email: ";
                        cin.ignore();
                        getline(cin, temp);
                        it->setEmail(temp);
                        break;


                    case(5):
                        cout << endl;
                        cout << "Novo telefone: ";
                        cin >> temp;
                        it->setTelefone(stoi(temp));
                        break;

                    case(0):
                        break;

                    default:
                        cout << "A sua escolha nao e valida \n"
                             << "Escolha outra opcao por favor \n";
                }
            }
        }
        if (! bFound)
        {
            cout << "Lamentamos, mas nao existe nenhum cliente com NIF correspondente." << endl;
        }
    }
}

void FibonacciAirlines::removeClient(){
    unsigned int aux;

    cout << "NIF do cliente a remover ('0' para voltar): ";
    cin >> aux;
    if (aux != 0)
    {
        list<Cliente>::iterator it;
        for (it = clientes.begin(); it != clientes.end(); it++)
        {
            if (it->getNif() == aux)
            {
               clientes.erase(it);
               cout << endl;
               cout << "Cliente removido com sucesso!" << endl;
               cout << endl;
               break;
            }
        }
        int newId = 1;
        for (it = clientes.begin(); it != clientes.end(); it++){
            it->setId(newId);
            newId++;
        }
    }
}

void FibonacciAirlines::showSpecificAirport(){
    bool found = false;
    string aux;

    cout << endl;
    cout << "Nome do aeroporto: ";
    cin >> aux;
    cin.ignore();

    list<Aeroporto>::iterator it;
    for (it = aeroportos.begin(); it != aeroportos.end(); it++)
    {
        if (it->getNome() == aux)
        {
            cout << endl;
            cout << "----------------------------" << endl;
            cout << "AEROPORTO" << endl;
            it -> showAirportInformation();
            found = true;
            cout << "----------------------------" << endl;
            cout << endl;
            break;
        }
    }
    if(!found) {
        cout << "Lamentamos, mas nao existe nenhum aeroporto com esse nome." << endl;
    }
}

void FibonacciAirlines::showAirports(){
    cout << endl;
    cout << endl;
    int aux;
    aux = aeroportos.size();
    list<Aeroporto>::iterator it;
    for (it =aeroportos.begin(); it != aeroportos.end(); it++)
    {
        cout << it->getNome() << endl;
        if (aux > 1)
        {
            cout << "----" << endl;
            aux--;
        }
        else{
            cout << endl;
            cout << endl;
        }
    }
}

void FibonacciAirlines::addLocalTransporte(Aeroporto &aeroporto){
    int selection = 0;
    string aux;
    LocaisTransporte local;
    cout << "------------------------" << endl;
    cout << "LOCAL DE TRANSPORTE" << endl;
    cout <<"Selecione o tipo de Transporte" << endl;
    cout << "1. Metro" << endl;
    cout << "2. Comboio" << endl;
    cout << "3. Autocarro" << endl;
    cin >> selection;
    cin.ignore();
    switch (selection)
    {
        case(1):
            local.setTipoTransporte(METRO);
            break;

        case(2):
            local.setTipoTransporte(COMBOIO);
            break;

        case(3):
            local.setTipoTransporte(AUTOCARRO);
            break;
        default:
            cout << "A sua escolha nao e valida \n"
                 << "Escolha outra opcao por favor \n";
    }
    cout << "Distancia: ";
    cin >> aux;
    cin.ignore();
    local.setDistancia(stoi(aux));

    cout << "HORARIO" << endl;
    list<string> diasSemana;
    diasSemana.push_back("Segunda");
    diasSemana.push_back("Terca");
    diasSemana.push_back("Quarta");
    diasSemana.push_back("Quinta");
    diasSemana.push_back("Sexta");
    diasSemana.push_back("Sabado");
    diasSemana.push_back("Domingo");
    list<string>:: iterator it;

    for( it = diasSemana.begin(); it != diasSemana.end(); it++){
        cout << "---------------"  << endl;
        cout << (*it) << ": " << endl;
        bool addViagem = true;
        vector<int> viagens;
        while(addViagem){
            int viagem = 0;
            char sel;
            do{
                cout << "Deseja adicionar uma viagem? (Y or N)" << endl;
                cin >> sel;
                if (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n')
                    cout << "A sua escolha nao e valida \n";
            } while (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n');

            if (sel == 'Y' || sel == 'y'){
                addViagem = true;
            }
            else{
                addViagem = false;
                break;
            }
            cout << "Viagem: ";
            cin >> aux;
            cin.ignore();
            viagem = stoi(aux);
            viagens.push_back(viagem);
        }
        Horario horario((*it), viagens);
        local.addHorario(horario);
    }
    aeroporto.addLocalTransporte(local);
}


void FibonacciAirlines::createAirport(){
    const LocaisTransporte &local = LocaisTransporte();
    BST<LocaisTransporte> locais(local);
    Aeroporto aeroporto("", locais);
    bool addLocal = true;
    int selection;
    string aux;

    cout << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, aux);
    aeroporto.setNome(aux);

    while(addLocal){
        char sel;
        do{
        cout << "Deseja adicionar um local de transporte? (Y or N)" << endl;
        cin >> sel;
        if (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n')
            cout << "A sua escolha nao e valida \n";
        } while (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n');

        if (sel == 'Y' || sel == 'y'){
            addLocal = true;
        }
        else{
            addLocal = false;
            break;
        }

        addLocalTransporte(aeroporto);
    }
    cout << "----------------" << endl;
    cout << "AEROPORTO NOVO" << endl;
    aeroporto.showAirportInformation();
    cout << endl;

    char sel;

    do
    {
        cout << "Adicionar? (Y or N) ";

        cin >> sel;

        if (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n')
            cout << "A sua escolha nao e valida \n";

    } while (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n');

    if (sel == 'Y' || sel == 'y')
    {
        aeroportos.push_back(aeroporto);

        cout << "Aeroporto de " << aeroporto.getNome() << " adicionado!" << endl;
    }
}


void FibonacciAirlines::changeAirport(){

    string aux;
    int selection = 1;
    string temp;

    cout << endl;
    cout << "Nome do aeroporto a alterar: ";
    cin >> aux;
    bool bFound = false;

    list<Aeroporto>::iterator it;
    for (it = aeroportos.begin(); it != aeroportos.end(); it++)
    {
        if (it->getNome() == aux)
        {
            bFound = true;
            cout << endl;
            cout << "Informacao a alterar:" << endl;
            cout << "1. Nome" << endl;
            cout << "2. Adicionar Local de Transporte" << endl;
            cout << "3. Eliminar Local de Transporte" << endl;
            cout << "4. Voltar" << endl;
            cin >> selection;
            cin.ignore();


            switch (selection)
            {
                case(1):
                    cout << "Novo nome: ";
                    getline(cin, temp);
                    it->setNome(temp);

                    cout << endl << "Nome alterado!" << endl;
                    break;

                case(2):
                    addLocalTransporte(*it);
                    break;

                case (3):
                    it->removeLocalTransporte();
                    break;

                case(0):
                    break;

                default:
                    cout << "A sua escolha nao e valida \n"
                         << "Escolha outra opcao por favor \n";
            }
        }
    }
    if (!bFound)
    {
        cout << "Lamentamos, mas nao existe nenhum cliente com NIF correspondente." << endl;
    }
}


void FibonacciAirlines::removeAirport(){

    string aux;

    cout << "Nome do aeroporto a remover: ";
    cin.ignore();
    getline(cin, aux);

    list<Aeroporto>::iterator it;
    for (it = aeroportos.begin(); it != aeroportos.end(); it++)
    {
        if (it->getNome() == aux)
        {
            aeroportos.erase(it);
            cout << endl;
            cout << "Aeroporto removido com sucesso!" << endl;
            cout << endl;
            break;
        }
    }
}

void FibonacciAirlines::showClosestTransport(){
    string aux;

    cout << endl;
    cout << "Nome do aeroporto: ";
    cin.ignore();
    getline(cin, aux);
    list<Aeroporto>::iterator it;
    for(it = aeroportos.begin(); it != aeroportos.end(); it++){
        if(it->getNome() == aux){
            it->showClosestTransport((*it));
        }
    }

}


void FibonacciAirlines::showAllAvioes() {
    cout << endl;
    cout << "--------------------------------------" <<endl;
    for (list<Aviao>::iterator it = avioes.begin(); it != avioes.end(); it++){
        cout << (*it);
        cout << "--------------------------------------" <<endl;
    }
}

void FibonacciAirlines::showByMatricula() {
    cout << "Matricula: ";
    string matricula;
    cin >> matricula;
    for (auto & aviao : avioes){
        if (aviao.get_matricula() == matricula){
            cout << "--------------------------------------" <<endl;
            cout << aviao;
            cout << "--------------------------------------" <<endl;
            return;
        }
    }
    cout << "Nao existe nenhum aviao com esta matricula." << endl;
    return;
}

void FibonacciAirlines::showByCapacidade() {
    cout << "Capacidade: ";
    string capstr;
    int count = 0;
    cin.ignore();
    cin.clear();
    getline(cin, capstr);
    while(true){

        if (capstr.empty() || !all_of(capstr.begin(), capstr.end(), ::isdigit) || cin.fail() ){
            cout << "Input invalido, por favor tente outra vez: ";

            cin.clear();
            getline(cin, capstr);

        }else{
            break;
        }
    }
    for (list<Aviao>::iterator it = avioes.begin(); it != avioes.end(); it++){
        if ((*it).get_capacidade() == stoi(capstr)){
            cout << "--------------------------------------" <<endl;
            cout << (*it);
            cout << "--------------------------------------" <<endl;
            count += 1;
        }
    }
    if(count == 0){
        cout << "Nao existe nenhum aviao com a capacidade indicada." << endl;
    }

}

bool FibonacciAirlines::sortServicos(Servico &s1, Servico &s2) {
    if (s1.getTipoServico() == s2.getTipoServico()){
        return s1.getData() < s2.getData();
    }else{
        return s1.getTipoServico() < s2.getTipoServico();
    }
}

void FibonacciAirlines::showServicos(int opcao, TipoServico ML) {

    queue<Servico> aux = servicosPorRealizar;



    if (opcao == 1){
            cout << "Matricula: ";
            string matricula;
            cin >> matricula;

            cout << "LIMPEZA" << endl;
            cout << "REALIZADOS:" << endl;
            cout << "-----------------------------" << endl;
            for (int i = 0; i < aux.size(); i++){
                if (aux.front().getAviao().get_matricula() == matricula && aux.front().getData() < data_atual && aux.front().getTipoServico() == ML){
                    cout << aux.front() << endl;
                }
                aux.push(aux.front());
                aux.pop();
            }
            cout  << endl;
            cout << "POR REALIZAR:" << endl;
            cout << "-----------------------------" << endl;
            for (int i = 0; i < aux.size(); i++){
                if (aux.front().getAviao().get_matricula() == matricula && data_atual < aux.front().getData()   && aux.front().getTipoServico() == ML){
                    cout << aux.front() << endl;
                }
                aux.push(aux.front());
                aux.pop();
            }
            cout << endl;
        }
        else if(opcao == 2){
            cout << "LIMPEZA" << endl;
            cout << "REALIZADOS:" << endl;
            cout << "-----------------------------" << endl;
            for (int i = 0; i < aux.size(); i++){
                if (aux.front().getData() < data_atual){
                    cout << aux.front() << endl;
                }
                aux.push(aux.front());
                aux.pop();
            }
            cout  << endl;
            cout << "POR REALIZAR:" << endl;
            cout << "-----------------------------" << endl;
            for (int i = 0; i < aux.size(); i++){
                if (data_atual < aux.front().getData()){
                    cout << aux.front() << endl;
                }
                aux.push(aux.front());
                aux.pop();
            }
        }


}

void FibonacciAirlines::addServico() {
    Servico servico;
    cout << "ADICIONAR UM SERVIÇO" << endl;
    cout << "1. Manutencao \n"
         << "2. Limpeza \n" << endl;
    string tipo;

    cin.clear();
    cin >> tipo;
    while (tipo != "1" && tipo != "2"){
        cout << "Input invalido, por favor tente outra vez: ";
        cin.clear();
        cin >> tipo;
    }

    if (tipo == "1") { servico.setTipoServico(MANUTENCAO); }
    else if (tipo == "2") { servico.setTipoServico(LIMPEZA); }

    cout << "Matricula: ";
    string matricula;
    cin.clear();
    cin >> matricula;

    while(true){
        bool found = false;
        for (list<Aviao>::iterator it = avioes.begin(); it != avioes.end(); it++){
            if ((*it).get_matricula() == matricula){
                servico.setAviao((*it));
                found = true;
                break;
            }
        }
        if (found == false){
            cout << "Nao existe nenhum aviao com esta matricula, por favor tente outra vez: ";
            cin.clear();
            cin >> matricula;
        }else{
            break;
        }
    }

    Data data1;

    do {
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
        if (data1 < data_atual ){
            cout << "Data invalida, por favor tente outra vez: " << endl;
        }else{
            break;
        }
    } while (true);

    servico.setData(data1);

    cout << "Funcionario: ";
    string funcionario;
    cin.clear();
    cin.ignore();
    getline(cin, funcionario);

    servico.setFuncionario(funcionario);

    cout << "Servico adicionado!" << endl;

    servicosPorRealizar.push(servico);

}

void FibonacciAirlines::eliminarServico() {
    cout << "ELIMINAR SERVICO" << endl;

    Data data1;

    do {
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
        if (data1 < data_atual ){
            cout << "So e possível alterar um servico futuro, por favor insira uma nova data. " << endl;
        }else{
            break;
        }
    } while (true);



    queue<Servico> aux = servicosPorRealizar;
    int count = 0;
    for (int i = 0; i < aux.size() ; i++){
        if (aux.front().getData() == data1){
            count += 1;
            cout << count << ") Aviao: "<< aux.front().getAviao().get_matricula() << "  Tipo: " << aux.front().getTipoServico() << "  Funcionario: " << aux.front().getFuncionario() << endl;

        }
        aux.pop();
        i -= 1;
    }
    if (count == 0){
        cout << "Nao existem servicosPorRealizar nesta data" << endl;
    }else {

        cout << "ELIMINAR: " << endl;
        int serv;
        string servico;
        cin.clear();
        cin >> servico;
        while (true) {
            if (servico.empty() || !all_of(servico.begin(), servico.end(), ::isdigit) || cin.fail() ||
                stoi(servico) < 0 || stoi(servico) > count) {
                cout << "Input invalido, por favor tente outra vez: ";
                cin.clear();
                cin >> servico;
            } else {
                serv = stoi(servico);
                break;
            }
        }

        count = 0;
        aux = servicosPorRealizar;
        for (int i = 0; i < servicosPorRealizar.size(); i++) {
            if (aux.front().getData() == data1) {
                count += 1;
            }
            if (count == serv) {
                aux.pop();
            } else {
                aux.push(aux.front());
                aux.pop();
            }
        }
        servicosPorRealizar = aux;

        cout << "Servico eliminado!" << endl;
    }
}

void FibonacciAirlines::addAviao() {
    Aviao aviao;
    cout << "ADICIONAR AVIAO" << endl;
    cout << "Matricula: " ;
    string matricula;
    bool found = false;
    do{
        cin.clear();
        cin >> matricula;
        for (list<Aviao>::iterator it = avioes.begin(); it != avioes.end(); it++){
            if ((*it).get_matricula() == matricula){
                cout << "Esta matricula ja existe, por favor tente outra vez: " << endl;
                found = true;
            }else{
                found = false;
            }
        }
    } while (found == true);

    aviao.set_matricula(matricula);

    cout << "Capacidade: ";
    string capacidade;
    cin.clear();
    cin >> capacidade;
    while (true) {
        if (capacidade.empty() || !all_of(capacidade.begin(),capacidade.end(), ::isdigit) || cin.fail() || stoi(capacidade) <= 0 ) {
            cout << "Input invalido, por favor tente outra vez: ";
            cin.clear();
            cin >> capacidade;
        } else {
            aviao.set_capacidade(stoi(capacidade));
            break;
        }
    }

    newPlanoVoo(aviao);
    avioes.push_back(aviao);

    cout << "Aviao adicionado!" << endl;
}

void FibonacciAirlines::eraseAviao() {
    cout << "ELIMINAR AVIAO" << endl;
    cout << "Matricula: " ;
    string matricula;
    cin >> matricula;

    for (list<Aviao>::iterator it = avioes.begin(); it != avioes.end(); it++){
        if ((*it).get_matricula() == matricula){
            avioes.erase(it);
            cout << "Aviao " << matricula <<" eliminado com sucesso."  << endl;
            return;
        }
    }
    cout << "Nao existe nenhum aviao com a matricula indicada." << endl;

}

void FibonacciAirlines::alterarAviao() {
    cout << "ALTERAR AVIAO" << endl;
    cout << "Matricula: ";
    string matricula;
    cin >> matricula;

    for (list<Aviao>::iterator it = avioes.begin(); it != avioes.end(); it++){
        if ((*it).get_matricula() == matricula){
            cout << "1. Alterar Capacidade\n"
                 << "2. Alterar Plano Voo\n" << endl;

            string opcao;
            cin.clear();
            cin >> opcao;
            while (opcao != "1" && opcao != "2"){
                cout << "Input invalido, por favor tente outra vez: ";
                cin.clear();
                cin >> opcao;
            }

            if(stoi(opcao) == 1) {
                cout << "Nova Capacidade: ";
                string capacidade;
                cin.clear();
                cin >> capacidade;
                while (true) {
                    if (capacidade.empty() || !all_of(capacidade.begin(), capacidade.end(), ::isdigit) ||
                        cin.fail() || stoi(capacidade) < 0) {
                        cout << "Input invalido, por favor tente outra vez: ";
                        cin.clear();
                        cin >> capacidade;
                    } else {
                        (*it).set_capacidade(stoi(capacidade));
                        break;
                    }
                }
            }else if (stoi(opcao) == 2)
                {
                    newPlanoVoo((*it));
                }

            return;
        }
    }
    cout << "Nao existe nenhum aviao com a matricula indicada." << endl;
}

Aviao FibonacciAirlines::getAviao(string matricula){
    Aviao aviao;
    list<Aviao>::iterator it;
    for( it = avioes.begin(); it != avioes.end(); it++){
        if(it->get_matricula() == matricula){
            aviao = (*it);
        }
    }
    return aviao;
}

void FibonacciAirlines::newPlanoVoo(Aviao &aviao) {

    cout << "Numero de voos: ";
    int n;
    string numVoos;
    cin.clear();
    cin >> numVoos;
    while (true) {
        if (numVoos.empty() || !all_of(numVoos.begin(),numVoos.end(), ::isdigit) || cin.fail() || stoi(numVoos) < 0 ) {
            cout << "Input invalido, por favor tente outra vez: ";
            cin.clear();
            cin >> numVoos;
        } else {
            n = stoi(numVoos);
            break;
        }
    }

    vector<Voo> planoVoo;

    string num;
    int numVoo;
    for (int i = 0; i < n; i++){
        cout << "Voo "<< i+1 <<": ";
        cin >> num;
        while (true) {
            if (num.empty() || !all_of(num.begin(), num.end(), ::isdigit) || cin.fail() || stoi(num) < 0) {
                cout << "Input invalido, por favor tente outra vez: ";
                cin.clear();
                cin >> num;
            } else {
                numVoo = stoi(num);
                for (auto it = voos.begin(); it != voos.end();it++){
                    if((*it).get_numVoo() == numVoo){
                        planoVoo.push_back((*it));
                    }
                }
                if (planoVoo.size() < i+1){
                    cout << "Este voo nao existe, por favor tente outra vez: ";
                    cin.clear();
                    cin >> num;
                }else{
                    break;
                }

            }
        }


    }

    aviao.set_planoVoo(planoVoo);

}

void FibonacciAirlines::showProximosVoos() {

    cout << "PROXIMOS VOOS" << endl;
    cout << "--------------------------------" << endl;
    for (auto it = voos.begin(); it != voos.end(); it++){
        if(data_atual < (*it).get_data()) {
            cout << (*it) << endl;
            cout << "--------------------------------" << endl;
        }
    }

}

void FibonacciAirlines::showTodosVoos() {
    cout << "TODOS OS VOOS" << endl;
    cout << "--------------------------------" << endl;
    for (auto it = voos.begin(); it != voos.end(); it++){
        cout << (*it) << endl;
        cout << "--------------------------------" << endl;
    }
}

void FibonacciAirlines::showPassageiros() {
    cout << "VER PASSAGEIROS" << endl;
    cout << "Numero de Voo: ";
    int n;
    string numVoo;
    cin.clear();
    cin >> numVoo;
    while (true) {
        if (numVoo.empty() || !all_of(numVoo.begin(),numVoo.end(), ::isdigit) || cin.fail() || stoi(numVoo) < 0 ) {
            cout << "Input invalido, por favor tente outra vez: ";
            cin.clear();
            cin >> numVoo;
        } else {
            n = stoi(numVoo);
            break;
        }
    }
    list<Voo>::iterator itVoos;

    for(itVoos = voos.begin(); itVoos != voos.end(); itVoos++){
        if((*itVoos).get_numVoo() == n){
            list<Passageiro> passageiros = (*itVoos).get_passageiros();
            list<Passageiro>::iterator itPassageiros;
            for(itPassageiros = passageiros.begin(); itPassageiros != passageiros.end(); itPassageiros++ ){
                cout << (*itPassageiros) << endl;
                cout << "--------------------------------" << endl;
            }
            return;
        }
    }

    cout << "Voo numero " << n << " nao existe." << endl;

}

void FibonacciAirlines::addVoo() {
    Voo voo;
    cout << "ADICIONAR VOO" << endl;

    cout << "Numero de Voo: ";
    string numVoo;
    cin.clear();
    cin >> numVoo;
    while (true) {
        if (numVoo.empty() || !all_of(numVoo.begin(),numVoo.end(), ::isdigit) || cin.fail() || stoi(numVoo) < 0 ) {
            cout << "Input invalido, por favor tente outra vez: ";
            cin.clear();
            cin >> numVoo;
        } else {
            voo.set_numVoo(stoi(numVoo));
            break;
        }
    }

    Data data1;

    do {
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
        if (data1 < data_atual ){
            cout << "So e possivel adicionar um voo futuro, por favor insira uma nova data. " << endl;
        }else{
            break;
        }
    } while (true);

    cout << "Duracao: ";

    string duracao;
    cin.clear();
    cin >> duracao;
    while (true) {
        if (duracao.empty() || !all_of(duracao.begin(),duracao.end(), ::isdigit) || cin.fail() || stoi(duracao) < 0 ) {
            cout << "Input invalido, por favor tente outra vez: ";
            cin.clear();
            cin >> duracao;
        } else {
            voo.set_duracao(stoi(duracao));
            break;
        }
    }

    cout << "Origem: ";
    string origem;
    cin >> origem;
    while (bool found = false) {

        for (auto it = aeroportos.begin(); it != aeroportos.end();it++){
            if((*it).getNome() == origem){
                voo.set_origem(origem);
                found = true;
            }
        }
        if (found = false){
            cout << "Este aeroporto nao existe, por favor tente outra vez: ";
                cin.clear();
                cin >> origem;
            }else{
                break;
            }

        }

    cout << "Destino: ";
    string destino;
    cin >> destino;
    while (bool found = false) {

        for (auto it = aeroportos.begin(); it != aeroportos.end();it++){
            if((*it).getNome() == destino){
                voo.set_origem(destino);
                found = true;
            }
        }
        if (found = false){
            cout << "Este aeroporto nao existe, por favor tente outra vez: ";
            cin.clear();
            cin >> origem;
        }else{
            break;
        }

    }

    voos.push_back(voo);
    cout << "Voo adicionado!" << endl;
}

void FibonacciAirlines::eraseVoo() {

    cout << "ELIMINAR VOO" << endl;
    cout << "Numero de Voo: " ;
    int voo;
    string numVoo;
    cin.clear();
    cin >> numVoo;
    while (true) {
        if (numVoo.empty() || !all_of(numVoo.begin(),numVoo.end(), ::isdigit) || cin.fail() || stoi(numVoo) < 0 ) {
            cout << "Input invalido, por favor tente outra vez: ";
            cin.clear();
            cin >> numVoo;
        } else {
            voo = stoi(numVoo);
            break;
        }
    }

    for (list<Voo>::iterator it = voos.begin(); it != voos.end(); it++){
        if ((*it).get_numVoo() == voo){
            voos.erase(it);
            cout << "Voo numero " << voo <<" eliminado com sucesso."  << endl;
            return;
        }
    }
    cout << "Nao existe nenhum aviao com a matricula indicada." << endl;


}

void FibonacciAirlines::alterarVoo() {
    cout << "ALTERAR VOO" << endl;
    cout << "Numero de Voo: " ;
    int voo;
    string numVoo;
    cin.clear();
    cin >> numVoo;
    while (true) {
        if (numVoo.empty() || !all_of(numVoo.begin(),numVoo.end(), ::isdigit) || cin.fail() || stoi(numVoo) < 0 ) {
            cout << "Input invalido, por favor tente outra vez: ";
            cin.clear();
            cin >> numVoo;
        } else {
            voo = stoi(numVoo);
            break;
        }
    }

    for(list<Voo>::iterator it = voos.begin(); it != voos.end(); it++){
        if((*it).get_numVoo() == voo){
            cout << "1. Alterar Data\n"
                 << "2. Alterar Duracao\n"
                 << "3. Alterar Origem\n"
                 << "4. Alterar Destino"<< endl;

            string opcao;
            cin.clear();
            cin >> opcao;
            while (opcao != "1" && opcao != "2" && opcao != "3" && opcao != "4"){
                cout << "Input invalido, por favor tente outra vez: ";
                cin.clear();
                cin >> opcao;
            }

            if (stoi(opcao) == 1){
                Data data1;

                do {
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
                    if (data1 < data_atual ){
                        cout << "So e possivel alterar um voo futuro, por favor insira uma nova data. " << endl;
                    }else{
                        break;
                    }
                } while (true);
                (*it).set_data(data1);

            }else if(stoi(opcao) == 2){
                cout << "Duracao: ";

                string duracao;
                cin.clear();
                cin >> duracao;
                while (true) {
                    if (duracao.empty() || !all_of(duracao.begin(),duracao.end(), ::isdigit) || cin.fail() || stoi(duracao) < 0 ) {
                        cout << "Input invalido, por favor tente outra vez: ";
                        cin.clear();
                        cin >> duracao;
                    } else {
                        (*it).set_duracao(stoi(duracao));
                        break;
                    }
                }


            }else if (stoi(opcao) == 3){
                cout << "Origem: ";
                string origem;
                cin >> origem;
                while (bool found = false) {

                    for (auto it2 = aeroportos.begin(); it2 != aeroportos.end();it++){
                        if((*it2).getNome() == origem){
                            (*it).set_origem(origem);
                            found = true;
                        }
                    }
                    if (found = false){
                        cout << "Este aeroporto nao existe, por favor tente outra vez: ";
                        cin.clear();
                        cin >> origem;
                    }else{
                        break;
                    }

                }

            }else if(stoi(opcao) == 4){
                cout << "Destino: ";
                string destino;
                cin >> destino;
                while (bool found = false) {

                    for (auto it2 = aeroportos.begin(); it2 != aeroportos.end();it2++){
                        if((*it2).getNome() == destino){
                            (*it).set_destino(destino);
                            found = true;
                        }
                    }
                    if (found = false){
                        cout << "Este aeroporto nao existe, por favor tente outra vez: ";
                        cin.clear();
                        cin >> destino;
                    }else{
                        break;
                    }

                }

            }
            cout << "Voo alterado com sucesso." << endl;
            return;
        }
    }
    cout << "Nao existe nenhum voo com este numero." << endl;

}

void FibonacciAirlines::buyTicket(int tickets){
    string aux;
    int numVoo=0;
    bool vooFound = false;

    int idBuyer = 0;
    bool clientFound = false;

    cout << endl;
    cout << "Numero do voo: ";
    cin >> aux;
    cin.clear();
    numVoo = stoi(aux);

    list<Voo>::iterator itVoos;
    for(itVoos = voos.begin(); itVoos != voos.end(); itVoos++){
        if(itVoos->get_numVoo() == numVoo){
            vooFound = true;
            break;
        }
    }
    if(vooFound){
        if(itVoos->getDisponiveis() > tickets){
            for(int i = 0; i < tickets; i++){
                cout << endl;
                cout << "ID do cliente: ";
                cin >> aux;
                cin.clear();
                idBuyer = stoi(aux);

                list<Cliente>::iterator itClientes;
                for ( itClientes = clientes.begin(); itClientes != clientes.end(); itClientes++){
                    if(itClientes->getId() == idBuyer){
                        clientFound = true;
                        break;
                    }
                }
                if(clientFound){
                    cout << "Bagagem (sim ou nao): ";
                    cin >> aux;
                    cin.clear();
                    bool bagagem = false;
                    if(aux == "sim"){
                        bagagem = true;
                    }
                    else{
                        bagagem = false;
                    }
                    Passageiro newPassageiro((*itClientes), bagagem);
                    itVoos->addPassageiro(newPassageiro);
                }
                else{
                    cout << endl;
                    cout << "Nao existe nenhum cliente com esse ID, por favor escolha outro. " << endl;
                    cout << endl;
                    i--;
                }
            }

        }
        else{
            cout << endl;
            cout << "Nao temos esse numero de bilhetes disponiveis." << endl;
            cout << endl;
            cout << "--------------------------------------" << endl;
            cout << "VOO" << endl;
            cout << (*itVoos);
            cout << endl;
            cout << endl;
        }

    }

    else{
        cout << endl;
        cout << "Nao existe nenhum voo com este numero." << endl;
        cout << endl;
    }
}

void FibonacciAirlines::buyOneTicket() {
    buyTicket(1);
}

void FibonacciAirlines::buyGroupTicket() {
    string aux;
    int tickets = 0;
    cout << endl;
    cout << "Numero de bilhetes: ";
    cin >> aux;
    cin.clear();
    tickets = stoi(aux);
    buyTicket(tickets);
}

void FibonacciAirlines::saveData() {
    ofstream fClient (FICHEIRO_CLIENTES, ofstream::out);
    list<Cliente>::iterator itClientes;
    int countClientes = clientes.size();
    for (itClientes = clientes.begin(); itClientes != clientes.end(); itClientes++)
    {
        fClient << (*itClientes);

        if(countClientes > 1){
            fClient << "----" << endl;
        }
        else{
            fClient << "----";
        }
        countClientes--;

    }
    fClient.close();
    cout << endl;
    cout << "Clientes gravados com sucesso!" << endl;

    ofstream fAirport (FICHEIRO_AEROPORTOS, ofstream::out);
    ofstream fLocaisTransporte (FICHEIRO_LOCAISTRANSPORTE, ofstream::out);
    list<Aeroporto>::iterator itAeroportos;
    int countAeroportos = aeroportos.size();
    for (itAeroportos = aeroportos.begin(); itAeroportos != aeroportos.end(); itAeroportos++)
    {
        fAirport << itAeroportos->getNome() << endl;
        if(countAeroportos > 1 ){
            fAirport << "----" << endl;
        }
        else{
            fAirport << "----";
        }
        countAeroportos--;
        itAeroportos->saveData((*itAeroportos), fLocaisTransporte);
    }
    fAirport.close();
    fLocaisTransporte.close();
    cout << endl;
    cout << "Aeroportos e Locais de Transporte gravados com sucesso!" << endl;

    ofstream fAvioes (FICHEIRO_AVIOES, ofstream::out);
    list<Aviao>::iterator itAvioes;
    int countAvioes = avioes.size();
    for (itAvioes = avioes.begin(); itAvioes != avioes.end(); itAvioes++)
    {
        fAvioes << itAvioes->get_matricula() << endl;
        fAvioes << itAvioes->get_capacidade() << endl;
        vector<Voo> planoVoo = itAvioes->get_planoVoo();
        for(int i = 0; i < planoVoo.size(); i++){
            if(planoVoo.size() == 1){
                fAvioes << planoVoo[i].get_numVoo() << endl;
            }
            else if (planoVoo.size() > 1){
                if(i == planoVoo.size()-1){
                    fAvioes << planoVoo[i].get_numVoo() << endl;
                }
                else{
                    fAvioes << planoVoo[i].get_numVoo() << " / ";
                }
            }
        }
        if(countAvioes > 1){
            fAvioes << "----" << endl;
        }
        else{
            fAvioes << "----";
        }
        countAvioes--;
    }
    fAvioes.close();
    cout << endl;
    cout << "Avioes gravados com sucesso!" << endl;

    ofstream fVoo (FICHEIRO_VOO, ofstream::out);
    list<Voo>::iterator itVoos;
    int countVoos = voos.size();
    for (itVoos = voos.begin(); itVoos != voos.end(); itVoos++)
    {
        fVoo << itVoos->get_numVoo() << endl;
        fVoo << itVoos->get_aviao() << endl;
        fVoo << itVoos->get_data() << endl;
        fVoo << itVoos->get_duracao() << endl;
        fVoo << itVoos->get_origem() << endl;
        fVoo << itVoos->get_destino() << endl;

        list<Passageiro> passageiros = itVoos->get_passageiros();
        list<Passageiro>::iterator itPassageiros;
        for(itPassageiros = passageiros.begin(); itPassageiros != passageiros.end(); itPassageiros++ ){
            string bagagem = "";
            if(itPassageiros->getBagagem() == true){
                bagagem = "sim";
            }
            else{
                bagagem = "nao";
            }
            fVoo << itPassageiros->getCliente().getId() << "/" << bagagem << "/";
        }
        fVoo << endl;
        if(countVoos > 1){
            fVoo << "----" << endl;
        }
        else{
            fVoo << "----";
        }
        countVoos--;

    }
    fVoo.close();
    cout << endl;
    cout << "Voos gravados com sucesso!" << endl;

    ofstream fServicos (FICHEIRO_SERVICOS, ofstream::out);
    int countServicosList = servicosRealizados.size();
    int countServicosQueue = servicosPorRealizar.size();
    list<Servico>::iterator itServicos;
    for (itServicos = servicosRealizados.begin(); itServicos != servicosRealizados.end(); itServicos++)
    {
        fServicos << itServicos->getAviaoMatricula() << endl;
        fServicos << itServicos->getTipoServicoAsString() << endl;
        fServicos << itServicos->getData() << endl;
        fServicos << itServicos->getFuncionario() << endl;

        if(countServicosQueue > 0){
            fServicos << "----" << endl;
        }
        else{
            if(countServicosList > 1){
                fServicos << "----" << endl;
            }
            else{
                fServicos << "----";
            }

        }
        countServicosList--;
    }

    queue<Servico> aux = servicosPorRealizar;
    int size = aux.size();
    for (int i = 0; i < size ; i++){
        fServicos << aux.front().getAviaoMatricula() << endl;
        fServicos << aux.front().getTipoServicoAsString() << endl;
        fServicos << aux.front().getData() << endl;
        fServicos << aux.front().getFuncionario() << endl;
        if(countServicosQueue > 1){
            fServicos << "----" << endl;
        }
        else{
            fServicos << "----";
        }
        aux.pop();
        countServicosQueue--;
    }

    fServicos.close();
    cout << endl;
    cout << "Servicos gravados com sucesso!" << endl;

}

