#include <iostream>
using namespace std;

/*
Crie um programa que calcula o n-ésimo número harmônico que é calculado pela seguinte
fórmula: H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n, sendo (n >=1). Escreva uma função
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
        cout << "Digite o número(n(int) >= 1): ";
        cin >> n;
        if(n<1)
        {
            cout << "Inválido!\n";
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



