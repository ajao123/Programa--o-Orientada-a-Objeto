#ifndef DISCIPLINA_H_INCLUDED
#define DISCIPLINA_H_INCLUDED
#include <vector>
#include <iostream>
#include "Alunos.h"

using namespace std;
class Alunos;
class disciplina{
public:
 string id_disciplina;
 vector<Alunos*> m_aluno;

    disciplina(string id_disciplina){
        this->id_disciplina = id_disciplina;
    }

    string getId(){
        return id_disciplina;
    }
    void matricular(Alunos *aluno){
        m_aluno.push_back(aluno);
    }
    vector<Alunos*> getAlunos(){
        return m_aluno;
    }


friend class Alunos;
};

#endif // DISCIPLINA_H_INCLUDED
