#ifndef TRANSACAO_H_INCLUDED
#define TRANSACAO_H_INCLUDED

#include <string.h>
#include<sstream>
#include <vector>
using namespace std;

class transacao{

    public:
      int id;
      string id_cliente;
      int valor;
      string toString();
      transacao(int id, string id_cliente, int valor);
};

    transacao::transacao(int id, string id_cliente, int valor = 0){
        this->id = id;
        this->id_cliente = id_cliente;
        this->valor = valor;
    }

    string transacao::toString(){
        stringstream  ss;
        ss <<"id: " <<id << " [" << id_cliente <<" "<< valor <<"]";
        return ss.str();
    }


#endif // CLIENTE_H_INCLUDED

