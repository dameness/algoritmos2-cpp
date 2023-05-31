#include <iostream>
using namespace std;

/*
Utilizando de ponteiros e aloca��o din�mica de mem�ria, escreva um programa que receba um
n�mero qualquer N, sendo 3 >= N <= 20 e apresente um losango conforme os exemplos.
*/
void losango(int *n)
{
    int *i = new int, *j = new int;

    for(*i=0; *i<=*n; (*i)++)
    {
        for(*j=*n; *j>*i; (*j)--)
        {
            cout << " ";
        }
        for(*j=0; *j<*i; (*j)++)
        {
            cout << *n << " ";
        }
        cout << endl;
    }
    for(*i=0; *i<*n; (*i)++)
    {
        for(*j=0; *j<=*i; (*j)++)
        {
            cout << " ";
        }
        for(*j=*n-1; *j>*i; (*j)--)
        {
            cout << *n << " ";
        }
        cout << endl;
    }

    delete i, j;
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    int *n = new int;

    do
    {
        system("cls");
        cout << "Digite um n�mero entre 3 e 20: ";
        cin >> *n;

        if(*n<3 || *n>20)
        {
            cout << "\nInv�lido!\n";
            system("pause");
        }
    }while(*n<3 || *n>20);

    losango(n);
    delete n;
}

