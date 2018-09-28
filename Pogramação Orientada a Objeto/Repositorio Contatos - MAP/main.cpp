
#include<iostream>
#include<stdio.h>
#include<string.h>
#include "agendaContatos.h"
#include "Contato.h"
#include <sstream>

using namespace std;

void menu(){

    cout << "Para ver o menu novamente: menu" << endl;
    cout << "Para adicionar um contato: init id nome" << endl;
    cout << "Para acessar um contato: acess id" << endl;
    cout << "Para ver todos os contaros no sistema: show" << endl;
    cout << "Para remover um contato: remove id" << endl << endl;

}


int main(){
    string escolha, id, nome;
    agendaContatos agenda = agendaContatos();

    menu();
    while(1){

        cin >> escolha;
        if(escolha == "init"){
            cin >> id;
            getline(cin, nome);
            agenda.inserirContatos(id, nome);

        }else if(escolha == "acess"){
            cin >> id;
            agenda.logar(id);

        }else if(escolha == "show"){
            agenda.show();
        }else if(escolha == "remove"){
            cin >> id;
            agenda.remover(id);

        }else if(escolha == "menu"){
            menu();
        }
    }
}
