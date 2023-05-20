#include <iostream>
#include <ctime>
using namespace std;

#define n 10

/*
Faça um programa que preencha dois vetores de dez elementos inteiros cada um com números
menores que 100, mostre os dois vetores na tela e a seguir mostre o vetor resultante da intercalação
destes dois vetores.
*/

void exibir(int *arr, int tam = n)
{
    int *i = new int;
    for(*i=0; *i<tam; (*i)++)
    {
        cout <<  arr[*i];
        if(*i < tam-1)
            cout << ", ";
    }
    cout << endl;
    delete i;
}
void gerar(int *arr)
{
    int *i = new int(0), *x = new int;
    bool *ok = new bool;

   while(*i<n)
   {
       *x =  rand()%100;
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

   delete i, x, ok;
}
void intercalacao(int *v1, int *v2)
{
    gerar(v1);
    cout << "v1: ";
    exibir(v1);
    gerar(v2);
    cout << "\nv2: ";
    exibir(v2);

    int *i = new int, *j = new int(0), *v3 = new int[2*n];

    for(*i=0; *i<n;(*i)++)
    {
        v3[*j] = v1[*i];
        (*j)++;
        v3[*j] = v2[*i];
        (*j)++;
    }

    cout << "\nv3: ";
    exibir(v3, 2*n);
    cout << endl;

    delete i, j;
    delete[] v3;
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int *v1 = new int[n], *v2 = new int[n];

    intercalacao(v1, v2);

    delete[] v1, v2;

}
