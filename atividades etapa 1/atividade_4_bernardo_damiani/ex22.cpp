#include <iostream>
using namespace std;

/*
Escreva um programa que apresente os primeiros 20 termos da sequência de Fibonacci: “A
geração n de Fibonacci retorna 1 quando for até a 2a geração. Se não, retorna a soma das duas
últimas gerações anteriores”. Utilize uma função recursiva para resolver este problema.
*/
int fibonacci(int n);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    for(int i=0; i<20; i++)
        cout << fibonacci(i) << ", ";

    return 0;
}
int fibonacci(int n)
{
    //termo0 = 0; termo1 = 1
    //termoN = termoN-1 + termoN-2
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return(fibonacci(n-1)+fibonacci(n-2));
}

