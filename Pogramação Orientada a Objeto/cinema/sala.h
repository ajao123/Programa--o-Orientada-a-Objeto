#ifndef SALA_H
#define SALA_H
#include "cliente.h"
#include <vector>
#include<iostream>
#include<stdio.h>

using namespace std;
class sala
{
    public:
        int qtd_cadeiras;
        vector<cliente> cadeiras;
        sala(int qtd_cadeiras);
        string toString();
        bool inserir(cliente clt, int posicao);
        bool excluir(string nome);
};

    sala::sala(int qtd_cadeiras){

        this->qtd_cadeiras = qtd_cadeiras;
        for(int i = 0; i < qtd_cadeiras; i++){
            cadeiras.push_back(cliente("","",false));
        }
    }

    string sala::toString(){

        stringstream ss;
        ss << "[ ";
            for(cliente clt : cadeiras){
                ss << "|" << clt.toString() << "|";
            }
        ss << " ]";

        return ss.str();
    }

    bool sala::inserir(cliente clt, int posicao){

        int estou = 0;
        if(cadeiras[posicao].existe){
            cout << "\n A cadeira esta ocupada.";
            return false;
        }
        if(posicao >= cadeiras.size() || posicao < 0){
            cout << "\n A cadeira nao existe";
            return false;
        }
        for(int i = 0; i < cadeiras.size(); i++){
                if(cadeiras[i].id == clt.id)
                    estou =1;
        }
        if(!estou){
        cadeiras[posicao] = clt;
        cout << "\n" << toString();
        return true;
        }else{
            cout << "\n Voce ja esta no cinema";
            return false;
        }

    }
    bool sala::excluir(string nome){
        int achou = 0;
        for(int i = 0; i < cadeiras.size(); i++){

            if(cadeiras[i].id == nome){
                cadeiras[i].id = "";
                cadeiras[i].fone = "";
                cadeiras[i].existe = false;
            cout << toString();
                return true;
            }

        }
        cout << "O cliente " << nome << " nao esta na sala";
        return false;
    }

#endif // SALA_H
