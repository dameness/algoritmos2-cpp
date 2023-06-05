#include <iostream>
#include <ctime>
using namespace std;

#define n 5

/*
- Escreva um programa que preencha dois vetores X e Y com cinco elementos numéricos cada e,
depois, ordene-os de maneira crescente. Deverá ser gerado um terceiro vetor com dez posições,
composto pela junção dos elementos dos vetores anteriores, também ordenado de maneira crescente.
*/

void exibir(int *arr, int tam = n)
{
    int *i = new int;
    for(*i=0; *i<tam; (*i)++)
    {
        cout << arr[*i] << " ";
    }
    cout << endl;
    delete i;
}
void gerar(int *arr, int tam = n)
{
    int *i = new int(0), *j = new int, *x = new int;
    bool *ok = new bool;

    while(*i<tam)
    {
        *x = rand()%30; // limitando a geração do vetor
        *ok=1;

        for(*j=0; *j<*i; (*j)++)
        {
            if(*x == arr[*j])
            {
                *ok=0;
                break;
            }
        }
        if(*ok==1)
        {
            arr[*i] = *x;
            (*i)++;
        }
    }

    delete i, j, x, ok;
}
void ordemCrescente(int *arr, int tam = n)
{
    int *i = new int, *j = new int, *aux = new int;

    for(*i=0; *i<tam; (*i)++)
    {
        for(*j=0; *j<tam; (*j)++)
        {
            if(arr[*i] < arr[*j])
            {
                *aux = arr[*i];
                arr[*i] = arr[*j];
                 arr[*j] = *aux;
            }
        }
    }

    delete i, j, aux;
}
void uniao(int *v3, int *v1, int *v2)
{
    int *i = new int;

    for(*i=0; *i<n; (*i)++)
    {
        v3[*i] = v1[*i];
    }
    for(*i=n; *i<2*n; (*i)++)
    {
         v3[*i] = v2[*i - n];
    }

    delete i;
}
main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int *v1 = new int[n], *v2 = new int[n], *v3 = new int[2*n];

    gerar(v1);
    gerar(v2);
    cout << "v1 inicial: ";
    exibir(v1);
    ordemCrescente(v1);
    cout << "v1 ordenado: ";
    exibir(v1);

    cout << "\nv2 inicial: ";
    exibir(v2);
    ordemCrescente(v2);
    cout << "v2 ordenado: ";
    exibir(v2);

    uniao(v3, v1, v2);
    ordemCrescente(v3, 2*n);
    cout << "\nv3 ordenado: ";
    exibir(v3, 2*n);

    delete[] v1, v2, v3;
}
