#include <iostream>
#include <cstring>
using namespace std;

int leitura(string msg);
int calculo(int a, int b);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x, y;

    x = leitura("Informe x: ");
    y = leitura("Informe y: ");

    cout << "A soma de x e y é: " << calculo(x, y);


}
int leitura(string msg)
{
    int var;
    cout << msg;
    cin >> var;
    fflush(stdin);

    return var;

}
int calculo(int a, int b)
{
    int res = a+b;
    return res;

}
