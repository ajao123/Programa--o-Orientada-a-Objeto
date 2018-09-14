
#include<iostream>
#include<stdio.h>
#include<string.h>
#include "telefone.h"
#include <sstream>

using namespace std;



int main(){

    int i = 0;
    int indice;
    string escolha, nome, nome2, num;
    int val;
    string valido = "0123456789()";
    int numero1, numero2;
    telefone tp;

    while(i == 0){

        cout << "\n Adicione um contato: init nome\n";
        cout << "\n Adicione um telefone:  add Operadora Numero\n";
         cout << "\n Mostre todos os contatos: show \n";
         cout << "\n Delete um contato: rm numero \n";
         cout << "\n Alterar contatos: update nome nome:numero \n";

         cin >> escolha;

        if(escolha == "init"){
            cin >> nome;
            tp = telefone(nome);
        }else{
            if(escolha == "add"){
                    cin >> nome;
                    cin >> num;

                            val = 1;

                            for(char c : num){
                                if(valido.find(c) == string::npos){
                                    val = 0;
                                    break;
                                }
                            }
                            if(val){
                                tp.inserir(nome, num);
                            }else{
                                cout << "Numero Invalido";
                            }

            }else{
                if(escolha == "show"){
                    tp.show();

                }else{
                    if(escolha == "rm"){
                        cin >> indice;
                        operadora *op = tp.remover(indice);
                        delete op;
                        tp.show();
                        }else{

                            if(escolha == "update"){

                                string contatos;
                                getline(cin, contatos);

                                stringstream str(contatos);

                                vector<string> contato;

                                string idef, tef;

                                int i = 0;
                                while(getline(str, nome,' ')){
                                    if(i > 0){

                                    val = 1;
                                    stringstream ss(nome);
                                    getline(ss, idef, ':');
                                    ss >> tef;
                                    for(char c : tef){

                                        if(valido.find(c) == string::npos){

                                            val = 0;
                                            break;
                                        }
                                    }
                                    }
                                    if(val || i == 0){
                                        contato.push_back(nome);
                                        i++;
                                    }

                                 tp = tp.alterar(contato);
                                }
                            }else{
                                cout << "\n" << "Comando invalido." << endl;
                            }
                        }
                }

            }
        }

    }

}
