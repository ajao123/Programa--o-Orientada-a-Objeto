#ifndef OPERADORA_H
#define OPERADORA_H
#include <sstream>
#include <string.h>

using namespace std;

class operadora
{
    public:
        string opr;
        string tf;
        string dados;



        operadora(string opr, string tf);
        string toString();

};

        operadora::operadora(string opr = "", string tf = ""){
            this->opr = opr;
            this->tf = tf;
            stringstream ss;
            ss << opr << " : " <<  tf;
            this->dados = ss.str();
        }

        string operadora::toString(){
            stringstream ss;

            ss << dados;

            return ss.str();
        }



#endif // OPERADORA_H
