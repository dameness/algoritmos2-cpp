#include <iostream>
#include <ctime>
using namespace std;

#define n 10


/*
Crie um programa que manipule dois vetores vet1 e vet2 ambos de 10 posições e devem ser
preenchidos com números inteiros entre 5 e 20, sem números repetidos.
Após o sistema deverá ordenar os dois vetores em ordem crescente e apresentar os dois vetores na tela e
também apresentar em quais posições os números são iguais, depois de ordenados.
*/
void exibir(int *vet, int tam = n)
{
     int i=0;
    while(i<tam)
    {
        cout << *vet;
        if(i < tam-1)
            cout << ", ";

        vet++;
        i++;
    }
    vet-=i;

    cout << endl;
}
void gerar(int **vet)
{
    int i=0;

    while(i<n)
    {
        int x = rand()%16 + 5;
        bool ok = 1;

        for(int j=0; j<i; j++)
        {
            if( *((*vet) - i+ j) == x) // movimento com i e j a partir do ponteiro de nível 1
            {
                ok = 0;
                break;
            }

        }

        if(ok==1)
        {
            **vet = x;
            (*vet)++;
            i++;
        }
    }
    (*vet)-=i;

}
void ordemCrescente(int **vet)
{
    gerar(vet);

    int *pi = *vet, *pj = *vet;

    for(int i=0; i<n; i++)
    {
         for(int j=0; j<n-1; j++)
         {
            if(*pj > *pi)
            {
                int aux = *pj;
                *pj = *pi;
                *pi = aux;
            }
            pj++;
         }

         pj = *vet;

         pi++;
    }

}
void numIguais(int *vet1, int *vet2)
{
    ordemCrescente(&vet1);
    ordemCrescente(&vet2);

    int *p1 = vet1, *p2 = vet2;
    int iguais[n], *p3 = iguais, cont=0;

    for(int i=0; i<n; i++)
    {
        if(*p1 == *p2)
        {
           *p3 = i;
           p3++;
           cont++;
        }

        p1++;
        p2++;
    }
    p3 = iguais;

    exibir(vet1);
    cout << "\n";
    exibir(vet2);
    cout << "\nPosição(ões) dos vetores cujos números são iguais: ";
    exibir(p3, cont);

}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int vet1[n], vet2[n];

    numIguais(vet1, vet2);



}

