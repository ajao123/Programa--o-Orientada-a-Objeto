
#include<iostream>
#include<stdio.h>
#include<string.h>
#include "agendaContatos.h"
#include "Contato.h"
#include <sstream>

using namespace std;

void menu(){

    cout << "Para ver o menu novamente: menu" << endl;
    cout << "Para adicionar um contato: init id" << endl;
    cout << "Para acessar um contato: acess id" << endl;
    cout << "Para ver todos os contaros no sistema: show" << endl;
    cout << "Para remover um contato: remove id" << endl << endl;

}


int main(){
    string escolha, id;
    agendaContatos agenda = agendaContatos();
    menu();
    while(1){

        cin >> escolha;
        if(escolha == "init"){
            cin >> id;
            if(agenda.inserirContato(id)){
                cout << "Contato adicionado com sucesso." << endl << endl;
            }else{
                cout << "Contato nao pode ser adicionado com sucesso." << endl << endl;
            }

        }else if(escolha == "acess"){
            cin >> id;
            agenda.logar(id);
        }else if(escolha == "show"){
            agenda.show();
        }else if(escolha == "remove"){
            cin >> id;
            Contato *contato = agenda.remover(id);
            delete contato;
        }else if(escolha == "menu"){
            menu();
        }
    }
}
