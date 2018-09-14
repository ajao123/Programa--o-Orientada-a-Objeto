#include<iostream>
#include<stdio.h>
#include "ClasseCarro.h"
#include <string.h>
using namespace std;

int main(){

    ClasseCarro carro = ClasseCarro(0, 0);
    int i = 0, contador;
    float contador2;

    int esc = 0;
    int sec;

    char palavra[30];
    char primeira[30];
    char segunda[30];
    char terceira[30];
     char quarta[30];
    while(i == 0){

         cout<<"\nDigite subir\n";
         cout<<"Digite descer\n";
         cout<<"Digite fuel\n";
         cout<<"Digite drive\n";

         cin>>primeira;


            if(strcmp(primeira, "subir") == 0){
                esc = 1;
            }

            if(strcmp(primeira, "descer") == 0){
                esc = 2;

            }
            if(strcmp(primeira, "fuel") == 0){
                    cin>>segunda;
                    contador2 = atof(segunda);

                esc = 3;

            }

            if(strcmp(primeira, "drive") == 0){
                    cin>>segunda;
                    contador = atoi(segunda);
                esc = 4;

            }

         switch(esc){

         case 1:
            carro.entrar();
            break;

         case 2:
            carro.sair();
            break;

         case 3:
            carro.abastecer(contador2);
            break;

         case 4:
            carro.andar(contador);
            break;
         }
    }

}
