#include <iostream>
using namespace std;

/*
Diz-se que um número inteiro N é um quadrado perfeito se existirem M números ímpares
consecutivos a partir do valor 1 cuja soma é igual a N. Neste caso N = M^2.

Exemplo:

16=1+3+5+7 (16 é igual à soma dos quatro primeiros ímpares a partir de 1) e 16=4^2.
25
36
49
64

Logo 16 representa um quadrado perfeito. Escreva um algoritmo que utilizando funções, verifique se um
valor inteiro positivo fornecido pelo usuário é um quadrado perfeito ou não.
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
        cout << "Digite um número inteiro positivo (se n<=0 o programa pedirá outro número válido): ";
        cin >> n;
    }while(n<=0);

    if(isQP(n))
        cout << "\nO número é um quadrado perfeito!\n";
    else
        cout << "\nO número NÃO é um quadrado perfeito!\n";

    return 0;
}
