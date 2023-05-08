#include <iostream>
using namespace std;

/*
Escreva uma fun��o que receba como par�metro um array de inteiros com N valores, e determina o
maior elemento do array e o n�mero de vezes que este elemento ocorreu no array. Por exemplo, para um
array com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a fun��o deve fornecer para o programa
que a chamou o valor 15 e o n�mero 3 (indicando que o n�mero 15 ocorreu 3 vezes). A fun��o deve ser
do tipo void, utilize ponteiros e aritm�tica de ponteiro para resolver este exerc�cio.
*/
void leitura(int **pArr, int n)
{
    int i=0;
    while(i<n)
    {
        printf("\narr[%d] = ", i);
        cin >> **pArr;
        (*pArr)++;
        i++;
    }
    *pArr-=i;
}
void maiorTermo(int *arr, int n)
{
    leitura(&arr, n);

    int i=0, maior, vezes;
    while(i<n)
    {
        if(i==0 || *arr > maior)
        {
            maior = *arr;
            vezes = 1;
        }
        else if(*arr == maior)
        {
            vezes++;
        }
       arr++;
       i++;
    }
    arr-=i;
    i=0;

    cout << "\narr: ";
    while(i<n)
    {
        cout << *arr;
        if(i < n-1)
            cout << ", ";

        arr++;
        i++;
    }
    printf("\n\nO maior n�mero de 'arr' foi [%d] que apareceu [%d]", maior, vezes);
    if(vezes==1)
        cout << " vez!";
    else
        cout << " vezes!";

    cout << endl;
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;

    cout << "Informe quantos valores ser�o lidos no array: ";
    cin >> n;

    int arr[n];

    maiorTermo(arr, n);


}

