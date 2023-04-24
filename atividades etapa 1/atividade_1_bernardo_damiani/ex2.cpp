#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

#define tam 20

/*
Escreva um programa que manipule um vetor VET[20] de números float, os valores para
preencher o vetor devem ser gerados randomicamente, mostre o vetor gerado na tela, exibindo
5 valores em cada linha e separando cada valor com uma vírgula, a seguir mostre o vetor com
valores arredondados para cima, para baixo e seguindo o critério da primeira casa decimal.
*/
void exibir(float vetor[], int tamanho);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    float vet[tam], vet_ceil[tam], vet_floor[tam], vet_round[tam];

    cout << fixed;
    cout.precision(2);

    for(int i=0; i<tam; i++)
        vet[i] = rand()%101 * 1.36; // limitei os valores até 100 para facilitar a visualização
        // o número gerado pela função rand() é inteiro; multipliquei por um float aleatório para convertê-lo para float

    cout << "Vetor gerado:\n";
    exibir(vet, tam);

    cout.precision(0);

    cout << "Vetor com os valores arredondados para cima:\n";
    for(int i=0; i<tam; i++)
        vet_ceil[i] = ceil(vet[i]);
    exibir(vet_ceil, tam);

    cout << "Vetor com os valores arredondados para baixo:\n";
    for(int i=0; i<tam; i++)
        vet_floor[i] = floor(vet[i]);
    exibir(vet_floor, tam);

    cout << "Vetor com os valores arredondados seguindo o critério da primeira casa decimal:\n";
    for(int i=0; i<tam; i++)
        vet_round[i] = round(vet[i]);
    exibir(vet_round, tam);

    return 0;
}

void exibir(float vetor[], int tamanho)
{
    int j=1; //usado para pular a linha a cada 5 posições
    for(int i=0; i<tamanho; i++)
    {
        cout << vetor[i];
        if(i!=(tam-1))
            cout << ", ";
        if(i!=0 && j%5==0)
            cout << "\n\n";
        j++;
    }
    cout << "\n\n";
}
