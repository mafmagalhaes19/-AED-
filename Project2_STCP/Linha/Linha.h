//
// Created by Vasco Enes on 28/01/2022.
//

#include <string>
#include <vector>

#ifndef UNTITLED_LINHA_H
#define UNTITLED_LINHA_H

using namespace std;

/**
* \class Linha
* \brief Class que permite criar objetos linha de autocarro
*/
class Linha {

public:

    /**
    * \brief get do membro código
    * @return Retorna o código da linha
    */
    const string &getCode() const;

    /**
    * \brief set do membro código
    * @param code Código que vai ser atribuido à linha
    */
    void setCode(const string &code);

    /**
    * \brief get do membro name
    * @return Retorna o nome da linha
    */
    const string &getName() const;

    /**
    * \brief set do membro name
    * @param name Nome que vai ser atribuido à linha
    */
    void setName(const string &name);

    /**
    * \brief get do membro vetor das paragens
    * @return Retorna as paragens da linha
    */
    const vector<string> &getParagens() const;

    /**
    * \brief set do membro paragens
    * @param paragens Paragens que vão ser atribuidas à linha
    */
    void setParagens(const vector<string> &paragens);

    /**
    * \brief Função que adiciona uma paragem ao vetor de paragens da linha
    * @param paragem Paragem que vai ser adicionada à linha
    */
    void addParagem(const string& paragem){
        paragens.push_back(paragem);
    }


private:

    /**
    * Código único de cada linha
    */
    string code;

    /**
    * Nome da linha
    */
    string name;

    /**
    * Vector que guarda todas as paragens que fazem parte da linha
    */
    vector<string > paragens;

};


#endif //UNTITLED_LINHA_H
