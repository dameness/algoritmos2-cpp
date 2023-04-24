#include <iostream>
#include <cstring>
using namespace std;

struct data
{
    int dia;
    int mes;
    int ano;
};

void validarData(data &d, int diasMeses[]); // como não estou usando um vetor, é necessário passar essa variável de struct por referencia!
void contDias(data d, int diasMeses[]);
void line();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct data d;
    int diasMeses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //29 dias do bissexto fixado na validacao

    validarData(d, diasMeses);
    contDias(d, diasMeses);

    return 0;
}
void validarData(data &d, int diasMeses[])
{

    do
    {
        system("cls");
        cout << "Ano: ";
        cin >> d.ano;
        if(d.ano<1)
        {
           cout << "\nAno inválido! Digite novamente!\n";
           system("pause");
           continue;
        }
        cout << "Mês: ";
        cin >> d.mes;
        if(d.mes<1 || d.mes>12)
        {
           cout << "\nMês inválido! Digite novamente!\n";
           system("pause");
           continue;
        }
        cout << "Dia: ";
        cin >> d.dia;
        if(d.dia<1 || (d.mes==2 && d.ano%4==0 && d.dia>29) || (d.mes==2 && d.ano%4!=0 && d.dia>28) || ((d.mes==4 || d.mes==6 || d.mes==9 || d.mes==11) && d.dia>30) || d.dia>31)
        {
           cout << "\nDia inválido! Digite novamente!\n";
           system("pause");
           continue;
        }
        if(d.ano%4==0)
            diasMeses[1] = 29;

    }while(d.ano<1 || d.mes<1 || d.mes>12 || (d.dia<1 || (d.mes==2 && d.ano%4==0 && d.dia>29) || (d.mes==2 && d.ano%4!=0 && d.dia>28) || ((d.mes==4 || d.mes==6 || d.mes==9 || d.mes==11) && d.dia>30) || d.dia>31));


}
void contDias(data d, int diasMeses[])
{
    int soma=0;
    for(int i=0; i<d.mes-1; i++)
    {
        soma += diasMeses[i];
    }
    soma += d.dia;//mes atual

    int r;
    if(diasMeses[1]==29)
        r = 366 - soma;
    else
        r = 365 - soma;

    line();
    printf("Dia informado: %d\nMês Informado: %d\nAno informado: %d\nDias transcorridos no ano: %d\nDias restantes no ano: %d\n", d.dia, d.mes, d.ano, soma, r);
    line();
}
void line()
{
    for(int i=0; i<40; i++)
        cout << "-";
    cout << "\n";
}

