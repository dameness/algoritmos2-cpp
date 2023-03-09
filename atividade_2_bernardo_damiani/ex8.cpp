#include <iostream>
#include <cstring>
using namespace std;

/*
Escreva um programa que recebe uma string do usu�rio e verifica se ela � um
endere�o de e-mail do google v�lido, sabendo que os endere�os de e-mail do google
seguem o seguinte formato: textoqualquer@gmail.com

Algumas restri��es importantes:
- endere�os de e-mail n�o podem conter espa�o em branco
- obrigatoriamente deve aparecer somente uma vez o caracter @
- considere que neste caso o endere�o de e-mail n�o pode iniciar por um n�mero
- endere�o de e-mail s� pode conter caracteres min�sculos
- o �_� underline e o �.� ponto podem aparecer entre duas palavras

Apresente como sa�da a mensagem �V�LIDO� se o endere�o for correto ou �INV�LIDO�
se o endere�o n�o estiver correto
*/
int main()
{
    setlocale(LC_ALL, "Portuguese");
    string email;

    cout << "Digite seu gmail: ";
    getline(cin, email);

    cout << endl;

    if (email.find("@gmail.com") != string::npos && email.find(" ") == string::npos && (email[email.size()-4] == '.' && email[email.size()-3] == 'c' && email[email.size()-2] == 'o' && email[email.size()-1] == 'm'))
    {//validac�o de n�o conter espa�os, da presen�a da substring "@gmail.com" e do ".com" estar nos �ltimos caracteres, para prevenir que n�o haja nada depois
        int arroba=0, certo;
        for(int i=0; i<email.size(); i++)
        {
            if(email[i]=='@')
            {
                arroba++;
                if(email[i-1]=='_' || email[i-1]=='.')//validando que se houver . ou _, estara apenas entre as palavras
                {
                    cout << "inv�lido!";
                    break;
                }

            }
            if(arroba>1 || !(isalpha(email[0])) || isupper(email[i]))
            {
                cout << "inv�lido!";
                break;
            }
            else if(i==email.size()-1)
                cout << "v�lido!";
        }
    }
    else
        cout << "inv�lido!";

    cout << endl;

        return 0;
}
