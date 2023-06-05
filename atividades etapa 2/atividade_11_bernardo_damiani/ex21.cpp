#include <iostream>
#include <cstring>
using namespace std;

/*
– Faça um programa que preencha três vetores com cinco posições cada. O primeiro vetor receberá os
nomes de cinco funcionários; o segundo e o terceiro vetor receberão, respectivamente, o salário e o
tempo de serviço de cada um.
Mostre um primeiro relatório apenas com os nomes dos funcionários que não terão aumento;
Mostre um segundo relatório apenas com os nomes e os novos salários dos funcionários que terão
aumento, sabe-se que os funcionários que terão direito ao aumento são aqueles que possuem tempo de
serviço superior a cinco anos ou salário inferior a R$ 1800,00, sabe-se, ainda, que, se o funcionário
satisfizer às duas condições anteriores, tempo de serviço e salário, o aumento será de 15%; para o
funcionário que satisfazer apenas à condição tempo de serviço, o aumento será de 10%; para aquele que
satisfazer apenas à condição salário, o aumento será de 5%.
*/
struct empregados
{
    string nome;
    float salario;
    int anosTrab;
};
void leitura(empregados *x)
{
    cout << "Nome: ";
    fflush(stdin);
    getline(cin, (*x).nome);
    cout << "\nSalário: ";
    cin >> (*x).salario;
    cout << "\nAnos trabalhados: ";
    cin >> (*x).anosTrab;
    cout << "\n";
}
void aumento(empregados *x, bool op)// 0 - mostrar os sem aumento  e  1  - os aumentados
{
    if(op==0)
    {
        if((*x).anosTrab <= 5 && (*x).salario >= 1800)
            printf("\n%s  ", (*x).nome.c_str());
    }
    else
    {
         if((*x).anosTrab <= 5 && (*x).salario < 1800) // 5%
         {
             printf("\n%s (%.2f)  ", (*x).nome.c_str(), ((*x).salario)*1.05 );

         }
         else if((*x).anosTrab > 5 && (*x).salario >= 1800)//10%
         {
             printf("\n%s (%.2f)  ", (*x).nome.c_str(), ((*x).salario)*1.1);
         }
        else if((*x).anosTrab > 5 && (*x).salario < 1800)//15%
         {
             printf("\n%s (%.2f)  ", (*x).nome.c_str(), ((*x).salario)*1.15);
         }
    }
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    struct empregados funcionario[5];
    int *i = new int;

    for(*i=0; *i<5; (*i)++)
    {
        leitura(&funcionario[*i]);
    }
    cout << "\nFuncionários sem aumento:\n";
     for(*i=0; *i<5; (*i)++)
    {
        aumento(&funcionario[*i], 0);
    }
    cout << "\n\nFuncionários com aumento e novos salários:\n";
    for(*i=0; *i<5; (*i)++)
    {
        aumento(&funcionario[*i], 1);
    }
    cout << "\n\n";
    delete i;
}
