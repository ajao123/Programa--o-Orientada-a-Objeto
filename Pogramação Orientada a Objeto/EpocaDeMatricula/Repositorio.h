#ifndef REPOSITORIO_H_INCLUDED
#define REPOSITORIO_H_INCLUDED
#include <iostream>
#include <map>
#include "Alunos.h"

using namespace std;

template<typename K, typename V>
class Repositorio{

public:
    map<K,V> rep;
    string _typename = "";

    void add(K k, V v){
        if(rep.count(k) == 0){
            rep.insert(make_pair(k,v));
        }else{
             cout << _typename << " " << k << " ja existe." << endl;
        }
    }
    void rm(K k){
        auto it = rep.find(k);
        if(it == rep.end()){
             cout << _typename << " " << k << " nao existe." << endl;
        }else{
            rep.erase(it);
        }
    }
    bool has(K k){
        if(rep.count(k) == 0)
            return false;
        else
            return true;

    }
    vector<K> getKeys(){
        vector<K> keys;
        for(auto& it : rep){
            keys.push_back(it.first);
        }
        return keys;
    }
    vector<V> getValues(){
        vector<V> values;
        for(auto& it : rep){
            values.push_back(it.second);
        }
        return values;
    }
    V& get(K k){
        auto it = rep.find(k);
        if(it == rep.end())
            cout << _typename << " " << k << " nao existe." << endl;
        else
            return it->second;
    }
};

#endif // REPOSITORIO_H_INCLUDED
