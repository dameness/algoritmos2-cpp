#include <iostream>
#include <ctime>
using namespace std;

/*
Escreva um programa que utilizando ponteiros manipule um vetor de 6 posições, o
sistema deverá ter uma função para gerar os valores para preencher o vetor com
valores aleatórios entre 1 e 50. Após deverá exibir o vetor e um relatório conforme
exemplo
*/
void gerar(int *vet, int tam)
{
    srand(time(NULL));

    for(int i=0; i<tam; i++)
         *(vet + i) = rand()%50 + 1; // valor(*) do endereço vet + i recebe valor aleatório
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

    cout << "\nRelatório\nOs números pares são:\n";
    for(int i=0; i<tam; i++)
    {
        if( *(vet+i) % 2 == 0 )
        {
            printf("número %d na posição %d\n", *(vet+i), i);
            *pt += *(vet+i);
        }
    }
    printf("Soma dos pares: %d\n", *pt);

    *pt=0;
    cout << "\nOs números ímpares são: \n";
    for(int i=0; i<tam; i++)
    {
        if( *(vet+i) % 2 != 0 )
        {
            printf("número %d na posição %d\n", *(vet+i), i);
            *pt += 1; //"*pt++" não funcionaria pois o operador '++' tem prioridade em relação a '*'
            //portanto *pt++ == *(pt++), para o resultado de *pt += 1, usar *(pt)++
        }
    }
    printf("Quantidade de ímpares: %d\n", *pt);
}
main() // main() não é uma funcao que precisa tipada e, dessa forma, nao precisa retornar nada
{
    setlocale(LC_ALL, "Portuguese");
    int vet[6];

    gerar(vet, 6);
    exibir(vet, 6);
    relatorio(vet, 6);
}
