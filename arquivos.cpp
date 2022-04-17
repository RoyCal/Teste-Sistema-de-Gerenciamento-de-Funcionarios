#include "Funcionario.h" 
#include <iostream>
#include <fstream> //biblioteca de arquivos
#include <string> //biblioteca de manipulacao de strings
#include <cstdlib> //biblioteco do system("cls"), que limpa o console

using namespace std;

string completaNumero(string numero){
    if(numero.size() == 3){
        numero = "0" + numero;
    } else if(numero.size() == 2){
        numero = "00" + numero;
    } else if(numero.size() == 1){
        numero = "000" + numero;
    }

    return numero;
}

int main(){
    int i, j, escolha, count;
    char c;

    Funcionario funcionario;

    fstream arquivo; //cria um stream chamada arquivo

    string linhas[100], nome, ocupacao, linhaAux, numero;

    arquivo.open("funcionarios.txt", ios::in); //abre o arquivo

    if(arquivo.is_open() == false){                 ///////////////////////////////////////////////
        arquivo.open("funcionarios.txt", ios::out); //se o arquivo nao existe, ele cria o arquivo//
        arquivo.close();                            ///////////////////////////////////////////////
    }
    
    i = 0;                              //Colocando todas as linhas do arquivo num vetor de strings
    while(getline(arquivo, linhas[i])){
        i++;
    }

    arquivo.close();

    for(i = 0; i < 100; i++){         //imprimindo as linhas
        if(linhas[i] != ""){
            cout << linhas[i] << endl;
        }
    }

    cout << "\nDeseja deletar, adicionar ou buscar algum funcionario? [s/n]" << endl;

    cin >> c; //verifica a escolha
    getchar();
    
    i = 1;
    while(i){
        switch(c){
            case 's':
                i = 0;
                break;
            case 'n':
                return 0;
            default:
                system("cls");

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        cout << linhas[i] << endl;
                    }
                }

                cout << "\nDeseja deletar, adicionar ou buscar algum funcionario? [s/n]" << endl;
                cout << "Opcao digitada invalida!" << endl;
                cin >> c;
                getchar();
        }
    }

    system("cls");

    for(i = 0; i < 100; i++){         //imprimindo as linhas
        if(linhas[i] != ""){
            cout << linhas[i] << endl;
        }
    }
    
    cout << "\nDeseja deletar(1), adicionar(2) ou buscar(3)?" << endl;


    i = 1;
    while(i){
        cin >> escolha; //verifica se o usuario quer deletar, adicionar ou buscar
        getchar();

        switch(escolha){
            case 2:  //caso de adicionar
                system("cls");

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        cout << linhas[i] << endl;
                    }
                }

                cout << "\nQual o codigo do novo funcionario?" << endl;

                while(1){           //verifica se o codigo digitado ja existe
                    count = 0;

                    while(1){
                        getline(cin, numero);

                        if(numero.size() > 4){
                            system("cls");

                            for(i = 0; i < 100; i++){
                                if(linhas[i] != ""){
                                    cout << linhas[i] << endl;
                                }
                            }

                            cout << "\nO codigo deve ter 4 digitos! Tente novamente" << endl;
                        } else if(numero.size() == 4){
                            break;
                        } else {
                            numero = completaNumero(numero);
                            break;
                        }
                    }

                    for(i = 0; i < 100; i++){
                        if(linhas[i] != ""){
                            linhaAux = linhas[i];
                            linhaAux.erase(4, linhaAux.size());
                        }

                        if(numero == linhaAux){  
                            system("cls");

                            for(i = 0; i < 100; i++){
                                if(linhas[i] != ""){
                                    cout << linhas[i] << endl;
                                }
                            }

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

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        cout << linhas[i] << endl;
                    }
                }

                cout << "\nQual o nome do novo funcionario?" << endl;
                getline(cin, nome);

                system("cls");

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        cout << linhas[i] << endl;
                    }
                }

                cout << "\nQual sera sua ocupacao" << endl;
                getline(cin, ocupacao);

                for(i = 0; i < 100; i++){
                    if(linhas[i] == ""){
                        linhas[i] = numero + " - " + nome + " - " + ocupacao;
                        break;
                    }
                }

                arquivo.open("funcionarios.txt", ios::out);
                arquivo.clear();
                arquivo.close();

                arquivo.open("funcionarios.txt", ios::out | ios::app);

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        arquivo << linhas[i] << endl;
                    }
                }

                arquivo.close();

                system("cls");

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        cout << linhas[i] << endl;
                    }
                }

                break;
            case 1:  //caso de deletar
                system("cls");

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        cout << linhas[i] << endl;
                    }
                }

                cout << "\nQual o codigo da pessoa a ser deletada?" << endl;
                
                getline(cin, numero);

                numero = completaNumero(numero);    

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        linhaAux = linhas[i];
                        linhaAux.erase(4, linhaAux.size());
                    }

                    if(linhaAux == numero){
                        linhas[i] = "";

                        arquivo.open("funcionarios.txt", ios::out);
                        arquivo.clear();
                        arquivo.close();

                        arquivo.open("funcionarios.txt", ios::out | ios::app);

                        for(i = 0; i < 100; i++){
                            if(linhas[i] != ""){
                                arquivo << linhas[i] << endl;
                            }
                        }

                        arquivo.close();
                    }
                }

                system("cls");

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        cout << linhas[i] << endl;
                    }
                }

                break;
            case 0:  //caso para sair do programa
                i = 0;
                break;
            case 3: //caso para buscar um funcionario
                system("cls");

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        cout << linhas[i] << endl;
                    }
                }

                cout << "\nDigite o codigo de algum funcionario:" << endl;

                getline(cin, numero);

                numero = completaNumero(numero);

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        linhaAux = linhas[i];
                        linhaAux.erase(4, linhaAux.size());
                    }

                    if(linhaAux == numero){
                        funcionario.setCodigo(numero);

                        nome = linhas[i];
                        nome.erase(0, 7);
                        for(j = 0; j < nome.size(); j++){
                            if(nome[j] == '-'){
                                nome.erase(j-1, nome.size());
                            }
                        }

                        funcionario.setNome(nome);

                        ocupacao = linhas[i];
                        ocupacao.erase(0, j+8);

                        funcionario.setOcupacao(ocupacao);

                        break;
                    }

                    linhaAux = "";
                }

                system("cls");

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        cout << linhas[i] << endl;
                    }
                }

                cout << "\nCodigo: " << numero << "\nNome: " << funcionario.getNome() << "\nOcupacao: " << funcionario.getOcupacao() << endl;

                funcionario = Funcionario();

                break;
            default:  //caso para uma escolha invalida
                system("cls");

                for(i = 0; i < 100; i++){
                    if(linhas[i] != ""){
                        cout << linhas[i] << endl;
                    }
                } 

                cout << "\nDeseja deletar(1), adicionar(2) ou buscar(3)?" << endl;
                cout << "Opcao digitada invalida!" << endl;
                continue;
        }

        cout << "\nDeseja deletar(1), adicionar(2), buscar(3) ou sair(0)?" << endl;
    }

    system("cls");

    for(i = 0; i < 100; i++){         //imprimindo as linhas
        if(linhas[i] != ""){
            cout << linhas[i] << endl;
        }
    }  

    cout << "\n";

    return 0;
}