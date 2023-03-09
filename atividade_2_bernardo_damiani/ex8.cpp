#include <iostream>
#include <cstring>
using namespace std;

/*
Escreva um programa que recebe uma string do usuário e verifica se ela é um
endereço de e-mail do google válido, sabendo que os endereços de e-mail do google
seguem o seguinte formato: textoqualquer@gmail.com

Algumas restrições importantes:
- endereços de e-mail não podem conter espaço em branco
- obrigatoriamente deve aparecer somente uma vez o caracter @
- considere que neste caso o endereço de e-mail não pode iniciar por um número
- endereço de e-mail só pode conter caracteres minúsculos
- o “_” underline e o “.” ponto podem aparecer entre duas palavras

Apresente como saída a mensagem “VÁLIDO” se o endereço for correto ou “INVÁLIDO”
se o endereço não estiver correto
*/
int main()
{
    setlocale(LC_ALL, "Portuguese");
    string email;

    cout << "Digite seu gmail: ";
    getline(cin, email);

    cout << endl;

    if (email.find("@gmail.com") != string::npos && email.find(" ") == string::npos && (email[email.size()-4] == '.' && email[email.size()-3] == 'c' && email[email.size()-2] == 'o' && email[email.size()-1] == 'm'))
    {//validacão de não conter espaços, da presença da substring "@gmail.com" e do ".com" estar nos últimos caracteres, para prevenir que não haja nada depois
        int arroba=0, certo;
        for(int i=0; i<email.size(); i++)
        {
            if(email[i]=='@')
            {
                arroba++;
                if(email[i-1]=='_' || email[i-1]=='.')//validando que se houver . ou _, estara apenas entre as palavras
                {
                    cout << "inválido!";
                    break;
                }

            }
            if(arroba>1 || !(isalpha(email[0])) || isupper(email[i]))
            {
                cout << "inválido!";
                break;
            }
            else if(i==email.size()-1)
                cout << "válido!";
        }
    }
    else
        cout << "inválido!";

    cout << endl;

        return 0;
}
