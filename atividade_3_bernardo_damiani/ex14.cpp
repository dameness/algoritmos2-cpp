#include <iostream>
#include <ctime>
using namespace std;

/*
Escreva um programa em C++ que manipule uma matriz de inteiros M[8][8] e acione as
seguintes funções:

A) Função que gere valores aleatórios, menores que 100 para preencher a matriz.

B) Função que receba a matriz por parâmetro e exiba os seus valores na tela.

C) Função que receba a matriz M e um vetor V[8] o qual deve ser formado pela soma dos
elementos de cada linha da matriz, apresente o vetor na tela.

D) Função que recebe a matriz e apresenta os elementos da diagonal principal e diagonal
secundária.
*/
void gerar(int arr[][8]);
void mostrar1D(int arr[]);
void mostrar2D(int arr[][8]);
void linhasSoma(int arr2D[][8], int arr1D[]);
void diagonais(int arr[][8]);


int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int arr[8][8], arrSoma[8] = {0};

    gerar(arr);
    mostrar2D(arr);
    linhasSoma(arr, arrSoma);
    diagonais(arr);

    return 0;
}
void gerar(int arr[][8])
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            arr[i][j] = rand()%99;
    }
}
void mostrar1D(int arr[])
{
    for(int i=0; i<8; i++)
    {
        cout << arr[i];
        if(i<7)
            cout << ", ";
    }
    cout << "\n\n";
}
void mostrar2D(int arr[][8])
{
    cout << "A matriz foi gerada e agora será exibida:\n";
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            cout << arr[i][j] << "\t";

        cout << endl;
    }
}
void linhasSoma(int arr2D[][8], int arr1D[])
{
    for(int i=0; i<8; i++)
    {

        for(int j=0; j<8; j++)
            arr1D[i] += arr2D[i][j];
    }

    cout << "\n\nVetor em que cada termo é a soma de uma linha da matriz:\n\n";
    mostrar1D(arr1D);
}
void diagonais(int arr[][8])
{
    int DP[8], DS[8];

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if((i + j) == 8 - 1)
                DS[i]=arr[i][j];
            else if(i==j)
                DP[i]=arr[i][j];
        }
    }
    cout<<"Diagonal Principal: ";
    mostrar1D(DP);
    cout<<"Diagonal Secundária: ";
    mostrar1D(DS);
}
