#include <iostream>
#include <ctime>
using namespace std;

/*
Crie um programa que manipule uma matriz 3 x 5 de números inteiros, o sistema deverá
utilizar funções para realizar as ações apresentadas abaixo:
- Gerar valores para preencher toda a matriz, não sendo permitido números maiores que 50 e
somente números pares serão aceitos na matriz
- Mostrar a matriz gerada e sua respectiva matriz transposta.
- Calcular e mostrar o maior, o menor e a média dos elementos existentes na matriz.
*/
void gerar(int arr[][5]);
void mostrar2D_3x5(int arr[][5]);
void transpos(int arr[][5], int arr2[][3]);
void mostrar2D_5x3(int arr[][3]);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int m[3][5], m_transp[5][3];

    gerar(m);
    mostrar2D_3x5(m);
    cout << "\n\n";
    transpos(m, m_transp);
    mostrar2D_5x3(m_transp);



    return 0;
}
void gerar(int arr[][5])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<5; j++)
        {
           int n = rand()%51;
           if(n%2!=0)
              j--;
           else
              arr[i][j] = n;
        }
    }
}
void mostrar2D_3x5(int arr[][5])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<5; j++)
            cout << arr[i][j] << "\t";

        cout << endl;
    }
}
void transpos(int arr[][5], int arr2[][3])
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
          arr2[i][j] = arr[j][i];
    }
}
void mostrar2D_5x3(int arr[][3])
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
            cout << arr[i][j] << "\t";

        cout << endl;
    }
}
