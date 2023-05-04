#include <iostream>
using namespace std;

void venda(bool *v, char aux)
{

    int p;
    cout << "\nEscolha o n�mero de sua poltrona (1 a 20): ";
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
            cout << "\n\nO �nibus est� lotado nas poltronas ";
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
        cout << "Digite uma op��o:\n1 - vender passagem\n2 - mostrar mapa de ocupa��o do �nibus\n3 - encerrar\n\n\tOp��o: ";
        cin >> op;

        if(op<1 || op>3)
        {
            cout << "\nOp��o inv�lida! Digite novamente!\n";
            system("pause");
        }
        else if(op==1)
        {
            char aux;
            do
            {
                cout << "\n\nEscolha uma op��o:\nJ - janela\nC - corredor\n\n\tOp��o: ";
                cin >> aux;

                aux = tolower(aux);

                if(aux!='j' && aux!='c')
                {
                    cout << "\nOp��o inv�lida! Digite novamente!\n";
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
            cout << "\nO programa ser� encerrado!\n";
        }

    }
    while(op!=3);
}
