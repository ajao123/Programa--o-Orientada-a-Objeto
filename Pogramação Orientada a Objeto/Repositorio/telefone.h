#include <sstream>
#include <string.h>

#ifndef TELEFONE_H_INCLUDED
#define TELEFONE_H_INCLUDED

using namespace std;

class telefone{
    public:

        string operadora;
        string fone;
        string dados;

        telefone(string opr, string tf);
        string toString();
};

telefone::telefone(string opr = "", string tf = ""){
            this->operadora = opr;
            this->fone = tf;
            stringstream ss;
            ss << operadora << ":" <<  fone;
            this->dados = ss.str();
}

 string telefone::toString(){

    stringstream ss;
    ss << dados;
    return ss.str();
}
#endif // TELEFONE_H_INCLUDED
