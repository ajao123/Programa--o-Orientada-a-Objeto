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
#include "Movimento.h"

using namespace std;

class Registro{
    public:
        vector<Passageiro*> cadastramento;
        vector<Movimento*> movimentos;

        void RegistroEmbarcarPessoa(Passageiro *passageiro){
                if(passageiroPessoa *pPessoa = dynamic_cast<passageiroPessoa*>(passageiro))
                    cadastramento.push_back(pPessoa);
        }
        void RegistroEmbarcarCarga(Passageiro *passageiro){
            if(passageiroCarga *pCarga = dynamic_cast<passageiroCarga*>(passageiro))
                cadastramento.push_back(pCarga);
        }

        void adicionarMovimentacao(string id, int mov){

            string nome;
            movimentos.push_back(new Movimento(id,mov));

        }

        string cadastro(){
            stringstream ss;
            ss << "Cadastro" << endl << endl;
            for(auto *it : cadastramento){
                if(it != nullptr){
                    ss << it->getId() << endl;
                }
            }
            return ss.str();
        }
        string movimentacao(){
            stringstream ss;
                ss << "Movimentacao" << endl << endl;
                for(auto *it : movimentos){
                    ss << it->toString() << endl;
                }
            return ss.str();
        }
};

#endif // REGISTRO_H_INCLUDED
