#ifndef SIPPA_H_INCLUDED
#define SIPPA_H_INCLUDED

#include <sstream>
#include <string.h>
#include <vector>
#include <map>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

using namespace std;

class sippa{

    public:

        map<string, aluno> alunos;
        map<string, professor> professores;
        map<string, disciplina> disciplinas;

        void inserirAluno(string matricula, string curso, string nome);
        void inserirProfessor(string matricula, string nome);
        void inserirDisciplina(string matricula, string nome);

        void removerAluno(string matricula);
        void removerProfessor(string matricula);
        void removerDisciplina(string matricula);

        void showAlunos();
        void showProfessores();
        void showDisciplinas();

        void getAluno(string matricula);
        void getProfessor(string matricula);
        void getDisciplina(string matricula);

};

void sippa::inserirAluno(string matricula, string curso, string nome){

    auto res = alunos.find(matricula);

    if(res != alunos.end()){
        cout << endl <<"Matricula existente, Aluno nao pode ser adicionado." << endl << endl;

    }else{
        alunos.insert(make_pair(matricula, aluno(matricula, curso, nome)));
        cout << endl << "Aluno adicionado com sucesso." << endl << endl;
    }

}
void sippa::inserirProfessor(string matricula, string nome){

    auto res = professores.find(matricula);

    if(res != professores.end()){
        cout << endl <<"Matricula existente, Professor nao pode ser adicionado." << endl << endl;
    }else{
        professores.insert(make_pair(matricula, professor(matricula, nome)));
        cout << endl << "Professor adicionado com sucesso." << endl << endl;
    }
}
void sippa::inserirDisciplina(string matricula, string nome){

   auto res = disciplinas.find(matricula);

    if(res != disciplinas.end()){
        cout << endl <<"Matricula existente, Disciplina nao pode ser adicionada." << endl << endl;
    }else{
        disciplinas.insert(make_pair(matricula, disciplina(matricula, nome)));
        cout << endl << "Disciplina adicionada com sucesso." << endl << endl;
    }
}

void sippa::removerAluno(string matricula){

    auto res = alunos.find(matricula);
    if(res != alunos.end()){
        alunos.erase(matricula);
    }else{
        cout << endl << "O aluno nao esta no sistema." << endl;
    }
}
void sippa::removerProfessor(string matricula){
    auto res = professores.find(matricula);
    if(res != professores.end()){
        professores.erase(matricula);
    }else{
        cout << endl << "O professor nao esta no sistema." << endl;
    }
}
void sippa::removerDisciplina(string matricula){
    auto res = disciplinas.find(matricula);
    if(res != disciplinas.end()){
        disciplinas.erase(matricula);
    }else{
        cout << endl << "A disciplina nao esta no sistema." << endl;
    }

}
void sippa::showAlunos(){
    cout << endl <<"Alunos" << endl;
    for(auto it : alunos){
        cout << endl <<it.second.toString() << endl;
    }
}
void sippa::showProfessores(){
    cout << endl <<"Professores" << endl;
    for(auto it : professores){
        cout << endl <<it.second.toString() << endl;
    }
}
void sippa::showDisciplinas(){
    cout << endl <<"Disciplinas" << endl;
    for(auto it : disciplinas){
        cout << endl <<it.second.toString() << endl;
    }
}
void sippa::getAluno(string matricula){

    auto res = alunos.find(matricula);
    if(res != alunos.end()){
        cout << alunos.at(matricula).toString() << endl;
    }else{
        cout << endl << "O aluno nao esta no sistema." << endl;
    }
}
void sippa::getProfessor(string matricula){
    auto res = professores.find(matricula);
    if(res != professores.end()){
        cout << professores.at(matricula).toString() << endl;
    }else{
        cout << endl << "O professor nao esta no sistema." << endl;
    }

}
void sippa::getDisciplina(string matricula){
    auto res =  disciplinas.find(matricula);
    if(res != disciplinas.end()){
        cout << disciplinas.at(matricula).toString() << endl;
    }else{
        cout << endl << "A disciplina nao esta no sistema." << endl;
    }

}
#endif // SIPPA_H_INCLUDED
