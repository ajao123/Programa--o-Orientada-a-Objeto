#ifndef TOPIC_H
#define TOPIC_H
#include "passageiro.h"
#include <vector>
#include<iostream>
#include<stdio.h>
class topic
{
    public:
        vector<passageiro> cadeira;
        int qtd_cadeiras;
        int cadeirasPrioritarias;

        topic(int qtd_cadeiras, int cadeirasPrioritarias);
        bool inserir(passageiro psg);
        bool remover(string nome);
        void show();
};

        topic::topic(int qtd_cadeiras, int cadeirasPrioritarias){
            this->qtd_cadeiras = qtd_cadeiras;
            this->cadeirasPrioritarias = cadeirasPrioritarias;

            for(int i=0; i < qtd_cadeiras; i++){
                    if(i < cadeirasPrioritarias){
                        this->cadeira.push_back(passageiro("",0,true));
                    }else{
                         this->cadeira.push_back(passageiro("",0));
                    }
            }
            show();
        }

        void topic::show(){
            stringstream ss;
            int i = 0;
            ss << "[ ";
            for(passageiro nova : cadeira){

                    ss << "|";

                    if(nova.existe){

                    if(i < cadeirasPrioritarias)
                        ss << "@";
                    else
                        ss << "#";
                    }

                ss << nova.toString() << "|";
                i++;
            }
            ss << " ]";
            cout << ss.str();
        }

        bool topic::remover(string nome){
            int i = 0;
            for(passageiro psg : cadeira){
                if(psg.nome == nome){
                        if(i < cadeirasPrioritarias){
                            cadeira[i].prioridade = true;
                        }else{
                            cadeira[i].prioridade = false;
                        }
                    cadeira[i].nome = "";
                    cadeira[i].idade = 0;
                    cadeira[i].existe = false;
                    show();
                    return true;
                }

                i++;
            }

        show();
        cout << "\n Contato nao esta no sistema";
        return false;
        }

         bool topic::inserir(passageiro psg){


            for(int i = 0; i < cadeira.size(); i++){
                if(cadeira[i].nome == psg.nome){
                        show();
                        cout << "\n Passageiro ja esta no onibus. \n";
                        return false;
                }

            }

            if(psg.idade < 60){

             for(int i = cadeirasPrioritarias; i < cadeira.size(); i++){
                    if(!cadeira[i].existe){
                        cadeira[i] = psg;
                        show();
                        return true;
                    }
                }

            for(int i = 0; i < cadeirasPrioritarias; i++){
                if(!cadeira[i].existe){
                        cadeira[i] = psg;
                        show();
                        return true;
                    }
            }
                cout << "\n Onibus lotado.\n ";
                show();
                return false;
        }else{
            if(cadeira[cadeirasPrioritarias - 1].existe){

               for(int i = cadeirasPrioritarias; i < cadeira.size(); i++){
                    if(!cadeira[i].existe){
                        cadeira[i] = psg;
                        show();
                        return true;
                    }
                }
                cout << "\n Onibus lotado.\n ";
                 show();
                return false;

            }else{

            for(int i = 0; i < cadeira.size(); i++){

                    if(!cadeira[i].existe){
                        cadeira[i] = psg;
                        show();
                        return true;
                    }
            }
            cout << "\n Onibus lotado.\n ";
            show();
                return false;
            }


        }

        }
#endif // TOPIC_H
