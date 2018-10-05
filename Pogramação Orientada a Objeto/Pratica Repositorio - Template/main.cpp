
#include<iostream>
#include<stdio.h>
#include<string.h>
#include <sstream>
#include "sippa.h"
using namespace std;

void menu(){
    cout << "Adicionar aluno: addAlu matricula curso nome." << endl;
    cout << "Adicionar professor: addPro matricula nome." << endl;
    cout << "Adicionar disciplina: addDis codigo nome." << endl;
    cout << "Remover aluno: rmAlu matricula." << endl;
    cout << "Remover professor: rmPro matricula." << endl;
    cout << "Remover disciplina: rmDis codigo." << endl;
    cout << "Buscar aluno: getAlu matricula." << endl;
    cout << "Buscar professor: getPro matricula." << endl;
    cout << "Buscar disciplina: getDis codigo." << endl;
    cout << "Buscar todos os alunos: showAlu matricula." << endl;
    cout << "Buscar todos os professores: showPro matricula." << endl;
    cout << "Buscar todos os disciplinas: showDis codigo." << endl;

}

int main(){

    //string escolha, matricula, curso, nome;
    string comando;
    sippa meuSippa = sippa();
    menu();

    while(1){
        getline(cin, comando);
        meuSippa.opcoes(comando);
    }

}

