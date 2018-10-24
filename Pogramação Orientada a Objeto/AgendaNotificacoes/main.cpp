#include <string>
#include <iostream>
#include "Agenda.h"
using namespace std;

void mennu(){
    cout << "Adicionar um Usuario: addUser usuario password" << endl;
    cout << "Efetuar Login: login Usuario Password" << endl;
    cout << "Mostrar os Usuarios do Sistema: showUsers" << endl;
    cout << "Logout: logout" << endl;
    cout << "Opcoes: Menu" << endl << endl;
}

int main(){
    Agenda agenda;
    mennu();
    string escolha, login, senha;
    while(true){
        cin >> escolha;
        if(escolha == "addUser"){
            cin >> login;
            cin >> senha;
            agenda.cadastro(login, senha);
        }else if(escolha == "login"){
            cin >> login;
            cin >> senha;
            agenda.login(login, senha);
        }else if(escolha == "showUsers"){
            agenda.showUsuarios();
        }else if(escolha == "menu"){
            mennu();
        }else if(escolha == "logout"){
            cout << "Vc saiu do sistema." << endl << endl;
            break;
        }
    }
}
