
#include<iostream>
#include<stdio.h>
#include<string.h>
#include <sstream>
#include "tamagoshi.h"
using namespace std;

void menu(){
        cout << "\n Menu de opcoes: menu " << endl;
        cout << "\n Criar pet: init energia fome limpeza " << endl;
        cout << "\n Brincar com pet: play " << endl;
        cout << "\n Dar comida ao pet: eat " << endl;
        cout << "\n Limpar pet: clean " << endl;
        cout << "\n Dormir: sleep " << endl;
        cout << "\n Mostrar os status do pet: show " << endl;
        cout << "\n Fechar o programa: end " << endl;
}

int main(){


    int i = 0, energia, fome, limpeza;
    string escolha;
    tamagoshi t;
    menu();
    while(true){

        cin >> escolha;

        if(escolha == "init"){
            cin >> energia;
            cin >> fome;
            cin >> limpeza;
            t = tamagoshi(energia, fome, limpeza);
        }
        if(escolha == "play"){
            t.brincar();
        }else{
            if(escolha == "eat"){
                t.comer();
            }else{
                if(escolha == "clean"){
                    t.limpar();
                }else{
                    if(escolha == "sleep"){
                        t.dormir();
                    }else{
                        if(escolha == "show"){
                            t.show();
                        }else{
                            if(escolha == "menu"){
                                menu();
                            }else{
                                if(escolha == "end")
                                break;
                            }
                        }
                    }
                }

            }
        }
    }
}
