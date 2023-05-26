#include <iostream>
#include <ctime>
using namespace std;

#define n 10

/*
Escreva um programa que preencha um vetor A com dez números inteiros entre 1 e 50, a seguir
gere dois vetores: X contendo os valores do vetor A menores que 26 e outro vetor Y com os números
acima de 25. Os vetores X e Y devem ser alocados dinamicamente com a dimensão necessária. Caso o
vetor A não tiver valores para gerar um dos dois vetores X e Y o programa deverá mostrar mensagem
com esta condição.
O programa deverá exibir o vetor A e caso possível X e Y
*/
void exibir(int *a, int tam = n)
{
    int *i = new int;
    for(*i=0; *i<tam; (*i)++)
    {
        cout << a[*i] << " ";
    }
    cout << endl;
    delete i;
}
void gerar(int *a)
{
    int *i = new int;
    for(*i=0; *i<n; (*i)++)
    {
        a[*i] = rand()%50 + 1;
    }
    delete i;
}
void separar(int *a)
{
    gerar(a);
    cout << "A: ";
    exibir(a);

    int *cont = new int(0), *i = new int;

    for(*i=0; *i<n; (*i)++)
    {
        if(a[*i]<26)
            (*cont)++;
    }
    if(*cont>0)
    {
        *cont = 0;
        int *x = new int[*cont];
        for(*i=0; *i<n; (*i)++)
        {
            if(a[*i]<26)
            {
                x[*cont] = a[*i];
                (*cont)++;
            }
        }
        cout << "\nX: ";
        exibir(x, *cont);
        delete[] x;
    }
    else
    {
        cout << "\nX não existe!\n";
    }

    *cont = 0;
    for(*i=0; *i<n; (*i)++)
    {
        if(a[*i]>25)
            (*cont)++;
    }
    if(*cont>0)
    {
        *cont = 0;
        int *y = new int[*cont];
        for(*i=0; *i<n; (*i)++)
        {
            if(a[*i]>25)
            {
                y[*cont] = a[*i];
                (*cont)++;
            }
        }
        cout << "\nY: ";
        exibir(y, *cont);
        delete[] y;
    }
    else
    {
        cout << "\nY não existe!\n";
    }

    delete cont, i;
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *a = new int[10];
    separar(a);
    delete[] a;
}
