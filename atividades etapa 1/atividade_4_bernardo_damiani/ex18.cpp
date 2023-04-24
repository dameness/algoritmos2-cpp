#include <iostream>
#include <ctime>
using namespace std;

/*
Implemente um programa para manipular uma matriz de 5 x 5 de números inteiros,
deverá ser possível realizar as seguintes ações:
- Gerar valores para a matriz, não sendo permitido números duplicados.
- Mostrar os elementos da matriz
- Mostrar os elementos da diagonal principal da matriz
- Mostrar os elementos da diagonal secundária da matriz
- Encontrar o maior elemento da matriz e exibir sua posição (linha, coluna) onde se encontra
*/
void isValid(int arr[][5], int &i, int &j, int n);
void gerar(int arr[][5]);
void print2D(int arr[][5]);
void maiorElem(int arr[][5]);
void printDPDS(int arr[][5], bool DP);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int m[5][5], op;
    bool ok=0;

    do
    {
        system("cls");
        cout << "1 - gerar valores para a matriz\n2 - mostrar a matriz\n3 - mostrar DP\n4 - mostrar DS\n5 - mostrar maior elemento da matriz\n\n\tOpção: ";
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
            cout << "Matriz:\n";
            print2D(m);
        }
        else if(ok==1 &&op==3)
        {
            cout << "Matriz:\n";
            print2D(m);
            cout << "\nDiagonal principal:\n";
            printDPDS(m, 1);
        }
        else if(ok==1 && op==4)
        {
            cout << "Matriz:\n";
            print2D(m);
            cout << "\nDiagonal secundária:\n";
            printDPDS(m, 0);
        }
        else if(ok==1 && op==5)
        {
            cout << "Matriz:\n";
            print2D(m);
            maiorElem(m);
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
void isValid(int arr[][5], int &i, int &j, int n)
{
    for(int k=0; k<=i; k++)
    {
        if(k!=i)
        {
            for(int l=0; l<5; l++)
            {
                if(n == arr[k][l])
                {
                    if(j>0)
                        j--;
                    else
                    {
                        i--;
                        j=5;
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
                        j=5;
                    }
                    return;
                }

            }
        }
    }
    arr[i][j]=n;
    return;
}
void gerar(int arr[][5])
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            int n = rand()%100;

            isValid(arr, i, j, n);

        }
    }
}
void print2D(int arr[][5])
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
            cout << arr[i][j] << "\t";

        cout << endl;
    }
}
void maiorElem(int arr[][5])
{
    int maior, mLin, mCol;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(arr[i][j]>maior || (i==0 && j==0))
            {
                maior = arr[i][j];
                mLin = i;
                mCol = j;
            }
        }
    }

    printf("\nm[%d][%d] vale %d e é o maior elemento da matriz!\n", mLin, mCol, maior);
}
void printDPDS(int arr[][5], bool DP)
{
    if(DP==1)
    {
       for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(i==j)
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
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(i+j== (5 - 1))
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

}

