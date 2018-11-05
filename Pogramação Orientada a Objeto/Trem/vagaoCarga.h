#ifndef VAGAOCARGA_H_INCLUDED
#define VAGAOCARGA_H_INCLUDED

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

class vagaoCarga : public Vagao{
    public:
        float pesoMaximo;
        int qtd = 0;
        vector<Passageiro*> pass;

        vagaoCarga(float pesoMaximo = 0.0){
            this->pesoMaximo = pesoMaximo;
        }

        float pesoAtual(){
            float pesado = 0.0;

            for(auto *it : pass){
                if(passageiroCarga *pCarga = dynamic_cast<passageiroCarga*>(it)){
                    if(pCarga != nullptr){
                        pesado += pCarga->pesoCarga();
                    }
                }
            }
            return pesado;
        }
        bool Embarcar(Passageiro *passageiro)
        {

            if(passageiroCarga *pCarga = dynamic_cast<passageiroCarga*>(passageiro)){

                if((pesoAtual()+pCarga->peso) <= pesoMaximo){
                        pass.push_back(pCarga);
                        return true;
                }else{
                    cout << "fail: Peso do vagao excedido." << endl;
                    return false;
                }
            }

            return false;
        }
        bool Desembarcar(string id){
            int i = 0;
            for(auto * passageiro : pass){
                if(passageiro != nullptr){
                    if(passageiro->getId() == id){
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
            ss <<  "Peso Maximo: "<<pesoMaximo  << "  -  Peso Disponivel: "<< (pesoMaximo-pesoAtual())<< endl;
            ss << " { ";
            for(auto *it : pass){
                ss << "[ ";
                if(it == nullptr)
                    ss << " - ";
                else
                    ss << it->toString() << " ";
                ss << " ] ";
            }
            ss <<" } ";
            return ss.str();
        }
};


#endif // VAGAOCARGA_H_INCLUDED
