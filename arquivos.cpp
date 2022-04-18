#include "Funcionario.h" 
#include "Arquivo.h"
#include <iostream>
#include <fstream> //biblioteca de arquivos
#include <string> //biblioteca de manipulacao de strings
#include <cstdlib> //biblioteco do system("cls"), que limpa o console

using namespace std;

string completaNumero(string numero){ //funcao que completa o numero caso o usuario digite 
    if(numero.size() == 3){           //um numero com menos de 4 digitos
        numero = "0" + numero;
    } else if(numero.size() == 2){
        numero = "00" + numero;
    } else if(numero.size() == 1){
        numero = "000" + numero;
    }

    return numero;
}

int main(){
    int i, j, k, escolha, count;
    char c;

    Funcionario funcionario;

    Arquivo arquivo;

    string nome, ocupacao, numero;

    arquivo.criaArquivo();

    arquivo.imprimeArquivo();

    cout << "\nDeseja deletar, adicionar ou buscar algum funcionario? [s/n]" << endl;

    cin >> c; //verifica a escolha
    getchar();
    
    k = 1;
    while(k){
        switch(c){
            case 's':
                k = 0;
                break;
            case 'n':
                return 0;
            default:
                system("cls");

                arquivo.imprimeArquivo();

                cout << "\nDeseja deletar, adicionar ou buscar algum funcionario? [s/n]" << endl;
                cout << "Opcao digitada invalida!" << endl;
                cin >> c;
                getchar();
        }
    }

    system("cls");

    arquivo.imprimeArquivo();
    
    cout << "\nDeseja deletar(1), adicionar(2) ou buscar(3)?" << endl;


    k = 1;
    while(k){
        cin >> escolha; //verifica se o usuario quer deletar, adicionar ou buscar
        getchar();

        switch(escolha){
            case 2:  //caso de adicionar
                system("cls");

                arquivo.imprimeArquivo();

                cout << "\nQual o codigo do novo funcionario?" << endl;

                while(1){           //verifica se o codigo digitado ja existe
                    count = 0;

                    while(1){
                        getline(cin, numero);

                        if(numero.size() > 4){
                            system("cls");

                            arquivo.imprimeArquivo();

                            cout << "\nO codigo deve ter 4 digitos! Tente novamente" << endl;
                        } else if(numero.size() == 4){
                            break;
                        } else {
                            numero = completaNumero(numero);
                            break;
                        }
                    }

                    for(i = 0; i < 100; i++){
                        arquivo.stringToCode(i);

                        if(numero == arquivo.linhaAux){  
                            system("cls");

                            arquivo.imprimeArquivo();

                            cout << "\nCodigo ja existente. Tente novamente" << endl;
                            count++;
                            break;
                        }
                    }

                    if(count == 0){ //se nenhum codigo igual for encontrado, o programa segue
                        break;
                    }
                }

                system("cls");

                arquivo.imprimeArquivo();

                cout << "\nQual o nome do novo funcionario?" << endl;
                getline(cin, nome);

                system("cls");

                arquivo.imprimeArquivo();

                cout << "\nQual sera sua ocupacao" << endl;
                getline(cin, ocupacao);

                for(i = 0; i < 100; i++){
                    if(arquivo.linhas[i] == ""){
                        arquivo.linhas[i] = numero + " - " + nome + " - " + ocupacao;
                        break;
                    }
                }

                arquivo.arquivo.open("funcionarios.txt", ios::out);
                arquivo.arquivo.clear();
                arquivo.arquivo.close();

                arquivo.arquivo.open("funcionarios.txt", ios::out | ios::app);

                for(i = 0; i < 100; i++){
                    if(arquivo.linhas[i] != ""){
                        arquivo.arquivo << arquivo.linhas[i] << endl;
                    }
                }

                arquivo.arquivo.close();

                system("cls");

                arquivo.imprimeArquivo();

                break;
            case 1:  //caso de deletar
                system("cls");

                arquivo.imprimeArquivo();

                cout << "\nQual o codigo da pessoa a ser deletada?" << endl;
                
                getline(cin, numero);

                if(numero.size() < 4){
                    numero = completaNumero(numero);    
                }

                for(i = 0; i < 100; i++){
                    arquivo.stringToCode(i);

                    if(arquivo.linhaAux == numero){
                        arquivo.linhas[i] = "";

                        arquivo.arquivo.open("funcionarios.txt", ios::out);
                        arquivo.arquivo.clear();
                        arquivo.arquivo.close();

                        arquivo.arquivo.open("funcionarios.txt", ios::out | ios::app);

                        for(i = 0; i < 100; i++){
                            if(arquivo.linhas[i] != ""){
                                arquivo.arquivo << arquivo.linhas[i] << endl;
                            }
                        }

                        arquivo.arquivo.close();
                    }
                }

                system("cls");

                arquivo.imprimeArquivo();

                break;
            case 0:  //caso para sair do programa
                k = 0;
                break;
            case 3: //caso para buscar um funcionario
                system("cls");

                arquivo.imprimeArquivo();

                cout << "\nDigite o codigo de algum funcionario:" << endl;

                getline(cin, numero);

                if(numero.size() < 4){
                    numero = completaNumero(numero);    
                }

                for(i = 0; i < 100; i++){
                    arquivo.stringToCode(i);

                    if(arquivo.linhaAux == numero){
                        funcionario.setCodigo(numero);

                        nome = arquivo.linhas[i];
                        nome.erase(0, 7);
                        for(j = 0; j < nome.size(); j++){
                            if(nome[j] == '-'){
                                nome.erase(j-1, nome.size());
                            }
                        }

                        funcionario.setNome(nome);

                        ocupacao = arquivo.linhas[i];
                        ocupacao.erase(0, j+8);

                        funcionario.setOcupacao(ocupacao);

                        break;
                    }

                    arquivo.linhaAux = "";
                }

                system("cls");

                arquivo.imprimeArquivo();

                cout << "\nCodigo: " << numero << "\nNome: " << funcionario.getNome() << "\nOcupacao: " << funcionario.getOcupacao() << endl;

                funcionario = Funcionario();

                break;
            default:  //caso para uma escolha invalida
                system("cls");

                arquivo.imprimeArquivo();

                cout << "\nDeseja deletar(1), adicionar(2) ou buscar(3)?" << endl;
                cout << "Opcao digitada invalida!" << endl;
                continue;
        }

        cout << "\nDeseja deletar(1), adicionar(2), buscar(3) ou sair(0)?" << endl;
    }

    system("cls");

    arquivo.imprimeArquivo(); 

    cout << "\n";

    return 0;
}