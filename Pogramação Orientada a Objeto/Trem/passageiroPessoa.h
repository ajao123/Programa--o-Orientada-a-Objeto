#ifndef PASSAGEIROPESSOA_H_INCLUDED
#define PASSAGEIROPESSOA_H_INCLUDED

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include "Passageiro.h"

using namespace std;

class passageiroPessoa : public Passageiro{
    public:
        string id;

        passageiroPessoa(string id){
            this->id = id;
        }

        string getId(){
            return id;
        }
        string toString(){
            stringstream ss;
            ss << "Passageiro: " << id;
            return ss.str();
        }
};


#endif // PASSAGEIROPESSOA_H_INCLUDED
