#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

/*
Crie um programa que apresente um menu com as seguintes opções:
0 – Sair
1 – Cadastrar
2 – Mostrar
3 – Consultar
Onde, a opção 1 permita que o usuário informe o nome completo de uma pessoa e o sistema
deverá incluir este nome em um arquivo texto chamado “cadastro.txt”, colocando cada nome
em uma linha e mantendo os nomes já cadastrados.
Opção 2 deverá ler o arquivo texto e mostrar os nomes na tela.
Opção 3 deverá solicitar um nome qualquer e verificar se o nome já existe no arquivo texto.
Exibindo a respectiva informação na tela.
*/
void cadastrar(ofstream &escrever){

    escrever.open("cadastro.txt", ios::app);

    char nomeEscrever[100];

    cout << "\nInforme o nome a ser escrito: ";
    fflush(stdin);
    cin.getline(nomeEscrever, 100);

    escrever << nomeEscrever << "\n";

    cout << "\nO nome foi escrito com sucesso!\n";

    escrever.close();
}
void mostrar(ifstream &ler){

    ler.open("cadastro.txt", ios::in);

    char linhaTexto[100];

    if(ler.is_open()){

            cout << "\n";
            while(ler.getline(linhaTexto, 100))
                cout << linhaTexto << "\n";
            cout << "\n";

    }else
        cout << "\nErro ao ler o arquivo!\n";

    ler.close();
}
void consultar(ifstream &ler){

    ler.open("cadastro.txt", ios::in);

    char stringComparada[100];

    cout << "\nInforme o nome a ser consultado: ";
    fflush(stdin);
    cin.getline(stringComparada, 100);

    char linhaTexto[100];

    if(ler.is_open()){

            int ok=0;
            while(ler.getline(linhaTexto, 100))
            {
                if(strcmp(linhaTexto, stringComparada) == 0)
                {
                    cout << "\nO nome existe no arquivo texto!\n";
                    ok=1;
                    break;
                }
            }
            if( !ok )
            {
                cout << "\nEsse nome não existe no arquivo texto!\n";
            }

    }else
        cout << "\nErro ao ler o arquivo!\n";

    ler.close();
}
main()
{
    setlocale(LC_ALL, "Portuguese");

    ifstream ler;
    ofstream escrever;

    int op;
    do{
        system("cls");
        cout << "0 - sair\n1 - cadastrar\n2 - mostrar\n3 - consultar\n\n\tOpção: ";
        cin >> op;

        if(op<0 || op>3){
            cout << "\nOpção inválida! Digite novamente\n";
        }else if(op==0){
            cout << "\nVocê sairá do programa!\n";
        }else if(op==1){
            cadastrar(escrever);
        }else if(op==2){
            mostrar(ler);
        }else if(op==3){
            consultar(ler);
        }

        if(op!=0)
            system("pause");

    }while(op!=0);

}
