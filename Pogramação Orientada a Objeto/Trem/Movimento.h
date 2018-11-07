#ifndef MOVIMENTO_H_INCLUDED
#define MOVIMENTO_H_INCLUDED
#include <iostream>
#include <sstream>
using namespace std;

class Movimento{
public:

    string passageiroId;
    string dir;

    Movimento(string passageiroId, int mov){
        if(mov == 0)
            dir = "in";
        else
            dir = "out";
        this->passageiroId = passageiroId;
    }
    string toString(){
        stringstream ss;
        ss << passageiroId << " " << dir << endl;
        return ss.str();
    }
    string getId(){
        return passageiroId;
    }
};


#endif // MOVIMENTO_H_INCLUDED
