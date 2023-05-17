#include <iostream>
#include <ctime>
using namespace std;

#define n 10

/*
Crie uma função que receba como parâmetros dois vetores de inteiros: x1[10] e x2[10]. A função
deverá alocar um terceiro vetor, x3, alocado dinamicamente, contendo a união de x1 e x2 e deverá
apresentar:
- Os elementos do vetor x3.
- Os elementos do vetor x3 em ordem crescente.
- O maior e o menor elemento do vetor x3.
- Quantos dos elementos do vetor x3 são primos e quais são eles.
OBS: os vetores x1 e x2 devem ser gerados de forma randômica contendo valores entre 200 e 300
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
       *x =  rand()%101 + 200;
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
void ordemCrescente(int *x, int tam = n)
{
    int *i = new int, *j = new int, *aux = new int;

    for(*i=0; *i<tam; (*i)++)
    {
         for(*j=0; *j<tam-1; (*j)++)
         {
            if(x[*j] > x[*i])
            {
                *aux = x[*j];
                x[*j] = x[*i];
                x[*i] = *aux;
            }
         }
    }
    delete i, j, aux;
}
bool isPrimo(int *x, int *i)
{
   int *j = new int;

    for(*j=2; *j<x[*i]; (*j)++)
    {
        if( x[*i]% (*j) == 0)
        {
            delete j;
            return 0;
        }
    }

    delete j;
    return 1;
}
void operacoes(int *x1, int *x2)
{
    int *t = new int(20), *i = new int, *j = new int;

    for(*i=0; *i<n; (*i)++)
    {
        for(*j=0; *j<n; (*j)++)
        {
            if(x2[*i] == x1[*j])
            {
                (*t)--;
                break;
            }
        }
    }

    int *x3 = new int[*t];

    for(*i=0; *i<n; (*i)++)
    {
        x3[*i] = x1[*i];
    }

    int *cont = new int(n);

    for(*i=0; *i<n; (*i)++)
    {
        for(*j=0; *j<*cont; (*j)++)
        {
            if(x2[*i] == x3[*j]) // se o termo ja foi colocado em x3, significa que ele também existe em x1
            {
                break;
            }
            else if(*j==n-1)
            {
                x3[*cont] = x2[*i];
                (*cont)++;
            }
        }
    }

    cout << "\nx3 (x1 U x2): ";
    exibir(x3 , *t);

    ordemCrescente(x3, *t);
    cout << "\nx3 em ordem crescente: ";
    exibir(x3 , *t);

    printf("\nMaior elemento de x3: %d\n\nMenor elemento de x3: %d\n", x3[0], x3[(*cont) - 1]);

    int *cont2 = new int(0);

    for(*i=0; *i<*cont; (*i)++)
    {
        if(isPrimo(x3, i))
            (*cont2)++;
    }

    printf("\nHá %d números primos em x3: ", *cont2);

    for(*i=0; *i<*cont; (*i)++)
    {
        if(isPrimo(x3, i))
            cout << x3[*i] << ", ";
    }

    cout << endl;

    delete t, i, j, cont, cont2;
    delete[] x3;

}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int *x1 = new int[n], *x2 = new int[n];

    gerar(x1);
    gerar(x2);
    cout << "x1: ";
    exibir(x1);
    cout << "\nx2: ";
    exibir(x2);

    operacoes(x1, x2);

    delete[] x1, x2;
}
