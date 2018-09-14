
#include<iostream>
#include<stdio.h>
#include <string.h>
#include "topic.h"
#include "passageiro.h"

using namespace std;

int main(){

int i = 0;
    string escolha, nome;

    int numero1, numero2;
    int existe = 0;
    topic tp =  topic(0,0);

    while(i == 0){
        cout << "\n Digite a quantidade de cadeiras e quantas irao ser preferenciais: new 5 2\n";
        cout << "\n Digite o nome e a idade do passageiro: in nome idade \n";
         cout << "\n Digite o nome do passageiro: out nome \n";

        cin >> escolha;

        if(escolha == "in" && existe == 1){


            cin >> nome;
            cin >> numero2;


                if(tp.inserir(new passageiro(nome, numero2))){
                    cout << "Passageiro Adicionado com sucesso.";
                }else{
                    cout << "Passageiro nao pode ser adicionado.";
                }
                cout << "\n";
                tp.show();
            }


        if(escolha == "new"){

            cin >> numero1;
            cin >> numero2;
            tp = topic(numero1, numero2);
            existe = 1;
        }

        if(escolha == "out"){

            cin >> nome;
            passageiro *pass = tp.remover(nome);
            delete pass;
            tp.show();

        }

    }

}
