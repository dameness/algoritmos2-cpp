#include <iostream>
#include <ctime>
using namespace std;

#define n 10

/*
Fa�a um programa que preencha de forma aleat�ria um primeiro vetor com dez n�meros inteiros
entre 1 e 30, e um segundo vetor com cinco n�meros inteiros entre 2 e 15. O programa dever� mostrar
uma lista dos n�meros do primeiro vetor com seus respectivos divisores armazenados no segundo vetor,
bem como suas posi��es.
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
void divisores(int *v1, int *v2)
{
    int *i = new int, *j = new int;
    bool *ok = new bool;

     for(*i=0; *i<10; (*i)++)
    {
        v1[*i] = rand()%30 + 1;
    }
     for(*i=0; *i<5; (*i)++)
    {
        v2[*i] = rand()%14 + 2;
    }

    exibir(v1);
    exibir(v2, n/2);

    for(*i=0; *i<10; (*i)++)
    {
        cout << "\nN�mero " << v1[*i] << "\n";
        *ok = 0;
        for(*j=0; *j<5; (*j)++)
        {
            if(v1[*i] % v2[*j] == 0)
            {
                cout << "Divis�vel por " << v2[*j] << " na posi��o " << *j << "\n";
                *ok=1;
            }
            else if(*j==4 && *ok==0)
            {
                cout << "N�o possui divisores no segundo vetor\n";
            }
        }
    }

    delete i, j, ok;
}
main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int *v1 = new int[10], *v2 = new int[5];

    divisores(v1, v2);

    delete[] v1, v2;
}
