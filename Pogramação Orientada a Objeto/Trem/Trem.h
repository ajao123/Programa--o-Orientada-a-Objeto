#ifndef TREM_H_INCLUDED
#define TREM_H_INCLUDED

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
#include "Registro.h"

using namespace std;

class Trem{
    public:
        int maxVagoes;
        vector<Vagao*> vagoes;
        Registro registro;

        Trem(int maxVagoes = 0){
            this->maxVagoes = maxVagoes;
            menu();
            interface();
        }
        string menu(){
            stringstream ss;
            ss << "Adicionar Vagao de Pessoas: nwvp Numero de Pessoas" << endl;
            ss << "Adicionar Vagao de Cargas: nwvc Peso" << endl;
            ss << "Adicionar Pessoa: addp Nome" << endl;
            ss << "Adicionar Carga: addc Nome Peso" << endl;
            ss << "Remover Pessoa: rmp Nome" << endl;
            ss << "Remover Carga: rmc Nome" << endl;
            ss << "Mostrar Vagoes de Cargas: showc" << endl;
            ss << "Mostrar Vagoes de Pessoas: showp " << endl;
            ss << "Registro de Passageiros: registro" << endl;
            ss << "Movimentacao dos Passageiros: movimento" << endl;
            return ss.str();
        }
        void interface(){
            string escolha, nome;
            int numero;
            float peso;
            menu();
            while(1){
                cin >> escolha;
                if(escolha == "menu"){
                    cout << menu() << endl;
                }else if(escolha == "nwvc"){
                    cin >> peso;
                    if((vagoes.size()+1) <= maxVagoes){
                        vagoes.push_back(new vagaoCarga(peso));
                    }else{
                        cout << "fail: Trem chegou ao seu limite de vagoes." << endl;
                    }
                }else if(escolha == "nwvp"){
                        cin >> numero;
                    if((vagoes.size()+1) <= maxVagoes){
                        vagoes.push_back(new vagaoPessoa(numero));
                    }else{
                        cout << "fail: Trem chegou ao seu limite de vagoes." << endl;
                    }
                }else if(escolha == "addp"){
                    cin >> nome;

                    for(Vagao *vagao : vagoes){
                        if(vagaoPessoa *vPessoa = dynamic_cast<vagaoPessoa*>(vagao)){
                            if(vPessoa->Exists(nome)){
                                cout << "fail: Pessoa ja esta no trem." << endl;
                                break;
                            }
                            if(vPessoa->Embarcar(new passageiroPessoa(nome))){
                                registro.cadastrar(nome);
                                registro.movimentar(nome + " IN");
                                break;
                            }
                        }
                    }
                }else if(escolha == "addc"){
                    cin >> nome;
                    cin >> peso;

                    for(Vagao *vagao : vagoes){
                        if(vagaoCarga *vCarga = dynamic_cast<vagaoCarga*>(vagao)){
                            if(vCarga->Exists(nome)){
                                cout << "fail: Carga ja esta no trem." << endl;
                                break;
                            }
                            if(vCarga->Embarcar(new passageiroCarga(nome, peso))){
                                registro.cadastrar(nome + "  Peso: "+to_string(peso));
                                registro.movimentar(nome + " IN");
                                break;
                            }
                        }
                    }


                }else if(escolha == "showp"){
                    for(Vagao *vagao : vagoes){
                        if(vagaoPessoa *vPessoa = dynamic_cast<vagaoPessoa*>(vagao)){
                            cout << endl <<vPessoa->toString() << endl;
                        }
                    }
                }else if(escolha == "showc"){
                    for(Vagao *vagao : vagoes){
                        if(vagaoCarga *vCarga = dynamic_cast<vagaoCarga*>(vagao)){
                            cout << endl <<vCarga->toString() << endl;
                        }
                        cout << endl;
                    }
                }else if(escolha == "rmp"){

                    cin >> nome;
                    for(Vagao *vagao : vagoes){
                        if(vagaoPessoa *vPessoa = dynamic_cast<vagaoPessoa*>(vagao)){
                            if(vPessoa->Desembarcar(nome)){
                                registro.movimentar(nome + " OUT");
                                break;
                            }
                        }
                    }
                }else if(escolha == "rmc"){
                    cin >> nome;
                    for(Vagao *vagao : vagoes){
                        if(vagaoCarga *vCarga = dynamic_cast<vagaoCarga*>(vagao)){
                            if(vCarga->Desembarcar(nome)){
                                registro.movimentar(nome + " OUT");
                                break;
                            }
                        }
                    }
                }else if(escolha == "registro"){
                    cout << registro.cadastrados() << endl;
                }else if(escolha == "movimento"){
                    cout << registro.movimentados() << endl;
                }
            }
        }

};


#endif // TREM_H_INCLUDED
