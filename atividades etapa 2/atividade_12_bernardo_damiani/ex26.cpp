#include <iostream>
#include <cstring>
using namespace std;

/*
Implemente uma função em C++ que receba dois ponteiros para strings e concatene o conteúdo das
duas strings em uma terceira string. A terceira string deve ser alocada dinamicamente, apresente o
conteúdo das três strings.
*/

main()
{
    setlocale(LC_ALL, "Portuguese");
    char *s1 = new char[50], *s2 = new char[50];

    cout << "Digite as duas strings a serem concatenadas, com no máximo 50 caracteres cada (os demais não serão validados)\n\n";
    cout << "String 1: ";
    cin.getline(s1, 50);

    cout << "\nString 2: ";
    cin.getline(s2, 50);

    char *s3 = new char[strlen(s1)+strlen(s2)];

    s3 = strcat(s1, s2);

    cout << "\nConcatenação: " << s3 << "\n"; //mostra a partir do endereço

    delete[] s1, s2, s3;
}

