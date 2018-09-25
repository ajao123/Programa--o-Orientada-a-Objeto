#ifndef AGENDACONTATOS_H_INCLUDED
#define AGENDACONTATOS_H_INCLUDED

#include <sstream>
#include <string.h>
#include "Contato.h"
#include "telefone.h"
#include <vector>

using namespace std;

class agendaContatos{
    public:
        int tamanho = 0;
        vector<Contato*> contatos;

        agendaContatos();
        bool inserirContato(string id);

        void logar(string id);
        void opcoesContato(int posicao);
        void rename(string novoId, int posicao);
        void menu();
        void show();
        Contato* remover(string id);
};

agendaContatos::agendaContatos(){
    this->tamanho = 0;
}

bool agendaContatos::inserirContato(string id){

    for(int i=0; i < contatos.size(); i++){
        if(contatos[i]->id == id){
            cout << "Id existente, contato nao pode ser adicionado." << endl;
            return false;
        }
    }

    Contato *contato = new Contato(id);
    contatos.push_back(contato);

    return true;
}
void agendaContatos::logar(string id){
    int posicao = -1;

    for(int i = 0; i < contatos.size(); i++){
        if(id == contatos[i]->id){
            posicao = i;
            break;
        }
    }
    if(posicao == -1){
        cout << "Contato nao esta no sistema." << endl;
        }else{
            cout << "Contato esta no sistema." << endl;
            opcoesContato(posicao);
        }
}
void agendaContatos::opcoesContato(int posicao){
    string escolha, id, operadora, numero, valido = "0123456789()";
    int validar, num;

    menu();
    while(1){

        cin >> escolha;
        if(escolha == "rename"){
            cin >> id;
            rename(id, posicao);
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
                contatos[posicao]->inserir(operadora, numero);
            }else{
                cout << "Numero Invalido" << endl;
            }
        }else if(escolha == "show"){
            contatos[posicao]->show();
        } else if(escolha == "rm"){
            cin >> num;
            telefone *fone_delete = contatos[posicao]->remover(num);
            delete fone_delete;
        } else if(escolha == "update"){

            int contatos_existentes = 0, passar;

            for(int j = 0; j < contatos[posicao]->telefones.size(); j++){
                if(contatos[posicao]->telefones[j] != nullptr){
                    contatos_existentes++;
                }
            }

            for(int i = 0; i < contatos_existentes; i++){
                telefone *fone_delete = contatos[posicao]->remover(0);
                delete fone_delete;
            }

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
                    contatos[posicao]->inserir(novoId, novoTelefone);

                }
                passar++;
            }
        }
    }
    cout << "Saindo do contato "<< contatos[posicao]->id << endl;
}

void agendaContatos::menu(){
    cout <<endl;
    cout << "Adicione um telefone:  add Operadora Numero" << endl;
    cout << "Mostre todos os telefones: show" << endl;
    cout << "Delete um telefone: rm numero" << endl;
    cout << "Alterar telefones: update nome nome:numero" << endl << endl;

    cout << "Para ver o menu novamente: menu" << endl;
    cout << "Alterar nome do Contato: rename novoId" << endl;
    cout << "Remover contato: remove" << endl;
    cout << "Deslogar: end " << endl;
    cout << endl;
}

void agendaContatos::rename(string novoId, int posicao){
    int existe = 0, i;
    for(i = 0; i < contatos.size(); i++){
        if(novoId == contatos[i]->id){
            existe = 1;
            cout << "ID existente, nao foi possivel altera o ID do contato na posicao" << posicao << endl;
            break;
        }
    }
    if(existe == 0){
        contatos[posicao]->id = novoId;
        cout << "ID alterado com sucesso, seu novo ID e: " << contatos[posicao]->id << endl;
    }
}

void agendaContatos::show(){
    cout << "Contatos"<<endl;
    for(int i = 0; i < contatos.size(); i++){
        if(contatos[i] != nullptr){
            cout << endl <<"["<<contatos[i]->id <<"]"<< endl;
            for(int j = 0; j < contatos[i]->telefones.size(); j++){
                if(contatos[i]->telefones[j] != nullptr){
                    cout <<"["<<contatos[i]->telefones[j]->dados <<"]"<< endl;
                }
            }
        }
    }
    cout << endl;
}

Contato* agendaContatos::remover(string id){

    for(int i = 0; i < contatos.size(); i++){
        if(id == contatos[i]->id){
            auto *pass = contatos[i];
            contatos[i] = nullptr;
            return pass;
        }
    }
    return nullptr;
}
#endif // OPERADORA_H
