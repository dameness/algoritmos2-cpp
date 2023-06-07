#include <iostream>
#include <fstream>
using namespace std;

/*
Crie um programa que leia um arquivo texto chamado �n�meros.txt�, o qual cont�m uma
s�rie de n�meros separados por ponto e v�rgula, o sistema dever� ler os n�meros necess�rios
para preencher uma matriz 5 x 5 de n�meros inteiros. Ap�s ler os dados o sistema dever� exibir
um menu com as seguintes a��es:
1 � Mostrar elementos da diagonal principal
2 � Mostrar os elementos da diagonal secund�ria
3 � Mostrar a matriz e a soma dos elementos acima e abaixo da diagonal principal.
*/
void criarMatriz(ifstream &lerTexto, int matrizNumeros[][5]){

    lerTexto.open("numeros.txt", ios::in);

    if(lerTexto.is_open()){

        char numeroTexto[20];
        int linha=0, coluna=0;

        while(lerTexto.getline(numeroTexto, 20, ';')){
            matrizNumeros[linha][coluna]=atoi(numeroTexto);
            coluna++;
            if(coluna==5){
                linha++;
                coluna=0;
            }
        }

    }else
        cout << "\nErro ao abrir o arquivo!\n";

    lerTexto.close();
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    ifstream lerTexto;

    int matrizNumeros[5][5];

    criarMatriz(lerTexto, matrizNumeros);

    int op;
    do{
            system("cls");
            cout << "0 -  sair\n1 - mostrar DP\n2 - mostrar DS\n3 - mostrar matriz e a soma dos elementos acima e abaixo da DP\n\n\tOp��o: ";
            cin >> op;
            cout << "\n";

        if(op<0 || op>3)
            cout << "Op��o inv�lida!";
        else if(op==0)
            cout << "Voc� sair� do programa!";
        else if(op==1){
            for(int i=0; i<5; i++){
                cout << matrizNumeros[i][i];
                if(i<4)
                        cout << ", ";
            }
        }else if(op==2){
            for(int i=0; i<5; i++){
                cout << matrizNumeros[i][4-i];
                if(i<4)
                    cout << ", ";
            }
        }else if(op==3){
            int somaNaoDP=0;
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    cout << matrizNumeros[i][j] << "\t";

                    if(i!=j)
                        somaNaoDP += matrizNumeros[i][j];
                }
                cout << "\n";
            }
            cout << "\nSoma dos elementos acima e abaixo da DP: " << somaNaoDP;

        }
        cout << "\n";
        system("pause");
    }while(op!=0);
}
