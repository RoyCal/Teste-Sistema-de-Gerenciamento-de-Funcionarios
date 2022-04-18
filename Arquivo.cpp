#include "Arquivo.h"

void Arquivo::imprimeArquivo(){
    int i;

    arquivo.open("funcionarios.txt", ios::in); //abre o arquivo
    
    i = 0;                              //Colocando todas as linhas do arquivo em um vetor de strings
    while(getline(arquivo, linhas[i])){
        i++;
    }

    arquivo.close();

    for(i = 0; i < 100; i++){         //imprimindo as linhas
        if(linhas[i] != ""){
            cout << linhas[i] << endl;
        }
    }
}

void Arquivo::criaArquivo(){
    arquivo.open("funcionarios.txt", ios::in); //abre o arquivo

    if(arquivo.is_open() == false){                 ///////////////////////////////////////////////
        arquivo.open("funcionarios.txt", ios::out); //se o arquivo nao existe, ele cria o arquivo//
        arquivo.close();                            ///////////////////////////////////////////////
    }

    arquivo.close();
}

void Arquivo::stringToCode(int i){
    if(linhas[i] != ""){
        linhaAux = linhas[i];
        linhaAux.erase(4, linhaAux.size());
    }
}