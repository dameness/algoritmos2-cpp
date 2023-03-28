#include <iostream>
#include <ctime>
using namespace std;

/*
Crie um programa que manipule uma matriz de inteiros m[7][7]. Utilizando funções o
programa deverá apresentar um menu para acionar as seguintes funcionalidades:
1 – Gerar valores para preencher a matriz, não sendo permitido números duplicados e devem
ser menores que 100.
2 – Mostrar a matriz na tela
3 - Encontrar o maior elemento de cada linha e passá-lo para a posição da diagonal principal na
linha e o elemento que estava na diagonal principal para o local do número, exibir a matriz
original e depois modificada.
4 – Verificar se a Matriz é uma matriz simétrica
5 – Mostrar os elementos acima e abaixo da diagonal principal
*/
void isValid(int arr[][7], int &i, int &j, int n);
void gerar(int arr[][7]);
void print2D(int arr[][7]);
void maiorElemDP(int arr[][7]);
void printAcimaAbaixoDP(int arr[][7], bool acima);
bool isSym(int arr[][7]);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int m[7][7], op;
    bool ok=0;

    do
    {
        system("cls");
        cout << "Opção: ";
        cin >> op;

        if(op==0)
        {
            cout << "\nFim do programa!\n";
            break;
        }
        else if(op==1)
        {
            gerar(m);
            cout << "\nValores gerados!\n";
            ok=1;
        }
        else if(ok==1 && op==2)
        {
            cout << "\nMatriz:\n";
            print2D(m);
        }
        else if(ok==1 &&op==3)
        {
            cout << "\nMatriz original:\n";
            print2D(m);
            maiorElemDP(m);
            cout << "\nMatriz modificada:\n";
            print2D(m);
        }
        else if(ok==1 && op==4)
        {
            cout << "Matriz:\n";
            print2D(m);

            if(isSym(m))
                cout << "\nÉ simétrica!\n";
            else
                cout << "\nNão é simétrica!\n";
        }
        else if(ok==1 && op==5)
        {
            cout << "Matriz:\n";
            print2D(m);
            cout << "\nAcima da DP:\n";
            printAcimaAbaixoDP(m , 1);
            cout << "\nAbaixo da DP:\n";
            printAcimaAbaixoDP(m , 0);
        }
        else
        {
            cout << "\nEssa opção é inválida pois a matriz ainda não foi gerada! Digite novamente!\n";
            system("pause");
            continue;//pula o while e reinicia
        }

        system("pause");
    }
    while(op!=0);

    return 0;
}
void isValid(int arr[][7], int &i, int &j, int n)
{
    for(int k=0; k<=i; k++)
    {
        if(k!=i)
        {
            for(int l=0; l<7; l++)
            {
                if(n == arr[k][l])
                {
                    if(j>0)
                        j--;
                    else
                    {
                        i--;
                        j=7;
                    }
                    return;
                }

            }
        }
        else
        {
            for(int l=0; l<=j; l++)
            {
                if(n == arr[k][l])
                {
                    if(j>0)
                        j--;
                    else
                    {
                        i--;
                        j=7;
                    }
                    return;
                }

            }
        }
    }
    arr[i][j]=n;
    return;
}
void gerar(int arr[][7])
{
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            int n = rand()%100;

            isValid(arr, i, j, n);

        }
    }
}
void print2D(int arr[][7])
{
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
            cout << arr[i][j] << "\t";

        cout << endl;
    }
}
void maiorElemDP(int arr[][7])
{
    int maior, mPos;

    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
           if(arr[i][j] > maior || j==0)
           {
               maior = arr[i][j];
               mPos = j;
           }//descobre e armazena a posição do maior elemento da linha
        }
        //depois de acabar o loop (troca de colunas dentro da linha), troca o maior elemento com o elemento da DP da linha, de acordo com
        // a posição armazenada
        int aux = arr[i][i];
        arr[i][i] = arr[i][mPos];
        arr[i][mPos] = aux;
    }// em seguida pula para a próxima linha e faz o mesmo processo
}
void printAcimaAbaixoDP(int arr[][7], bool acima)
{
    if(acima==1)
    {
       for(int i=0; i<7; i++)
        {
            for(int j=0; j<7; j++)
            {
                if(i<j)
                {
                    cout << arr[i][j] << "\t";
                }
                else
                {
                    cout << " \t";
                }
            }

            cout << endl;
        }
    }
    else
    {
        for(int i=0; i<7; i++)
        {
            for(int j=0; j<7; j++)
            {
                if(i>j)
                {
                    cout << arr[i][j] << "\t";
                }
            }

            cout << endl;
        }
    }

}
bool isSym(int arr[][7])
{
    for(int i=0; i<7; i++)
        {
            for(int j=0; j<7; j++)
            {
                if(arr[i][j]!=arr[j][i])
                    return 0;
            }
        }

    return 1;
}
