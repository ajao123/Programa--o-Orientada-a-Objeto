#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H
#include "operacao.h"
#include <vector>
#include<iostream>

class contaBancaria
{
    public:
        string id;
        float saldo;
        vector<operacao*> contas;
        int numero = 0;


    contaBancaria(string id, float saldo);
    void show();
    bool depositar(float valor);
    bool saque(float valor);
    bool tarifa(float valor);
    bool extrato();
    bool extratoN(int sz);
};

    contaBancaria::contaBancaria(string id = "", float saldo = 0.0){
        this->id = id;
        this->saldo = saldo;

    }

    void contaBancaria::show(){
        stringstream saida;
            cout << "\n \t" <<id << ":" << saldo << "\n";
    }

    bool contaBancaria::depositar(float valor){

        saldo = saldo + valor;

        operacao *op = new operacao(numero, saldo, valor, "deposito");
        numero++;

        contas.push_back(op);
        show();
        return true;
    }

    bool contaBancaria::saque(float valor){

        if((saldo - valor) < 0)
            return false;

        saldo = saldo - valor;

        operacao *op = new operacao(numero, saldo, valor*-1, "saque");
        numero++;

        contas.push_back(op);

        show();
        return true;
    }

    bool contaBancaria::tarifa(float valor){
        saldo = saldo + valor;

        operacao *op = new operacao(numero, saldo, valor, "tarifa");
        numero++;
        contas.push_back(op);

        show();
        return true;
    }

    bool contaBancaria::extratoN(int sz){

        if(sz >= contas.size()){
            return false;
        }

        for(int i = sz; i >= 0; i--){
            if(contas[i] != nullptr){

            cout << "\n \t" << contas[i]->toString() << "\n";

            }
        }

        return true;
    }

    bool contaBancaria::extrato(){

        for(int i = 0; i < contas.size(); i++){
            if(contas[i] != nullptr){
                cout << "\n \t" << contas[i]->toString() << "\n";
            }
        }
        return true;
    }
#endif // CONTABANCARIA_H
