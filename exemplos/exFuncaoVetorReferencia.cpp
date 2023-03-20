#include <iostream>
#include <ctime>
using namespace std;

// exercício para mostrar que a passagem de vetores na função é sempre por referência --> modifica o vetor na memória, não apenas na função
void gerar(int arr[], int tam);
void mostrar1D(int arr[], int tam);
void modificarTeste(int arr[], int tam);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int a1[10];

    gerar(a1, 10);
    mostrar1D(a1, 10);
    modificarTeste(a1, 10);
    mostrar1D(a1, 10);

    return 0;
}
void gerar(int arr[], int tam)
{
    int n;
    bool repete;

    for(int j=0; j<tam; j++)
    {
        do
        {
            n = rand()%49 + 36; // entre 35 e 85 sem incluir ambos e sem repetir

            repete = 0;

            for(int i=0; i<j; i++)
            {
                if(n==arr[i])
                {
                    repete=1;
                    break;
                }
            }
            if(repete==0)
                arr[j] = n;


        }
        while(repete==1);
    }
}
void mostrar1D(int arr[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << arr[i];
        if(i<tam-1)
            cout << ", ";
    }
    cout << "\n\n";
}
void modificarTeste(int arr[], int tam)
{
    for(int i=0; i<tam; i++)
        arr[i] = arr[i] + 1;
}
