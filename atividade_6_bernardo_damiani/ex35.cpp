#include <iostream>
using namespace std;

/*
Dados o número total de espaços e figurinhas do álbum, e uma lista das figurinhas já
compradas (que pode conter figurinhas repetidas), sua tarefa é determinar quantas figurinhas
faltam para completar o álbum.
Entrada

A primeira linha contém um inteiro N indicando o número total de figurinhas e espaços no
álbum. A segunda linha contém um inteiro M indicando o número de figurinhas já compradas.
Cada uma das M linhas seguintes contém um número inteiro X indicando uma figurinha já
comprada.
Saída

Seu programa deve produzir uma única linha contendo um inteiro, o número de figurinhas que
falta para completar o álbum.
Restrições
1 ≤ N ≤ 100
1 ≤ M ≤ 300
1 ≤ X ≤ N
*/
struct album
{
    bool fig[100]; // 1 a n  -- usa o indice
    int compradas[300];//1 a m -- usa o valor
};
int main()
{
    setlocale(LC_ALL, "Portuguese");

    //cin n --> fig definidas 0 ate n-1
    struct album a;
    int N, M;
    do
    {
        cin >> N;

        if(N<1 || N>100)
        {
            cout << "\nValor inválido! Digite novamente!";
            system("pause");
        }

    }
    while(N<1 || N>100);

    for(int i=0; i<N; i++)
        a.fig[i]=0;

    //cin m --> compradas definidas 0 ate m-1
    do
    {
        cin >> M;

        if(M<1 || M>300)
        {
            cout << "\nValor inválido! Digite novamente!";
            system("pause");
        }

    }
    while(M<1 || M>300);
    //cin x1 ate xm  --> elementos do compradas
    for(int i=0; i<M; i++)
    {
        int x;
        do
        {
            cin >> x;

            if(x<1 || x>N)
            {
                cout << "\nValor inválido! Digite novamente!";
                system("pause");
            }
            else
                a.compradas[i] = x - 1;//pois se for, por exemplo, a figurinha 1, ficará depois na posicao 0 (1° posicao) do vetor fig
        }
        while(x<1 || x>N);
    }
    //troca de 0 para 1 os elementos de fig cujo indice é igual a o valor de um elemento de compradas
    for(int i=0; i<M; i++)
    {
        a.fig[a.compradas[i]] = 1;
    }
    //faz um contador que conta os valores '0' em fig de i==0 até i==n-1
    int cont=0;
    for(int i=0; i<N; i++)
    {
        if(a.fig[i]==0)
            cont++;
    }
    //apresenta o contador como saída
    cout << "\n\n";
    cout << cont;

    return 0;
}
