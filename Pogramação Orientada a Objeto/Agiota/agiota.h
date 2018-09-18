#ifndef AGIOTA_H_INCLUDED
#define AGIOTA_H_INCLUDED

#include"transacao.h"
#include"cliente.h"
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

class agiota{

    public:
        vector<cliente*> clientes;
        vector<transacao*> transacoes;

        int saldo, contador = 0;

        agiota(int saldo);
        void inserir(string nome, string id);
        void trato(string id, int valor);
        void show();
        void show_tr_clt(string id);
        void show_tr();
        cliente* kill(string id);
};

    agiota::agiota(int saldo = 0){
        this->saldo = saldo;
        cout << "Saldo do Agiota: "<<saldo << endl;
    }

    void agiota::inserir(string id, string nome){
        int achou = 0;

        for(int i=0; i < clientes.size(); i++){
            if(clientes[i] != nullptr && clientes[i]->id == id){
                achou++;
            }
        }
        if(achou == 0){
            cliente* clt = new cliente(id,nome);
            clientes.push_back(clt);
        }else{
            cout <<"O cliente ja esta cadastrado."<< endl;
        }

    }
    void agiota::trato(string id, int valor){


        for(int i=0; i < clientes.size(); i++){
            if(clientes[i] != nullptr && clientes[i]->id == id){
                if((clientes[i]->divida + valor) > 0){
                    cout << "fail: valor maior que a divida" << endl;
                }else{
                    if((valor+saldo) < 0){
                        cout << "Saldo insuficiente." << endl;
                    }else{
                            transacao* tr = new transacao(contador, clientes[i]->id, valor);
                            transacoes.push_back(tr);
                            clientes[i]->divida+=valor;
                            saldo+=valor;
                            contador++;
                    }
                }

            }
        }

    }
    void agiota::show(){
        cout << "Saldo do Agiota: "<<saldo << endl;
        for(int i = 0; i < clientes.size(); i++){
            if(clientes[i] != nullptr){
                cout << clientes[i]->toString() << endl;
            }
        }
    }
    void agiota::show_tr_clt(string id){
        int i = 0,resultado = 0;
        cout << "Saldo do Agiota: "<<saldo << endl;
        for(int i = 0; i < transacoes.size(); i++){
            if(transacoes[i] != nullptr && transacoes[i]->id_cliente == id){
                cout << transacoes[i]->toString() << endl;
            }
        }

    }

    void agiota::show_tr(){
        cout << "Saldo do Agiota: "<<saldo << endl;
        for(int i = 0; i < transacoes.size(); i++){
            if(transacoes[i] != nullptr){
                cout << transacoes[i]->toString() << endl;
            }
        }
    }

    cliente *agiota::kill(string id){
        for(int i = 0; i < clientes.size(); i++){
            if(clientes[i] != nullptr && clientes[i]->id == id){
                cout << id <<", no ceu tem pao? E morreu"<< endl;
                auto *pass = clientes[i];
                clientes[i] = nullptr;

                return pass;
            }
        }

        return nullptr;
    }

#endif // AGIOTA_H_INCLUDED
