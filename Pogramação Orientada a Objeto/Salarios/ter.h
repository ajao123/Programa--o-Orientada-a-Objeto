#ifndef TER_H_INCLUDED
#define TER_H_INCLUDED
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

using namespace std;

class ter : public funcionario{

    public:
        string saudavel;
        int horas;

        ter(string nome, string horas, string saudavel):
            funcionario(nome, 0)
        {
            this->nome = nome;
            this->horas = stoi(horas);
            this->saudavel = saudavel;
        }

        string toString(){
            stringstream ss;
            ss << "Ter " << nome << " " << horas << "h ";
            if(saudavel == "sim")
                ss << "Salubre";
            else
                ss << "Insalubre";

            ss << endl << "Salario ";
            ss << calcSalario();
            return ss.str();
        }

        double calcSalario(){
            if(saudavel == "sim"){
                return 4*this->horas +_calcSalario();
            }else if(saudavel == "nao"){
                return 4*this->horas + 500 + _calcSalario();
            }
        }
};
#endif // TER_H_INCLUDED
