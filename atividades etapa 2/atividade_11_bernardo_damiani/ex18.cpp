#include <iostream>
using namespace std;

#define n 8

/*
Escreva um programa que manipule um vetor de oito números inteiros, os quais devem ser
digitados pelo usuário, no momento de preencher o vetor, já os armazene de forma crescente e apresente
o vetor a cada inclusão.
*/
void exibir(int *v, int tam = n)
{
    int *i = new int;

    for(*i=0; *i<tam; (*i)++)
    {
        cout << v[*i] << " ";
    }
    cout << endl;

    delete i;
}
void organizar(int *v)
{
    int *i = new int(0), *j = new int, *k = new int, *x = new int;

    do
    {
        system("cls");
        if(*i>0)
        {
            cout << "Vetor: ";
            exibir(v, *i);
        }

        printf("\n\n%d° Termo: ", (*i)+1);
        cin >> *x;

        if(*i==0)
            v[*i] = *x;
        else
        {
            for(*j=0; *j<*i; (*j)++)
            {
                if(*x <= v[*j])
                {
                    for(*k=*i; *k>=*j; (*k)--)
                    {
                        v[*k]= v[(*k)-1]; // se há um termo >= no vetor, todos os outro termos pulam pra frente
                    }
                    v[*j] = *x;
                    break;
                }
                else if(*j == (*i)-1)
                {
                    v[*i] = *x;// se nao encontrou nenhum termo menor ate o fim da rodagem, atribui o termo informado pelo usuário ao termo vazio disponível
                }
            }

        }

        (*i)++;
    }
    while(*i<n);

    system("cls");

    cout << "Vetor Final: ";
    exibir(v, *i);

    delete i, j, k, x;
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    int *v = new int[8];

    organizar(v);

    delete[] v;
}

