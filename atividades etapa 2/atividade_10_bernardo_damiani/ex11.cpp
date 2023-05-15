#include <iostream>
using namespace std;

/*
Crie um programa que receba do usu�rio a informa��o de quantos n�meros deseja digitar, a seguir
o programa dever� receber os n�meros e apresentar na tela:
- Total de n�meros pares digitados
- Percentual de n�meros �mpares digitados
- M�dia dos n�meros digitados com duas casas decimais
- Maior n�mero digitado e em qual digita��o ele foi informado.

A partir de agora os exerc�cios n�o devem mais usar declara��o de vari�veis.
*/

void qtd(int **pn)
{
    cout << "\nQuantos n�meros voc� deseja digitar? ";
    cin >> **pn;
}
void ParOuImpar(int **arr, int **pn)
{
    int *contPar = new int(0);
    float *Imp = new float(0);

    for(int *i = new int(0); *i < **pn; (*i)++)
    {
        if((*arr)[*i]%2 == 0)
            (*contPar)++;
        else
            (*Imp)++;
    }

    *Imp = ((*Imp) * 100.0) / (**pn);

    printf("\nTotal de n�meros pares digitados: %d\n\nPercentual de n�meros �mpares digitados: %.2f%%\n", *contPar, *Imp);
}
void media(int **arr, int **pn)
{
    float *m = new float(0);

     for(int *i = new int(0); *i < **pn; (*i)++)
        *m += (*arr)[*i];

    *m = (*m)/(**pn);

    printf("\nM�dia dos n�meros digitados com duas casas decimais: %.2f\n", *m);
}
void maior(int **arr, int **pn)
{
    int *maior = new int;
    int *maiorPos = new int;

    for(int *i = new int(0); *i < **pn; (*i)++)
    {
        if(*i==1 || (*arr)[*i] > *maior)
        {
            *maior = (*arr)[*i];
            *maiorPos = *i;
        }
    }

    printf("\nMaior n�mero: %d\nDigita��o na qual foi informado o maior n�mero: %d\n\n", *maior, (*maiorPos)+1);
}

void resultado(int *pn)
{
    qtd(&pn);
    int *arr = new int[*pn];

    for(int *i = new int(0); *i < *pn; (*i)++)
    {
        printf("\narr[%d]: ", *i);
        cin >> arr[*i];
    }

    ParOuImpar(&arr, &pn);
    media(&arr, &pn);
    maior(&arr, &pn);

}
main()
{
    setlocale(LC_ALL, "Portuguese");

    int *pn = new int;

    resultado(pn);

}

