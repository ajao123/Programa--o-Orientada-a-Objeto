#ifndef ALUNOS_H_INCLUDED
#define ALUNOS_H_INCLUDED
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "disciplina.h"

using namespace std;
class disciplina;
class Alunos{
public:
    string idAluno;
    vector<disciplina*> m_disc;

    Alunos(string idAluno){
        this->idAluno = idAluno;
    }
    void matricular(disciplina *disc){
        m_disc.push_back(disc);
        disc->matricular(this);
    }
    vector<disciplina*> getDisciplinas(){
        return m_disc;
    }
    string getId(){
        return idAluno;
    }
};

#endif // ALUNO_H_INCLUDED
