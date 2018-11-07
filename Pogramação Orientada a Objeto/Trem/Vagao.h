#ifndef VAGAO_H_INCLUDED
#define VAGAO_H_INCLUDED

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include "Passageiro.h"
#include "passageiroPessoa.h"
#include "passageiroCarga.h"

using namespace std;

class Vagao{
    public:
        virtual bool Embarcar(Passageiro *pass) = 0;
        virtual bool Desembarcar(string id) = 0;
        virtual bool Exists(string id) = 0;
        virtual string toString() = 0;
};

#endif // VAGAO_H_INCLUDED
