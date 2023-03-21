#include <iostream>
using namespace std;

/*
Faça um programa que receba dois valores inteiros e positivos, referentes a uma base e
um expoente, após crie uma função recursiva para realizar o cálculo e retornar o valor
resultante.
*/
int potencia(int b, int e);
void invalido();
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int base, exp;

    do
    {
        system("cls");

        cout << "Base: ";
        cin >> base;
        if(base<1)
        {
            invalido();
            continue;
        }

        cout << "Expoente: ";
        cin >> exp;
        if(exp<1)
        {
            invalido();
            continue;
        }

    }while(base<1 || exp<1);//enunciado aceita apenas valores positivos para essa potência

    cout << potencia(base, exp);

    return 0;
}
int potencia(int b, int e)
{
    //b^e = b * b^(e-1)

   if(e>1)
   {
       return b * (potencia(b, e-1));
   }
   else
       return b;

}
void invalido()
{
    cout << "Valor inválido! Digite os números novamente!\n";
    system("pause");
}
