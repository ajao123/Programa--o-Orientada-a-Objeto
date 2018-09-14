
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
    bool existe;
    bool prioridade;
    bool prioridade_cadeira;

    passageiro(string nome, int idade, bool prioridade, bool existe);
    string toString();
};
    passageiro::passageiro(string nome, int idade, bool prioridade =  false, bool existe = false){
        this->nome = nome;
        this->idade = idade;
        this->existe = existe;
        this->prioridade = prioridade;
    }

    string passageiro::toString(){

        stringstream ss;

            if(this->existe){
                ss << this->nome << ":" << this->idade;
            }else{
                if( this->prioridade){
                    ss << "@";
                }else{
                    ss << "=";
                }
            }

        return ss.str();
    }


#endif // CLIENTE_H
