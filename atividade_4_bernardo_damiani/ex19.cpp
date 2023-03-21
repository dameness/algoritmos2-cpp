#include <iostream>
using namespace std;

/*
Crie um programa que, utilizando uma função recursiva, inverta um número inteiro qualquer.
*/
void inverter(int n);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x;

    cout << "Número: ";
    cin >> x;

    cout << "Número invertido: ";
    inverter(x);
    cout << endl;

    return 0;
}
void inverter(int n)
{
    if(n<10)
    {
        cout << n;
        return;
    }
    else
    {
        cout << n%10;
        inverter(n/10);
    }
}
