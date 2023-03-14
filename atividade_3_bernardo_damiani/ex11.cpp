#include <iostream>
#include <ctime>
using namespace std;

/*
Crie programa em C++ que manipule um vetor de inteiros de 10 posi��es, o programa
deve apresentar um menu com as seguintes op��es:
0 � Sair
1 � Gerar Valores (Fun��o que gera os valores para preencher o vetor com n�meros entre 20 e
50 sem valores repetidos)
2 � Mostrar Vetor (Fun��o que recebe o vetor e exibe seus valores na tela)
3 � Mostrar Ordenado (Fun��o que recebe o vetor e exibe os seus valores ordenados em ordem
crescente e decrescente)

OBS: A op��o 2 e 3 do menu s� podem ser executadas ap�s a execu��o da op��o 1, ao escolher
a op��o inv�lida do menu exibir mensagem de �op��o inv�lida�.
*/
void gerar(int vet[], int tam);
void mostrar(int vet[], int tam);
void ordenarMostrar(int vet[], int tam); //usar mostrar();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int arr[10], option;
    bool ok=0;

    do
    {
        system("cls");

        cout << "Op��o: ";
        cin >> option;

        if(option<0 || option>3)
        {
            cout << "\nOp��o inv�lida!\n\n";
            system("pause");
        }
        else if(option==0)
        {
            cout << "\nVoc� sair� do programa!\n\n";
        }
        else if(option==1)
        {
            gerar(arr, 10);
            ok=1;
        }
        else if(ok==1 )
        {
            if(option==2)
            {
                mostrar(arr, 10);
                cout << "\n\n";
                system("pause");
            }
            else if(option==3)
            {
                ordenarMostrar(arr, 10);
                cout << "\n\n";
                system("pause");
            }
        }
        else
        {
            cout << "\nO vetor ainda n�o foi gerado!\n\n";
            system("pause");
        }

    }while(option!=0);

    return 0;
}
void gerar(int vet[], int tam)
{
    for(int i=0; i<tam; i++)
        vet[i] = rand()%31 + 20;
}
void mostrar(int vet[], int tam)
{
    for(int i=0; i<tam; i++)
        cout << vet[i] << ", ";
}
void ordenarMostrar(int vet[], int tam)
{
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vet[i]>vet[j])
            {
                int aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    cout << "\nVetor crescente: ";
    mostrar(vet, tam);
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vet[i]<vet[j])
            {
                int aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    cout << "\nVetor decrescente: ";
    mostrar(vet, tam);
}
