#ifndef AGENDACONTATOS_H_INCLUDED
#define AGENDACONTATOS_H_INCLUDED

#include <sstream>
#include <string.h>
#include "Contato.h"
#include "telefone.h"
#include <vector>
#include <map>

using namespace std;

class agendaContatos{
    public:
        map<string, Contato> rep;
        void inserirContatos(string id, string nome);
        void show();
        void logar(string id);
        void opcoesContato(string id);
        void rename(string id, string newNome);
        void menu();
        void remover(string id);
};

void agendaContatos::inserirContatos(string id, string nome){
   int existe = 0;
   for(auto it : rep){
         if(it.first == id){
            existe = 1;
            break;
         }
    }
    if(existe == 0){
        rep.insert(make_pair(id, Contato(id, nome)));
        cout << endl << "Contato adicionado com sucesso." << endl << endl;
     }else{
        cout << endl <<"Id existente, contato nao pode ser adicionado." << endl << endl;
    }

}

void agendaContatos::show(){
    cout << endl;
    for(auto it : rep){
        cout << it.second.id <<" : " << it.second.nome << endl;
        for(auto jt : it.second.rep_telefone){
            cout << jt.second.dados << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void agendaContatos::logar(string id){

   int existe = 0;

   for(auto it : rep){
         if(it.first == id){
            existe = 1;
            break;
         }
    }
    if(existe == 1){
        cout << endl <<"Contato esta no Sistema."<<endl << endl;
        opcoesContato(id);
    }else{
        cout << endl <<"Contato nao esta no Sistema."<<endl << endl;
    }
}

void agendaContatos::opcoesContato(string id){
    menu();
    string newNome, num, escolha, operadora, numero, valido = "0123456789()";
    int validar;
    while(1){

            cin >> escolha;
        if(escolha == "rename"){
            cin >> newNome;
            rename(id, newNome);
        }else if(escolha == "end"){
            break;
        } else if(escolha == "menu"){
            menu();
        } else if(escolha == "add"){
            validar = 1;
            cin >> operadora;
            cin >> numero;

            for(char c : numero){
               if(valido.find(c) == string::npos){
                    validar = 0;
                    break;
                }
            }
            if(validar){
                rep.at(id).inserir(operadora, numero);
            }else{
                cout << endl <<"Numero Invalido" << endl << endl;
            }
        }else if(escolha == "show"){
            rep.at(id).show();
        } else if(escolha == "rm"){
            cin >> num;
            rep.at(id).remover(num);
        } else if(escolha == "update"){

            int contatos_existentes = 0, passar;

            rep.at(id).rep_telefone.clear();

            string contatosNovos, novoId, novoTelefone, nome;;
            getline(cin, contatosNovos);
            stringstream str(contatosNovos);
            vector<string> novos;

            passar = 0;
            while(getline(str, nome,' ')){


                    validar = 1;
                    stringstream ss(nome);
                    getline(ss, novoId, ':');
                    ss >> novoTelefone;
                    for(char c : novoTelefone){
                        if(valido.find(c) == string::npos){
                            validar = 0;
                            break;
                        }
                    }
                if(validar && passar > 0){
                    rep.at(id).inserir(novoId, novoTelefone);
                }
                passar++;
            }
        }
    }
}

void agendaContatos::menu(){
    cout <<endl;
    cout << "Adicione um telefone:  add Operadora Numero" << endl;
    cout << "Mostre todos os telefones: show" << endl;
    cout << "Delete um telefone: rm numero do telefone" << endl;
    cout << "Alterar telefones: update nome nome:numero" << endl << endl;

    cout << "Para ver o menu novamente: menu" << endl;
    cout << "Alterar nome do Contato: rename novoNome" << endl;
    cout << "Remover contato: remove" << endl;
    cout << "Deslogar: end " << endl;
    cout << endl;
}

void agendaContatos::rename(string id, string newNome){
    rep.at(id).nome = newNome;
}

void agendaContatos::remover(string id){
    rep.erase(id);
}
#endif // OPERADORA_H
