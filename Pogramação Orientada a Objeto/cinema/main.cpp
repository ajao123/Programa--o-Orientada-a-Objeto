#include<iostream>
#include<stdio.h>
#include "sala.h"
#include "cliente.h"
#include <string.h>
using namespace std;

int main(){

    int i = 0;
    string escolha;
    int exs = 0;
    int qtd = 0;
    sala ns = sala(0);
    bool rst;
    while(i == 0){

        cout << "Digite init para adicionar uma sala:init 5\n";
        cout << "Digite reservar para adicionar um cliente: reservar davi 3232 0 \n";
        cout << "Digite cancelar para excluir um cliente: cancelar davi\n";
        cin >> escolha;

        if(escolha == "init"){
                cin >> qtd;
            ns = sala(qtd);
            cout << ns.toString();
            exs = 1;
        }
        if(exs == 1){
        if(escolha == "reservar"){
            string nome, fone;
            int cadeira;
            cin >> nome;
            cin >> fone;
            cin >> cadeira;

            rst = ns.inserir(cliente(nome, fone), cadeira);
            if(rst){
                cout << "\nCliente adicionado com sucesso";
            }else{
                cout <<"\nCliente nao pode ser adicionado";
            }
        }
        if(escolha == "cancelar"){
            string nome;

            cin >> nome;


            rst = ns.excluir(nome);
            if(rst){
                cout << "\nCliente excluido com sucesso.";
            }else{
                cout <<"\nCliente nao pode ser excluido.";
            }
        }
        }else{cout << "Nao existe nenhuma sala.";}
    }

}
