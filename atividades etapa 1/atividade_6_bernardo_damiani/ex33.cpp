#include <iostream>
using namespace std;

/*
Crie um programa para controlar o estoque de uma empresa, sabendo que serão no
máximo 50 produtos (mas o sistema deve funcionar para qualquer quantidade inferior ao
máximo permitido), o sistema deverá manipular o código do produto, nome, unidade (kg, dz, m,
un, cx, tn, etc...), valor de venda e quantidade em estoque.
0 – Sair
1 – Cadastrar produto
2 – Listar produtos cadastrados
3 – Consultar produto pelo código
4 – Vender produto (fornece o código e a quantidade de venda, o sistema verifica se existe
estoque suficiente e executa a venda atualizando a quantidade em estoque).
*/
struct estoque
{
    int codigo;
    float qtd;
    float valor;
    char nome[50];
    char unidade[50];

};

void line();
void invalido();
void cadastrar(estoque produto[], int n);
void mostrarUm(estoque produto[], int n);
void mostrarTodos(estoque produto[], int n);
int checkCod(estoque produto[], int n, int codigo);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct estoque produto[50];
    int op, n=-1;
    bool ok=0;

    do
    {
        system("cls");
        cout << "0 - Sair\n1 - Cadastrar produto\n2 - Listar produtos cadastrados\n3 - Consultar produto por código\n4 - Vender produto\n\n\t\tOpção: ";
        cin >> op;

        if(op<0 || op>4)
        {
            cout << "\nSelecione uma opção válida!\n";
            system("pause");
        }
        else if(op==0)
        {
            cout << "\nVocê sairá do programa!\n";
        }
        else if(op==1)
        {
            n++;
            cadastrar(produto, n);
            ok=1;
        }
        else if(ok==1)
        {
            if(op==2)
            {
                mostrarTodos(produto, n);
                system("pause");
            }
            if(op==3)
            {
                int cod;
                cout << "\nCódigo: ";
                cin >> cod;

                if(checkCod(produto, n, cod)==-1)
                    invalido();
                else
                {
                    mostrarUm(produto, checkCod(produto, n, cod));
                    line();
                    cout << "\n";
                    system("pause");
                }
            }
            if(op==4)
            {
                int cod;
                float qtd;

                do
                {
                    cout << "\nCódigo: ";
                    cin >> cod;

                    if(checkCod(produto, n, cod)==-1)
                        invalido();
                    else
                    {
                        int x = checkCod(produto, n, cod);
                         do
                        {
                            cout << "\nQuantidade: ";
                            cin >> qtd;

                            if(qtd<=0)
                                invalido();
                            else if(qtd > produto[x].qtd)
                            {
                                cout << "\nQuantidade insuficiente!\n";
                                system("pause");
                            }
                            else
                            {
                                produto[x].qtd -= qtd;
                                printf("\nForam vendidos %.2f %s do produto '%s' pelo preço de R$ %.2f!\n", qtd, produto[x].unidade, produto[x].nome, (produto[x].valor * qtd));
                                system("pause");
                            }

                        }while(produto[n].qtd <=0);
                    }

                }while(checkCod(produto, n, cod)==-1);

            }
        }
        else
        {
            cout << "\nNão há nenhum produto cadastrado! Cadastre um produto para realizar operações!\n";
            system("pause");
        }
    }while(op!=0);

        return 0;
}
    void line()
    {
        for(int i=0; i<50; i++)
            cout << "-";
    }
    void invalido()
    {
        cout << "\nValor inválido!\n";
        system("pause");
    }
    void cadastrar(estoque produto[], int n)
    {
        int inv;
        do
        {
            cout << "\nCódigo: ";
            cin >> produto[n].codigo;
            inv=0;

            for(int i=0; i<=n; i++)
            {
                if(i!=n && produto[i].codigo == produto[n].codigo)
                {
                    inv=1;
                    invalido();
                    break;
                }
            }

        }
        while(inv==1);


        do
        {
            cout << "\nQuantidade: ";
            cin >> produto[n].qtd;

            if(produto[n].qtd <=0)
                invalido();

        }
        while(produto[n].qtd <=0);

        do
        {
            cout << "\nValor Unitário: ";
            cin >> produto[n].valor;

            if(produto[n].valor <=0)
                invalido();

        }
        while(produto[n].valor <=0);

        cout << "\nNome do produto: ";
        fflush(stdin);
        cin.getline(produto[n].nome, 50);

        cout << "\nUnidade utilizada (abreviada): ";
        fflush(stdin);
        cin.getline(produto[n].unidade, 50);
    }
    void mostrarUm(estoque produto[], int n)
    {
        line();
        printf("\nCódigo: %d\nQuantidade: %.2f %s\nValor: R$%.2f\nNome: %s\n", produto[n].codigo, produto[n].qtd, produto[n].unidade, produto[n].valor, produto[n].nome);
    }
    void mostrarTodos(estoque produto[], int n)
    {
        for(int i=0; i<=n; i++)
            mostrarUm(produto, i);
        line();
    }
    int checkCod(estoque produto[], int n, int codigo)
    {
        for(int i=0; i<=n; i++)
        {
            if(produto[i].codigo == codigo)
                return i;
        }
        return -1;
    }
