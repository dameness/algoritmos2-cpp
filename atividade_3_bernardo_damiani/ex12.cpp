#include <iostream>
using namespace std;

/*
Escreva um programa que simule um caixa eletr�nico, sabendo que o caixa disp�e das
seguintes notas: 2, 5, 10, 20, 50, 100 e 200. O caixa deve priorizar (sempre que poss�vel) a
entrega das notas de maior valor, por exemplo:
Saque 75,00: uma nota de 50, uma nota de 20 e uma nota de 5
Saque 11,00: uma nota de 5, 3 notas de 2
Caso seja solicitado um valor inv�lido para saque dever� informar uma mensagem com tal
informa��o e solicitar a leitura de outro valor.
O valor do saque deve ser lido e validado utilizando fun��o
O c�lculo das notas dever� ser realizado utilizando uma fun��o que recebe como par�metro o
valor do saque e a nota e retornar a quantidade de notas do referido valor.
*/
int leitura();
void calculo(int x);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    calculo(leitura());

    return 0;
}
int leitura()
{
    int valor;
    do
    {
        system("cls");

        cout << "Informe um valor para sacar: ";
        cin >> valor;
        fflush(stdin);

        if(valor < 1)
        {
            cout << "\nValor inv�lido! Insira um valor v�lido!\n\n";
            system("pause");
        }

    }while(valor<1);//deixei o 3 e o 1 v�lidos pois utilizei a moeda de 1 real
    return valor;
}
void calculo(int valor)
{
    int n200, n100, n50, n20, n10, n5, n2, m1;

    n200 = valor / 200;
    valor %= 200;

    n100 = valor / 100;
    valor %= 100;

    n50 = valor / 50;
    valor %= 50;

    n20 = valor / 20;
    valor %= 20;

    n10 = valor / 10;
    valor %= 10;

    n5 = valor / 5;
    valor %= 5;

    n2 = valor / 2;
    valor %= 2;

    m1 = valor;

    printf("Notas de 200: %d\nNotas de 100: %d\nNotas de 50: %d\nNotas de 20: %d\nNotas de 10: %d\nNotas de 5: %d\nNotas de 2: %d\nMoedas de 1: %d\n", n200, n100, n50, n20, n10, n5, n2, m1);
}

