#ifndef DISCIPLINA_H_INCLUDED
#define DISCIPLINA_H_INCLUDED
#include <sstream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

class disciplina{
    public:
        string matricula, nome;
        string tipo = "Disciplina";
        string toString();
        disciplina(string matricula, string nome);
};

disciplina::disciplina(string matricula, string nome){
    this->matricula = matricula;
    this->nome = nome;
}

string disciplina::toString(){
    stringstream ss;
    ss << "Nome: " << nome << " | Codigo: " << matricula;
    return ss.str();
}

#endif // DISCIPLINA_H_INCLUDED
