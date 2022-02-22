//
// Created by Matilde Sequeira on 07/12/2021.
//
/**\file Data.h
 * \brief Ficheiro de header da classe Data
 */

#ifndef AED_G32_DATA_H
#define AED_G32_DATA_H

#include <string>
#include <sstream>

using namespace std;

/**
 * \class Data
 * \brief Esta classe serve para guardar datas num formato mais flexível do que uma string.
 * */
class Data {
private:
    int ano; /**< Ano. */
    int mes; /**< Mês. */
    int dia; /**< Dia. */

public:
    /** Construtor default da classe. Cria um objeto que guarda a data 1/1/2000 */
    Data();

    /** Constrói uma Data através de uma string. A string tem de ter o formato "DD MM AA".
     * \param data String com a data a guardar. */
    Data(string data);

    /**
     * Constrói uma Data recebendo três inteiros, dia, mês e ano.
     * \param ano valor do ano a guardar
     * \param mes valor do mes a guardar
     * \param dia valor do dia a guardar
     * */
    Data(int dia, int mes, int ano );

    /**
     * Altera o valor do ano guardado.
     * @param ano valor que será guardado.
     */
    void setAno(int ano);

    /**
     * Altera o valor do mês.
     * @param mes valor que será guardado.
     */
    void setMes(int mes);

    /**
     * Altera o valor do dia.
     * @param dia valor a ser guardado.
     */
    void setDia(int dia);

    /**
     * retorna o ano da Data
     * @return valor do ano
     */
    int getAno();

    /**
     * retorna o mês da Data
     * @return valor do mês
     */
    int getMes();

    /**
     * retorna o dia da Data
     * @return valor do dia
     */
    int getDia();

    /**
     * \brief Overload do operador '<'.
     * Efetua a comparação entre duas datas, comparando os seus anos, meses e dias.
     * @param d1 data que estará à direita do operador (this < d1)
     * @return retorna 'true' se o ano da data a comparar for menor que o ano de d1.
     * No caso de igualdade dos anos, retorna 'true' se o mês for menor que o mês de d1.
     * No caso de igualdade dos meses e anos retorna 'true' se o dia for menor que o dia de d1
     *
     */
    bool operator < (const Data & d1) const ;

    /**
     * \brief Overload do operador '=='
     * Verifica se duas datas são iguais.
     * @param d1 objeto que estará à direita do operador '=='
     * @return 'true' se ambas as datas tiverem o mesmo ano, mês e dia.
     */
    bool operator == (const Data & d1) const ;

    /**
     * Define como é feito o output de um objeto da classe Data.
     * @param out output stream
     * @param data Data a ser passada ao output stream
     * @return retorna o 'out' com o conteúdo de 'data' no buffer.
     */
    friend ostream& operator<<(ostream& out, const Data & data);

};


#endif //AED_G32_DATA_H
