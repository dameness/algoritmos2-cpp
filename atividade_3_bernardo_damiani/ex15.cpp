#include <iostream>
#include <ctime>
using namespace std;

/*
Escreva um programa em C++ que manipule dois vetores x1 e x2 de 10 elementos do tipo
inteiro, o programa dever� apresentar um menu com as seguintes a��es:

0 - Sair
1 � Gerar vetores (gerar valores para preencher os dois vetores com n�meros pseudoaleat�rios
entre 35 e 85 (n�o incluindo o 35 e o 85) e n�o sendo permitido valores duplicados no mesmo
vetor)
2 - Mostra (mostrar os dois vetores na tela.
3 � Intersec��o (gerar um terceiro vetor que dever� conter a intersec��o de x1 e x2, ou seja, os
elementos que existem nos dois vetores.

OBS: as a��es 1, 2 e 3 do menu devem acionar as respectivas fun��es que dever�o executar as
a��es solicitadas em cada item. Ao escolher op��o inv�lida no menu deve exibir mensagem com
tal informa��o.
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
        cout << "Op��o: ";
        cin >> option;
        if(option<0||option>3)
        {
            cout << "\nOp��o inv�lida!\n\n";
            system("pause");
            system("cls");
        }
        else if(option==0)
        {
            cout << "\nVoc� sair� do programa!\n\n";
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
                cout << "\nIntersec��o dos dois vetores: ";
                intersec(x1, x2, vetIntersec, 10, contador);
                mostrar1D(vetIntersec, contador);
            }
        }
        else
        {
            cout << "\nOs vetores ainda n�o foi gerados!\n\n";
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
void intersec(int arr1[], int arr2[], int *arrIntersec, int tam, int &cont) //referencia ao endere�o do contador
{
    //ponteiro apontanr� para a posi��o 0 do vetor da intersec��o e modificar� os valores do vetor

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
