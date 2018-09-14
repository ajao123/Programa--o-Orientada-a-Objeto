#ifndef CLASSECARRO_H
#define CLASSECARRO_H
#include<iostream>
#include<stdio.h>

class ClasseCarro
{
    public:

        float combustivel_litros;
        int numero_passageiros;


        ClasseCarro(float combustivel_litros, int numero_passageiros);

        void entrar();
        void sair();
        void abastecer(float combustivel);
        void andar(int distancia);
};

    ClasseCarro::ClasseCarro(float combustivel_litros, int numero_passageiros){
        this->combustivel_litros = combustivel_litros;
        this->numero_passageiros = numero_passageiros;

    }

    void ClasseCarro::entrar(){

        if(this->numero_passageiros  < 2){
            this->numero_passageiros++;
            std::cout<<"\nUm passageiro entrou";
            std::cout<<"\nNumero de passageiros: "<<numero_passageiros;
        }else{
            std::cout<<"\nSem Vagas.";
        }

    }
    void ClasseCarro::sair(){

        if(this->numero_passageiros > 0){
            this->numero_passageiros--;
            std::cout<<"\nUm passageiro saiu.";
            std::cout<<"\nNumero de passageiros: "<<numero_passageiros;

        }else{
            std::cout<<"\nNão há passageiros.";
        }

    }
    void ClasseCarro::abastecer(float combustivel){

        if(this->combustivel_litros + combustivel <= 10){
            this->combustivel_litros+=combustivel;
            std::cout<<"\nAbastecimento de "<<combustivel<<" litros efetuado com sucesso.";
            std::cout<<"\nTanque: "<<this->combustivel_litros<<" litros.";
        }else{
            std::cout<<"O tanque nao suporta essa quantidade de combustível.";
        }

    }
    void ClasseCarro::andar(int distancia){

        if((distancia/10) <= this->combustivel_litros && this->numero_passageiros > 0){
            this->combustivel_litros-= (distancia/10);

           std::cout<<"\nCarro andou 10 KM.";
           std::cout<<"\nTanque: "<<combustivel_litros<<" litros.";
           std::cout<<"\nNumero de passageiros: "<<numero_passageiros;

        }else{

            if((distancia/10) > this->combustivel_litros){
                std::cout<<"Combustivel nao suporta a viagem, abasteca o carro.";
            }
            if(this->numero_passageiros <= 0){
                std::cout<<"Nao ha passageiros.";
            }
        }

    }
#endif // CLASSECARRO_H
