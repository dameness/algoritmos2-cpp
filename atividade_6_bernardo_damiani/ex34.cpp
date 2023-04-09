#include <iostream>
#include <string>
using namespace std;


/*
 papelaria 2.0
 refeita com struct
*/
struct itens
{
    int codigo;
    float valor, desconto;
    string nome;
};
struct vendido
{
    int codigo;
    int qtd;
};
struct vendas
{
    int codigoCl;
    string nomeCl;
    vendido compraCl[9];
    int qtdCompras;
};

void line();
void tabelaProdutos(itens item[], int n), invalido();
int checkCod(vendas v[], int n, int codigo);
void mostrarUm(itens item[], vendas v[], int n);
void mostrarTodos(itens item[], vendas v[], int n);
void somaTot(itens item[], vendas v[], int n, float &somaVendas);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct itens item[9];
    struct vendas v[10];
    item[0] = {.codigo=1, .valor=28, .desconto=0.07, .nome = "Folha branca A4 com 500"};
    item[1] = {.codigo=2, .valor=6.3, .desconto=0.05, .nome = "Caneta Bic ponta fina"};
    item[2] = {.codigo=3, .valor=22, .desconto=0.05, .nome = "Caderno 10 matérias"};
    item[3] = {.codigo=4, .valor=17.8, .desconto=0.06, .nome = "Caneta marca texto"};
    item[4] = {.codigo=5, .valor=5.5, .desconto=0.07, .nome = "Cola Bastão"};
    item[5] = {.codigo=6, .valor=11, .desconto=0.1, .nome = "Corretor ortográfico"};
    item[6] = {.codigo=7, .valor=4.5, .desconto=0.02, .nome = "Lápis preto"};
    item[7] = {.codigo=8, .valor=138, .desconto=0.07, .nome = "Mochila com repartimento"};
    item[8] = {.codigo=9, .valor=8, .desconto=0.05, .nome = "Caderno de desenho"};

    int op, n=-1;
    bool ok=0;
    float somaVendas = 0;

    do
    {
        system("cls");
        tabelaProdutos(item, 8);

        cout << "\n0 – Sair do programa\n1 – Registrar venda\n2 – Mostrar todas as vendas\n3 – Consultar venda pelo código do cliente\n4 – Mostrar o valor total das vendas realizadas\n\n\tOpção: ";
        cin >> op;

        if(op<0 || op>4)
        {
            invalido();
        }
        else if(op==0)
        {
            cout << "\nVocê sairá do programa!\n";
        }
        else if(op==1)
        {
            if(n>=9)
            {
                cout << "\nQuantidade máxima de vendas alcançada! Não é possível vender mais!\n";
                system("pause");
            }
            else
            {
                int cCl, numCl, c, qtd;
                bool segue=1;

                cout << "\nCódigo do cliente: ";
                cin >> cCl;

                for(int i=0; i<=n; i++)
                {
                    if(cCl == v[i].codigoCl)
                    {
                        cout << "\nPor questões de organização das vendas, não é possível registrar mais de uma venda com o mesmo código do cliente! Inicie a venda com outro código ou faça várias compras com o mesmo cliente em uma venda só!\n";
                        system("pause");
                        segue=0;
                    }
                }

                if(segue == 1)
                {
                    n++;
                    int x=-1;

                    v[n].codigoCl = cCl;

                    cout << "\nNome do cliente: ";
                    fflush(stdin);
                    getline(cin, v[n].nomeCl);

                    int interromper; //coloquei como int para não dar bug no programa se o usuário digitar algo que nao seja 0 ou 1
                    do
                    {
                        interromper=1;

                        do
                        {
                            cout << "\nCódigo do produto: ";
                            cin >> c;

                            if(c<1 || c>9)
                            {
                                cout << "\nCódigo inválido! Digite novamente!\n";
                                system("pause");
                            }
                            else
                            {
                                x++;
                                if(x==0)
                                    v[n].qtdCompras=0;
                                v[n].qtdCompras++;
                                v[n].compraCl[x].codigo = c - 1;
                            }
                        }
                        while(c<1 || c>9);

                        do
                        {
                            cout << "\nQuantidade: ";
                            cin >> qtd;

                            if(qtd<=0)
                            {
                                cout << "\nQuantidade inválida! Digite novamente!\n";
                                system("pause");
                            }
                            else
                            {
                                v[n].compraCl[x].qtd = qtd;
                            }

                        }
                        while(qtd<=0);

                        do
                        {
                            cout << "\nDigite 0 para continuar comprando. Digite 1 para sair.\n";
                            cin >> interromper;

                            if(interromper!=0 && interromper!=1)
                                cout << "\nInválido! Digite novamente!\n";

                        }
                        while(interromper!=0 && interromper!=1);


                    }
                    while(interromper==0);
                }
            }
            ok=1;
        }
        else if(ok==1)
        {
            if(op==2)
            {
                mostrarTodos(item, v, n);
                cout << endl;
                system("pause");
            }
            else if(op==3)
            {
                int x, check;
                do
                {
                    cout << "\nCódigo do cliente: ";
                    cin >> x;

                    check = checkCod(v, n, x);

                    if(check == -1)
                    {
                        cout << "\nCódigo Inválido! Digite novamente!\n";
                        system("pause");
                    }

                }
                while(check == -1);

                mostrarUm(item, v, check);
                cout << endl;
                system("pause");
            }
            else if(op==4)
            {
                somaVendas=0;
                for(int i=0; i<=n; i++)
                    somaTot(item, v, i, somaVendas);

                printf("\nSoma de todas as vendas: %.2f\n\n", somaVendas);
                system("pause");
            }
        }
        else
        {
            cout << "\nNão há nenhuma venda cadastrada! Venda para realizar operações!\n";
            system("pause");
        }
    }
    while(op!=0);


    return 0;
}
void line()
{
    for(int i=0; i<90; i++)
        cout << "-";
}
void tabelaProdutos(itens item[], int n)
{
    cout << "\t\tPAPELARIA LIVRO E CIA\n\n";
    printf("|%18s        |%7s |%8s |%10s |\n", "DESCRIÇÃO", "CÓDIGO", "VALOR R$", "DESCONTO %");
    for(int i=0; i<=n; i++)
    {
        printf("|%25s |%7d |%8.2f |%10.2f |\n", item[i].nome.c_str(), item[i].codigo, item[i].valor, item[i].desconto*100 );
    }
}
void invalido()
{
    printf("\nValor inválido!\n\n");
    system("pause");
}
int checkCod(vendas v[], int n, int codigo)
{
    for(int i=0; i<=n; i++)
    {
        if(v[i].codigoCl == codigo)
            return i;
    }
    return -1;
}
void mostrarUm(itens item[], vendas v[], int n)//n sera obtido pelo checkcod
{
    line();
    printf("\nCliente: %d - %s\n\n", v[n].codigoCl, v[n].nomeCl.c_str());
    printf("\n|%18s        |%3s |%8s\t|%10s\t |%10s \n", "DESCRIÇÃO", "QTD", "VALOR ITEM", "DESCONTO R$", "TOTAL ITEM");


    int q = v[n].qtdCompras;
    float parcial, total=0, descontoRS;

    for(int i=0; i<q; i++)
    {
        int c = v[n].compraCl[i].codigo;
        int qtd = v[n].compraCl[i].qtd;

        descontoRS  = item[c].valor*item[c].desconto*qtd;
        parcial = (item[c].valor * qtd) - descontoRS;
        total += parcial;

        printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", item[c].nome.c_str(), qtd, item[c].valor, descontoRS, parcial);

    }

    printf("\n\nTotal:....................................................................%.2f\n\n", total);

    /*
    c1.descontoRS = c1.valor*c1.qtd*c1.desconto;
    c1.total = (c1.valor*c1.qtd) - c1.descontoRS;
    totalgeral+=c1.total;
    printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", c1.nome, c1.qtd, c1.valor, c1.descontoRS, c1.total);

    */
}
void mostrarTodos(itens item[], vendas v[], int n)
{
    for(int i=0; i<=n; i++)
        mostrarUm(item, v, i);
    line();
}

void somaTot(itens item[], vendas v[], int n, float &somaVendas)
{
    int q = v[n].qtdCompras;
    float parcial, total=0, descontoRS;

    for(int i=0; i<q; i++)
    {
        int c = v[n].compraCl[i].codigo;
        int qtd = v[n].compraCl[i].qtd;

        descontoRS  = item[c].valor*item[c].desconto*qtd;
        parcial = (item[c].valor * qtd) - descontoRS;
        total += parcial;

    }

    somaVendas+=total;
}


