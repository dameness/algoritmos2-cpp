#include <iostream>
using namespace std;

/*
Diz-se que um n�mero inteiro N � um quadrado perfeito se existirem M n�meros �mpares
consecutivos a partir do valor 1 cuja soma � igual a N. Neste caso N = M^2.

Exemplo:

16=1+3+5+7 (16 � igual � soma dos quatro primeiros �mpares a partir de 1) e 16=4^2.
25
36
49
64

Logo 16 representa um quadrado perfeito. Escreva um algoritmo que utilizando fun��es, verifique se um
valor inteiro positivo fornecido pelo usu�rio � um quadrado perfeito ou n�o.
*/
bool isQP(int n)
{
    int i=1, m=0, soma=0;

    do
    {
        soma+=i;
        m++;
        i+=2;
    }while(soma<n);

    if(m*m == n && soma == n)
        return 1;
    return 0;
}
int main()
{
    int n;
    setlocale(LC_ALL, "portuguese");

    do
    {
        cout << "Digite um n�mero inteiro positivo (se n<=0 o programa pedir� outro n�mero v�lido): ";
        cin >> n;
    }while(n<=0);

    if(isQP(n))
        cout << "\nO n�mero � um quadrado perfeito!\n";
    else
        cout << "\nO n�mero N�O � um quadrado perfeito!\n";

    return 0;
}
