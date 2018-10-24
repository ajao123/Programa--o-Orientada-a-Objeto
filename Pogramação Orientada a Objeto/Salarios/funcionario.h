#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

using namespace std;

class funcionario{

    public:
        string nome;
        int max_diarias;
        int qtd_diarias;
        double bonus;

        funcionario(string nome, int max_diarias){
            this->max_diarias = max_diarias;
            this->nome = nome;
            this->qtd_diarias = 0;
        }

        void setBonus(double bonus){
            this->bonus = bonus;
        }

        void addDiaria(){
            if((qtd_diarias+1) <= max_diarias){
                qtd_diarias++;
            }else{
                cout << endl <<"fail: limite de diarias atingido" << endl;
            }
        }

        double _calcSalario(){
                return (bonus + (qtd_diarias*100));
        }
};

#endif // FUNCIONARIO_H_INCLUDED
