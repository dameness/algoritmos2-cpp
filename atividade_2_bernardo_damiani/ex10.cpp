#include <iostream>
#include <cstring>
using namespace std;

/*
Uma palavra A � um anagrama de outra palavra B se podemos transformar a
palavra A na palavra B apenas trocando de posi��o as letras da palavra A.

Por exemplo,"iracema" � um anagrama de "america", e "estudo" � um anagrama de "duetos".

Sabendo deste conceito escreva um programa que receba duas palavras diferentes
quaisquer e verifique se elas s�o um anagrama exibindo como resposta �SIM�, caso n�o
s�o um anagrama exibir �N�O�
*/
int isAnagram(string a, string b);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    string A, B;

    cout << "Digite a palavra A: ";
    getline(cin, A);

    cout << "Digite a palavra B: ";
    getline(cin, B);

    if(A.size()!=B.size())
        cout << "\nN�O\n";
    else if(isAnagram(A, B))
        cout << "\nSIM\n";
    else
        cout << "\nN�O\n";

    return 0;
}
int isAnagram(string a, string b)
{
    for(int i=0; i<a.size();i++)
    {
        if(b.find(a[i]) == string::npos)//.find() retorna string::npos se n�o encontra o valor
            return 0;
    }

    return 1;
}
