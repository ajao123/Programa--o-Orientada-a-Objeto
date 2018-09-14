#ifndef TOPIC_H
#define TOPIC_H
#include "passageiro.h"
#include <vector>
#include<iostream>
#include<stdio.h>
class topic
{
    public:
        vector<passageiro*> cadeira;
        int cadeirasPrioritarias;

        topic(int qtd_cadeiras, int cadeirasPrioritarias);

        bool inserir(passageiro *psg);
        passageiro* remover(string nome);

        void show();
};

        topic::topic(int qtd_cadeiras = 0, int cadeirasPrioritarias = 0){

            this->cadeirasPrioritarias = cadeirasPrioritarias;
            for(int i = 0; i < qtd_cadeiras; i++){
                cadeira.push_back(nullptr);
            }
            show();
        }

        bool topic::inserir(passageiro *psg){

            for(int i = 0; i < cadeira.size(); i++){
                if(cadeira[i] != nullptr){
                    if(cadeira[i]->nome == psg->nome){

                        cout << "\n Passageiro ja esta no onibus. \n";
                        return false;
                    }
                }
            }

            if(psg->idade < 60){

             for(int i = cadeirasPrioritarias; i < cadeira.size(); i++){
                    if(cadeira[i] == nullptr){
                        cadeira[i] = psg;

                        return true;
                    }
                }

            for(int i = 0; i < cadeirasPrioritarias; i++){
                if(cadeira[i] == nullptr){
                        cadeira[i] = psg;

                        return true;
                    }
            }
                cout << "\n Onibus lotado.\n ";

                return false;
        }else{
            if(cadeira[cadeirasPrioritarias - 1] != nullptr){

               for(int i = cadeirasPrioritarias; i < cadeira.size(); i++){
                    if(cadeira[i] == nullptr){
                        cadeira[i] = psg;

                        return true;
                    }
                }
                cout << "\n Onibus lotado.\n ";

                return false;

            }else{

            for(int i = 0; i < cadeira.size(); i++){

                    if(cadeira[i] == nullptr){
                        cadeira[i] = psg;

                        return true;
                    }
            }
            cout << "\n Onibus lotado.\n ";

                return false;
            }


        }

        }



        void topic::show(){
            stringstream saida;

            for(int i = 0; i < cadeira.size(); i++){

                saida << (i < cadeirasPrioritarias ? '@' : '=');

                if(cadeira[i] != nullptr){
                    saida << cadeira[i]->toString();
                }else{
                    saida << "";
                }
                //saida << (cadeira[i] == nullptr ? cadeira[i].toString() : "");

                saida << " ";

            }
             cout << saida.str();
        }

        passageiro *topic::remover(string nome){

            for(int i = 0; i < cadeira.size(); i++){
            if(cadeira[i] != nullptr){

                if(cadeira[i]->nome == nome){

                    auto *pass = cadeira[i];
                    cadeira[i] = nullptr;

                    return pass;

                }
            }

            }
            return nullptr;

        }
#endif // TOPIC_H
