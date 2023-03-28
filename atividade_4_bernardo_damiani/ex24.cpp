#include <iostream>
#include <ctime>
using namespace std;

/*
Dado um vetor V[10] implemente um programa com as seguintes funções:
- Função para gerar valores para o vetor sem número repetidos e menores que 100.
- Função para mostrar os elementos do vetor na tela.
- Função RECURSIVA que recebe o vetor por parâmetro, percorrendo todo o vetor e retornando
o maior elemento existente no vetor, não é permitido o uso de laços de repetição para percorrer
o vetor.
*/
void randomArr(int arr[], int tam);
void print1D(int arr[], int tam);
int compare(int a, int b);
int maxVal(int arr[], int cont);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int v[10];

    randomArr(v, 10);
    cout << "Vetor: ";
    print1D(v, 10);
    cout << "Maior valor: " << maxVal(v, 10) << endl;

    return 0;
}
void randomArr(int arr[], int tam)
{
    srand(time(NULL));
    int n;
    bool repete;

    for(int j=0; j<tam; j++)
    {
        do
        {
            n = rand()%100;

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
void print1D(int arr[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << arr[i];
        if(i<tam-1)
            cout << ", ";
    }
    cout << "\n\n";
}
int compare(int a, int b)
{
    return a>b?a:b; //if a>b return a; else return b;
}
int maxVal(int arr[], int cont) // cont = tamanho do vetor
{

    if(cont==1)
        return arr[0];
    return compare(arr[cont-1], maxVal(arr, cont-1));//else não é necessário nesse caso

}

