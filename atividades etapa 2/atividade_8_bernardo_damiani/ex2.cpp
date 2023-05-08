#include <iostream>
#include <ctime>
using namespace std;

/*
Escreva um programa que utilizando ponteiros manipule um vetor de 6 posi��es, o
sistema dever� ter uma fun��o para gerar os valores para preencher o vetor com
valores aleat�rios entre 1 e 50. Ap�s dever� exibir o vetor e um relat�rio conforme
exemplo
*/
void gerar(int *vet, int tam)
{
    srand(time(NULL));

    for(int i=0; i<tam; i++)
         *(vet + i) = rand()%50 + 1; // valor(*) do endere�o vet + i recebe valor aleat�rio
}
void exibir(int *vet, int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << *(vet+i);

        if(i<tam-1)
            cout << ", ";
    }

    cout << endl;
}
void relatorio(int *vet, int tam)
{
    int t=0, *pt = &t;

    cout << "\nRelat�rio\nOs n�meros pares s�o:\n";
    for(int i=0; i<tam; i++)
    {
        if( *(vet+i) % 2 == 0 )
        {
            printf("n�mero %d na posi��o %d\n", *(vet+i), i);
            *pt += *(vet+i);
        }
    }
    printf("Soma dos pares: %d\n", *pt);

    *pt=0;
    cout << "\nOs n�meros �mpares s�o: \n";
    for(int i=0; i<tam; i++)
    {
        if( *(vet+i) % 2 != 0 )
        {
            printf("n�mero %d na posi��o %d\n", *(vet+i), i);
            *pt += 1; //"*pt++" n�o funcionaria pois o operador '++' tem prioridade em rela��o a '*'
            //portanto *pt++ == *(pt++), para o resultado de *pt += 1, usar *(pt)++
        }
    }
    printf("Quantidade de �mpares: %d\n", *pt);
}
main() // main() n�o � uma funcao que precisa tipada e, dessa forma, nao precisa retornar nada
{
    setlocale(LC_ALL, "Portuguese");
    int vet[6];

    gerar(vet, 6);
    exibir(vet, 6);
    relatorio(vet, 6);
}
