
#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#include <stdlib.h>
#include <sstream>
using namespace std;

class passageiro
{
public:
    string nome;
    int idade;
    bool prioridade;
  //  bool prioridade_cadeira;

    passageiro(string nome, int idade);
    string toString();
};
    passageiro::passageiro(string nome, int idade){
        this->nome = nome;
        this->idade = idade;

    }

    string passageiro::toString(){

        stringstream ss;
        ss << this->nome << ":" << this->idade;
        return ss.str();
    }


#endif // CLIENTE_H
