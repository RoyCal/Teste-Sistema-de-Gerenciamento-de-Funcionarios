#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class Arquivo{
    public:
        void criaArquivo();
        
        void imprimeArquivo();

        fstream arquivo;
        string linhas[100];
};