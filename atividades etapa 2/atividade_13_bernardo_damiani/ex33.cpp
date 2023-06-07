#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

/*
Crie um programa que apresente um menu com as op��es listadas a seguir:
0 � Sair
1 � Gerar valores (gera valores entre 5 e 50, para preencher um vetor[20] de n�meros inteiros,
sem n�meros repetidos)
2 � Escrever valores no arquivo texto (escreve os valores constantes no vetor em um arquivo
texto chamado vetor.txt, separando cada elemento com uma v�rgula)
3 � Ler arquivo (l� os valores do arquivo e exibe eles na tela)
OBS: n�o ser� permitido executar as op��es 2 e 3 do menu caso n�o tenha sido executado a
op��o 1, caso a op��o 1 seja executada mais de uma vez o programa dever� manter os dados
j� existentes no arquivo.
*/
void gerarVetor(int vetor[]){

    int i, aux;
    bool ok;

    while(i<20){

        aux = rand()%46+5;
        ok=true;

        for(int j=0; j<i; j++){

            if(aux == vetor[j]){
                ok=0;
                break;
            }
        }
        if(ok){
            vetor[i] = aux;
            i++;
        }
    }
}
void vetorParaTexto(int vetor[]){

    ofstream escreverTexto("vetor.txt", ios::out);

   if(escreverTexto.is_open()){
        for(int i=0; i<20; i++)
        escreverTexto << vetor[i] << ',';
   }else
        cout << "Erro ao abrir o arquivo!";

    escreverTexto.close();
}
void lerExibir(){

    ifstream lerTexto("vetor.txt", ios::in);

    if(lerTexto.is_open()){

        char numeroTexto[20];

        while(lerTexto.getline(numeroTexto, 20, ','))
        cout << numeroTexto << ", ";

    }else
        cout << "Erro ao abrir o arquivo!";

    lerTexto.close();
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int op, vetor[20];
    bool ok=false;
    do{
        system("cls");
        cout << "0 - sair\n1 - gerar\n2 - escrever\n3 - ler\n\n\tOp��o: ";
        cin >> op;
        cout << "\n";

        if(op<0 || op>3)
            cout << "Op��o inv�lida! Digite novamente!";
        else if(op==0)
            cout << "Voc� sair� do programa!";
        else if(op==1){
            if( !ok ){
                gerarVetor(vetor);
                ok=true;
            }
        }else if(ok){
            if(op==2){
                vetorParaTexto(vetor);
            }else if(op==3){
                lerExibir();
            }
        }else
            cout << "Gere um vetor!";

        cout << "\n";
        system("pause");
    }while(op!=0);
}
