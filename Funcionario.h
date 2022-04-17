#pragma once 
#include <iostream>

using namespace std;

class Funcionario{
    private:
        string codigo;
        string nome;
        string ocupacao;

    public:
        Funcionario();
        
        void setCodigo(string x);
        string getCodigo();

        void setNome(string str);
        string getNome();

        void setOcupacao(string str);
        string getOcupacao();
};