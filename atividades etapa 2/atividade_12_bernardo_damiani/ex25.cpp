#include <iostream>
#include <ctime>
using namespace std;

/*
Escreva um programa em C++ que leia um número inteiro positivo N e crie dinamicamente uma
matriz de inteiros de tamanho NxN. Preencha a matriz com números pseudoaleatorios menores que o
produto de N * N, imprima a matriz na tela e apresente também:
- Soma dos elementos da diagonal principal - DP
- Maior e menor elemento da diagonal secundária - DS
- Diferença das somas dos elementos acima da DP e abaixo da DP
*/


void exibir(int *arr, int *n)
{
    int *i = new int;

    for(*i=0; *i<( (*n)*(*n) ); (*i)++)
    {
        if(*i % *n == 0)
            cout << "\n\n";
        cout << arr[*i] << "\t";
    }
    cout << "\n";

    delete i;
}
void gerar(int *arr, int *n)
{
    int *i = new int;

    for(*i=0; *i<( (*n)*(*n) ); (*i)++)
    {
        arr[*i] = rand()%( (*n)*(*n) ); //valores menores que N *N
    }

    delete i;
}
void matrizOp(int *n)
{
    int *arr = new int[(*n)*(*n)];
    gerar(arr, n);
    exibir(arr, n);

    int *i = new int;
    int *l = new int(0), *c = new int(0);

    int *somaDp = new int(0), *maiorDs = new int, *menorDs = new int, *somaAcimaDp = new int(0), *somaAbaixoDp = new int(0);

    for(*i=0; *i<( (*n)*(*n) ); (*i)++)
    {
        if(*i % *n == 0 && *i!=0)// incrementar linha e resetar coluna
        {
            (*l)++;
            *c = 0;
        }
        else if (*i!=0) // senao, incrementar coluna
        {
            (*c)++;
        }

        if(*l == *c)
        {
            *somaDp += arr[*i];
        }
        if(*l + *c == *n - 1)
        {
            if(arr[*i] > *maiorDs || *i == *n -1) //primeiro elemento da ds
            {
                *maiorDs = arr[*i];
            }
            if(arr[*i] < *menorDs || *i == *n -1)
            {
                *menorDs = arr[*i];
            }
        }

        if(*l > *c)
        {
            *somaAbaixoDp += arr[*i];
        }
        else if(*l < *c)
        {
            *somaAcimaDp += arr[*i];
        }
    }

    printf("\nSoma dos elementos da DP: %d\nMaior elemento da DS: %d\nMenor elemento da DS: %d\nDiferença das somas dos elementos acima da DP (%d) e abaixo da DP (%d): %d\n", *somaDp, *maiorDs, *menorDs, *somaAcimaDp, *somaAbaixoDp, *somaAcimaDp - *somaAbaixoDp);

    delete[] arr;
    delete i, l, c, somaDp, maiorDs, menorDs, somaAcimaDp, somaAbaixoDp;
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *n = new int;

    do
    {
        system("cls");
        cout << "Quantidade de valores inteiros da matriz: ";
        cin >> *n;

        if(*n<1 || *n>100)
        {
            cout << "\nVetor inválido! Por favor insira um valor entre 1 e 100\n";
            system("pause");
        }

    }while(*n<1 || *n>100); //limitei os valores para a matriz ficar aceitável

    matrizOp(n);

    delete n;
}

