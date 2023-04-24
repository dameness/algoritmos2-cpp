#include <iostream>
#include <cstring>
using namespace std;

/*
Fa�a um programa que realize o cadastro de contas banc�rias com as seguintes
informa��es: n�mero da conta, nome do cliente e saldo. O banco permite o cadastramento de
10 contas e n�o poder� haver mais que uma conta com o mesmo n�mero. O sistema dever�
apresentar um menu com as seguintes op��es:

1 � Cadastrar contas;
2 � Visualizar dados da conta; (deve ser informado o n�mero da conta)
3 � Depositar; (deve ser informado o n�mero da conta e o valor a ser depositado)
4 � Sacar; (deve ser informado o n�mero da conta e o valor a ser sacado, validar se o saque
pode ser realizado ou n�o)
5 � Pix; (deve ser informado o n�mero da conta de origem, o n�mero da conta de destino e o
valor, existindo saldo na conta de origem o programa deve realizar a transfer�ncia, atualizando
o saldo nas duas contas)
6 � Sair;
*/
struct contas
{
    int numero;
    string cliente;
    float saldo;
};
void cadastrarConta(contas c[], int n);
int checkNum(contas c[], int num);
void line();
void mostrarConta(contas c[], int n);
void DepositoOuSaque(contas c[], int n, char DS);
void pix(contas c[], int n1, int n2); // ARRUMAR PARA CHECAR SALDO

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct contas conta[10];
    int op, ok=0, n=-1;

    do
    {
        system("cls");
        cout << "1 - Cadastrar conta\n2 - Visualizar dados da conta\n3 - Depositar\n4 - Sacar\n5 - Pix\n6 - Sair do programa\n\n\tOp��o: ";
        cin >> op;

        if(op<1 || op>6)
        {
            cout << "\nOp��o inv�lida! Digite novamente!\n";
            system("pause");
            continue;
        }
        else if(op==1)
        {
            n++;
            cadastrarConta(conta, n);
            ok++;
        }
        else if(op==2 && ok>=1)
        {
            int num;
            cout << "\nInforme o n�mero da sua conta: ";
            cin >> num;
            int x = checkNum(conta, num);
            if(x==-1)
            {
                cout << "\nConta inv�lida! O programa ser� reiniciado!\n";
                system("pause");
                continue;
            }
            else
                mostrarConta(conta, x);
        }
        else if(op==3 && ok>=1)
        {
            int num;
            cout << "\nInforme o n�mero da sua conta: ";
            cin >> num;
            int x = checkNum(conta, num);
            if(x==-1)
            {
                cout << "\nConta inv�lida! O programa ser� reiniciado!\n";
                system("pause");
                continue;
            }
            else
                DepositoOuSaque(conta, x, 'D');
        }
        else if(op==4 && ok>=1)
        {
            int num;
            cout << "\nInforme o n�mero da sua conta: ";
            cin >> num;
            int x = checkNum(conta, num);
            if(x==-1)
            {
                cout << "\nConta inv�lida! O programa ser� reiniciado!\n";
                system("pause");
                continue;
            }
            else
                DepositoOuSaque(conta, x, 'S');
        }
        else if(op==2||op==3|op==4)
        {
            cout << "\nN�o h� nenhuma conta cadastrada! Cadastre uma conta para realizar opera��es!\n";
            system("pause");
            continue;
        }
        else if(op==5 && ok>=2)
        {
            int num1, num2;
            cout << "\nInforme o n�mero da sua conta(origem): ";
            cin >> num1;
            int x1 = checkNum(conta, num1);
            if(x1==-1)
            {
                cout << "\nConta inv�lida! O programa ser� reiniciado!\n";
                system("pause");
                continue;
            }
            cout << "\nInforme o n�mero da conta destino: ";
            cin >> num2;
            int x2 = checkNum(conta, num2);
            if(x2==-1)
            {
                cout << "\nConta inv�lida! O programa ser� reiniciado!\n";
                system("pause");
                continue;
            }
            else
                pix(conta, x1, x2);
        }
        else if(op==5)
        {
            cout << "\nDevem haver no m�nimo duas contas cadastradas para realizar pix!\n";
            system("pause");
            continue;
        }
        else if(op==6)
            cout << "\nVoc� sair� do programa!\n";

    }
    while(op!=6);
    return 0;
}
void cadastrarConta(contas c[], int n)
{
    cout << "\nInforme seu nome completo: ";
    getchar(); // vai parar para receber o enter e nao bugar
    getline(cin, c[n].cliente); // CIN NAO FUNCIONA PARA STRING COM ESPA�O

    bool ok = 0;
    do
    {
        cout << "\nInforme um n�mero para sua conta: ";
        cin >> c[n].numero;

        for(int i=0; i<10; i++)
        {
            if(n!=i && c[i].numero == c[n].numero)
            {
                cout << "\nN�mero j� existente! escolha outro!\n";
                system("pause");
                break;
            }
            else if(i==9)
                ok=1;
        }
    }
    while(ok==0);

    c[n].saldo=0;
}
int checkNum(contas c[], int num)
{
    for(int i=0; i<10; i++)
    {
        if(c[i].numero==num)
            return i;
    }
    return -1;
}
void line()
{
    for(int i=0; i<50; i++)
        cout << "-";
}
void mostrarConta(contas c[], int n)
{
    line();
    printf("\nNome: %s\nN�mero da conta: %d\nSaldo: %.2f\n", c[n].cliente.c_str(), c[n].numero, c[n].saldo);
    line();
    cout << endl;
    system("pause");
}
void DepositoOuSaque(contas c[], int n, char DS)
{
    float d;

    do
    {
        cout << "\nInforme um valor para ser movimentado: ";
        cin >> d;

        if(d<=0)
        {
            cout << "\nValor inv�lido! Insira outro valor.\n";
            system("pause");
        }
    }
    while(d<=0);

    if(DS=='D')
    {
        c[n].saldo += d;

        cout << "\nO valor foi depositado com sucesso!\n";
        system("pause");
    }
    else if(DS=='S')
    {
        if(c[n].saldo>=d)
        {
            c[n].saldo -= d;

            cout << "\nO valor foi sacado com sucesso!\n";
            system("pause");
        }
        else
        {
            cout << "\nSaldo Insuficiente!\n";
            system("pause");
        }
    }
}
void pix(contas c[], int n1, int n2)
{
    float d;

    do
    {
        cout << "\nInforme um valor para ser movimentado: ";
        cin >> d;

        if(d<=0)
        {
            cout << "\nValor inv�lido! Insira outro valor.\n";
            system("pause");
        }
        else if(c[n1].saldo < d)
        {
            cout << "\nSaldo Insuficiente!\n";
            system("pause");
            return;
        }
    }
    while(d<=0);

    c[n1].saldo -= d;
    c[n2].saldo += d;

    cout << "\nO pix foi realizado com sucesso!\n";
    system("pause");

}

