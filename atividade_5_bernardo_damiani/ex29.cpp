#include <iostream>
#include <cstring>
using namespace std;

/*
Escreva um programa que manipule um card�pio de um restaurante, com as seguintes
estruturas:
struct prato
{
string ingredientes;
string preparo;
int calorias;
};
struct cardapio
{
int codigo;
string nome;
prato x;
float valor;
};
O sistema dever� permitir o cadastro de no m�ximo 20 itens no card�pio e dever� apresentar o
seguinte menu:
0 - Sair
1 � Incluir
2 � Mostrar card�pio (utilize um linha pontilhada entre um item e outro)
3 � Detalhar card�pio (recebe o c�digo do card�pio e mostra os dados do referido card�pio)
4 � Mostrar card�pio mais caro;
5 � Mostrar card�pio com a menor quantidade de calorias;
*/

struct prato
{
    string ingredientes;
    string preparo;
    int calorias;
};
struct cardapio
{
    int codigo;
    string nome;
    prato x;
    float valor;
};

void line();
void incluirItem(cardapio item[], int n);
void mostrarCardapio(cardapio item[], int n);
int checkCod(cardapio item[], int n, int cod);
int maisCaro(cardapio item[], int n);
int menosKcal(cardapio item[], int n);
void mostrarItem(cardapio item[], int n, bool detalhado=0);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct cardapio item[20];
    int op, n=-1, ok=0;

    do
    {
        system("cls");

        cout << "0 - Sair\n1 - Incluir item\n2 - Mostrar card�pio\n3 - Mostrar item detalhado\n4 - Mostrar item mais caro\n5 - Mostrar item com menos calorias\n\n\tOp��o: ";
        cin >> op;

        if(op<0 || op>5)
        {
            cout << "\nOp��o inv�lida! Digite novamente!\n";
            system("pause");
            continue;
        }
        else if(op==0)
            cout << "\nVoc� sair� do programa!\n";
        else if(op == 1)
        {
            n++;
            if(n<20)
                incluirItem(item, n);
            else
            {
                cout << "\nO limite de itens no card�pio ja foi alcan�ado!\n";
                system("pause");
            }
            ok=1;
        }
        else if(op == 2 && ok==1)
            mostrarCardapio(item, n);

        else if(op == 3 && ok==1)
        {
            int cod;
            cout << "\nInforme o c�digo do prato: ";
            cin >> cod;
            int x = checkCod(item, n, cod);
            if(x==-1)
            {
                cout << "\nC�digo inv�lido! O programa ser� reiniciado!\n";
                system("pause");
                continue;
            }
            else
            {
                mostrarItem(item, x, 1);
                cout << "\n\n";
                system("pause");

            }
        }
        else if(op == 4 && ok==1)
        {
            cout << "\nItem mais caro do card�pio:\n";
            mostrarItem(item, maisCaro(item, n));
            cout << "\n\n";
            system("pause");
        }
        else if(op == 5 && ok==1)
        {
            cout << "\nItem menos cal�rico do card�pio:\n";
            mostrarItem(item, menosKcal(item, n), 1);
            cout << "\n\n";
            system("pause");
        }
        else
        {
            cout << "\n� necess�rio incluir algo no card�pio antes de realizar essa fun��o!\n";
            system("pause");
        }
    }
    while(op!=0);

    return 0;
}
void line()
{
    for(int i=0; i<50; i++)
        cout << "-";
}
void incluirItem(cardapio item[], int n)
{
    cout << "\nNome do item: ";
    fflush(stdin); // limpando o buffer para o getline nao bugar
    getline(cin, item[n].nome);
    do
    {
        cout << "\nValor do item: ";
        cin >> item[n].valor;

        if(item[n].valor<=0)
        {
            cout << "\nValor inv�lido! Digite novamente!\n";
            system("pause");
        }

    }
    while(item[n].valor<=0);

    bool invalido;
    do
    {
        cout << "\nC�digo do item: ";
        cin >> item[n].codigo;


        for(int i=0; i<=n; i++)
        {
            if(n!=i && item[n].codigo == item[i].codigo)
            {
                cout << "\nValor inv�lido! Digite novamente!\n";
                system("pause");
                invalido = 1;
                break;
            }
            invalido=0;
        }
    }
    while(invalido==1);
    cout << "\nIngredientes: ";
    fflush(stdin);
    getline(cin, item[n].x.ingredientes);
    cout << "\nModo de preparo: ";
    fflush(stdin);
    getline(cin, item[n].x.preparo);
    do
    {
        cout << "\nQtd. de Calorias(kcal): ";
        cin >> item[n].x.calorias;
        if(item[n].x.calorias<0)
        {
            cout << "\nValor inv�lido! Digite novamente!\n";
            system("pause");
        }

    }
    while(item[n].x.calorias<0);

}
void mostrarCardapio(cardapio item[], int n)
{
    cout << "\n\tCARD�PIO DO RESTAURANTE\n";
    for(int i=0; i<=n; i++)
        mostrarItem(item, i);
    line();
    cout << "\n\n";
    system("pause");

}
int checkCod(cardapio item[], int n, int cod)
{
    for(int i=0; i<=n; i++)
    {
        if(item[i].codigo == cod)
            return i;
    }
    return -1;
}
int maisCaro(cardapio item[], int n)
{
    int maior;
    for(int i=0; i<=n; i++)
    {
        if(item[i].valor > item[maior].valor|| i==0)
            maior = i;
    }
    return maior;
}
int menosKcal(cardapio item[], int n)
{
    int menor;
    for(int i=0; i<=n; i++)
    {
        if(item[i].x.calorias < item[menor].x.calorias || i==0) // cuidar as comparacoes e testes condicionais
            menor = i;
    }
    return menor;
}
void mostrarItem(cardapio item[], int n, bool detalhado)
{
    line();
    printf("\nNome do item: %s\nC�digo do item: %d\nValor: %.2f\n", item[n].nome.c_str(), item[n].codigo, item[n].valor);

    if(detalhado==1)
    {
        printf("Ingredientes: %s\nModo de preparo: %s\nCalorias(kcal): %d\n", item[n].x.ingredientes.c_str(), item[n].x.preparo.c_str(), item[n].x.calorias);
    }
}

