#ifndef REPOSITORIO_H_INCLUDED
#define REPOSITORIO_H_INCLUDED
#include <sstream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

template <class T>
class repositorio{
    public:
        map<string, T> objetos;

        void add(string id, T t){
            auto res = objetos.find(id);
            if(res != objetos.end()){
                cout << endl <<"Id existente, o Objeto " << t.tipo << " nao pode ser adicionado." << endl << endl;
            }else{
                objetos.insert(make_pair(id, t));
                cout << endl << "Objeto " <<t.tipo << " adicionado com sucesso." << endl << endl;
            }
        }

        void show(){
            for(auto it:objetos){
                cout << endl <<it.second.toString() << endl;
            }
        }
        void remover(string id){

            auto res = objetos.find(id);
            if(res != objetos.end()){
                objetos.erase(id);
            }else{
                cout << endl <<"Id nao encontrado." << endl << endl;
            }
        }
        void getRepositorio(string id){

            auto res = objetos.find(id);
            if(res != objetos.end()){
                cout << endl << objetos.at(id).toString() << endl;
            }else{
                cout << endl <<"Id nao encontrado." << endl << endl;
            }
        }
};


#endif // REPOSITORIO_H_INCLUDED
