#include <iostream>
#include <cstring>
using namespace std;

/*
Implemente uma fun��o em C++ que receba dois ponteiros para strings e concatene o conte�do das
duas strings em uma terceira string. A terceira string deve ser alocada dinamicamente, apresente o
conte�do das tr�s strings.
*/

main()
{
    setlocale(LC_ALL, "Portuguese");
    char *s1 = new char[50], *s2 = new char[50];

    cout << "Digite as duas strings a serem concatenadas, com no m�ximo 50 caracteres cada (os demais n�o ser�o validados)\n\n";
    cout << "String 1: ";
    cin.getline(s1, 50);

    cout << "\nString 2: ";
    cin.getline(s2, 50);

    char *s3 = new char[strlen(s1)+strlen(s2)];

    s3 = strcat(s1, s2);

    cout << "\nConcatena��o: " << s3 << "\n"; //mostra a partir do endere�o

    delete[] s1, s2, s3;
}

