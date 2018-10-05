#ifndef SIPPA_H_INCLUDED
#define SIPPA_H_INCLUDED

#include <sstream>
#include <string.h>
#include <vector>
#include <map>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "repositorio.h"
using namespace std;

class sippa{

    public:

        repositorio<aluno> alunos;
        repositorio<professor> professores;
        repositorio< disciplina> disciplinas;

        //repositorio<T> objetos;
        void opcoes(string comando);

};

void sippa::opcoes(string comando){

    stringstream ss(comando);
    string nome;
    vector<string> comandos;
    while(getline(ss, nome, ' ')){
            comandos.push_back(nome);
    }
    if(comandos[0] == "addAlu"){
        alunos.add(comandos[1], aluno(comandos[1], comandos[2], comandos[3]));
    }else if(comandos[0] == "addPro"){
        professores.add(comandos[1], professor(comandos[1], comandos[2]));
    }else if(comandos[0] == "addDis"){
        disciplinas.add(comandos[1], disciplina(comandos[1], comandos[2]));
    }else if(comandos[0] == "rmAlu"){
        alunos.remover(comandos[1]);
    }else if(comandos[0] == "rmPro"){
        professores.remover(comandos[1]);
    }else if(comandos[0] == "rmDis"){
        professores.remover(comandos[1]);
    }else if(comandos[0] == "getAlu"){
        alunos.getRepositorio(comandos[1]);
    }else if(comandos[0] == "getPro"){
        professores.getRepositorio(comandos[1]);
    }else if(comandos[0] == "getDis"){
        disciplinas.getRepositorio(comandos[1]);
    }else if(comandos[0] == "showAlu"){
        alunos.show();
    }else if(comandos[0] == "showPro"){
        professores.show();
    }else if(comandos[0] == "showDis"){
        disciplinas.show();
    }
}
#endif // SIPPA_H_INCLUDED
