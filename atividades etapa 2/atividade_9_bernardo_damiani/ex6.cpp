#include <iostream>
#include <string.h>
using namespace std;

/*
Crie um programa que receba um texto qualquer do teclado e implemente uma função que utilizando
aritmética de ponteiro realize as seguintes ações:
- Transformar todos os caracteres do texto para maiúsculo
- Remover os caracteres especiais existentes no texto
- Remover os espaços em branco.
- Contar quantas vogais existem no texto.
- Mostrar o texto resultante.
- Mostrar o total de vogais existentes no texto.
*/

void modificar(char *t, int tam)
{
    cout << "\nString inicial: ";
    int i=0;
    while(i<tam)
    {
        cout << *t;
        t++;
        i++;
    }
    t -= i;
    i=0;

    int vogais =0;

    cout << "\n\nString formatada: ";
    while(i<tam)
    {
        if(isalnum(*t))
        {
            *t = toupper(*t);
            cout << *t;

            if(*t == 'A' || *t == 'E' || *t == 'I' || *t == 'O' || *t == 'U')
               vogais++;
        }
        t++;
        i++;
    }
    t -= i;
    i=0;
    cout << "\n\nQtd. de vogais: " << vogais << endl;

}
main()
{
    setlocale(LC_ALL, "Portuguese");
    char t[200];

    cout << "Digite um texto qualquer: ";
    gets(t);

    modificar(t, strlen(t));

}

