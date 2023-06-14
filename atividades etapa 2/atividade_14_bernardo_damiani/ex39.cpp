#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

/*
Escrever um programa que gere um vetor V[20] com valores no intervalo de 0 a 100,
mostre os valores gerados e escreva-os em um arquivo texto chamado “exer_39.txt”. Após o
usuário deve informar duas posições do vetor (validar para aceitar 0 a 19) e o programa deverá
trocar os elementos destas posições e escrever o vetor alterado no arquivo texto e mostrar na
tela.
*/
void escreverValores(int vetor[]){
    ofstream escrever("exer_39.txt");

    if(escrever.is_open()){
        for(int i=0; i<20; i++)
            escrever << vetor[i] << " ";

        cout << "\nValores escritos no arquivo!\n";

    }else{
        cout << "\nHouve um problema ao abrir o arquivo!\n";
        system("pause");
    }

    escrever.close();
}
void gerarVetor(int vetor[]){
    for(int i=0; i<20; i++){
            vetor[i] = rand()%101;
    }
}
void mostrarVetor(int vetor[]){
    cout << "\nVetor: ";
    for(int i=0; i<20; i++){
            cout << vetor[i] << " ";
    }
    cout << "\n";
}
int selecionarPosicao(int primeiraPosicao=-1){

    int pos;

    do{
        cout << "\nInforme a posição a ser trocada (entre 0 e 19, a primeira e segunda posições devem ser diferentes) : ";
        cin >> pos;

        if(pos<0 || pos>19 || pos == primeiraPosicao){
           cout << "\nPosição inválida!\n";
           system("pause");
        }

    }while(pos<0 || pos>19 || pos == primeiraPosicao);

    return pos;
}
void trocarVetor(int vetor[]){

    int pos1 = selecionarPosicao();
    int pos2 = selecionarPosicao(pos1);

    int aux = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = aux;
}

main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int vetor[20];

    gerarVetor(vetor);
    mostrarVetor(vetor);
    escreverValores(vetor);
    trocarVetor(vetor);
    mostrarVetor(vetor);
    escreverValores(vetor);

}
