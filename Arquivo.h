#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Arquivo{
    public:
        void criaArquivo();

        void imprimeArquivo();

        void stringToCode(int i);

        fstream arquivo;
        string linhas[100], linhaAux;
};