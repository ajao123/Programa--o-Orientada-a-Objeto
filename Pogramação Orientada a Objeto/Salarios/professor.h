#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED
#include <sstream>
#include <stdlib.h>
#include "funcionario.h"

using namespace std;

class professor : public funcionario{
    public:
        string classe;

        professor(string nome, string classe):
        funcionario(nome, 2)
            {
                this->nome = nome;
                this->classe = classe;
            }

        string toString(){
            stringstream ss;
            ss << "Prof " << nome << " classe " << classe << endl;
            ss << "Salario " << calcSalario();

            return ss.str();
        }

        double calcSalario(){
            if(classe == "A"){
               return 3000 + _calcSalario();
            }else if(classe == "B"){
               return 5000 + _calcSalario();
            }else if(classe == "C"){
               return 7000 + _calcSalario();
            }else if(classe == "D"){
               return 9000 + _calcSalario();
            }else if(classe == "E"){
               return 11000 + _calcSalario();
            }
        }

};


#endif // PROFESSOR_H_INCLUDED
