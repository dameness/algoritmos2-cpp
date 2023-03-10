#include <iostream>
#include <cstring>
using namespace std;

/*
Uma palavra A é um anagrama de outra palavra B se podemos transformar a
palavra A na palavra B apenas trocando de posição as letras da palavra A.

Por exemplo,"iracema" é um anagrama de "america", e "estudo" é um anagrama de "duetos".

Sabendo deste conceito escreva um programa que receba duas palavras diferentes
quaisquer e verifique se elas são um anagrama exibindo como resposta “SIM”, caso não
são um anagrama exibir “NÃO”
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
        cout << "\nNÃO\n";
    else if(isAnagram(A, B))
        cout << "\nSIM\n";
    else
        cout << "\nNÃO\n";

    return 0;
}
int isAnagram(string a, string b)
{
    for(int i=0; i<a.size();i++)
    {
        if(b.find(a[i]) == string::npos)//.find() retorna string::npos se não encontra o valor
            return 0;
    }

    return 1;
}
