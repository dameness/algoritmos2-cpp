#include <iostream>
#include <ctime>
using namespace std;

#define n 20

/*
Implemente um programa utilizando ponteiros, que manipule um vetor vet[20] de números
inteiros, o programa deverá ter um menu com as seguintes opções:
0 – Sair
1 – Gerar vetor (gera valores para preencher o vetor com números menores que 50 sem valores
repetidos)
2 – Acha Maior e Menor (crie uma função que receba por parâmetro o vetor vet e os endereços de duas
variáveis inteiras (que podemos chamar de min e max). Ao passar essas variáveis para a função seu
programa deverá analisar qual é o maior e o menor elemento do vetor e depositar esses elementos nas
respectivas variáveis)
3 – Mostra (Exibe o vetor na tela e os valores de min e max)
4 – Calcula (Exibe o percentual de valores pares e ímpares no vetor)
*/

void gerar(int *arr)
{
    int *i = new int;

    for(*i=0; *i<n; (*i)++)
    {
        arr[*i] = rand()%50;
    }

    delete i;
}
void exibir(int *arr)
{
    int *i = new int;

    for(*i=0; *i<n; (*i)++)
    {
       cout << arr[*i] << " ";
    }
    cout << endl;

    delete i;
}
void maiorMenor(int *arr, int *minimo, int *maximo)
{
    int *i = new int;

    for(*i=0; *i<n; (*i)++)
    {
        if(*i==0 || arr[*i] > *maximo)
            *maximo = arr[*i];
        if(*i==0 || arr[*i] < *minimo)
            *minimo = arr[*i];
    }

    delete i;
}
void parOuImpar(int *arr)
{
    int *i = new int, *cPar = new int(0);

    for(*i=0; *i<n; (*i)++)
    {
        if( arr[*i] %2 == 0)
            (*cPar)++;
    }

    cout << "Porcentagem de pares: " << (*cPar) * 5;
    cout << "\nPorcentagem de Ímpares: " << 100 - ((*cPar) * 5);
    cout << "\n\n";

    delete i, cPar;
}
main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int *op = new int, *arr = new int[n], *minimo = new int, *maximo = new int;
    bool *ok = new bool(0);

    do
    {
        system("cls");
        if(*ok==1)
        {
            cout << "Vetor: ";
            exibir(arr);
            cout << endl;
        }
        cout << "0 - Sair\n1 - Gerar\n2 - Maior e menor\n3 - Mostrar maior e menor\n4 - Calcular percentual de pares e ímpares\n\n\tOpção: ";
        cin >> *op;

        if(*op<0 || *op>4)
        {
            cout << "\nOpção inválida!\n";
            system("pause");
        }
        else if(*op==0)
            cout << "\nVocê sairá do programa!\n";
        else if(*op==1)
        {
            gerar(arr);
            *ok = 1;
        }
        else if(*ok==1)
        {
            if(*op==2)
            {
                maiorMenor(arr, minimo, maximo);
                cout << "Valores encontrados!\n";
            }
            else if(*op==3)
            {
                cout << "Mín.: " << *minimo;
                cout << "\nMáx.: " << *maximo;
                cout << "\n\n";
            }
            else if(*op==4)
            {
                parOuImpar(arr);
            }
            system("pause");
        }
        else
        {
            cout << "\nGere um vetor antes de realizar operações!\n";
            system("pause");
        }
    }while(*op!=0);

    delete op, ok, minimo, maximo;
    delete[] arr;
}
