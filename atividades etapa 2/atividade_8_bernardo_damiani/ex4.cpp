#include <iostream>
using namespace std;

void venda(bool *v, char aux)
{

    int p;
    cout << "\nEscolha o número de sua poltrona (1 a 20): ";
    cin >> p;

    if(p<1 || p>20)
        cout << "\nPoltrona inexistente!\n";
    else
    {
        p--;
        bool inv = 1;

        for(int i=0; i<20; i++)
        {
           if(*(v+i) == 0)
               inv = 0;
        }

        if(inv == 1)
        {
            cout << "\n\nO ônibus está lotado nas poltronas ";
            if(aux=='j')
                cout << "da janela!\n";
            else
                cout << "do corredor!\n";
        }
        else if(*(v + p) == 1)
        {
            cout << "\nPoltrona ocupada!\n";
        }
        else
        {
            *(v + p) = 1;
            cout << "\nVenda efetivada!\n";
        }
    }


    system("pause");

}
void ocupacao(bool *j, bool *c)
{
    cout << "\n\nJANELA\t\tCORREDOR\n\n";
    for(int i=0; i<20; i++)
    {
        cout << i+1 << "- ";
        if(*(j+i)==1)
            cout << "Ocupada";
        else
            cout << "Livre";
        cout << "\t\t";
        cout << i+1 << "- ";
        if(*(c+i)==1)
            cout << "Ocupada";
        else
            cout << "Livre";
            cout << "\n";
    }
    cout << "\n\n";
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    bool janela[20], corredor[20];

    for(int i=0; i<20; i++)
    {
        *(janela + i) = 0;
        *(corredor + i) = 0;
    }

    int op;
    do
    {

        system("cls");
        cout << "Digite uma opção:\n1 - vender passagem\n2 - mostrar mapa de ocupação do ônibus\n3 - encerrar\n\n\tOpção: ";
        cin >> op;

        if(op<1 || op>3)
        {
            cout << "\nOpção inválida! Digite novamente!\n";
            system("pause");
        }
        else if(op==1)
        {
            char aux;
            do
            {
                cout << "\n\nEscolha uma opção:\nJ - janela\nC - corredor\n\n\tOpção: ";
                cin >> aux;

                aux = tolower(aux);

                if(aux!='j' && aux!='c')
                {
                    cout << "\nOpção inválida! Digite novamente!\n";
                    system("pause");
                }

            }while(aux!='j' && aux!='c');

            if(aux=='j')
                venda(janela, aux);
            else
                venda(corredor, aux);


        }
        else if(op==2)
        {
            ocupacao(janela, corredor);
            system("pause");
        }
        else if(op==3)
        {
            cout << "\nO programa será encerrado!\n";
        }

    }
    while(op!=3);
}
