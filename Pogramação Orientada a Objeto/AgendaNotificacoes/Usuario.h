#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include<map>

using namespace std;

class Usuario{

    private:

        string usuario;
        string senha;

    public:

        map<string, string> notas;

        string getUsuario();
        string getSenha();


        void setUsuario(string usuario);
        void setSenha(string senha);
        void setNotas(string titulo, string nota);

         map<string, string> *getNotas(){
            return &notas;
        }
        void removerNota(string nome){
            notas.erase(nome);
        }
        Usuario(string id, string senha);
};
    Usuario::Usuario(string id, string senha){
        Usuario::setUsuario(id);
        Usuario::setSenha(senha);
    }

    string Usuario::getUsuario(){
        return usuario;
    }
    string Usuario::getSenha(){
        return senha;
    }


    void Usuario::setUsuario(string usuario){
        this->usuario = usuario;
    }
    void Usuario::setSenha(string senha){
        this->senha = senha;
    }
    void Usuario::setNotas(string titulo, string nota){
        notas[titulo] = nota;
    }

#endif // USUARIO_H_INCLUDED
