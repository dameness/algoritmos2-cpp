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

struct contato{
    string numero;
    string nome;
};

void lerAgenda(ifstream &ler, contato pessoas[], int &proximaPessoa){
    ler.open("agenda.txt", ios::in);

    char infoTexto[100];
    int cont=1;

    proximaPessoa=0;

    if(ler.is_open()){
        while(ler.getline(infoTexto, 100, ';')){

            if(cont==1){
                pessoas[proximaPessoa].nome = infoTexto;
                cont++;
            }else if(cont==2){
                pessoas[proximaPessoa].numero = infoTexto;
                cont=1;
                proximaPessoa++;
            }
        }
    }
    ler.close();
}
void gravarAgenda(ofstream &escrever, contato pessoas[], int proximaPessoa){
     escrever.open("agenda.txt", ios::out);

    if(escrever.is_open()){

        for(int i=0; i<proximaPessoa; i++)
            escrever << pessoas[i].nome << ";" << pessoas[i].numero << ";\n";

    }

    escrever.close();
}
void cadastrarContato(contato pessoas[], int &proximaPessoa){

    string validarNumero;
    bool ok;
    do{
        ok=1;
        cout << "\nInforme um número de telefone: ";
        fflush(stdin);
        getline(cin, validarNumero);

        int s = validarNumero.size();

        for(int i=0; i<s; i++){
            if(!isdigit(validarNumero[i])){
                ok=0;
                cout << "\nValor inválido\n";
                system("pause");
                break;
            }
        }

    }while(!ok);


    for(int i=0; i<proximaPessoa; i++){

        if(pessoas[i].numero == validarNumero){
            cout << "\nEsse número já existe!\n";
            system("pause");
            return;
        }
    }
    pessoas[proximaPessoa].numero = validarNumero;

    cout << "\nInforme seu nome: ";
    fflush(stdin);
    getline(cin, pessoas[proximaPessoa].nome);

    proximaPessoa++;

}
void excluirContato(contato pessoas[], int &proximaPessoa){

     string validarNumero;
    bool ok;

    do{
        ok=1;
        cout << "\nInforme um número de telefone: ";
        fflush(stdin);
        getline(cin, validarNumero);

        int s = validarNumero.size();

        for(int i=0; i<s; i++){
            if(!isdigit(validarNumero[i])){
                ok=0;
                cout << "\nInválido\n";
                system("pause");
                break;
            }
        }

    }while(!ok);

    int posicaoExcluir;
    ok=0;
    for(int i=0; i<proximaPessoa; i++){

        if(pessoas[i].numero == validarNumero){
            posicaoExcluir = i;
            ok=1;
            break;
        }

    }
   if(!ok){
    cout << "\nEsse número não existe!\n";
    system("pause");
    return;
   }
proximaPessoa--;
    struct contato pessoasAux[proximaPessoa];


    int i=0, j=0;
    while(i<proximaPessoa){
        if(j==posicaoExcluir)
            j++;

        pessoasAux[i] = pessoas[j];

        i++;
        j++;
    }
    for(int i=0; i<proximaPessoa; i++)
        pessoas[i] = pessoasAux[i];
}
void consultarContato(contato pessoas[], int proximaPessoa){

    string nome;
    cout << "\nInforme o nome do contato: ";
    fflush(stdin);
    getline(cin, nome);

    bool ok=0;

    for(int i=0; i<proximaPessoa; i++){

        if(nome==pessoas[i].nome){
            cout << pessoas[i].nome << " - " << pessoas[i].numero <<"\n";
            ok=1;
        }
    }
    if(!ok){
        cout << "\nNenhum contato com esse nome!\n";
    }

    cout << endl;
    system("pause");
}
void mostrarContatos(contato pessoas[], int proximaPessoa){

  cout << "\nContatos:\n\n";
  for(int i=0; i<proximaPessoa; i++){
    cout << pessoas[i].nome << " - " << pessoas[i].numero  <<  "\n";
  }
  cout << endl;
  system("pause");
}
main(){
    setlocale(LC_ALL, "Portuguese");
    ofstream escrever;
    ifstream ler;
    struct contato pessoas[100]; // limite de 100 pessoas na agenda
    int proximaPessoa;

    lerAgenda(ler, pessoas, proximaPessoa);

    int op;
    do{
        system("cls");

        cout << "\tAGENDA TELEFÔNICA:\n\n0 - Sair do programa\n1 - Cadastrar contato\n2 - Mostrar todos os contatos\n3 - Consultar contato\n4 - Excluir contato\n\n\tEscolha a sua opção: ";
        cin >> op;
        fflush(stdin);

        if(op<0 || op>4){
            cout << "\nEscolha uma opção válida!\n";
            system("pause");
        }else if(op==0){
            gravarAgenda(escrever, pessoas, proximaPessoa);
            cout << "\nVocê sairá do programa!\n";
        }else if(op==1){
            cadastrarContato(pessoas, proximaPessoa);
            gravarAgenda(escrever, pessoas, proximaPessoa);
        }else if(op==2){
            mostrarContatos(pessoas, proximaPessoa);
        }else if(op==3){
            consultarContato(pessoas, proximaPessoa);
        }else if(op==4){
            excluirContato(pessoas, proximaPessoa);
            gravarAgenda(escrever, pessoas, proximaPessoa);
        }
    }while(op!=0 && proximaPessoa<100);

    if(proximaPessoa>=100)
        cout << "\nO limite de pessoas foi alcançado!\n";
}
