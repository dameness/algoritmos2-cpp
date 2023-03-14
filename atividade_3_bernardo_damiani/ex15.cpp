#include <iostream>
#include <ctime>
using namespace std;

/*
Escreva um programa em C++ que manipule dois vetores x1 e x2 de 10 elementos do tipo
inteiro, o programa deverá apresentar um menu com as seguintes ações:

0 - Sair
1 – Gerar vetores (gerar valores para preencher os dois vetores com números pseudoaleatórios
entre 35 e 85 (não incluindo o 35 e o 85) e não sendo permitido valores duplicados no mesmo
vetor)
2 - Mostra (mostrar os dois vetores na tela.
3 – Intersecção (gerar um terceiro vetor que deverá conter a intersecção de x1 e x2, ou seja, os
elementos que existem nos dois vetores.

OBS: as ações 1, 2 e 3 do menu devem acionar as respectivas funções que deverão executar as
ações solicitadas em cada item. Ao escolher opção inválida no menu deve exibir mensagem com
tal informação.
*/
void gerar(int arr[], int tam);
void mostrar1D(int arr[], int tam);
void intersec(int arr1[], int arr2[], int *arrIntersec, int tam, int &cont);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int x1[10], x2[10], vetIntersec[10] = {0}, contador, option;
    bool ok = 0;

    do
    {
        cout << "Opção: ";
        cin >> option;
        if(option<0||option>3)
        {
            cout << "\nOpção inválida!\n\n";
            system("pause");
            system("cls");
        }
        else if(option==0)
        {
            cout << "\nVocê sairá do programa!\n\n";
            system("pause");
        }
        else if(option==1)
        {
            gerar(x1, 10);
            gerar(x2, 10);
            ok=1;
        }
        else if(ok==1)
        {
            if(option==2)
            {
                cout << "\nx1: ";
                mostrar1D(x1, 10);
                cout << "x2: ";
                mostrar1D(x2, 10);
            }
            else if(option==3)
            {
                cout << "\nIntersecção dos dois vetores: ";
                intersec(x1, x2, vetIntersec, 10, contador);
                mostrar1D(vetIntersec, contador);
            }
        }
        else
        {
            cout << "\nOs vetores ainda não foi gerados!\n\n";
            system("pause");
            system("cls");
        }
    }
    while(option!=0);

    return 0;
}
void gerar(int arr[], int tam)
{
    int n;
    bool repete;

    for(int j=0; j<tam; j++)
    {
        do
        {
            n = rand()%49 + 36; // entre 35 e 85 sem incluir ambos e sem repetir

            repete = 0;

            for(int i=0; i<j; i++)
            {
                if(n==arr[i])
                {
                    repete=1;
                    break;
                }
            }
            if(repete==0)
                arr[j] = n;


        }
        while(repete==1);
    }
}
void mostrar1D(int arr[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << arr[i];
        if(i<tam-1)
            cout << ", ";
    }
    cout << "\n\n";
}
void intersec(int arr1[], int arr2[], int *arrIntersec, int tam, int &cont) //referencia ao endereço do contador
{
    //ponteiro apontanrá para a posição 0 do vetor da intersecção e modificará os valores do vetor

    cont=0;

    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(arr1[i]==arr2[j])
            {
                arrIntersec[cont] = arr1[i];
                cont++;
            }
        }
    }
}
