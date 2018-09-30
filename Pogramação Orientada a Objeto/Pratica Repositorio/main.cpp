
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

    string escolha, matricula, curso, nome;
    sippa meuSippa = sippa();
    menu();

    while(1){
        cin >> escolha;
        if(escolha == "addAlu"){
            cin >> matricula;
            cin >> curso;
            getline(cin, nome);
            meuSippa.inserirAluno(matricula, curso, nome);
        }else if(escolha == "addPro"){
            cin >> matricula;
            getline(cin, nome);
            meuSippa.inserirProfessor(matricula, nome);
        }else if(escolha == "addDis"){
            cin >> matricula;
            getline(cin, nome);
            meuSippa.inserirDisciplina(matricula, nome);
        }else if(escolha == "rmAlu"){
            cin >> matricula;
            meuSippa.removerAluno(matricula);
        }else if(escolha == "rmPro"){
            cin >> matricula;
            meuSippa.removerProfessor(matricula);
        }else if(escolha == "rmDis"){
            cin >> matricula;
            meuSippa.removerDisciplina(matricula);
        }else if(escolha == "getAlu"){
            cin >> matricula;
            meuSippa.getAluno(matricula);
        }else if(escolha == "getPro"){
            cin >> matricula;
            meuSippa.getProfessor(matricula);
        }else if(escolha == "getDis"){
            cin >> matricula;
            meuSippa.getDisciplina(matricula);
        }else if(escolha == "showAlu"){
            meuSippa.showAlunos();
        }else if(escolha == "showPro"){
            meuSippa.showProfessores();
        }else if(escolha == "showDis"){
            meuSippa.showDisciplinas();
        }else if(escolha == "menu"){
            menu();
        }
    }

}

