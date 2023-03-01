#include <iostream>
#include <cmath>
using namespace std;

/*
Elabore um programa que possibilite a realiza��o dos seguintes c�lculos:
1 � Potencia��o (entrada dois valores inteiros e positivos)
2 � Raiz quadrada (entrada um valor inteiro e positivo)
3 - Arredondar o valor seguindo o crit�rio da primeira casa decimal e mostrar na tela
(entrada um valor float)
4 � Verificar se um valor � primo ou n�o (entrada um valor inteiro positivo)
5 � Verificar se um valor � um n�mero perfeito ou n�o (entrada um valor inteiro positivo).
O sistema dever� apresentar um menu com as op��es e conforme a op��o desejada ser�
solicitado os dados de entrada.
*/
void invalido()
{
    cout << "\nValor inv�lido! O programa ser� reiniciado!\n\n";
    system("pause");
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int option;

    do
    {
        system("cls");
        int x, y;

        cout << "Escolha uma op��o:\n0 - Sair do programa\n1 - Potencia��o\n2 � Raiz quadrada (entrada um valor inteiro e positivo)\n3 - Arredondar o valor seguindo o crit�rio da primeira casa decimal e mostrar na tela(entrada um valor float)\n4 � Verificar se um valor � primo ou n�o (entrada um valor inteiro positivo)\n5 � Verificar se um valor � um n�mero perfeito ou n�o (entrada um valor inteiro positivo)\n\n\tOpc�o: ";
        cin >> option;
        cout << endl;

        if(option==0)
        {
          cout << "O programa ser� encerrado!\n";
          break;
        }
        else if(option==1)
        {
            cout << "Insira respectivamente a base e o expoente: ";
            cin >> x;
            cin >> y;
            cout << "\nO resultado da pot�ncia " << x << "^" << y << " �: " << pow(x, y) << "\n\n";
            // na ordem do exerc�cio, pedia valores positivos, por�m n�o validei pois a fun��o pow() funciona com n�meros negativos
        }
        else if(option==2)
        {
            cout << "Insira o radicando: ";
            cin >> x;
            if(x<0) // o 0 pode ser inclu�do pois tem raiz quadrada
            {
               invalido();
               continue;
            }
            cout << "\nO resultado da raiz quadrada de " << x << " �: " << sqrt(x) << "\n\n";
        }
        else if(option==3)
        {
            float z;
            cout << "Insira um valor float: ";
            cin >> z;
            printf("\nValor arredondado de acordo com a regra da primeira casa decimal: %.0f\n\n", round(z));
        }
        else if(option==4)
        {
            int div=0;
            cout << "Insira um n�mero inteiro positivo: ";
            cin >> x;
            if(x<=0)
            {
               invalido();
               continue;
            }
            for(int i=2; i<x; i++)//o n�mero primo n�o ter� nenhum divisor exceto 1 e ele mesmo
            {
                if(x%i==0)
                    div++;
            }
            if(div>0)
                cout << "\nO n�mero n�o � primo!\n\n";
            else
                cout << "\nO n�mero � primo!\n\n";
        }
        else if(option==5)
        {
            int somaDiv=0;
            cout << "Insira um n�mero inteiro positivo: ";
            cin >> x;
            if(x<=0)
            {
               invalido();
               continue;
            }
            for(int i=1; i<x; i++)
            {
                if(x%i==0)
                    somaDiv+=i;
            }
            if(somaDiv!=x)
                cout << "\nO n�mero n�o � perfeito!\n\n";
            else
                cout << "\nO n�mero � perfeito!\n\n";
        }
        else
        {
            invalido();
            continue;
        }

        system("pause");

    }while(option!=0);

    return 0;
}
