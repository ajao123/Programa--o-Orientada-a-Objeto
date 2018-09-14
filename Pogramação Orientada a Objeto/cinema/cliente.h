#ifndef CLIENTE_H
#define CLIENTE_H
#include <stdlib.h>
#include <sstream>
using namespace std;
class cliente
{
public:
    string id;
    string fone;
    bool existe;

    cliente(string id, string fone, bool existe);
    string toString();
};
    cliente::cliente(string id  = "fulano", string fone = "0000", bool existe = true){
        this->id = id;
        this->fone = fone;
        this->existe = existe;
    }

    string cliente::toString(){

        stringstream ss;

        if(!this->existe){
            ss << "-";
        }else{
            ss << this->id << " : " << this->fone;
        }
        return ss.str();
    }


#endif // CLIENTE_H
