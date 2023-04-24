#include <iostream>
#include <string.h>
using namespace std;


/*
Escreva um programa que auxilie o dono da papelaria a realizar as compras dos clientes, o
programa deve possibilitar que o atendente informe o código do item e a quantidade solicitada,
sendo possível incluir vários itens na mesma compra, para tanto a cada item solicitado o
sistema deverá apresentar as seguintes possibilidades:
1 – Incluir mais um item
2 – Encerrar a compra
Se a opção for incluir mais um item (1) permite informar o código e a quantidade do próximo
item, caso a opção seja encerrar a compra (2) deverá exibir os itens da compra, com as
respectivas quantidades, o valor do item e ao final o valor total da compra.
OBS:
- Validar para aceitar somente itens pertencentes à lista apresentada(tabela na folha de exercícios).
- Exibir a compra com os alinhamentos e os valores numéricos formatados conforme no
exemplo.
- Aplicar o desconto em cada item, conforme a tabela de promoções
*/

void tabelaLivraria(), invalido();
// TENTANDO USAR STRUCT E FORMATAR TABELAS
struct itens
{
    int qtd;
    float valor;
    float desconto;
    float descontoRS;
    float total;
    char nome[30];
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int option;

    struct itens c1{.valor=28, .desconto=0.07}, c2{.valor=6.3, .desconto=0.05}, c3{.valor=22, .desconto=0.05}, c4{.valor=17.8, .desconto=0.06}, c5{.valor=5.5, .desconto=0.07}, c6{.valor=11, .desconto=0.1}, c7{.valor=4.5, .desconto=0.02}, c8{.valor=138, .desconto=0.07}, c9{.valor=8, .desconto=0.05};
    strcpy(c1.nome, "Folha branca A4 com 500");
    strcpy(c2.nome, "Caneta Bic ponta fina");
    strcpy(c3.nome, "Caderno 10 matérias");
    strcpy(c4.nome, "Caneta marca texto");
    strcpy(c5.nome, "Cola Bastão");
    strcpy(c6.nome, "Corretor ortográfico");
    strcpy(c7.nome, "Lápis preto");
    strcpy(c8.nome, "Mochila com repartimento");
    strcpy(c9.nome, "Caderno de desenho");

    do
    {
        system("cls");
        int confirm, c, qtd;
        float totalgeral=0;
        tabelaLivraria();

        cout << "1 - Incluir item\n2 - Encerrar a compra\n\tOpção: ";
        cin >> option;
        fflush(stdin);

        if(option!=1 && option!=2)
            invalido();
        else if(option==2)
        {
            printf("\n|%18s        |%3s |%8s\t|%10s\t |%10s \n", "DESCRIÇÃO", "QTD", "VALOR ITEM", "DESCONTO R$", "TOTAL ITEM");

            if(c1.qtd>0)
            {
                c1.descontoRS = c1.valor*c1.qtd*c1.desconto;
                c1.total = (c1.valor*c1.qtd) - c1.descontoRS;
                totalgeral+=c1.total;
                printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", c1.nome, c1.qtd, c1.valor, c1.descontoRS, c1.total);
            }
            if(c2.qtd>0)
            {
                c2.descontoRS = c2.valor*c2.qtd*c2.desconto;
                c2.total = (c2.valor*c2.qtd) - c2.descontoRS;
                totalgeral+=c2.total;
                printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", c2.nome, c2.qtd, c2.valor, c2.descontoRS, c2.total);
            }
            if(c3.qtd>0)
            {
                c3.descontoRS = c3.valor*c3.qtd*c3.desconto;
                c3.total = (c3.valor*c3.qtd) - c3.descontoRS;
                totalgeral+=c3.total;
                printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", c3.nome, c3.qtd, c3.valor, c3.descontoRS, c3.total);
            }
            if(c4.qtd>0)
            {
                c4.descontoRS = c4.valor*c4.qtd*c4.desconto;
                c4.total = (c4.valor*c4.qtd) - c4.descontoRS;
                totalgeral+=c4.total;
                printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", c4.nome, c4.qtd, c4.valor, c4.descontoRS, c4.total);
            }
            if(c5.qtd>0)
            {
                c5.descontoRS = c5.valor*c5.qtd*c5.desconto;
                c5.total = (c5.valor*c5.qtd) - c5.descontoRS;
                totalgeral+=c5.total;
                printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", c5.nome, c5.qtd, c5.valor, c5.descontoRS, c5.total);
            }
            if(c6.qtd>0)
            {
                c6.descontoRS = c6.valor*c6.qtd*c6.desconto;
                c6.total = (c6.valor*c6.qtd) - c6.descontoRS;
                totalgeral+=c6.total;
                printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", c6.nome, c6.qtd, c6.valor, c6.descontoRS, c6.total);
            }
            if(c7.qtd>0)
            {
                c7.descontoRS = c7.valor*c7.qtd*c7.desconto;
                c7.total = (c7.valor*c1.qtd) - c7.descontoRS;
                totalgeral+=c7.total;
                printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", c7.nome, c7.qtd, c7.valor, c7.descontoRS, c7.total);
            }
            if(c8.qtd>0)
            {
                c8.descontoRS = c8.valor*c8.qtd*c8.desconto;
                c8.total = (c8.valor*c8.qtd) - c8.descontoRS;
                totalgeral+=c8.total;
                printf("|%25s |%d \t|%.2f\t\t|%.2f \t |%.2f\t \n", c8.nome, c8.qtd, c8.valor, c8.descontoRS, c8.total);
            }
            if(c9.qtd>0)
            {
                c9.descontoRS = c9.valor*c9.qtd*c9.desconto;
                c9.total = (c9.valor*c9.qtd) - c9.descontoRS;
                totalgeral+=c9.total;
                printf("|%25s |%d \t|%.2f\t\t|%.2f \t\t |%.2f\t \n", c9.nome, c9.qtd, c9.valor, c9.descontoRS, c9.total);
            }
            printf("\n\t\tTOTAL: R$%.2f\n\n", totalgeral);
        }
        else if(option==1)
        {
            cout << "Informe o código do item: ";
            cin >> c;
            fflush(stdin);

            cout <<"Informe a quantidade do item: ";
            cin >> qtd;
            fflush(stdin);

            if(qtd<=0 || c<1 || c>9)
                invalido();
            else if(c==1)
                c1.qtd += qtd;
            else if(c==2)
                c2.qtd += qtd;
            else if(c==3)
                c3.qtd += qtd;
            else if(c==4)
                c4.qtd += qtd;
            else if(c==5)
                c5.qtd += qtd;
            else if(c==6)
                c6.qtd += qtd;
            else if(c==7)
                c7.qtd += qtd;
            else if(c==8)
                c8.qtd += qtd;
            else if(c==9)
                c9.qtd += qtd;
        }
    }
    while(option!=2);

    return 0;
}

void tabelaLivraria()
{
    printf("LIVRARIA LIVRO & CIA - TABELA DE DESCONTOS\n ");
    for(int i=0; i<57; i++)
    {
        printf("_");
    }
    printf("\n|%18s        |%7s |%8s |%10s |\n", "DESCRIÇÃO", "CÓDIGO", "VALOR R$", "DESCONTO %");
    printf("|%25s |%7s |%8s |%10s |\n", "Folha branca A4 com 500", "1", "28.00", "7%");
    printf("|%25s |%7s |%8s |%10s |\n", "Caneta Bic ponta fina", "2", "6.30", "5%");
    printf("|%25s |%7s |%8s |%10s |\n", "Caderno 10 matérias", "3", "22.00", "5%");
    printf("|%25s |%7s |%8s |%10s |\n", "Caneta marca texto", "4", "17.80", "6%");
    printf("|%25s |%7s |%8s |%10s |\n", "Cola Bastão", "5", "5.50", "7%");
    printf("|%25s |%7s |%8s |%10s |\n", "Corretor ortográfico", "6", "11.00", "10%");
    printf("|%25s |%7s |%8s |%10s |\n", "Lápis preto", "7", "4.50", "2%");
    printf("|%25s |%7s |%8s |%10s |\n", "Mochila com repartimento", "8", "138.00", "7%");
    printf("|%25s |%7s |%8s |%10s |\n", "Caderno de desenho", "9", "8.00", "5%");
    printf("|");
    for(int i=0; i<57; i++)
    {
        printf("_");
    }
    printf("|\n\n");
}

void invalido()
{
    printf("\nValor inválido! O programa será reiniciado!\n\n");
    system("pause");
}

