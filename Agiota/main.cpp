
#include<iostream>
#include<stdio.h>
#include<string.h>
#include <sstream>
#include "agiota.h"
#include "cliente.h"

using namespace std;

void menu(){
    cout << "Para iniciar o sistema: init valor" << endl;
    cout << "Para inserir um cliente: add cli ID NOME" << endl;
    cout << "Para adicionar uma negociacao: add tr ID_CLIENTE VALOR" << endl;
    cout << "Para mostrar todos os clientes: show cli" << endl;
    cout << "Para mostrar o historico de transacoes: show tr" << endl;
    cout << "Para mostrar o historico de transacoes de um cliente: show ID_CLIENTE" << endl;
    cout << "Para matar um cliente: matar ID_CLIENTE" << endl;
    cout << "Para ver o menu novamente: menu" << endl;


}

int main(){


    string mensagem, palavra, msg, id;
    int i;
    int saldo, valor;
    agiota agt;
    menu();
    while(1){
        i = 0;
          cin >> msg;

          if(msg == "add"){
                cin >> msg;

                if(msg == "cli"){

                    void menu();

                    getline(cin, mensagem);
                    stringstream str(mensagem);
                    stringstream pega_nome;

                    while(getline(str, palavra ,' ')){
                        if(i == 1){
                            id = palavra;
                        }else{
                            if(i > 1){
                                pega_nome << palavra <<" ";
                            }
                        }
                        i++;
                    }
                    agt.inserir(id, pega_nome.str());
                }else{
                    if(msg == "tr"){
                       cin >> id;
                       cin >> valor;
                       agt.trato(id, valor);
                    }
                }
          }else{
                if(msg == "init"){
                    cin >> saldo;
                    agt = agiota(saldo);
                }else{
                    if(msg == "show"){
                        cin >> msg;

                        if(msg == "tr"){
                            agt.show_tr();
                        }else{
                            if(msg == "cli"){
                                agt.show();
                            }else{
                                agt.show_tr_clt(msg);
                            }
                        }
                    }else{
                        if(msg == "matar"){
                            cin >> id;
                            cliente *clt = agt.kill(id);
                            delete clt;
                        }else{
                            if(msg == "menu")
                                menu();
                        }
                    }
                }
          }
    }
}
