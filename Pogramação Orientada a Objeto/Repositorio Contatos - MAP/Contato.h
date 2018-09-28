#ifndef CONTATO_H_INCLUDED
#define CONTATO_H_INCLUDED
#include "telefone.h"
#include <sstream>
#include <string.h>
#include<vector>
#include <map>

using namespace std;

class Contato{
    public:
        string id;
        string nome;
         map<string, telefone> rep_telefone;

        Contato(string id, string nome);
        void inserir(string operadora, string fone);
        void remover(string numero);
        void show();
};

Contato::Contato(string id, string nome){
    this->id = id;
    this->nome = nome;
}

void Contato::inserir(string operadora, string fone){
    rep_telefone.insert(make_pair(fone, telefone(operadora, fone)));
}

void Contato::show(){
    int i = 0;
    cout << endl;
    for(auto it : rep_telefone){
        cout << i << " - "<< it.second.dados << endl;
        i++;
    }
}

void Contato::remover(string numero){
    rep_telefone.erase(numero);
}
#endif // CONTATO_H_INCLUDED
