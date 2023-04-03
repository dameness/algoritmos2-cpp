#include <iostream>
#include <ctime>
using namespace std;

//o trabalho deu errado por que comparou parcialmente os elementos, logo, nao gerou todos os conjuntos

void gerar(int arr[], int tam);
void mostrar(int arr[], int tam);
int lerInt();
void somaValeX(int v[], int x);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int X;
    //int VET[10];

    X = lerInt();
    //gerar(VET, 10);
    int VET[10] = {3, 5, 19, 4, 7, 54, 1, 2, 21, 18};
    cout << "\nVET: ";
    mostrar(VET, 10);
    somaValeX(VET, X);

    return 0;
}
void gerar(int arr[], int tam)
{
    srand(time(NULL));
    int n;
    bool repete;

    for(int j=0; j<tam; j++)
    {
        do
        {
            n = rand()%30;
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
void mostrar(int arr[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << arr[i];
        if(i<tam-1)
            cout << ", ";
    }
    cout << "\n\n";
}
int lerInt()
{
    int x;

    do
    {
        system("cls");
        cout << "Diga o valor de X: ";
        cin >> x;

        if(x<=2 || x>=300)
        {
            cout << "\nVocê digitou um valor inválido! Digite novamente!\n";
            system("pause");
        }

    }while(x<=2 || x>=300);

    return x;
}
void somaValeX(int v[], int x)
{
    int soma, vSoma[10], cont;
    bool ok=0;
    for(int i=0; i<9; i++)
    {
        cont=0;
        soma = v[i];
        vSoma[cont]=v[i];
        cont++;

        for(int j=i+1; j<10; j++)
        {
            soma += v[j];
            vSoma[cont]= v[j];
            cont++;

            if(soma==x)
            {
                ok=1;
                cout << "--> ";
                mostrar(vSoma, cont);
            }
            else if(soma>x)
            {
                soma -= v[j];
                cont--;
            }

        }
    }
    if(ok==0)
    {
        cout << "\nNão houveram conjuntos cuja soma vale X.\n";
    }
}
