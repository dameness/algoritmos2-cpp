#include <iostream>
#include <cstring>
using namespace std;

/*
Crie um programa para manipular uma estrutura chamada "pessoa" com os campos
"nome" e "idade". Em seguida, o programa dever� apresentar um menu com as seguintes
op��es:
0 � Sair
1 � Cadastrar Pessoa
2 � Pessoa de maior e menor idade
3 � M�dia das idades
OBS: Utilize fun��es e passagem de par�metro para resolver este exerc�cio, as op��es 2 e 3 s�
poder�o ser executadas se existir ao menos uma pessoa cadastrada, o programa dever�
funcionar para qualquer quantidade de pessoa cadastrada, sendo no m�ximo 20.
*/
struct pessoa
{
    string nome;
    int idade;
};

void cadastrar(pessoa p[], int n);
int posMaiorMenorIdade(pessoa p[], int n, bool id=1);
float mediaId(pessoa p[], int n);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op, n=-1;
    bool ok=0;

    struct pessoa p[20];

    do
    {
        system("cls");
        cout << "0 - Sair\n1 - Cadastrar Pessoas\n2 - Pessoa de maior e de menor idade\n3 - M�dia das idades\n\n\tOp��o: ";
        cin >> op;

        if(op<0 || op>3)
        {
            cout << "\nOpc�o Inv�lida! Digite novamente!\n";
            system("pause");
        }
        else if(op==0)
        {
            cout << "\nVoc� sair� do programa!\n";
        }
        else if(op==1)
        {

            if(n<19)
            {
                n++;
                cadastrar(p, n);
                ok=1;
            }
            else
            {
                cout << "\nN�mero m�ximo de pessoas alcan�ado!\n";
                system("pause");
            }
        }
        else if(ok==1)
        {
            if(op==2)
            {
                int x = posMaiorMenorIdade(p, n), y = posMaiorMenorIdade(p, n, 0);

                cout << "\nA pessoa de maior idade � a " << x+1 << "� cadastrada e tem " << p[x].idade << " anos!\n";
                cout << "\nA pessoa de menor idade � a " << y+1 << "� cadastrada e tem " << p[y].idade << " anos!\n";

            }
            else if(op==3)
            {
                printf("\nM�dia das idades: %.1f\n", mediaId(p, n));
            }

            cout << endl;
            system("pause");
        }
        else
        {
            cout << "\nCadastre ao menos uma pessoa antes de realizar opera��es!\n";
            system("pause");
        }

    }while(op!=0);

    return 0;
}

void cadastrar(pessoa p[], int n)
{
    cout << "\nNome: ";
    fflush(stdin);
    getline(cin, p[n].nome);

    do
    {
        cout << "\nIdade: ";
        cin >> p[n].idade;
        if(p[n].idade<0)
        {
            cout << "\nIdade inv�lida! Digite novamente!\n";
            system("pause");
        }
    }while(p[n].idade<0);
}
int posMaiorMenorIdade(pessoa p[], int n, bool id)
{
    int m, pos;

    if(id==1)
    {
        for(int i=0; i<=n; i++)
        {
            if(i==0 || p[i].idade > m)
            {
                m = p[i].idade;
                pos = i;
            }
        }
    }
    else
    {
        for(int i=0; i<=n; i++)
        {
            if(i==0 || p[i].idade < m)
            {
                m = p[i].idade;
                pos = i;
            }
        }
    }

    return pos;
}
float mediaId(pessoa p[], int n)
{
    float soma=0;

    for(int i=0; i<=n; i++)
        soma += p[i].idade;

    return soma/(n+1);
}
