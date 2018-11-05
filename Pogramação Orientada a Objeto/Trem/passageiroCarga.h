#ifndef PASSAGEIROCARGA_H_INCLUDED
#define PASSAGEIROCARGA_H_INCLUDED

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include "Passageiro.h"

using namespace std;

class passageiroCarga : public Passageiro{
    public:
        string id;
        float peso;

        passageiroCarga(string id = "", float peso = 0.0){
            this->id = id;
            this->peso = peso;
        }

        string getId(){
            return id;
        }
        string toString(){
            stringstream ss;
            ss << "Carga: " << id << " -  Peso: " << peso;
            return ss.str();
        }
        float pesoCarga(){
            return peso;
        }
};

#endif // PASSAGEIROCARGA_H_INCLUDED
