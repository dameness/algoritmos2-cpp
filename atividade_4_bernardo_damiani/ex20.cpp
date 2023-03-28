#include <iostream>
using namespace std;

/*
Crie um programa que implemente uma função recursiva para calcular o MDC (Máximo
Divisor Comum) entre dois números inteiros e positivos. Para calcular o MDC deve-se utilizar o
algoritmo de Euclides, que possui como conceito: “O MDC de dois números inteiros é o maior
número inteiro que divide ambos sem deixar resto”, a figura abaixo exemplifica o algoritmo de
Euclides.
*/
void invalido();
int mdc(int a, int b, int div);
int termoMin(int a, int b);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x, y;

     do
    {
        system("cls");

        cout << "Primeiro número: ";
        cin >> x;
        if(x<1)
        {
            invalido();
            continue;
        }

        cout << "Segundo número: ";
        cin >> y;
        if(y<1)
        {
            invalido();
            continue;
        }

    }while(x<1 || y<1);


    cout << "\nMaior divisor comum: " << mdc(x, y, termoMin(x, y)) << endl;

    return 0;
}
int mdc(int a, int b, int div)
{
    if(a%div==0 && b%div==0)
        return div;
    return mdc(a, b, div-1);//else
}
int termoMin(int a, int b)
{
    return a<b?a:b;
}
void invalido()
{
    cout << "Valor inválido! Digite os números novamente!\n";
    system("pause");
}

