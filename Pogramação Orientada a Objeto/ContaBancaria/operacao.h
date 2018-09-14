#ifndef OPERACAO_H
#define OPERACAO_H
#include <stdlib.h>
#include <sstream>
using namespace std;

class operacao
{
    public:
        int indice;
        float saldo;
        float valor;
        string op;

        operacao(int indice, float saldo, float valor, string op);
        string toString();
};

    operacao::operacao(int indice = 0, float saldo = 0, float valor = 0, string op = ""){

        this->indice = indice;
        this->saldo = saldo;
        this->valor = valor;
        this->op = op;

    }

    string operacao::toString(){

        stringstream ss;
        ss << indice << ": " << op <<": " << valor << ": " << saldo;
        return ss.str();

    }

#endif // OPERACAO_H
