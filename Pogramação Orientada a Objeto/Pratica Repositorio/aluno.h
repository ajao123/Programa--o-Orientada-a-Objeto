#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include <sstream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

class aluno{
    public:
        string matricula, curso, nome;
        string toString();
        aluno(string matricula, string curso, string nome);
};

aluno::aluno(string matricula, string curso, string nome){
    this->matricula = matricula;
    this->curso = curso;
    this->nome = nome;
}

string aluno::toString(){
    stringstream ss;
    ss << "Nome: " << nome << " | Curso: " << curso << " | Matricula: " << matricula;
    return ss.str();
}
#endif // ALUNO_H_INCLUDED
