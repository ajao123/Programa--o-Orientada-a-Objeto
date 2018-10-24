#ifndef ESTAGIARIO_H_INCLUDED
#define ESTAGIARIO_H_INCLUDED
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

using namespace std;

class estagiario : public funcionario{
    public:
        int nivel;
        estagiario(string nome, string nivel):
            funcionario(nome, 1)
        {
            this->nome = nome;
            this->nivel = stoi(nivel);
        }

        string toString(){
            stringstream ss;
            ss << "Sta " << nome <<" nivel " << nivel << endl;
            ss << "Salario " << calcSalario();
            return ss.str();
        }

        double calcSalario(){
            return 3000 + (this->nivel*300) + _calcSalario();
        }

};


#endif // ESTAGIARIO_H_INCLUDED
