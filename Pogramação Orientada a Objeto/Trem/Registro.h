#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include "Vagao.h"
#include "vagaoPessoa.h"
#include "vagaoCarga.h"
#include "Passageiro.h"
#include "passageiroPessoa.h"
#include "passageiroCarga.h"

using namespace std;

class Registro{
    public:
        vector<string> cadastramento;
        vector<string> movimentacao;

        void cadastrar(string cadastro){
            this->cadastramento.push_back(cadastro);
        }
        void movimentar(string movimento){
            this->movimentacao.push_back(movimento);
        }
        string cadastrados(){
            stringstream ss;
            ss << "  Cadastro   " << endl;
            for(auto it : cadastramento){
                ss << it << endl;
            }
            return ss.str();
        }
        string movimentados(){
            stringstream ss;
            ss << "  Movimentacao   " << endl;
            for(auto it : movimentacao){
                ss << it << endl;
            }
            return ss.str();
        }
};

#endif // REGISTRO_H_INCLUDED
