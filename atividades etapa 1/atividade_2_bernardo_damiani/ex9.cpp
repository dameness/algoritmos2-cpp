#include <iostream>
#include <cstring>
using namespace std;

/*
Um pangrama � uma frase que cont�m todas as letras de um determinado alfabeto.
Em portugu�s, um pangrama pode incluir tamb�m letras acentuadas, mas neste
problema vamos desconsiderar os acentos (mesmo que isso torne a frase mal escrita!),
tamb�m vamos considerar o seguintes alfabeto:

a b c d e f g h i j l m n o p q r s t u v x z

N�o consideramos as letras k, w ou y. Note ainda que as frases n�o cont�m letras
acentuadas mas podem conter s�mbolos gr�ficos como espa�o em branco, v�rgula, ponto
e dois pontos.

Entrada: uma �nica linha da entrada cont�ndo uma cadeia de caracteres C.

Sa�da: seu programa deve produzir uma �nica linha, contendo um �nico caractere, que deve
ser S se a frase for um pangrama ou N caso contr�rio.

Restri��es: a cadeia de caracteres C tem no m�nimo um e no m�ximo 200 caracteres. Os �nicos
caracteres em C s�o as letras min�sculas do alfabeto mostrado acima, podem existir
caracteres repetidos, espa�os em branco, v�rgulas, ponto e o caractere dois pontos.
*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char C[201], abc[23]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'z'};
    int pangrama[23]={0};

    cout << "Cadeia de caracteres C: ";
    gets(C);

    //usando o gets ao inv�s do "cin.getline para validar o tamanho m�ximo depois
    //sizeof = tamanho declarado; strlen = tamanho utilizado;
    if(strlen(C)>=1 && strlen(C)<=200)
    {
       for(int i=0; i<strlen(C); i++)
        {
            if(isupper(C[i])||C[i]=='k'||C[i]=='w'||C[i]=='y'||isdigit(C[i]))
            {// "letras ou s�mbolos gr�ficos" --> sem n�meros
                cout << "\nValor inv�lido!\n";
                break;
            }
            else
            {
                    for(int j=0; j<23; j++)
                    {
                        if(C[i]==abc[j])
                            pangrama[j]=1;
                    }
            }
        }
    }
    else
        cout << "\nValor inv�lido!\n";

    int pangramaOK=1;
    for(int i=0; i<23; i++)
    {
        if(pangrama[i]==0)
        {
            cout << "\nN";
            pangramaOK=0;
            break;
        }
    }

    if(pangramaOK==1)
        cout << "\nS";

    cout << "\n\n";

    return 0;
}
