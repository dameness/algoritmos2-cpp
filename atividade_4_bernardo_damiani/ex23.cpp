#include <iostream>
using namespace std;

/*
Crie um programa que calcula o n-�simo n�mero harm�nico que � calculado pela seguinte
f�rmula: H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n, sendo (n >=1). Escreva uma fun��o
recursiva que calcula H(n).
*/

float harmonico(int n);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;
    cout << fixed;
    cout.precision(2);

    do
    {
        system("cls");
        cout << "Digite o n�mero(n(int) >= 1): ";
        cin >> n;
        if(n<1)
        {
            cout << "Inv�lido!\n";
            system("pause");
        }

    }while(n<1);

    cout << harmonico(n);

    return 0;
}
float harmonico(int n)
{
    if(n==1)
        return 1.0;
    else
        return 1.0/n + harmonico(n-1.0);
}



