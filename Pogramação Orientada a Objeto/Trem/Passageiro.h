#ifndef PASSAGEIRO_H_INCLUDED
#define PASSAGEIRO_H_INCLUDED

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

class Passageiro{
    public:
        virtual string getId() = 0;
        virtual string toString() = 0;
};


#endif // PASSAGEIRO_H_INCLUDED
