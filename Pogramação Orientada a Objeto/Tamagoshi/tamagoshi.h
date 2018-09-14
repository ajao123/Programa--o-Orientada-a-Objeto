#ifndef TAMAGOSHI_H
#define TAMAGOSHI_H
#include<iostream>
#include<stdio.h>
#include<string.h>
#include <sstream>

using namespace std;

class tamagoshi
{
    public:

        int idade;
        bool vivo;
        int diamante;

        int energia;
        int limpeza;
        int fome;

        int energia_MAX;
        int fome_MAX;
        int limpeza_MAX;




        tamagoshi(int energia_MAX, int fome_MAX, int limpeza_MAX);
        void comer();
        void dormir();

        void brincar();
        void show();
        void limpar();
        void morreu();
};

    tamagoshi::tamagoshi(int energia_MAX=0, int fome_MAX=0, int limpeza_MAX=0){

        this->idade = 0;
        this->vivo = true;
        this->energia = energia_MAX;
        this->diamante = 0;
        this->limpeza = limpeza_MAX;
        this->fome = fome_MAX;

        this->energia_MAX = energia_MAX;
        this->fome_MAX = fome_MAX;
        this->limpeza_MAX = limpeza_MAX;

    }

    void tamagoshi::comer(){

        if(this->vivo == true){

            if((this->energia-1) <= 0){
                this->energia = 0;
                this->vivo = false;
            }else{
                this->energia--;
            }

            if((this->limpeza-2) <= 0){
                this->limpeza = 0;
                this->vivo = false;
            }else{
                this->limpeza -= 2;
            }

            if((this->fome+4) > fome_MAX){
                this->fome = fome_MAX;
            }else{
                this->fome+=4;
            }
            this->idade++;
            morreu();
        }else{
            cout << "fail:Seu pet esta morto." << endl;
        }

        }

    void tamagoshi::dormir(){

        if(this->vivo == true){
            if((this->energia_MAX - this->energia) >= 5){

            if((this->fome-1) <= 0 ){
                    this->fome = 0;
                    this->vivo = false;
                }else{
                    this->fome--;
                }

                this->idade+=(this->energia_MAX - this->energia);
                this->energia = this->energia_MAX;

            }else{
                cout << "\n fail:Seu pet esta sem sono." << endl;
            }
            morreu();
        }else{
            cout << "fail:Seu pet esta morto." << endl;
        }

    }

    void tamagoshi::brincar(){

        if(this->vivo == true){

                if((this->energia-2) <= 0 ){
                    this->energia = 0;
                    this->vivo = false;
                }else{
                    this->energia-=2;
                }

                if((this->fome-1) <= 0 ){
                    this->fome = 0;
                    this->vivo = false;
                }else{
                    this->fome--;
                }

                if((this->limpeza-3) <= 0 ){
                    this->limpeza = 0;
                    this->vivo = false;

                }else{
                    this->limpeza-=3;
                }
                this->idade++;
                this->diamante++;
                morreu();
        }else{
            cout << "fail:Seu pet esta morto." << endl;
        }


    }
    void tamagoshi::show(){


        cout << "\n E: " << this->energia << "|" << this->energia_MAX << ", H: " << this->fome <<
        " | " << this->fome_MAX << ", C: " << this->limpeza << " | " << this->limpeza_MAX
             << ", D: "<<this->diamante << ", A: " << this->idade << endl;
    }

    void tamagoshi::limpar(){
        if(this->vivo == true ){

            if((this->fome-1) <= 0 ){
                    this->fome = 0;
                    this->vivo = false;
                }else{
                    this->fome--;
                }

            if((this->energia-3) <= 0 ){
                    this->energia = 0;
                    this->vivo = false;
                }else{
                    this->energia-=3;
                }
            this->idade+=2;
            this->limpeza=this->limpeza_MAX;
            morreu();
        }else{
                cout << "fail:Seu pet esta morto." << endl;
        }

    }
#endif // TAMAGOSHI_H
void tamagoshi::morreu(){
    if(this->fome > 0 && this->energia > 0 && this->limpeza > 0){

        if(this->fome <=3)
        cout << "\n Alert:Seu pet esta com fome." << endl;

        if(this->energia <=3)
            cout << "\n Alert:Seu pet esta cansado." << endl;

        if(this->limpeza <=3)
        cout << "\n Alert:Seu pet esta sujo." << endl;

    }else{

        if(this->fome == 0)
            cout << "\n fail:Seu pet morreu de fome." << endl;

        if(this->energia == 0)
            cout << "\n fail:Seu pet morreu de fraqueza." << endl;

        if(this->limpeza == 0)
            cout << "\n fail:Seu pet morreu de sujeira." << endl;
    }





}
