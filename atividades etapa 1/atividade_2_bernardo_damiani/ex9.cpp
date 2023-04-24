#include <iostream>
#include <cstring>
using namespace std;

/*
Um pangrama é uma frase que contém todas as letras de um determinado alfabeto.
Em português, um pangrama pode incluir também letras acentuadas, mas neste
problema vamos desconsiderar os acentos (mesmo que isso torne a frase mal escrita!),
também vamos considerar o seguintes alfabeto:

a b c d e f g h i j l m n o p q r s t u v x z

Não consideramos as letras k, w ou y. Note ainda que as frases não contêm letras
acentuadas mas podem conter símbolos gráficos como espaço em branco, vírgula, ponto
e dois pontos.

Entrada: uma única linha da entrada conténdo uma cadeia de caracteres C.

Saída: seu programa deve produzir uma única linha, contendo um único caractere, que deve
ser S se a frase for um pangrama ou N caso contrário.

Restrições: a cadeia de caracteres C tem no mínimo um e no máximo 200 caracteres. Os únicos
caracteres em C são as letras minúsculas do alfabeto mostrado acima, podem existir
caracteres repetidos, espaços em branco, vírgulas, ponto e o caractere dois pontos.
*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char C[201], abc[23]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'z'};
    int pangrama[23]={0};

    cout << "Cadeia de caracteres C: ";
    gets(C);

    //usando o gets ao invés do "cin.getline para validar o tamanho máximo depois
    //sizeof = tamanho declarado; strlen = tamanho utilizado;
    if(strlen(C)>=1 && strlen(C)<=200)
    {
       for(int i=0; i<strlen(C); i++)
        {
            if(isupper(C[i])||C[i]=='k'||C[i]=='w'||C[i]=='y'||isdigit(C[i]))
            {// "letras ou símbolos gráficos" --> sem números
                cout << "\nValor inválido!\n";
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
        cout << "\nValor inválido!\n";

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
