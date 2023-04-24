#include <iostream>
#include <cstring>
using namespace std;

/*
Crie um programa para manipular uma estrutura chamada "pessoa" com os campos
"nome" e "idade". Em seguida, o programa deverá apresentar um menu com as seguintes
opções:
0 – Sair
1 – Cadastrar Pessoa
2 – Pessoa de maior e menor idade
3 – Média das idades
OBS: Utilize funções e passagem de parâmetro para resolver este exercício, as opções 2 e 3 só
poderão ser executadas se existir ao menos uma pessoa cadastrada, o programa deverá
funcionar para qualquer quantidade de pessoa cadastrada, sendo no máximo 20.
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
        cout << "0 - Sair\n1 - Cadastrar Pessoas\n2 - Pessoa de maior e de menor idade\n3 - Média das idades\n\n\tOpção: ";
        cin >> op;

        if(op<0 || op>3)
        {
            cout << "\nOpcão Inválida! Digite novamente!\n";
            system("pause");
        }
        else if(op==0)
        {
            cout << "\nVocê sairá do programa!\n";
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
                cout << "\nNúmero máximo de pessoas alcançado!\n";
                system("pause");
            }
        }
        else if(ok==1)
        {
            if(op==2)
            {
                int x = posMaiorMenorIdade(p, n), y = posMaiorMenorIdade(p, n, 0);

                cout << "\nA pessoa de maior idade é a " << x+1 << "° cadastrada e tem " << p[x].idade << " anos!\n";
                cout << "\nA pessoa de menor idade é a " << y+1 << "° cadastrada e tem " << p[y].idade << " anos!\n";

            }
            else if(op==3)
            {
                printf("\nMédia das idades: %.1f\n", mediaId(p, n));
            }

            cout << endl;
            system("pause");
        }
        else
        {
            cout << "\nCadastre ao menos uma pessoa antes de realizar operações!\n";
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
            cout << "\nIdade inválida! Digite novamente!\n";
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
