#include <iostream>
#include <ctime>
using namespace std;

//o trabalho deu errado por que comparou parcialmente os elementos, logo, nao gerou todos os conjuntos
//corrigindo de forma que compara tudo

void gerar(int arr[], int tam);
void mostrar(int arr[], int tam);
int lerInt();
void igual_2(int v[], int x);
void igual_3(int v[], int x);
void igual_4(int v[], int x);
void igual_5(int v[], int x);
void igual_6(int v[], int x);
void igual_7(int v[], int x);
void igual_8(int v[], int x);
void igual_9(int v[], int x);
void igual_10(int v[], int x);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x;
    int VET[10] = {3, 5, 19, 4, 7, 54, 1, 2, 21, 18};

    x = lerInt();
    //gerar(VET, 10);
    cout << "\nVET: ";
    mostrar(VET, 10);
    igual_2(VET, x);
    igual_3(VET, x);
    igual_4(VET, x);
    igual_5(VET, x);
    igual_6(VET, x);
    igual_7(VET, x);
    igual_8(VET, x);
    igual_9(VET, x);
    igual_10(VET, x);
    cout << endl;

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
    cout << "\n";
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

    }
    while(x<=2 || x>=300);

    return x;
}

void igual_2(int v[], int x)
{
    for(int b=0; b<10; b++)
    {
        for(int a= b + 1; a<10; a++)
        {
            if(v[a] + v[b] == x)
                cout << "\n--> " << v[a] << ", " << v[b];
        }
    }
}
void igual_3(int v[], int x)
{
    for(int c=0; c<10; c++)
    {
        for(int b= c+1; b<10; b++)
        {
            for(int a= b+1; a<10; a++)
            {
                if(v[a] + v[b] + v[c] == x)
                    cout << "\n--> " << v[a] << ", " << v[b] << ", " << v[c];
            }
        }
    }
}
void igual_4(int v[], int x)
{
    for(int d=0; d<10; d++)
    {
        for(int c=d+1; c<10; c++)
        {
            for(int b=c+1; b<10; b++)
            {
                for(int a=b+1; a<10; a++)
                {
                    if(v[a] + v[b] + v[c] + v[d] == x)
                        cout << "\n--> " << v[a] << ", " << v[b] << ", " << v[c] << ", " << v[d];
                }
            }
        }
    }
}
void igual_5(int v[], int x)
{
    for(int e=0; e<10; e++)
    {
        for(int d=e+1; d<10; d++)
        {
            for(int c=d+1; c<10; c++)
            {
                for(int b=c+1; b<10; b++)
                {
                    for(int a=b+1; a<10; a++)
                    {
                        if(v[a] + v[b] + v[c] + v[d] + v[e] == x)
                            cout << "\n--> " << v[a] << ", " << v[b] << ", " << v[c] << ", " << v[d] << ", " << v[e];
                    }
                }
            }
        }
    }
}
void igual_6(int v[], int x)
{
    for(int f=0; f<10; f++)
    {
        for(int e=f+1; e<10; e++)
        {
            for(int d=e+1; d<10; d++)
            {
                for(int c=d+1; c<10; c++)
                {
                    for(int b=c+1; b<10; b++)
                    {
                        for(int a=b+1; a<10; a++)
                        {
                            if(v[a] + v[b] + v[c] + v[d] + v[e] + v[f] == x)
                                cout << "\n--> " << v[a] << ", " << v[b] << ", " << v[c] << ", " << v[d] << ", " << v[e] << ", " << v[f];
                        }
                    }
                }
            }
        }
    }
}
void igual_7(int v[], int x)
{
    for(int g=0; g<10; g++)
    {
        for(int f=g+1; f<10; f++)
        {
            for(int e=f+1; e<10; e++)
            {
                for(int d=e+1; d<10; d++)
                {
                    for(int c=d+1; c<10; c++)
                    {
                        for(int b=c+1; b<10; b++)
                        {
                            for(int a=b+1; a<10; a++)
                            {
                                if(v[a] + v[b] + v[c] + v[d] + v[e] + v[f] + v[g] == x)
                                    cout << "\n--> " << v[a] << ", " << v[b] << ", " << v[c] << ", " << v[d] << ", " << v[e] << ", " << v[f] << ", " << v[g];
                            }
                        }
                    }
                }
            }
        }
    }
}
void igual_8(int v[], int x)
{
    for(int h=0; h<10; h++)
    {
        for(int g=h+1; g<10; g++)
        {
            for(int f=g+1; f<10; f++)
            {
                for(int e=f+1; e<10; e++)
                {
                    for(int d=e+1; d<10; d++)
                    {
                        for(int c=d+1; c<10; c++)
                        {
                            for(int b=c+1; b<10; b++)
                            {
                                for(int a=b+1; a<10; a++)
                                {
                                    if(v[a] + v[b] + v[c] + v[d] + v[e] + v[f] + v[g] + v[h] == x)
                                        cout << "\n--> " << v[a] << ", " << v[b] << ", " << v[c] << ", " << v[d] << ", " << v[e] << ", " << v[f] << ", " << v[g] << ", " << v[h];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void igual_9(int v[], int x)
{
    for(int i=0; i<10; i++)
    {
        for(int h=i+1; h<10; h++)
        {
            for(int g=h+1; g<10; g++)
            {
                for(int f=g+1; f<10; f++)
                {
                    for(int e=f+1; e<10; e++)
                    {
                        for(int d=e+1; d<10; d++)
                        {
                            for(int c=d+1; c<10; c++)
                            {
                                for(int b=c+1; b<10; b++)
                                {
                                    for(int a=b+1; a<10; a++)
                                    {
                                        if(v[a] + v[b] + v[c] + v[d] + v[e] + v[f] + v[g] + v[h] + v[i] == x)
                                            cout << "\n--> " << v[a] << ", " << v[b] << ", " << v[c] << ", " << v[d] << ", " << v[e] << ", " << v[f] << ", " << v[g] << ", " << v[h] << ", " << v[i];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void igual_10(int v[], int x)
{
    for(int j=0; j<10; j++)
    {
        for(int i=j+1; i<10; i++)
        {
            for(int h=i+1; h<10; h++)
            {
                for(int g=h+1; g<10; g++)
                {
                    for(int f=g+1; f<10; f++)
                    {
                        for(int e=f+1; e<10; e++)
                        {
                            for(int d=e+1; d<10; d++)
                            {
                                for(int c=d+1; c<10; c++)
                                {
                                    for(int b=c+1; b<10; b++)
                                    {
                                        for(int a=b+1; a<10; a++)
                                        {
                                            if(v[a] + v[b] + v[c] + v[d] + v[e] + v[f] + v[g] + v[h] + v[i] + v[j] == x)
                                                cout << "\n--> " << v[a] << ", " << v[b] << ", " << v[c] << ", " << v[d] << ", " << v[e] << ", " << v[f] << ", " << v[g] << ", " << v[h] << ", " << v[i] << ", " << v[j];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

