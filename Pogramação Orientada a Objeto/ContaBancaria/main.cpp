
#include<iostream>
#include<stdio.h>
#include <string.h>
#include "contaBancaria.h"
#include "operacao.h"
using namespace std;

int main(){

int i = 0;
string funcao, nome;
contaBancaria cb;
int valor;

    while(i == 0){
        cout << "\n Iniciar Conta: init nome \n";
        cout << "\n Depositar na Conta: deposito valor \n";
        cout << "\n Saque dinheiro da Conta: saque valor \n";
        cout << "\n Tarifa da Conta: tarifa valor \n";
        cout << "\n Mostrar os valores da Conta: show \n";
        cout << "\n Extrato da Conta: extrato \n";
        cout << "\n Ultimos n extratos: extratoN n extrato \n";

        cin >> funcao;

        if(funcao == "init"){
            cin >> nome;
            cb = contaBancaria(nome);

        }
        if(funcao == "deposito"){
            cin >> valor;
            if(cb.depositar(valor)){
                cout << "\n" << "Deposito realizado sucesso." << "\n";
            }
        }
        if(funcao == "saque"){
            cin >> valor;
            if(cb.saque(valor)){
                cout << "\n" << "Saque realizado com sucesso." << "\n";
            }else{
                cout << "\n" << "Saldo insuficiente." << "\n";
            }

        }
        if(funcao == "tarifa"){
            cin >> valor;
            if(cb.tarifa(valor)){
                cout << "\n \t" << "Tarifa realizada com sucesso." << "\n";
            }

        }
        if(funcao == "show"){
            cb.show();
        }
        if(funcao == "extratoN"){
                cin >> valor;
           if(cb.extratoN(valor)){
                cout << "\n \t" << "Extrato realizado com sucesso." << "\n";
           }else{
                cout << "\n \t" << "Extrato nao pode ser realizado." << "\n";
           }
        }

        if(funcao == "extrato"){
            cb.extrato();
        }

    }

}
