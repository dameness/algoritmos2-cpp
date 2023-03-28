#include <iostream>
#include <cstring>
using namespace std;

/*
Crie um programa que manipule uma estrutura capaz de descrever um mês do ano. A
estrutura deve conter os seguintes membros: número do mês, nome por extenso do mês,
abreviatura com as três iniciais do mês e o número de dias do mês (validar o mês de fevereiro
em caso de ano bissexto).
Após alimentar os dados para esta estrutura o programa deve solicitar um dia e um mês
qualquer e deverá mostrar o total de dias já transcorrido no corrente ano, o dia e mês
informado e os dados (nome, abreviatura, total de dias) referente ao mês informado, caso seja
informado dia ou mês inválido deverá apresentar uma mensagem com tal informação.
*/
struct month
{
    int num;
    string name;
    string name_abr;
    int days;
};
int contDias(month arr[], int d, int m);
void line();
void showInfo(month arr[], int n);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct month mArr[12];
    mArr[0] = {1, "Janeiro", "Jan", 31};
    mArr[1] = {2, "Fevereiro", "Fev", 28};//validado depois
    mArr[2] = {3, "Março", "Mar", 31};
    mArr[3] = {4, "Abril", "Abr", 30};
    mArr[4] = {5, "Maio", "Mai", 31};
    mArr[5] = {6, "Junho", "Jun", 30};
    mArr[6] = {7, "Julho", "Jul", 31};
    mArr[7] = {8, "Agosto", "Ago", 31};
    mArr[8] = {9, "Setembro", "Set", 30};
    mArr[9] = {10, "Outubro", "Out", 31};
    mArr[10] = {11, "Novembro", "Nov", 30};
    mArr[11] = {12, "Dezembro", "Dez", 31};
    int d, m, y;

    do
    {
        system("cls");
        cout << "Ano: "; // solicitei um ano para poder validar se é bissexto ou não e mudar a qtd. de dias de fevereiro
        cin >> y;
        if(y<1)
        {
           cout << "\nAno inválido! Digite novamente!\n";
           system("pause");
           continue;
        }
        cout << "Mês: ";
        cin >> m;
        if(m<1 || m>12)
        {
           cout << "\nMês inválido! Digite novamente!\n";
           system("pause");
           continue;
        }
        cout << "Dia: ";
        cin >> d;
        if(d<1 || (m==2 && y%4==0 && d>29) || (m==2 && y%4!=0 && d>28) || ((m==4 || m==6 || m==9 || m==11) && d>30) || d>31)
        {
           cout << "\nDia inválido! Digite novamente!\n";
           system("pause");
           continue;
        }               //validar!

        if(y%4==0)
            mArr[1].days = 29;

    }while(y<1 || m<1 || m>12 || (d<1 || (m==2 && y%4==0 && d>29) || (m==2 && y%4!=0 && d>28) || ((m==4 || m==6 || m==9 || m==11) && d>30) || d>31));
    line();
    printf("Dia informado: %d\nMês Informado: %d\nAno informado: %d\nDias transcorridos no ano: %d\n",d, m, y, contDias(mArr, d, m));
    line();
    showInfo(mArr, m-1);
    line();


    return 0;
}
int contDias(month arr[], int d, int m)
{
    int soma=0;
    for(int i=0; i<m-1; i++)
    {
        soma += arr[i].days;
    }
    soma += d;//mes atual

    return soma;
}
void line()
{
    for(int i=0; i<40; i++)
        cout << "-";
    cout << "\n";
}
void showInfo(month arr[], int n)
{
    printf("Número do Mês: %d\nNome: %s\nAbr.: %s\nQtd. de dias: %d\n", arr[n].num, arr[n].name.c_str(), arr[n].name_abr.c_str(), arr[n].days); //.c_str() para funcionar no printf
}
