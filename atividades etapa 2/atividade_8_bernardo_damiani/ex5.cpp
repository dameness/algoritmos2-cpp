#include <iostream>
#include <ctime>
using namespace std;

/*
 Crie um programa que receba um valor qualquer representando o tamanho dos
lados de um quadrado, implemente uma função que receba esse valor e utilizando
ponteiros escreva com o caracter “*” asterisco na tela, um quadrado com as respectivas
diagonais,
*/

void leitura(int *n)
{
    cout << "Informe o tamanho da diagonal: ";
    cin >> *n;
}
void exibir(char *vet, int tam)
{
    for(int i=0; i<tam; i++)
        cout << *(vet+i) << " ";

    cout << endl;
}
void quad(char *vet, int tam)
{
    for(int i=0; i<tam; i++)
    {
        if(i==0 || i==tam-1)
        {
            for(int j=0; j<tam; j++)
                *(vet + j) = '*';
        }
        else
        {
            for(int j=0; j<tam; j++)
            {
                *(vet + j) = ' ';
            }
            for(int j=0; j<tam; j++)
            {
                if(j==0 || j==tam-1)
                    *(vet + j) = '*';
                else if(j==i)
                {
                    *(vet + j) = '*';
                    *(vet + (tam-1) - j) = '*';
                }
            }
        }

        exibir(vet, tam);
    }
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;
    leitura(&n);
    char vet[n];

    quad(vet, n);
}
