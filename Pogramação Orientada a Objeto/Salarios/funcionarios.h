#ifndef FUNCIONARIOS_H_INCLUDED
#define FUNCIONARIOS_H_INCLUDED
#include "professor.h"
#include "estagiario.h"
#include "ter.h"
#include <map>
class funcionarios{

    public:
        float bonus = 0;
        int qtdFuncionarios = 0;
        map<string, professor> professores;
        map<string, estagiario> estagiarios;
        map<string, ter> teres;
        void setBonus(float novoBonus);
        void logar();
        bool existe(string nome);
        bool show(string nome);
        bool diaria(string nome);
        bool remover(string nome);
};

void menu(){
    cout << endl << "Adicionar Prof: addProf nome classe" << endl;
    cout << endl << "Adicionar Sta: addSta nome nivel" << endl;
    cout << endl << "Adicionar Ter: addTer nome horas salubre(sim/nao)" << endl;
    cout << endl << "Mostrar Funcionario: show nome" << endl;
    cout << endl << "Remover Funcionario: rm nome" << endl;
    cout << endl << "Modificar Bonus: setBonus valor" << endl;
    cout << endl << "Adicionar Diaria: addDiaria nome" << endl;
    cout << endl << "Sair: logout" << endl;
}

void funcionarios::setBonus(float novoBonus){

    this->bonus = novoBonus;

}
bool funcionarios::existe(string nome){

    auto prof = professores.find(nome);
    auto esta = estagiarios.find(nome);
    auto tere = teres.find(nome);

    if(prof != professores.end() || esta != estagiarios.end() || tere != teres.end()){
        return true;
    }else{
        cout << endl <<"done" << endl;
        return false;
    }
}

bool funcionarios::show(string nome){

    auto prof = professores.find(nome);
    auto esta = estagiarios.find(nome);
    auto tere = teres.find(nome);

    if(prof != professores.end()){
        professores.at(nome).setBonus(bonus/qtdFuncionarios);
        cout << professores.at(nome).toString() << endl;
        return true;
    }else if(esta != estagiarios.end()){
        estagiarios.at(nome).setBonus(bonus/qtdFuncionarios);
        cout << estagiarios.at(nome).toString() << endl;
        return true;
    }else if(tere != teres.end()){
        teres.at(nome).setBonus(bonus/qtdFuncionarios);
        cout << teres.at(nome).toString() << endl;
        return true;
    }else{
        return false;
    }

}

bool funcionarios::diaria(string nome){
    auto prof = professores.find(nome);
    auto esta = estagiarios.find(nome);
    auto tere = teres.find(nome);

    if(prof != professores.end()){
        professores.at(nome).addDiaria();
        return true;
    }else if(esta != estagiarios.end()){
        estagiarios.at(nome).addDiaria();
        return true;
    }else if(tere != teres.end()){
        teres.at(nome).addDiaria();
        return true;
    }else{
        return false;
    }
}

bool funcionarios::remover(string nome){
    auto prof = professores.find(nome);
    auto esta = estagiarios.find(nome);
    auto tere = teres.find(nome);

    if(prof != professores.end()){
        professores.erase(nome);
        cout << "Prof " << nome <<" removido." << endl;
        return true;
    }else if(esta != estagiarios.end()){
        cout << "Sta " << nome <<" removido." << endl;
        estagiarios.erase(nome);
        return true;
    }else if(tere != teres.end()){
        cout << "Ter " << nome <<" removido." << endl;
        teres.erase(nome);
    }else{
        return false;
    }
}

void funcionarios::logar(){
    string vetor[4];
    menu();
    while(true){
        cin >> vetor[0];
        if(vetor[0] == "logout"){
            break;
        }else if(vetor[0] == "addProf"){
            cin >> vetor[1];
            cin >> vetor[2];

            if(existe(vetor[1]))
                cout << "fail: funcionario " << vetor[1] <<" ja existe." << endl;
            else{
                professores.insert(make_pair(vetor[1], professor(vetor[1], vetor[2])));
                qtdFuncionarios++;
            }


        }else if(vetor[0] == "addSta"){
            cin >> vetor[1];
            cin >> vetor[2];

            if(existe(vetor[1]))
                cout << "fail: funcionario " << vetor[1] <<" ja existe." << endl;
            else{
                estagiarios.insert(make_pair(vetor[1], estagiario(vetor[1], vetor[2])));
                qtdFuncionarios++;
            }


        }else if(vetor[0] == "addTer"){
            cin >> vetor[1];
            cin >> vetor[2];
            cin >> vetor[3];

            if(existe(vetor[1]))
                cout << "fail: funcionario " << vetor[1] <<" ja existe." << endl;
            else{
              teres.insert(make_pair(vetor[1], ter(vetor[1], vetor[2], vetor[3])));
              qtdFuncionarios++;
            }
        }else if(vetor[0] == "show"){
            cin >> vetor[1];
            if(show(vetor[1]))
                cout << endl << "done" << endl;
            else
                cout << "fail: funcionario "<< vetor[1] <<" nao existe" << endl;

        }else if(vetor[0] == "rm"){
            cin >> vetor[1];
            if(remover(vetor[1])){
                cout << "done" << endl;
                qtdFuncionarios--;
            }else{
                cout << "fail: funcionario "<< vetor[1] <<" nao existe" << endl;
            }
        }else if(vetor[0] == "setBonus"){

            cin >> vetor[1];
            this->bonus = stof(vetor[1]);
            cout << "done" << endl;

        }else if(vetor[0] == "addDiaria"){
            cin >> vetor[1];
             if(diaria(vetor[1]))
                cout << endl << "done" << endl;
            else
                cout << "fail: funcionario "<< vetor[1] <<" nao existe" << endl;
        }else if(vetor[0] == "menu"){
            menu();
        }
    }
}

#endif // FUNCIONARIOS_H_INCLUDED
