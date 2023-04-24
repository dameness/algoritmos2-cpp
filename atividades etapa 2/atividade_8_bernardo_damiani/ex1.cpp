#include <iostream>
#include <cmath>
using namespace std;

/*
Pedro comprou um saco de ração com peso em quilos. Ele possui dois gatos, para
os quais fornece a quantidade de ração em gramas. A quantidade diária de ração
fornecida para cada gato é sempre a mesma. Faça um programa que receba o peso do
saco de ração e a quantidade de ração fornecida para cada gato, calcule e mostre
quanto restará de ração no saco após cinco dias. Este exercício deverá ser resolvido com
a utilização de ponteiros.
*/
void leitura(int *racao, int *g1, int *g2)//vão apontar para os endereços passados como parâmetro
{
    cout << "\nQtd. do saco de ração (kg): ";
    cin >> *racao;//asterisco pois esta manipulando o valor

    cout << "Ração diária do gato  1 (g): ";
    cin >> *g1;

    cout << "Ração diária do gato  2 (g): ";
    cin >> *g2;
}
void checkRacao(int *racao, int g1, int g2)
{
    *racao *= 1000; // kg para g
    *racao -= 5*(g1+g2);

    cout << endl;

    if(*racao>=0)
    {
        cout << "Sobraram " << *racao << "g de ração após 5 dias!";
    }
    else
    {
        cout << "A ração foi insuficiente! Faltaram " << fabs(*racao) << "g!";
    }

    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int racao, g1, g2;

    leitura(&racao, &g1, &g2);
    checkRacao(&racao, g1, g2);

    return 0;
}
