#ifndef REPOSITORIO_H_INCLUDED
#define REPOSITORIO_H_INCLUDED
#include <iostream>
#include <sstream>
#include "Usuario.h"
#include "Tweet.h"
#include <map>
using namespace std;

template<typename K, typename V>
class Repositorio{
public:

    string _name;
    map<K, V> repositorio;

    Repositorio(string name = ""){
        this->_name = name;
    }

    bool add(K k, V v){
        auto res = repositorio.find(k);
        if(res == repositorio.end()){
            repositorio.insert(make_pair(k, v));
            return true;
        }
        return false;
    }
    string show(){
        stringstream ss;
        for(auto& it : repositorio){
            ss << it.second.toString() << endl;
        }
        return ss.str();
    }
    bool existe(K k){
        auto res = repositorio.find(k);
        if(res == repositorio.end())
            return false;
        return true;
    }
    V& get(K k){
        auto it = repositorio.find(k);
        if(it == repositorio.end()){
            cout << "fail: "<< _name << " "<< k <<" nao existe." << endl;
        }
        return it->second;
    }
    vector<V> getValues(){
        vector<Tweet> twt;
        for(auto& it : repositorio){
            twt.push_back(it.second);
        }
        return twt;
    }
};

#endif // REPOSITORIO_H_INCLUDED
