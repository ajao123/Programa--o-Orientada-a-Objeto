#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED
#include <iostream>
#include <sstream>
#include "Usuario.h"
#include "Tweet.h"
#include "Repositorio.h"
#include <vector>
using namespace std;

class Controlador{
public:
    int idTwitter;
    Repositorio<string, Usuario> usuarios;
    Repositorio<int, Tweet> tweets;

    Controlador(){
        this->idTwitter = 0;
    }

    string menu(){
        stringstream ss;
        ss << "Adicionar usuario: addUser Username" << endl;
        ss << "Mostrar usuarios: showUsers" << endl;
        ss << "Adicionar Twitter: twittar nome twittada" << endl;
        ss << "Mostrar Twitters: showTwetts" << endl;
        ss << "Mostrar usuarios: showUsers" << endl;
        ss << "Mostrar twetts de um usuario: myTwetts nome" << endl;
        ss << "Seguir outro Usuario: Seguir Usuario1 Usuario2" << endl;
        ss << "Mostrar Seguidores: showSeguidores Usuario" << endl;
        ss << "Mostrar Seguidos: showSeguidos Usuario" << endl;
        ss << "Mostrar Timeline: timeline Usuario" << endl;
        ss << "Mostrar Twetts nao lidos: unread Usuario" << endl;
        ss << "Dar Like: like Usuario idTwitter" << endl;
        ss << "Opcoes do Twitter: menu" << endl;
        ss << endl;
        return ss.str();
    }
    void Twitter(){
        cout << menu();
        string opcao;
        string nome, id, texto;
        int idt;
        while(1){
            cin >> opcao;
            if(opcao == "menu"){
              cout << menu() << endl;
            }else if(opcao == "addUser"){
                cin >> nome;
                if(usuarios.add(nome,Usuario(nome)))
                    cout << "Usuario adicionado com sucesso." << endl;
                else
                     cout << "fail: Id ja está em uso."<<endl;
            }else if(opcao == "showUsers"){
                cout << usuarios.show() << endl;
            }else if(opcao == "twittar"){

                cin >> nome;
                getline(cin, texto);
                if(usuarios.existe(nome)){
                    if(tweets.add(idTwitter, Tweet(idTwitter, texto, nome))){
                        Usuario *usuario = &usuarios.get(nome);
                        usuario->setMyTweets(new Tweet(idTwitter, texto, nome, 1));
                        cout << "Sucesso!!!" << endl;

                        for(auto *it : usuario->getSeguidores()){
                            it->setTimeline(new Tweet(idTwitter, texto, nome));
                        }

                        idTwitter++;
                    }else
                         cout << "fail: Id ja está em uso."<<endl;
                }else
                    cout << "fail: Usuario nao consta no sistema."<<endl;


            }else if(opcao == "showTwetts"){
                cout << tweets.show() << endl;
            }else if(opcao == "myTwetts"){
                cin >> nome;
                Usuario *usuario = &usuarios.get(nome);
                    cout << "Twetts "<< nome << endl;
                for(auto *it : usuario->getMyTwetts()){
                    cout << it->toString() << endl;
                }
            }else if(opcao == "Seguir"){
                cin >> nome;
                cin >> id;
                if(usuarios.existe(nome) && usuarios.existe(id) && nome != id){
                    Usuario *usuario1 = &usuarios.get(nome);
                    Usuario *usuario2 = &usuarios.get(id);
                    if(usuario2->setSeguidores(usuario1) && usuario1->setSeguidos(usuario2))
                        cout << "Sucess !!!" << endl;
                    else
                        cout << "fail: O usuario "<< nome <<" ja segue o usuario " << id << endl;
                }
            }else if(opcao == "showSeguidores"){
                cin >> nome;
                Usuario *usuario = &usuarios.get(nome);
                    cout << "Seguidores "<< nome << endl;
                for(auto *it : usuario->getSeguidores()){
                    cout << it->toString() << endl;
                }
            }else if(opcao == "showSeguidos"){
                cin >> nome;
                Usuario *usuario = &usuarios.get(nome);
                    cout << "Seguidos "<< nome << endl;
                for(auto *it : usuario->getSeguidos()){
                    cout << it->toString() << endl;
                }
            }else if(opcao == "timeline"){
                cin >> nome;
                vector<string> feed;
                Usuario *usuario = &usuarios.get(nome);
                cout << "Timeline - " << nome << endl << endl;
                for(auto& jt : tweets.getValues()){
                    if(usuario->IsSeguidor(jt.getUserName()) || jt.getUserName() == nome){
                        feed.push_back(jt.toString());
                    }
                }
                for(int i = feed.size()-1; i >= 0;  i--){
                    cout << feed[i] << endl;
                }
            }else if(opcao == "unread"){
                cin >> nome;
                cout << "Unread " << nome << endl;
                Usuario *usuario = &usuarios.get(nome);
                for(auto& it : usuario->getTimeline()){
                    if(!it->read()){
                        cout << it->toString() << endl;
                        it->reading();
                    }
                }
            }else if(opcao == "like"){
                cin >> nome;
                cin >> idt;
                if(tweets.existe(idt)){
                Tweet *tweet = &tweets.get(idt);
                Usuario *usuario = &usuarios.get(tweet->getUserName());
                if(usuario->IsSeguidores(nome)){
                    tweet->darLike(nome);
                    for(auto& it : usuario->getTimeline()){
                        if(it->getId() == idt)
                            it->darLike(nome);
                    }
                    for(auto& it : usuario->getMyTwetts()){
                        if(it->getId() == idt)
                            it->darLike(nome);
                    }
                }else
                    cout << "fail: Nao foi possivel dar like" << endl;

                }else
                    cout << "fail: Twitte nao existe." << endl;
            }
        }
    }

};

#endif // CONTROLADOR_H_INCLUDED
