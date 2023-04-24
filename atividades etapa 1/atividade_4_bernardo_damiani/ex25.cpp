#include <iostream>
#include <ctime>
using namespace std;

/*
Escreva um programa que gere randomicamente valores inteiros menores que 11 para
preencher uma matriz 3 x 3 de tal forma que a matriz resultante forme um quadrado mágico.
Quadrado mágico ocorre se a soma dos elementos de cada linha, a soma dos elementos de cada
coluna e a soma dos elementos das diagonais principal e secundária são todas iguais.

O sistema deverá contar quantas matrizes foram geradas até gerar a matriz que resultou no
quadrado mágico. Caso em 10 tentativas não foi gerado o quadrado mágico o sistema deverá
permitir que o usuário informe valores para a matriz, utilize funções e passagem de parâmetro
para resolver este exercício.
*/
void gen(int arr[][3]);
void ler(int arr[][3]);
int soma(int arr, int n, bool lin);
bool isQm(int arr[][3]);
void print2D(int arr[][3]);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int arr[3][3];
    bool ok=0;

    for(int i=1; i<=10; i++)
    {
        gen(arr);
        if(isQm(arr)==1)
        {
            cout << "\nA matriz gerada é um quadrado mágico! Ela será exibida a seguir:\n";
            print2D(arr);
            cout << "\nForam geradas " << i << " matrizes para gerar o quadrado mágico.\n";
            ok=1;
            break;
        }
    }
    if(ok==0)
    {
        cout << "O quadrado Mágico não foi gerado. Você pode informar valores para a matriz para testar se é um quadrado mágico.";
        ler(arr);
        if(isQm(arr)== 1)
        {
            cout << "\nA matriz digitada é um quadrado mágico! Ela será exibida a seguir:\n";
            print2D(arr);
        }
        else
        {
            cout << "A matriz digitada não é um quadrado mágico.\n";
            print2D(arr);
        }

    }


    return 0;
}
void gen(int arr[][3])
{
    srand(time(NULL));
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            arr[i][j] = rand()%11;
    }
}
void ler(int arr[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("\nInforme o valor [%d][%d]: ", i, j);
            cin >> arr[i][j];
        }
    }
}
int soma(int arr[][3], int n, int op)
{
    int s=0;

    if(op==0)//coluna
    {
        for(int i=0; i<3; i++)
            s+=arr[i][n];

        return s;
    }
    else if(op==1)//linha
    {
        for(int i=0; i<3; i++)
            s+=arr[n][i];

        return s;
    }
    else if(op==2)//dp
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(i==j)
                    s+=arr[i][j];
            }
        }
        return s;
    }

    else if(op==3)//ds
    {
       for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(i+j==2)
                    s+=arr[i][j];
            }
        }
        return s;
    }
    else
        return 0;

}
bool isQm(int arr[][3])
{
    if(soma(arr, 0, 1) == soma(arr, 1, 1) && soma(arr, 1, 1) == soma(arr, 2, 1) && soma(arr, 2, 1) == soma(arr, 0, 0) && soma(arr, 0, 0) == soma(arr, 1, 0) && soma(arr, 1, 0) == soma(arr, 2, 0) && soma(arr, 2, 0) == soma(arr,0, 2) && soma(arr,0, 2) == soma(arr,0,3) )
        return 1;
    return 0;//else
}
void print2D(int arr[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            cout << arr[i][j] << "\t";

        cout << endl;
    }
}
