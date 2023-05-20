#include <iostream>
#include <ctime>
using namespace std;

/*
- Implemente um programa que manipule uma matriz, onde o número de linhas deve ser alocado
dinamicamente (usuário informa quantas linhas) no máximo 20 e com 5 colunas, após preencha a matriz
com valores randômicos menores que 100, o programa deverá ter um menu com as seguintes opções:
0 – Sair
1 – Gerar matriz (nesta opção deverá ser informado o número de linhas)
2 – Mostrar a matriz
3 – Soma das diagonais (deverá mostrar os elementos da diagonal principal e secundária, juntamente
com as respectivas somas)
4 – Mostrar a matriz de forma invertida (a primeira linha passa a ser a última e a última linha a primeira e
assim sucessivamente)
OBS: as opções 2, 3 e 4 só poderão ser acionadas após a execução da opção 1 (mostrar mensagem com
tratamento deste erro), tratar opção inválida no menu.
*/
void exibir(int (*&m)[5], int *l) // passagem do ponteiro por referência, para que seja modificado no main()
{
    int *i = new int, *j = new int;
    cout << endl;

    for(*i=0; *i<*l; (*i)++)
    {
         for(*j=0; *j<5; (*j)++)
         {
             cout << m[*i][*j] << "\t";
         }
         cout << "\n\n";
    }
    cout << endl;

    system("pause");
    delete i, j;
}
void gerar(int (*&m)[5], int *l)
{
    int *i = new int, *j = new int;

    do
    {
        cout << "\nNúmero de linhas: ";
        cin >> *l;

        if(*l<1 || *l>20)
        {
            cout << "\nValor inválido!\n";
            system("pause");
        }

    }while(*l<1 || *l>20);

    m = new int[*l][5]; //ponteiro recebe a matriz com valor dinâmico para a qtd de linhas

    for(*i=0; *i<*l; (*i)++)
    {
         for(*j=0; *j<5; (*j)++)
         {
             m[*i][*j] = rand()%100;
         }
    }

    delete i, j;
}
void soma(int *somador, int (*m)[5], int *l)
{
    int *i = new int, *j = new int;

    for(*i=0; *i<*l; (*i)++)
    {
         for(*j=0; *j<5; (*j)++)
         {
             if(*i==*j || (*i + *j)==5-1)
                *somador += m[*i][*j];
         }
    }
    cout << "\nSoma: " << *somador << "\n\n";
    cout << "DP: ";
    for(*i=0; *i<*l; (*i)++)
    {
         for(*j=0; *j<5; (*j)++)
         {
             if(*i==*j)
                cout << m[*i][*j] << " ";
         }
    }
    cout << "\nDS: ";
    for(*i=0; *i<*l; (*i)++)
    {
         for(*j=0; *j<5; (*j)++)
         {
             if((*i + *j)==5-1)
                cout << m[*i][*j] << " ";
         }
    }
    cout << "\n\n";
    system("pause");
     delete i, j;
}
void invertida(int (*m)[5], int *l)
{
    int *i = new int, *j = new int;

    for(*i=(*l)-1; *i>=0; (*i)--)
    {
         for(*j=0; *j<5; (*j)++)
         {
             cout << m[*i][*j] << "\t";
         }
        cout << "\n\n";
    }

    system("pause");
    delete i, j;
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *op = new int;
    bool *ok = new bool(0);
    int (*m)[5];// ponteiro int para uma matriz onde cada linha possui 5 elementos
    int *l = new int; // qtd de linhas

    do
    {
        system("cls");
        cout << "Escolha uma opção:\n1 - Gerar Matriz\n2 - Mostrar Matriz\n3 - Soma das diagonais\n4 - Matriz invertida\n\n\tOpção: ";
        cin >> *op;

        if(*op<0 || *op>4)
        {
            cout << "\nOpção Inválida!\n";
            system("pause");
        }
        else if(*op==0)
        {
           cout << "\nVocê sairá do programa!\n";
        }
        else if(*op==1)
        {
            gerar(m, l);
            *ok=1;
        }
        else if(*ok==1)
        {
            if(*op==2)
            {
                exibir(m, l);
            }
            else if(*op==3)
            {
                if(*l==5)
                {
                    int *s = new int(0);
                    soma(s, m, l);
                    delete s;
                }
                else
                {
                    cout << "\nEssa matriz não é quadrada, portanto não é possível somar as diagonais\n";
                    system("pause");
                }
            }
            else
            {
                invertida(m, l);
            }
        }
        else
        {
            cout << "\nA opção 1 deve ser acionada anteriormente!\n";
            system("pause");
        }

    }while(*op!=0);

    delete op, ok, l;
    delete[] m;
}
