#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/*
Crie um programa para manipular uma estrutura chamada "hora" com os campos "horas",
"minutos" e “segundos”. Em seguida, escreva uma função que receba como parâmetro dois
valores inteiros expresso em segundos a função calcular e apresentar a diferença entre esses
dois valores em Horas:Minutos:Segundo. Após apresentar o resultado o programa deve solicitar
se o usuário deseja verificar outros valores (S) ou encerrar o programa (N).
*/
struct hora
{
    int horas;
    int minutos;
    int segundos;
};

int ler();
void calcular(hora dif, int s1, int s2);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char op;
    struct hora dif;

    do
    {
        system("cls");

        int s1 = ler();
        int s2 = ler();

        calcular(dif, s1, s2);


        cout << "\nDeseja verificar outros valores (S ou N): ";
        cin >> op;

        op = tolower(op);

        if(op!='s' && op!='n')
        {
            cout << "\nValor inválido!\n";
            system("pause");
        }


    }while(op!='n');

    return 0;
}

int ler()
{
    int s;

    do
    {
        cout << "\nValor em segundos: ";
        cin >> s;

        if(s<0)
        {
            cout << "\nValor inválido! Digite novamente!\n";
            system("pause");
        }

    }while(s<0);

    return s;
}

void calcular(hora dif, int s1, int s2)
{
    int x = fabs(s1 - s2);

    dif.horas = x/3600;
    x = x%3600;
    dif.minutos = x/60;
    x = x%60;
    dif.segundos = x;

    printf("\nDiferença --> %d:%d:%d\n", dif.horas, dif.minutos, dif.segundos);
}


