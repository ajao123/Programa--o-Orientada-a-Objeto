#ifndef CONTATO_H_INCLUDED
#define CONTATO_H_INCLUDED
#include "telefone.h"
#include <sstream>
#include <string.h>
#include<vector>

using namespace std;

class Contato{
    public:
        string id;
        string operadora;
        vector<telefone*> telefones;

        Contato(string id);
        void inserir(string operadora, string fone);
        telefone *remover(int indice);
        void show();


};

Contato::Contato(string id){
    this->id = id;
}

void Contato::inserir(string operadora, string fone){
    telefone *telef = new telefone(operadora, fone);
    telefones.push_back(telef);
}

void Contato::show(){
    int j = 0;
    for(int i = 0; i < telefones.size(); i++){
        if(telefones[i] != nullptr){
            cout << j << " - " << telefones[i]->toString() <<endl;
            j++;
        }
    }
}

telefone *Contato::remover(int indice){
    if(indice < telefones.size()){
        int j = -1, i;
        for(i = 0; i < telefones.size(); i++){
            if(telefones[i] != nullptr){
                j++;
            }
            if(j ==  indice){
                auto *pass = telefones[i];
                telefones[i] =  nullptr;
                return pass;
            }
        }
    }
    return nullptr;
}


#endif // CONTATO_H_INCLUDED
