#include <iostream>
#include <cstring>
using namespace std;

/*
� Escreva um programa que receba um texto qualquer do teclado, em seguida
apresente:
- Total de caracteres do texto
- Total de caracteres em mai�sculo e em min�sculo do texto
- Total de vogais
- Total de consoantes
- Total de n�meros
- Total de espa�os em branco
*/
int main()
{
    setlocale(LC_ALL, "Portuguese");
    string texto;
    int upper=0, lower=0, vogais=0, consoantes=0, num=0, spaces=0;

    cout << "Digite um texto qualquer: ";
    getline(cin, texto);

    for(int i=0; i<texto.size(); i++)
    {
        if(isupper(texto[i]))
            upper++;
        if(islower(texto[i]))
            lower++;
        if(tolower(texto[i])=='a'||tolower(texto[i])=='e'||tolower(texto[i])=='i'||tolower(texto[i])=='o'||tolower(texto[i])=='u')
            vogais++;
        else if(isalpha(texto[i]))
            consoantes++;
        if(isdigit(texto[i]))
            num++;
        if(isspace(texto[i]))
            spaces++;
    }

    printf("\nQtd. de caracteres: %d\nQtd. de caracteres mai�sculos: %d\nQtd. de caracteres em min�sculo: %d\nQtd. de vogais: %d\nQtd. de consoantes: %d\nQtd. de n�meros: %d\nQtd. de espa�os em branco: %d\n", texto.size(), upper, lower, vogais, consoantes, num, spaces);

    return 0;
}
