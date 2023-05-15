#include <iostream>
#include <ctime>
using namespace std;

#define n 10

/*
Escreva um programa que manipule um vetor de inteiros de 10 posi��es, o vetor dever� ser
preenchido de forma pseudoaleat�ria com valores entre 30 e 55, sem n�meros repetidos, mostrar o vetor
gerado na tela, realizar a troca dos valores no vetor de tal forma que o primeiro passa a ser o �ltimo, o
segundo o pen�ltimo e assim sucessivamente. Mostre o vetor na tela ap�s as trocas, utilize aritm�tica de
ponteiro para percorrer o vetor.
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
       *x = rand()%26 + 30;
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
    int *arrAux = new int;
    arrAux = arr + (n-1); // aponta para o fim do vetor para auxiliar

    while(*i < n/2)
    {
        *aux = *arr;
        *arr = *arrAux;
        *arrAux = *aux;

        arrAux--; // volta  1 posicao;
        arr++;// avan�a uma posi��o

        (*i)++;
    }
    arr-=(*i);

}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *arr = new int[n];// n � uma constante inteira que vale 10

    gerar(arr);
    cout << "Vetor inicial: ";
    exibir(arr);
    troca(arr);//aritm�tica de ponteiros foi usada nas trocas
    cout << "Vetor ap�s a troca: ";
    exibir(arr);


}

