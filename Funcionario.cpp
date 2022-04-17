#include "Funcionario.h"

Funcionario::Funcionario(){
    codigo = "404 not found";
    nome = "404 not found";
    ocupacao = "404 not found";
}

void Funcionario::setCodigo(string x){
    codigo = x;
}

string Funcionario::getCodigo(){
    return codigo;
}

void Funcionario::setNome(string str){
    nome = str;
}

string Funcionario::getNome(){
    return nome;
}

void Funcionario::setOcupacao(string str){
    ocupacao = str;
}

string Funcionario::getOcupacao(){
    return ocupacao;
}