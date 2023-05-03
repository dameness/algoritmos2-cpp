#include <iostream>
#include <ctime>
using namespace std;

/*
Faça um programa que utilizando ponteiros preencha dois vetores, A e B, com dez
caracteres cada. A seguir, troque o 1o elemento de A com o 10o de B, o 2o de A com o
9o de B, e assim por diante, até trocar o 10o de A com o 1o de B. Mostre os vetores
antes e depois da troca.
*/
void gerar(char *vet, int tam)
{
    for(int i=0; i<tam; i++)
    {
        if(rand()%2) //geração de char do alfabeto, maiúsculo ou minúsculo, de acordo com a numeração da tabela ascii
        {
            *(vet + i) = rand()%26 + 97;
        }
        else
        {
            *(vet + i) = rand()%26 + 65;
        }
    }
}
void exibir(char *vet, int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << *(vet+i);

        if(i<tam-1)
            cout << ", ";
    }

    cout << endl;
}
void trocar(char *a, char *b, int tam)
{
    for(int i=0; i<tam; i++)
    {
        int aux = *(a + i);
        *(a + i) = *(b + (tam-1) - i);
        *(b + (tam-1) - i) = aux;
    }
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    char a[10], b[10];

    gerar(a, 10);
    gerar(b, 10);
    cout << "Vetor A: ";
    exibir(a, 10);
    cout << "Vetor B: ";
    exibir(b, 10);
    trocar(a, b, 10);
    cout << "\n   **  Ocorrência das trocas  **  \n\n";
    cout << "Vetor A: ";
    exibir(a, 10);
    cout << "Vetor B: ";
    exibir(b, 10);
}

