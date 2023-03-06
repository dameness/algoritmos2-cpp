#include <iostream>
using namespace std;

/*
Escreva um programa que simule um caixa eletrônico que dispõe das seguintes notas: 2,
5, 10, 20, 50, 100 e 200 o programa deverá receber o valor do saque e, sendo possível realizar
o saque, deverá apresentar a quantidade e quais notas devem ser entregues, sempre
priorizando as notas maiores.
Não é permitido saque de valores menores que 2 e igual a 3 os demais valores é possível
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
            cout << "\nValor inválido! Insira um valor válido!\n\n";
            system("pause");
        }

    }while(valor==3 || valor<2);//ordem do exercício considera o 3 inválido

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
