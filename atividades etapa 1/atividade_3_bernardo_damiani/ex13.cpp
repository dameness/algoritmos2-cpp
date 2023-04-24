#include <iostream>
using namespace std;

/*
Escreva um programa que utilizando uma fun��o leia um n�mero inteiro qualquer, a seguir
execute outra fun��o que receba o valor por par�metro e gere e apresente na tela os primeiros
5 n�meros primos maiores que o valor informado.
*/
int leitura();
void proxPrimos(int x);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    proxPrimos(leitura());

    return 0;
}
int leitura()
{
    int n;
    cout << "Informe um n�mero inteiro qualquer: ";
    cin >> n;
    return n;
}
void proxPrimos(int x)
{
    int primos=0, vetPrimos[5], i=1;

    do
    {
        int div=0, n=x+i;

        for(int i=n; i>1; i--)
        {
            if(n%i==0)
                div++;
        }
        if(div==1)
        {
            vetPrimos[primos] = n;
            primos++;
        }
        i++;

    }while(primos<=5);

    cout << "\nPrimos: ";
    for(int i=0; i<5; i++)
    {
        cout << vetPrimos[i];
        if(i<4)
            cout << ", ";
    }
    cout << "\n";
}

