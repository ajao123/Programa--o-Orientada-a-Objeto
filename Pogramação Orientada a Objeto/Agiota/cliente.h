#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <string.h>
#include<sstream>
#include <vector>
using namespace std;

class cliente{

    public:
        string id;
        string nome;
        int divida;

        cliente(string id, string nome, int divida);
        string toString();
};

    cliente::cliente(string id, string nome, int divida = 0){
        this->id = id;
        this->nome = nome;
        this->divida = divida;
    }

    string cliente::toString(){
        stringstream  ss;
        ss << id << ":" << nome << ":" << divida;
        return ss.str();
    }


#endif // CLIENTE_H_INCLUDED
