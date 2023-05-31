#include <iostream>
#include <ctime>
using namespace std;

/*
Escreva um programa que atrav�s de uma fun��o receba como par�metro um array de inteiros com
N valores (a dimens�o deve ser definida pelo usu�rio ao iniciar o programa), e determina o maior
elemento do array e o n�mero de vezes que este elemento ocorreu no array. Por exemplo, para um array
com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a fun��o deve exibir o valor 15 e o n�mero 3
(indicando que o n�mero 15 ocorreu 3 vezes). A fun��o deve ser do tipo void, utilize ponteiros para
fornecer as informa��es solicitadas.
*/
void gerar(int *arr, int *n)
{
    int *i = new int;

    for(*i=0; *i<*n; (*i)++)
    {
        arr[*i] = rand()%20 + 1; //n�o foi especificado, portanto, gerando n valores de 1 a 20;
    }

    delete i;
}
void exibir(int *arr, int *n)
{
    int *i = new int;

    for(*i=0; *i<*n; (*i)++)
    {
       cout << arr[*i] << " ";
    }
    cout << endl;

    delete i;
}
void maiorInfo(int *n)
{
    int *arr = new int[*n];
    gerar(arr, n);

    int *i = new int, *cont = new int(0), *maiorPos = new int;

    for(*i=0; *i<*n; (*i)++)
    {
        if(*i==0 || arr[*i] > arr[*maiorPos])
            *maiorPos = *i;
    }
    for(*i=0; *i<*n; (*i)++)
    {
        if(arr[*i] == arr[*maiorPos])
            (*cont)++;
    }

    exibir(arr, n);
    printf("\nO maior termo � %d e apareceu %d vez(es).\n", arr[*maiorPos], *cont);

    delete i, cont, maiorPos;
    delete[] arr;
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *n = new int;

    do
    {
        system("cls");
        cout << "Quantidade de valores inteiros do vetor: ";
        cin >> *n;

        if(*n<1 || *n>1000)
        {
            cout << "\nVetor inv�lido! Por favor insira um valor entre 1 e 1000\n";
            system("pause");
        }

    }while(*n<1 || *n>1000); //limitei os valores para o vetor ficar aceit�vel

    maiorInfo(n);

    delete n;
}

