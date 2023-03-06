#include <iostream>
using namespace std;

/*
Escreva um programa que simule um caixa eletr�nico que disp�e das seguintes notas: 2,
5, 10, 20, 50, 100 e 200 o programa dever� receber o valor do saque e, sendo poss�vel realizar
o saque, dever� apresentar a quantidade e quais notas devem ser entregues, sempre
priorizando as notas maiores.
N�o � permitido saque de valores menores que 2 e igual a 3 os demais valores � poss�vel
realizar o saque:
*/
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int valor, n200, n100, n50, n20, n10, n5, n2;

    do
    {
        system("cls");

        cout << "Informe um valor para sacar em notas: ";
        cin >> valor;
        fflush(stdin);

        if(valor==3 || valor < 2)
        {
            cout << "\nValor inv�lido! Insira um valor v�lido!\n\n";
            system("pause");
        }

    }while(valor==3 || valor<2);//ordem do exerc�cio considera o 3 inv�lido

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

    printf("Notas de 200: %d\nNotas de 100: %d\nNotas de 50: %d\nNotas de 20: %d\nNotas de 10: %d\nNotas de 5: %d\nNotas de 2: %d\n", n200, n100, n50, n20, n10, n5, n2);

    if(valor>0)
        cout << "Alem disso, sera entregue uma moeda de um real.\n";

    return 0;
}
