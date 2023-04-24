#include <iostream>
using namespace std;

/*
Fa�a um programa que receba dois valores inteiros e positivos, referentes a uma base e
um expoente, ap�s crie uma fun��o recursiva para realizar o c�lculo e retornar o valor
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

    }while(base<1 || exp<1);//enunciado aceita apenas valores positivos para essa pot�ncia

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
    cout << "Valor inv�lido! Digite os n�meros novamente!\n";
    system("pause");
}
