#include <iostream>
using namespace std;

/*
Escreva um programa que leia um valor inteiro N, sendo 3 <= N <= 9. Em seguida, imprima um padr�o
triangular de n�meros, conforme os exemplos abaixo.

Observa��o: Caso o valor de N seja inv�lido (fora do intervalo), o programa deve mostrar uma
mensagem de erro e um novo valor deve ser lido, at� que um valor v�lido seja digitado pelo usu�rio.
Utilize ponteiro e aritm�tica de ponteiro para resolver este exerc�cio.
*/
void leitura(int *n)
{
    do
    {
        cout << "\nN (3 <= N <= 9): ";
        cin >> *n;
        if(*n<3 || *n>9)
        {
            cout << "\nN inv�lido!\n";
            system("pause");
        }
    }while(*n<3 || *n>9);
    cout << endl;
}
void triangulo(int n)
{
    int vet[n] , *p = vet, i=0;

    while(i<n) //atribui valores de 1 a N para vet
    {

        *p = i+1;
        p++;
        i++;
    }
    p -= i;

    int *pInicial = p;

    while(i>-1)
    {
        for(int j=0; j<i; j++)
            cout << "  ";


        int aux = p - pInicial, j=0;

        while(j<aux)
        {
            cout << *pInicial << " ";
            pInicial++;
            j++;
        }
        pInicial-=aux;

        p++;
        i--;
        cout << endl;
    }
    p = pInicial;
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;

    leitura(&n);
    triangulo(n);


}

