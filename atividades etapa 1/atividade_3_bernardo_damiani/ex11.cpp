#include <iostream>
#include <ctime>
using namespace std;

/*
Crie programa em C++ que manipule um vetor de inteiros de 10 posições, o programa
deve apresentar um menu com as seguintes opções:
0 – Sair
1 – Gerar Valores (Função que gera os valores para preencher o vetor com números entre 20 e
50 sem valores repetidos)
2 – Mostrar Vetor (Função que recebe o vetor e exibe seus valores na tela)
3 – Mostrar Ordenado (Função que recebe o vetor e exibe os seus valores ordenados em ordem
crescente e decrescente)

OBS: A opção 2 e 3 do menu só podem ser executadas após a execução da opção 1, ao escolher
a opção inválida do menu exibir mensagem de “opção inválida”.
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

        cout << "Opção: ";
        cin >> option;

        if(option<0 || option>3)
        {
            cout << "\nOpção inválida!\n\n";
            system("pause");
        }
        else if(option==0)
        {
            cout << "\nVocê sairá do programa!\n\n";
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
            cout << "\nO vetor ainda não foi gerado!\n\n";
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
