#include <iostream>
#include <ctime>
using namespace std;

#define n 10

/*
Escreva um programa que gere dois vetores inteiros X e Y de 10 posi��es que devem ser
preenchidos de forma aleat�ria com valores entre 0 e 12, A seguir apresente um menu que proporcione
as seguintes funcionalidades:
A) A uni�o de X com Y (todos os elementos de X e de Y, sem repeti��o)

B) A diferen�a entre X e Y (todos os elementos de X que n�o existam em Y, sem repeti��o)

C) A soma entre X e Y (soma de cada elemento de X com o elemento da mesma posi��o em Y)

D) O produto entre X e Y (multiplica��o de cada elemento de X com o elemento da mesma posi��o
em Y)

E) A intersec��o entre X e Y (apenas os elementos que aparecem nos dois vetores, sem repeti��o)
*/

void exibir(int *arr, int tam = n)
{
    int *i = new int;

    for(*i=0; *i<tam; (*i)++)
        cout << arr[*i] << " ";

    cout << endl;
    delete i;
}
void gerar(int *arr)
{
    int *i = new int;

    for(*i=0; *i<n; (*i)++)
        arr[*i] = rand()%13;

    delete i;
}
void uniao(int *x, int *y)
{
    int *i = new int, *j = new int;
    int *u = new int[13]; //0 - 12
    int *cont = new int(0);

    for(*i=0; *i<13; (*i)++) // vetores x e y tem termos de 0 a 12, por isso o m�ximo da uni�o sem repetir � 13 termos
    {
        for(*j=0; *j<n; (*j)++) // percorre os vetores x e y e se encontrar o termo da sequencia, coloca no vetor da uniao e para de percorrer
        {
            if(x[*j] == *i || y[*j] == *i)
            {
                u[*cont] = *i;
                (*cont)++;
                break;
            }
        }
    }
    cout << "Uni�o: ";
    exibir(u, *cont);  // mostra vetor uniao com a quantidade de termos definida pelo contador

    delete i, j, cont;
    delete[] u;
}
void diferenca(int *x, int *y)
{
    int *i = new int, *j = new int, *k = new int;
    int *d = new int[n];
    int *cont = new int(0);

    for(*i=0; *i<n; (*i)++)
    {
        for(*j=0; *j<n; (*j)++)
        {
            if(x[*i] == y[*j])
                break;
            else if(*j==n-1)
            {
                if(*cont==0)
                {
                    d[*cont] = x[*i];
                    (*cont)++;
                }
                else
                {
                    for(*k=0; *k<*cont; (*k)++)
                    {
                        if(x[*i] == d[*k])
                            break;
                        else if(*k == (*cont) - 1)
                        {
                            d[*cont] = x[*i];
                            (*cont)++;
                        }
                    }
                }
            }

        }
    }

    cout << "Diferen�a: ";
    exibir(d, *cont);

    delete i, j, k, cont;
    delete[] d;
}
void soma(int *x, int *y)
{
    int *i = new int;
    int *s = new int[n];

    for(*i=0; *i<n; (*i)++)
    {
        s[*i] = x[*i] + y[*i];
    }

    cout << "Soma: ";
    exibir(s);

    delete i;
    delete[] s;
}
void produto(int *x, int *y)
{
    int *i = new int;
    int *p = new int[n];

    for(*i=0; *i<n; (*i)++)
    {
        p[*i] = x[*i] * y[*i];
    }

    cout << "Soma: ";
    exibir(p);

    delete i;
    delete[] p;
}
void intersec(int *x, int *y)
{
    int *i = new int, *j = new int, *k = new int;
    int *inter = new int[n];
    int *cont = new int(0);

    for(*i=0; *i<n; (*i)++)
    {
        for(*j=0; *j<n; (*j)++)
        {
            if(x[*i] == y[*j])
            {
                if(*cont==0)
                {
                    inter[*cont] = x[*i];
                    (*cont)++;
                }
                else
                {
                    for(*k=0; *k<*cont; (*k)++)
                    {
                        if(x[*i] == inter[*k])
                            break;
                        else if(*k == (*cont) - 1)
                        {
                            inter[*cont] = x[*i];
                            (*cont)++;
                        }
                    }
                }
            }

        }
    }

    cout << "Intersec��o: ";
    exibir(inter, *cont);

    delete i, j, k, cont;
    delete[] inter;
}

main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *x = new int[n], *y = new int[n];
    int *op = new int;

    gerar(x);
    gerar(y);

    do
    {
        system("cls");

        cout << "x: ";
        exibir(x);
        cout << "\ny: ";
        exibir(y);

        cout << "\nEscolha uma op��o:\n\n0 - Sair\n1 - Uni�o\n2 - Diferen�a\n3 - Soma\n4 - Produto\n5 - Intersec��o\n\n\tOp��o: ";
        cin >> *op;
        cout << endl;

        if(*op<0 || *op>5)
            cout << "\nOp��o inv�lida!\n";

        else
        {
            if(*op==1)
                uniao(x, y);

            if(*op==2)
                diferenca(x, y);

            if(*op==3)
                soma(x, y);

            if(*op==4)
                produto(x, y);

            if(*op==5)
                intersec(x, y);

        }
        cout << endl;
        system("pause");

    }
    while(*op!=0);

    delete op;
    delete[] x, y;

}
