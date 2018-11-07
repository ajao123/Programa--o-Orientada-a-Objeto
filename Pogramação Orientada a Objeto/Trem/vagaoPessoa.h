#ifndef VAGAOPESSOA_H_INCLUDED
#define VAGAOPESSOA_H_INCLUDED

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include "Vagao.h"
#include "Passageiro.h"
#include "passageiroPessoa.h"
#include "passageiroCarga.h"

using namespace std;

class vagaoPessoa : public Vagao{
    public:
        vector<Passageiro*> pass;
        int qtdPassageiros;
        int maxPassageiros;
        vagaoPessoa(int maxPassageiros = 0):
        pass(maxPassageiros, nullptr)
        {
            this->maxPassageiros = maxPassageiros;
            qtdPassageiros = 0;
        }

        bool Embarcar(Passageiro *passageiro){
            int existe = 0;
            if(passageiroPessoa *pPessoa = dynamic_cast<passageiroPessoa*>(passageiro)){
                for(int i=0; i < pass.size(); i++){
                    if(pass[i] == nullptr){
                        pass[i] = pPessoa;
                        return true;
                    }
                }
            }
            return false;
        }
        bool Desembarcar(string id){
            int i = 0;
            for(auto * passageiro : pass){
                if(passageiro != nullptr){
                    if(passageiro->getId() == id){
                        passageiro = pass[i];
                        pass[i] = nullptr;
                        delete passageiro;
                        return true;
                    }
                }
                i++;
            }
            return false;
        }
        bool Exists(string id){
            for(auto *it : pass){
                if(it != nullptr){
                    if(it->getId() == id){
                        return true;
                    }
                }

            }
            return false;
        }
        string toString(){
            stringstream ss;
            ss << " { ";
            for(auto *it : pass){
                ss << "[ ";
                if(it == nullptr)
                    ss << " - ";
                else
                    ss << it->toString() << " ";
                ss << " ]";
            }
            ss << " } ";
            return ss.str();
        }
};

#endif // VAGAOPESSOA_H_INCLUDED
