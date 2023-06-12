#include <iostream>
#include <fstream>
using namespace std;

/*
Escreva um programa para controlar uma agenda telefônica, os dados da agenda devem
ser carregados e atualizados em um arquivo texto chamado “agenda.txt”, onde em cada linha
deve estar o nome e o número do telefone separados por um ponto e virgula. O programa
deverá apresentar um menu com as seguintes informações:
0 – Sair
1 – Cadastrar contato (não deve permitir números de telefone repetido)
2 – Mostrar contatos
3 – Consultar (informa o nome e apresenta os contatos do referido nome, pode haver mais de
um)
4 – Excluir (informa o número do telefone, caso exista, exclui do cadastro, caso contrário exibe
mensagem de contato inexistente)
*/

struct contato{ // criar vetor de struct com muitas posições para comportar
    int numero;
    string nome;
};

void cadastrarContato(ofstream escrever, contato pessoas[], int posicaoPessoa){

    int validarNumero;

    cout << "\nInforme um número de telefone: ";
    cin >> validarNumero;

    for(int i=0; i<posicaoPessoa; i++){

        if(pessoas[i].numero == validarNumero){
            cout << "\nEsse número já existe!\n"
            getchar();
            return;
        }else if(i == posicaoPessoa-1)
            pessoas[posicaoPessoa].numero = validarNumero;

    }

    cout << "\nInforme seu nome: ";
    getline(cin, pessoas[posicaoPessoa].nome);

    escrever.open("agenda.txt", ios::app);
    escrever << pessoas[posicaoPessoa].nome << ";" << pessoas[posicaoPessoa].numero << "\n";
    escrever.close();
}
void excluirContato(){

}
void consultarContato(){

}
void mostrarContatos(){

}
main(){
    setlocale(LC_ALL, "Portuguese");

    struct contato pessoas[100]; // limite de 100 pessoas

}
