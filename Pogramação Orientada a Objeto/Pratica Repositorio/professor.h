#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED
#include <sstream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

class professor{
    public:
        string matricula, nome;
        string toString();
        professor(string matricula, string nome);
};

professor::professor(string matricula, string nome){
    this->matricula = matricula;
    this->nome = nome;
}

string professor::toString(){
    stringstream ss;
    ss << "Nome: " << nome << " | Matricula: " << matricula;
    return ss.str();
}

#endif // PROFESSOR_H_INCLUDED
