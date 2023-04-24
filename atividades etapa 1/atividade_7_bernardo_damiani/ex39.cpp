#include <iostream>
#include <cstring>
using namespace std;

/*
Escreva uma função recursiva que determine quantas vezes um dígito K ocorre em um
número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 342021892.
O número K e o valor N devem ser informados pelo usuário
Validar para que o dígito K seja >=0 e <= 9
*/
void lerK(int &k)
{

    do
    {
        cout << "\nK: ";
        cin >> k;

        if(k<0 || k>9)
        {
            cout << "\nInválido! Digite novamente!\n";
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
        cout << "\nInforme um número natural N: ";
        fflush(stdin);
        gets(n);

        for(int i=0; i<strlen(n); i++)
        {
            if(!isdigit(n[i])) //é digito, portanto, também nao aceita o '-' e '.', e aceita apenas números naturais
            {
                cout << "\nNúmero inválido! Digite novamente!\n";
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

