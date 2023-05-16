#include <iostream>
using namespace std;

/*
Crie um programa que receba do usuário a informação de quantos números deseja digitar, a seguir
o programa deverá receber os números e apresentar na tela:
- Total de números pares digitados
- Percentual de números ímpares digitados
- Média dos números digitados com duas casas decimais
- Maior número digitado e em qual digitação ele foi informado.

A partir de agora os exercícios não devem mais usar declaração de variáveis.
*/

void qtd(int **pn)
{
    cout << "\nQuantos números você deseja digitar? ";
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

    printf("\nTotal de números pares digitados: %d\n\nPercentual de números ímpares digitados: %.2f%%\n", *contPar, *Imp);

    delete contPar, Imp;
}
void media(int **arr, int **pn)
{
    float *m = new float(0);

     for(int *i = new int(0); *i < **pn; (*i)++)
        *m += (*arr)[*i];

    *m = (*m)/(**pn);

    printf("\nMédia dos números digitados com duas casas decimais: %.2f\n", *m);

    delete m;
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

    printf("\nMaior número: %d\nDigitação na qual foi informado o maior número: %d\n\n", *maior, (*maiorPos)+1);

    delete maior, maiorPos;
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

    delete arr;

}
main()
{
    setlocale(LC_ALL, "Portuguese");

    int *pn = new int;

    resultado(pn);

    delete pn;
}
