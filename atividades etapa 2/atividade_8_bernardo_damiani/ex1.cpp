#include <iostream>
#include <cmath>
using namespace std;

/*
Pedro comprou um saco de ra��o com peso em quilos. Ele possui dois gatos, para
os quais fornece a quantidade de ra��o em gramas. A quantidade di�ria de ra��o
fornecida para cada gato � sempre a mesma. Fa�a um programa que receba o peso do
saco de ra��o e a quantidade de ra��o fornecida para cada gato, calcule e mostre
quanto restar� de ra��o no saco ap�s cinco dias. Este exerc�cio dever� ser resolvido com
a utiliza��o de ponteiros.
*/
void leitura(int *racao, int *g1, int *g2)//v�o apontar para os endere�os passados como par�metro
{
    cout << "\nQtd. do saco de ra��o (kg): ";
    cin >> *racao;//asterisco pois esta manipulando o valor

    cout << "Ra��o di�ria do gato  1 (g): ";
    cin >> *g1;

    cout << "Ra��o di�ria do gato  2 (g): ";
    cin >> *g2;
}
void checkRacao(int *racao, int g1, int g2)
{
    *racao *= 1000; // kg para g
    *racao -= 5*(g1+g2);

    cout << endl;

    if(*racao>=0)
    {
        cout << "Sobraram " << *racao << "g de ra��o ap�s 5 dias!";
    }
    else
    {
        cout << "A ra��o foi insuficiente! Faltaram " << fabs(*racao) << "g!";
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
