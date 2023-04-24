#include <iostream>
#include <cstring>
using namespace std;

/*
Escreva uma fun��o recursiva que determine quantas vezes um d�gito K ocorre em um
n�mero natural N. Por exemplo, o d�gito 2 ocorre 3 vezes em 342021892.
O n�mero K e o valor N devem ser informados pelo usu�rio
Validar para que o d�gito K seja >=0 e <= 9
*/
void lerK(int &k)
{

    do
    {
        cout << "\nK: ";
        cin >> k;

        if(k<0 || k>9)
        {
            cout << "\nInv�lido! Digite novamente!\n";
            system("pause");
        }

    }
    while(k<0 || k>9);
}
void lerN(char n[])
{
    bool invalido;
    do
    {
        invalido = 0;
        cout << "\nInforme um n�mero natural N: ";
        fflush(stdin);
        gets(n);

        for(int i=0; i<strlen(n); i++)
        {
            if(!isdigit(n[i])) //� digito, portanto, tamb�m nao aceita o '-' e '.', e aceita apenas n�meros naturais
            {
                cout << "\nN�mero inv�lido! Digite novamente!\n";
                invalido = 1;
                system("pause");
                break;
            }
        }

    }while(invalido == 1);
}
int calcVezes(int k, char n[], int vezes, int x)
{
    char buffer[50];

    char K = k + '0';// converte k em char ao somar o inteiro com o '0'(48) na tabela ascii. por exemplo se k=5, 48 + 5 = 53, que corresponde a '5'

    if(x==strlen(n))
            return vezes;

    for(int i=x; i<strlen(n); i++)
    {
        if(n[i] == K)
            return calcVezes(k, n, vezes+1, x+1);
        else
            return calcVezes(k, n, vezes, x+1);
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int k;
    lerK(k);

    char n[30];
    lerN(n);

    int v = calcVezes(k, n, 0, 0);

    cout << "\nVezes que K aparece em N: " << v << "\n\n";

    return 0;
}

