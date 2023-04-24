#include <iostream>
using namespace std;

/*
Escreva um programa que simule um caixa eletrônico, sabendo que o caixa dispõe das
seguintes notas: 2, 5, 10, 20, 50, 100 e 200. O caixa deve priorizar (sempre que possível) a
entrega das notas de maior valor, por exemplo:
Saque 75,00: uma nota de 50, uma nota de 20 e uma nota de 5
Saque 11,00: uma nota de 5, 3 notas de 2
Caso seja solicitado um valor inválido para saque deverá informar uma mensagem com tal
informação e solicitar a leitura de outro valor.
O valor do saque deve ser lido e validado utilizando função
O cálculo das notas deverá ser realizado utilizando uma função que recebe como parâmetro o
valor do saque e a nota e retornar a quantidade de notas do referido valor.
*/
int leitura();
int calc(int &val, int nota);
int transf_M5(int &val, int &notas2);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int valor = leitura(), n200, n100, n50, n20, n10, n5, n2;

    transf_M5(valor, n2);
    n200 = calc(valor, 200);
    n100 = calc(valor, 100);
    n50 = calc(valor, 50);
    n20 = calc(valor, 20);
    n10 = calc(valor, 10);
    n5 = calc(valor, 5);

    printf("Notas de 200: %d\nNotas de 100: %d\nNotas de 50: %d\nNotas de 20: %d\nNotas de 10: %d\nNotas de 5: %d\nNotas de 2: %d\n", n200, n100, n50, n20, n10, n5, n2);

    return 0;
}
int leitura()
{
    int valor;
    do
    {
        system("cls");

        cout << "Informe um valor para sacar (mínimo 2 reais, exceto 3 reais): ";
        cin >> valor;
        fflush(stdin);

        if(valor <2 || valor ==3)
        {
            cout << "\nValor inválido! Insira um valor válido!\n\n";
            system("pause");
        }

    }while(valor <2 || valor ==3);
    return valor;
}
int calc(int &val, int nota)
{
    int cont = 0;

    while(val >= nota)
    {
        cont ++;
        val -= nota;
    }
    return cont;
}
int transf_M5(int &val, int &notas2)
{
    notas2 = 0;

    while(val%5 != 0)
    {
        notas2++;
        val-=2;
    }
}



