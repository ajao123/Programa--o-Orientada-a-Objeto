#ifndef TELEFONE_H
#define TELEFONE_H
#include <string.h>
#include<sstream>
#include "operadora.h"
#include <vector>

using namespace std;

class telefone
{
    public:
        string id;
        int numero = 0;
        vector<operadora*> opp;

        telefone(string id);
        void inserir(string operadora, string telefone);
        telefone alterar(vector<string> contato);
        void show();

        operadora* remover(int indice);
};

telefone::telefone(string id = ""){
    this->id = id;
}

void telefone::inserir(string opr, string tf){

    operadora *op = new operadora(opr, tf);
    opp.push_back(op);


    numero++;
    show();
}

void telefone::show(){
    int j = 0;
   cout << " id: "<< id << endl;

    for(int i = 0; i < opp.size(); i++){

        if(opp[i] != nullptr){
            cout <<j <<" [" << opp[i]->toString() <<"] ";
            j++;
        }

    }

}

operadora *telefone::remover(int indice){

    if(indice < opp.size()){

        int j = -1, i = 0;

        for(i = 0; i < opp.size(); i++){

            if(opp[i] != nullptr){
                j++;
            }
            if(j == indice){
                auto *pass = opp[i];
                opp[i] = nullptr;
                return pass;
            }
        }

    }
    return nullptr;
}

telefone telefone::alterar(vector<string> contato){

 telefone newTp;

    for(int i = 0; i < contato.size(); i++){
        if(i > 1){
            operadora *op = new operadora();
            op->dados = contato[i];
            newTp.opp.push_back(op);
        }else{
            newTp.id = contato[i];
        }

    }

    return newTp;

}

#endif // TELEFONE_H
