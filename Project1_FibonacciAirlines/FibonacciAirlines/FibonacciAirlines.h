//
// Created by Matilde Sequeira on 07/12/2021.
//
/**
 * \file FibonacciAirlines.h
 */

#ifndef AED_G32_FIBONACCIAIRLINES_H
#define AED_G32_FIBONACCIAIRLINES_H

#include "../Aviao/Aviao.h"
#include "../Aeroporto/Aeroporto.h"
#include "../Cliente/Cliente.h"
#include "../Servico/Servico.h"
#include "../LocaisTransporte/LocaisTransporte.h"
#include "../Data/Data.h"
#include <list>
#include <queue>


/**
 * \class FibonacciAirlines
 * \brief Classe que trata de toda a leitura e escrita de dados em ficheiros e guarda a informação toda do programa.
 */
class FibonacciAirlines {
private:

    /**
     * Lista de todos os aviões existentes.
     */
    list<Aviao> avioes;

    /**
     * Lista de todos os aeroportos.
     */
    list <Aeroporto> aeroportos;

    /**
     * Lista de todos os voos
     */
    list<Voo> voos;

    /**
     * Lista de todos os clientes existentes
     */
    list<Cliente> clientes;

    /**
     * Fila de todos os serviços por realizar
     */
    queue<Servico> servicosPorRealizar;

    /**
     * Lista de todos os serviços ja realizados
     */
    list<Servico> servicosRealizados;

    Data data_atual;

public:
    /**
     * Construtor default da classe FibonacciAirlines.
     * Este construtor quando é chamado efetua a leitura de todos os ficheiros com informação do programa.
     */
    FibonacciAirlines(Data dataAtual);


    /**
     *
     * @return A lista de aviões.
     */
    list<Aviao> getAvioes();

    /**
     *
     * @return A lista de aeroportos.
     */
    list<Aeroporto> getAeroportos();

    /**
     *
     * @return A lista de todos os voos.
     */
    list<Voo> getVoos();

    /**
     *
     * @return Lista de todos os clientes.
     */
    list<Cliente> getClientes();

    /**
     *
     * @return A fila de serviços por realizar.
     */
    queue<Servico> getServicos();

    /**
     *
     * @return A data atual do programa.
     */
    Data getData();


    /**
     * \brief Altera o atributo 'avioes' para a lista que é passada pelo parâmetro avioes.
     * @param avioes Nova lista de aviões.
     */
    void setAvioes(list<Aviao> & avioes);

    /**
     * \brief Altera o atributo 'aeroportos' para a lista que é passada no parâmetro 'aeroportos'.
     * @param aeroportos Nova lista de aeroportos.
     */
    void setAeroportos(list<Aeroporto> & aeroportos);

    /**
     * \brief Altera o atributo 'voos' para a lista que é passada pelo parâmetro 'voos'.
     * @param voos Nova lista de Voos.
     */
    void setVoos(list<Voo> & voos);

    /**
     * \brief Altera o atributo 'clientes' para a lista de clientes que é passada pelo parâmetro 'clientes'.
     * @param clientes Nova lista de clientes.
     */
    void setClients(list<Cliente> & clientes);

    /**
     * \brief Altera o atributo 'serviçosPorRealizar' para a fila que é passada pelo parâmetro 'servicos'.
     * @param servicos Nova fila de serviços por realizar.
     */
    void setServicos(queue<Servico> & servicos);

    /**
     * \brief Altera o atributo 'data_atual' para a data passada pelo parâmetro 'data'.
     * @param data Nova data.
     */
    void setData(Data & data);


    /**
     * \brief Realiza a leitura da informação sobre os aeroportos.
     * Realiza a leitura do ficheiro em que está guardada a informação dos aeroportos e vai criando instâncias de Aeroporto
     * que vão sendo guardadas no atributo 'aeroportos'.
     */
    void readAeroportoFile();

    /**
     * \brief Realiza a leitura da informação sobre os aviões.
     * Realiza a leitura do ficheiro em que está guardada a informação dos avióes e vai criando instâncias de Aviao que
     * vão sendo guardadas no atributo 'avioes'.
     */
    void readAvioesFile();

    /**
     * \brief Realiza a leitura da informação sobre os clientes.
     * Realiza a leitura do ficheiro em que está guardada a informação dos aviões e vai criando instâncias de Cliente
     * que vão sendo guardadas no atributo 'clientes'.
     */
    void readClientesFile();

    /**
     * \brief Realiza a leitura da informação sobre os voos.
     * Realia a leitura do ficheiro em que está guardada a informação dos voos e vai criando instâncias de Voo
     * que são guardadas no atributo 'voos'.
     */
    void readVoosFile();

    /**
     * \brief Realiza a leitura da informação sobre os locais de transporte.
     * Realiza a leitura dos ficheiros onde está guardada a informação dos locais de transporte e vai criando instâncias
     * de LocaisTransporte que vão sendo adicionados
     */
    void readLocaisTransporteFile();

    /**
     * \brief Realiza a leitura da informação dos serviços.
     * Realiza a leitura da informação dos serviços e vai criando instâncias de Servico que vão sendo guardadas ou no
     * atributo 'servicosPorRealizar' ou 'servicosRealizados' dependendo se a sua data é ou não maior do que 'data_atual'.
     */
    void readServicosFile();


    void updateAvailable();

    /**
     * \brief Mostra a informação de um cliente específico.
     * Mostra a informação de um cliente com um NIF indicado através de input em runtime.
     */
    void showSpecificClient();

    /**
     *\brief Mostra a informação de todos os clientes.
     */
    void showClients();

    /**
     *\brief Cria um cliente com os atributos que são passados pelo input do utilizador.
     */
    void createClient();

    /**
     * \brief Altera um cliente específico com os dados novos introduzidos pelo utilizador.
     */
    void changeClient();

    /**
     * \brief Remove um cliente específico.
     */
    void removeClient();

    /**
     * \brief Mostra um aeroporto específico selecionado pelo nome.
     */
    void showSpecificAirport();

    /**
     * Mostra todos os aeroportos.
     */
    void showAirports();

    /**
     * Cria um aeroporto com as informações introduzidas pelo utilizador.
     */
    void createAirport();

    /**
     * Modifica um aeroporto com as novas informações introduzidas pelo utilizador.
     */
    void changeAirport();

    /**
     * Remove um aeroporto com o nome indicado pelo utilizador.
     */
    void removeAirport();

    /**
     * \brief Adiciona um local de transporte ao aeroporto selecionado.
     * @param aeroporto Aeroporto selecionado.
     */
    void addLocalTransporte(Aeroporto &aeroporto);

    /**
     * Mostra o transporte mais proximo do aeroporto indicado pelo utilizador.
     */
    void showClosestTransport();

    /**
     * \brief Mostra a lista de todos os aviões
     */
    void showAllAvioes();

    /**
     * \brief Mostra as informações do avião ou aviões com a matrícula indicada pelo utilizador.
     */
    void showByMatricula();

    /**
     * \brief Mostra as informações do avião ou aviões com a capacidade indicada pelo utilizador.
     */
    void showByCapacidade();
   // void showByPlanoVoo();

    static bool sortServicos(Servico & s1, Servico & s2);

    /**
     * \brief Mostra todos os serviços realizados e por realizar.
     * @param opcao se opcao == 1 mostra os serviços para um avião de matrícula indicada pelo utilizador,
     * se for 2 mostra todos os serviços.
     * @param ML
     */
    void showServicos(int opcao, TipoServico ML);

    /**
     * \brief Adiciona um serviço criado pelo utilizador.
     */
    void addServico();

    /**
     * Elimina o serviço indicado pelo utilizador.
     */
    void eliminarServico();

    /**
     * \brief Adiciona um avião criado pelo utilizador.
     */
    void addAviao();

    /**
     * Elimina o avião selecionado pelo utilizador.
     */
    void eraseAviao();

    /**
     * Altera o avião selecionado pelo utilizador com informações introduzidas pelo utilizador.
     */
    void alterarAviao();
    Aviao getAviao(string matricula);

    /**
     * Cria um novo plano de voo para o avião passado pelo parâmetro 'aviao'.
     * @param aviao Avião que vai receber o novo plano de voo.
     */
    void newPlanoVoo(Aviao &aviao);

    /**
     * Mostra todos os voos futuros.
     */
    void showProximosVoos();

    /**
     * Mostra todos os voos, incluíndo os voos passados.
     */
    void showTodosVoos();

    /**
     * Mostra todos os passageiros para um Voo específico indicado pelo utilizador.
     */
    void showPassageiros();

    /**
     * Adiciona um voo novo criado pelo utilizador.
     */
    void addVoo();

    /**
     * Elimina um voo com o número indicado pelo utilizador.
     */
    void eraseVoo();

    /**
     * Altera o voo com número indicado pelo utilizador com as informaões novas.
     */
    void alterarVoo();

    /**
     * Encontra um avião com matrícula igual a 'matricula_aviao'
     * @param matricula_aviao Matrícula a ser procurada
     * @return Apontador para o avião encontrado. Retorna 'nullptr' se nenhum avião tiver essa matrícula.
     */
    Aviao *encontraAviaoMatricula(string matricula_aviao);

    void buyTicket(int tickets);

    /**
     * Compra um bilhete para um cliente.
     */
    void buyOneTicket();

    /**
     * Compra um bilhete para um conjunto de clientes.
     */
    void buyGroupTicket();

    void saveData();
};


#endif //AED_G32_FIBONACCIAIRLINES_H
