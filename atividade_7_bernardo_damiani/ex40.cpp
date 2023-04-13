#include <iostream>
#include <cstring>
using namespace std;

/*

*/
void lerK(int &k)
{

    do
    {
        cout << "\nInforme o digito verificador: ";
        cin >> k;

        if(k<1 || k>9)
        {
            cout << "\nInválido! Digite novamente!\n";
            system("pause");
        }

    }
    while(k<1 || k>9);
}
void lerN(char n[])
{
    bool invalido;
    do
    {
        invalido = 0;
        cout << "\nInforme um número inteiro qualquer: ";
        fflush(stdin);
        gets(n);

        for(int i=0; i<strlen(n); i++)
        {
            if(!isdigit(n[i]))
            {
                if(i==0 && n[i]=='-')// aceita menos pois a questao pede um numero inteiro
                    continue;

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

    char n[30];
    lerN(n);

    int k;
    lerK(k);

    int v = calcVezes(k, n, 0, 0);

    cout << "\nResposta: " << v << "\n\n";

    return 0;
}

