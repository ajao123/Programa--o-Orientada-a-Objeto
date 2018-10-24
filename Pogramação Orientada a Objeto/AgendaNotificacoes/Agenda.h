#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
#include "Usuario.h"
using namespace std;

class Agenda{

    public:
        map<string, Usuario> usuarios;
        void cadastro(string id, string senha);

        void login(string id, string senha);
        void logado(string id, string senha);

        void escreverNota(string id, string titulo, string nota);
        void showNotas(string id);


        void removerNota(string id, string titulo);

        void mudarSenha(string id, string novaSenha);

        void showUsuarios();

};
    void Agenda::showUsuarios(){
        cout << "Usuarios presentes no sistema " << endl;
        for(auto& it : usuarios){
            cout << "["<<it.first << "]"<<endl;
        }
    }

    void Agenda::cadastro(string id, string senha){
        auto usuario = usuarios.find(id);
        if(usuario == usuarios.end()){
            usuarios.insert(make_pair(id, Usuario(id, senha)));
            cout << endl << "Contato adicionado com sucesso." << endl;
        }else
            cout << endl << "fail: O contato ja existe." << endl;
    }

    void Agenda::login(string id, string senha){
        for(auto &it : usuarios){
            if(it.first == id)
                logado(id, senha);
        }
    }

    void menu(){
                cout << "Escrever Nota: addNote _titulo _texto" << endl;
                cout << "Remover Nota: rmNote _titulo" << endl;
                cout << "Mudar Senha: changePass _newPass" << endl;
                cout << "Ver Notas: showNotes" << endl;
                cout << "Menu: menu" << endl;
    }

    void Agenda::mudarSenha(string id, string novaSenha){
        map<string, string> *str = usuarios.at(id).getNotas();
        map<string, string> txts = *str;
        usuarios.erase(id);

        usuarios.insert(make_pair(id, Usuario(id, novaSenha)));
        usuarios.at(id).notas = txts;
    }

    void Agenda::escreverNota(string id, string titulo, string nota){

        auto it = usuarios.at(id).notas.find(titulo);
        if(it == usuarios.at(id).notas.end()){
            usuarios.at(id).setNotas(titulo, nota);
            cout << endl << "Nota adicionada com sucesso." << endl;
        }else{
            cout << endl << "fail: Titulo de nota existente." << endl;
        }
    }

    void Agenda::showNotas(string id){
        map<string, string> *str = usuarios.at(id).getNotas();
        for(auto it : *str){
            cout << it.first << " | " << it.second << endl;
        }
    }

    void Agenda::removerNota(string id, string titulo){
        usuarios.at(id).removerNota(titulo);
    }

    void Agenda::logado(string id, string senha){
        if(usuarios.at(id).getSenha() == senha){
            cout << "Vc logou no Sistema." << endl << endl;
            cout << usuarios.at(id).getUsuario() << " - " << usuarios.at(id).getSenha() << endl;
            string escolha, texto, titulo;
            menu();
            while(true){
                    cin >> escolha;
                if(escolha == "menu"){
                    menu();
                }else if(escolha == "addNote"){
                    cin >> titulo;
                    getline(cin, texto);
                    escreverNota(id, titulo, texto);
                }else if(escolha == "rmNote"){
                    cin >> titulo;
                    removerNota(id, titulo);
                }else if(escolha == "changePass"){
                    cin >> texto;
                    mudarSenha(id, texto);
                }else if(escolha == "showNotes"){
                    showNotas(id);
                }else if(escolha == "logout"){
                    break;
                }
            }
        }else{
            cout << "Usuario ou Senha invalido." << endl << endl;
        }
    }
#endif // AGENDA_H_INCLUDED
