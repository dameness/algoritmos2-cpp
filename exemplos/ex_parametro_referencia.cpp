#include <iostream>
#include <cstring>
using namespace std;

int leitura(string msg);
void calculo(int &a, int &b);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x, y;

    x = leitura("Informe x: ");
    y = leitura("Informe y: ");

    cout << "\nValor inicial x: " << x;
    cout << " Valor inicial y: " << y;

    calculo(x, y);

    cout << "\n\nValor inicial x: " << x;
    cout << " Valor inicial y: " << y;
    cout << endl;
}
int leitura(string msg)
{
    int var;
    cout << msg;
    cin >> var;
    fflush(stdin);

    return var;

}
void calculo(int &a, int &b)
{
    if(a%2==0)
        a +=10;
    else
        a -=10;

    if(b%2==0)
        b+=50;
    else
        b-=50;
}
