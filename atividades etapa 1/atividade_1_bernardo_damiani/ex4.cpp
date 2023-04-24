#include <iostream>
#include <ctime>
using namespace std;

#define tam 10

/*
Crie um programa que manipule um vetor V[10] que deve ser preenchido randomicamente
com valores inteiros entre 15 e 50, sem n�meros repetidos.
Ap�s gerar o vetor o programa dever�:
- Exibir o vetor na tela
- Exibir o vetor em ordem crescente
- Exibir a quantidade de valores pares e �mpares existentes no vetor
- Exibir o percentual de valores pares e o percentual de valores �mpares no vetor
- Exibir a m�dia dos valores do vetor com duas casas decimais.
*/

void exibir(int vetor[], int tamanho);
void ordenar(int vetor[], int tamanho);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int v[tam], par=0, impar=0, soma=0;

    for(int i=0; i<tam; i++)
    {
        bool repete;

        do
        {
            repete=false;

            int n = rand()%36 + 15; //gera��o inclui o 15 e o 50

            for(int j=0; j<i; j++)
            {
                if(n == v[j])
                {
                    repete = true;
                    break;
                }
            }
            if(repete==false)
            {
                v[i] = n;

                if(v[i]%2==0)
                    par++;
                else
                    impar++;
                soma+=v[i];
            }
        }while(repete==true);
    }

    cout << "Vetor inicial: ";
    exibir(v, tam);
    cout << "\nVetor em ordem crescente: ";
    ordenar(v, tam);
    exibir(v, tam);

    float percPar = (par * 100)/tam, percImpar = 100 - percPar, media = float(soma)/tam;

    printf("\nH� %d valores pares (%.0f%) e %d valores �mpares (%.0f%) no vetor\n\nA m�dia dos valores do vetor � %.2f.\n\n", par, percPar, impar, percImpar, media);

    return 0;
}

void exibir(int vetor[], int tamanho)
{
    for(int i=0; i<tamanho; i++)
    {
        cout << vetor[i];
        if(i!=(tam-1))
            cout << ", ";
    }
    cout << "\n";
}
void ordenar(int vetor[], int tamanho)
{
    for(int i=0; i<tamanho-1; i++)
    {
        for(int j=i+1; j<tamanho; j++)
        {
            if(vetor[i]> vetor[j])
            {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j]= aux;
            }
        }
    }
}
