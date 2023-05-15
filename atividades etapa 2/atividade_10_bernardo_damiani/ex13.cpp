#include <iostream>
#include <ctime>
using namespace std;

#define n 20

/*
Escrever um programa que gere um vetor V[20] com valores no intervalo de 0 a 100 e mostre os
valores gerados. Modifique o vetor de modo que o primeiro elemento passe para a �ltima posi��o, e
desloque todos os outros elementos uma posi��o para a esquerda.
*/
void exibir(int *arr)
{
    for(int *i = new int(0); *i<n; (*i)++)
    {
        cout <<  arr[*i];
        if(*i < n-1)
            cout << ", ";
    }
    cout << endl;
}
void gerar(int *arr)
{
    int *i = new int(0);
    int *x = new int;
    bool *ok = new bool;

   while(*i<n)
   {
       *x = rand()%101;
       *ok = 1;

       for(int *j = new int(0); *j<*i; (*j)++)
       {
           if(*x == arr[*j])
           {
                *ok = 0;
                break;
           }
       }

       if(*ok==1)
       {
           arr[*i] = *x;
           (*i)++;
       }
   }
}
void troca(int *arr)
{
    int *i = new int(0);
    int *aux = new int;
    int *primeiroTermo = new int;
    *primeiroTermo = *arr;//

    while(*i < n)
    {
        *aux = arr[*i];
        arr[*i] = arr[*i+1];
        arr[*i+1] = *aux;

        (*i)++;
    }//o vetor todo se deslocou para a esquerda, o que resulta em lixo de mem�ria para a �ltima posi��o
    // al�m disso, o valor primeira posi��o inicial desaparece do vetor
    //portanto, este valor foi reservado e agora ser� inserido na �ltima posi��o

    arr[n-1] = *primeiroTermo;
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *arr = new int[n];// n � uma constante inteira que vale 20

    gerar(arr);
    cout << "Vetor inicial: ";
    exibir(arr);
    troca(arr);
    cout << "Vetor ap�s a troca: ";
    exibir(arr);


}

