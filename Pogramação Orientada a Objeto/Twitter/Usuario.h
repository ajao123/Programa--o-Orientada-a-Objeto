#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <iostream>
#include <sstream>
#include "Tweet.h"
#include <vector>

using namespace std;

class Usuario{
public:
    string userName;

    vector<Usuario*> seguidores;
    vector<Usuario*> seguidos;
    vector<Tweet*> timeline;
    vector<Tweet*> myTweets;

    Usuario(string userName){
        this->userName = userName;
    }
    string toString(){
        return userName;
    }

    bool setSeguidores(Usuario *usuario){
        for(auto& it : seguidores){
            if(it->toString() == usuario->toString())
                return false;
        }
        seguidores.push_back(usuario);
        return true;
    }
    bool setSeguidos(Usuario *usuario){
         for(auto& it : seguidos){
            if(it->toString() == usuario->toString())
                return false;
        }
        seguidos.push_back(usuario);
        return true;
    }
    void setTimeline(Tweet *tweet){
        timeline.push_back(tweet);
    }
    bool setMyTweets(Tweet *tweet){
        for(auto& it : myTweets){
            if(it->getId() == tweet->getId())
                return false;
        }
        myTweets.push_back(tweet);
        return true;
    }
    vector<Tweet*> getMyTwetts(){
        return myTweets;
    }
    vector<Usuario*> getSeguidores(){
        return seguidores;
    }
    vector<Usuario*> getSeguidos(){
        return seguidos;
    }
    vector<Tweet*> getTimeline(){
        return timeline;
    }
    bool IsSeguidor(string id){
        for(auto *it : seguidos){
            if(id == it->toString())
                return true;
        }
        return false;
    }
    bool IsSeguidores(string id){
        for(auto *it : seguidores){
            if(id == it->toString())
                return true;
        }
        return false;
    }
};


#endif // USUARIO_H_INCLUDED
