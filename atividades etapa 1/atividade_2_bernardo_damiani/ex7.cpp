#include <iostream>
#include <cstring>
using namespace std;

/*
Escreva um programa que recebe uma string qualquer do usu�rio e imprime a
mesma string em tr�s formatos: todas as letras em mai�sculo, todas as letras em
min�sculo e somente as letras iniciais de cada palavra em mai�sculo o restante em
min�sculo.
*/
int main()
{
    setlocale(LC_ALL, "portuguese");
    string texto;

    cout << "Digite um texto qualquer: ";
    getline(cin, texto);

    for(int i=0; i<texto.size(); i++)
    {
        if(isalpha(texto[i]))
            texto[i]=toupper(texto[i]);
    }
    cout << "\nMai�sculo: " << texto;

    for(int i=0; i<texto.size(); i++)
    {
        if(isalpha(texto[i]))
            texto[i]=tolower(texto[i]);
    }
    cout << "\nMin�sculo: " << texto;

    for(int i=0; i<texto.size(); i++)
    {
        if(isalpha(texto[i]))
        {
            if((i>0 && isspace(texto[i-1])) || i==0)
                texto[i]=toupper(texto[i]);
            else
                texto[i]=tolower(texto[i]);
        }
    }
    cout << "\nFormatado: " << texto << endl;

    return 0;
}
