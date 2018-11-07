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
                                registro.adicionarMovimentacao(nome,0);
                                break;
                            }

                        }
                    }
                    registro.RegistroEmbarcarPessoa(new passageiroPessoa(nome));
                }else if(escolha == "addc"){
                    stringstream ss;
                    cin >> nome;
                    cin >> peso;
                    for(Vagao *vagao : vagoes){
                        if(vagaoCarga *vCarga = dynamic_cast<vagaoCarga*>(vagao)){
                            if(vCarga->Exists(nome)){
                                cout << "fail: Carga ja esta no trem." << endl;
                                break;
                            }
                            if(vCarga->Embarcar(new passageiroCarga(nome, peso))){

                                ss << nome << " " << peso << " ";
                                registro.adicionarMovimentacao(ss.str(),0);
                                break;
                            }
                        }
                    }
                    registro.RegistroEmbarcarCarga(new passageiroCarga(nome, peso));
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
                                registro.adicionarMovimentacao(nome,1);
                                break;
                            }
                        }
                    }
                }else if(escolha == "rmc"){
                    cin >> nome;
                    string valores;
                    for(Vagao *vagao : vagoes){

                        if(vagaoCarga *vCarga = dynamic_cast<vagaoCarga*>(vagao)){
                            valores = vCarga->existCarga(nome);
                            if(vCarga->Desembarcar(nome)){
                                registro.adicionarMovimentacao(valores, 1);
                                break;
                            }
                        }
                    }
                }else if(escolha == "registro"){
                    cout << registro.cadastro() << endl;
                }else if(escolha == "movimento"){
                    cout << registro.movimentacao() << endl;
                }
            }
        }

};


#endif // TREM_H_INCLUDED
