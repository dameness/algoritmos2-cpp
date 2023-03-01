#include <iostream>
#include <cmath>
using namespace std;

/*
Elabore um programa que possibilite a realização dos seguintes cálculos:
1 – Potenciação (entrada dois valores inteiros e positivos)
2 – Raiz quadrada (entrada um valor inteiro e positivo)
3 - Arredondar o valor seguindo o critério da primeira casa decimal e mostrar na tela
(entrada um valor float)
4 – Verificar se um valor é primo ou não (entrada um valor inteiro positivo)
5 – Verificar se um valor é um número perfeito ou não (entrada um valor inteiro positivo).
O sistema deverá apresentar um menu com as opções e conforme a opção desejada será
solicitado os dados de entrada.
*/
void invalido()
{
    cout << "\nValor inválido! O programa será reiniciado!\n\n";
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

        cout << "Escolha uma opção:\n0 - Sair do programa\n1 - Potenciação\n2 – Raiz quadrada (entrada um valor inteiro e positivo)\n3 - Arredondar o valor seguindo o critério da primeira casa decimal e mostrar na tela(entrada um valor float)\n4 – Verificar se um valor é primo ou não (entrada um valor inteiro positivo)\n5 – Verificar se um valor é um número perfeito ou não (entrada um valor inteiro positivo)\n\n\tOpcão: ";
        cin >> option;
        cout << endl;

        if(option==0)
        {
          cout << "O programa será encerrado!\n";
          break;
        }
        else if(option==1)
        {
            cout << "Insira respectivamente a base e o expoente: ";
            cin >> x;
            cin >> y;
            cout << "\nO resultado da potência " << x << "^" << y << " é: " << pow(x, y) << "\n\n";
            // na ordem do exercício, pedia valores positivos, porém não validei pois a função pow() funciona com números negativos
        }
        else if(option==2)
        {
            cout << "Insira o radicando: ";
            cin >> x;
            if(x<0) // o 0 pode ser incluído pois tem raiz quadrada
            {
               invalido();
               continue;
            }
            cout << "\nO resultado da raiz quadrada de " << x << " é: " << sqrt(x) << "\n\n";
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
            cout << "Insira um número inteiro positivo: ";
            cin >> x;
            if(x<=0)
            {
               invalido();
               continue;
            }
            for(int i=2; i<x; i++)//o número primo não terá nenhum divisor exceto 1 e ele mesmo
            {
                if(x%i==0)
                    div++;
            }
            if(div>0)
                cout << "\nO número não é primo!\n\n";
            else
                cout << "\nO número é primo!\n\n";
        }
        else if(option==5)
        {
            int somaDiv=0;
            cout << "Insira um número inteiro positivo: ";
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
                cout << "\nO número não é perfeito!\n\n";
            else
                cout << "\nO número é perfeito!\n\n";
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
