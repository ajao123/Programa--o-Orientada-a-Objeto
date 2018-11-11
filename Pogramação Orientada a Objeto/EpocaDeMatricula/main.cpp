#include <iostream>
#include <sstream>
#include "Alunos.h"
#include "disciplina.h"
#include "Repositorio.h"

using namespace std;

string menu(){
        stringstream ss;
        ss << "          Menu          " << endl;
        ss << "Adicionar Aluno: addAlu Aluno" << endl;
        ss << "Adicionar Disciplina: addDis Disciplina" << endl;
        ss << "Matricular um Aluno numa Disciplina: matr Aluno Disciplina" << endl;
        ss << "Desmatricular um Aluno numa Disciplina: dsmatr Aluno Disciplina" << endl;
        ss << "Mostrar todos os Alunos: showAlu " << endl;
        ss << "Mostrar todas as Disciplinas: showDis " << endl;
        ss << "Mostrar os Alunos matriculados e uma Disciplina: showMatr Disciplina" << endl;
        ss << "Mostrar as Disciplinas que um Aluno está matriculado:  matrDis Aluno" << endl;
        ss << "Rever essas opcoes: menu" << endl;
        return ss.str();
    }

int main(){

    string opcao, nome, disc;
    Repositorio<string, Alunos> alunos;
    Repositorio<string, disciplina> disciplinas;
    cout << menu() << endl;
    while(1){
        cin >> opcao;
        if(opcao == "menu"){
            cout << menu() << endl;
        }else if(opcao == "addAlu"){
            cin >> nome;
            alunos.add(nome, Alunos(nome));
        }else if(opcao == "addDis"){
            cin >> nome;
            disciplinas.add(nome, disciplina(nome));
        }else if(opcao == "matr"){
            cin >> nome;
            cin >> disc;
            Alunos *alu = &alunos.get(nome);
            disciplina *dis = &disciplinas.get(disc);
            alu->matricular(dis);
        }else if(opcao == "dsmatr"){
            cin >> nome;
            cin >> disc;

            Alunos *alu = &alunos.get(nome);
            vector<disciplina> disci;
            for(auto *it : alu->getDisciplinas()){
                disci.push_back(*it); //todoas as disciplinas
            }
            alu->m_disc.clear();
            for(int i = 0; i < disci.size(); i++){
                if(disci[i].getId() != disc)
                    alu->m_disc.push_back(new disciplina(disci[i].getId()));
            }

            disciplina *ds = &disciplinas.get(disc);
            vector<Alunos> als;
           for(auto *it : ds->getAlunos()){
                als.push_back(*it); //todos os alunos
            }
            ds->m_aluno.clear();
            for(int j = 0; j < als.size(); j++){
                if(als[j].getId() != nome)
                    ds->m_aluno.push_back(new Alunos(als[j].getId()));
            }

        }else if(opcao == "showAlu"){
            cout << endl << "Alunos" << endl ;
            for(auto &al : alunos.getValues()){
                cout << al.getId() << endl;
            }
        }else if(opcao == "showDis"){
            cout << endl << "Disciplinas" << endl ;
            for(auto &ds : disciplinas.getValues()){
                cout << ds.getId() << endl;
            }
        }else if(opcao == "showMatr"){
            cin >> disc;
            disciplina *ds = &disciplinas.get(disc);
            for(auto &it : ds->getAlunos()){
                cout << it->getId() << endl;
            }
        }else if(opcao == "matrDis"){
            cin >> nome;
            Alunos *al = &alunos.get(nome);
            for(auto &it : al->getDisciplinas()){
                cout << it->getId() << endl;
            }
        }
    }
}
