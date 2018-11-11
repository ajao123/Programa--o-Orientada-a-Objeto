#ifndef TWEET_H_INCLUDED
#define TWEET_H_INCLUDED
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Tweet{
public:
    string texto ,userName;
    bool lido;
    int id;
    vector<string> like;

    Tweet(int id = 0, string texto = "", string userName = "", bool lido = false){
        this->id = id;
        this->texto = texto;
        this->userName = userName;
        this->lido = lido;
    }
    bool read(){
        return lido;
    }
    void reading(){
        lido = true;
    }

    string getUserName(){
        return userName;
    }
    int getId(){
        return id;
    }

    bool darLike(string id){
       for(int i = 0; i < like.size(); i++){
            if(id == like[i])
                return false;
        }
        like.push_back(id);
        return true;
    }

    string toString(){
        stringstream ss;
        ss << id <<" " << userName <<": " << texto << " { ";
        for(int i = 0; i < like.size(); i++){
            ss << like[i] << " ";
        }
        ss << " } " << endl;
        return ss.str();
    }

};


#endif // TWEET_H_INCLUDED
