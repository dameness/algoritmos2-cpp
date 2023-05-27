#include <iostream>
#include <cstring>
using namespace std;

/*
� Fa�a um programa que preencha tr�s vetores com cinco posi��es cada. O primeiro vetor receber� os
nomes de cinco funcion�rios; o segundo e o terceiro vetor receber�o, respectivamente, o sal�rio e o
tempo de servi�o de cada um.
Mostre um primeiro relat�rio apenas com os nomes dos funcion�rios que n�o ter�o aumento;
Mostre um segundo relat�rio apenas com os nomes e os novos sal�rios dos funcion�rios que ter�o
aumento, sabe-se que os funcion�rios que ter�o direito ao aumento s�o aqueles que possuem tempo de
servi�o superior a cinco anos ou sal�rio inferior a R$ 1800,00, sabe-se, ainda, que, se o funcion�rio
satisfizer �s duas condi��es anteriores, tempo de servi�o e sal�rio, o aumento ser� de 15%; para o
funcion�rio que satisfazer apenas � condi��o tempo de servi�o, o aumento ser� de 10%; para aquele que
satisfazer apenas � condi��o sal�rio, o aumento ser� de 5%.
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
    cout << "\nSal�rio: ";
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
    cout << "\nFuncion�rios sem aumento:\n";
     for(*i=0; *i<5; (*i)++)
    {
        aumento(&funcionario[*i], 0);
    }
    cout << "\n\nFuncion�rios com aumento e novos sal�rios:\n";
    for(*i=0; *i<5; (*i)++)
    {
        aumento(&funcionario[*i], 1);
    }
    cout << "\n\n";
    delete i;
}
