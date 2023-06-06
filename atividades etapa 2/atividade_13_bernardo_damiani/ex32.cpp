#include <iostream>
#include <fstream>
using namespace std;

/*
32 � Crie um programa que manipule um arquivo texto contendo em cada linha um n�mero
inteiro qualquer, o programa dever� ler todos os n�meros e apresentar os seguintes dados:
- Maior valor existente no arquivo
- Menor valor existente no arquivo
- M�dia aritm�tica dos valores no arquivo
- Quantidade de n�meros pares e �mpares existentes no arquivo
*/

main()
{
    setlocale(LC_ALL, "Portuguese");
    string nomeArquivo;

    cout << "Informe o nome do arquivo texto a ser lido (completo, com .txt no final): ";
    getline(cin, nomeArquivo);

    ifstream ler;
    ler.open(nomeArquivo, ios::in);

    char numeroTexto[20];
    int numerosLidos[100], somaValores=0, contador=0, quantidadePares=0, maiorValor, menorValor;

    if(ler.is_open()){
            cout << "\nConte�do do arquivo:\n\n";

            while( ler.getline(numeroTexto, 20) ){
                cout << numeroTexto << "\n";

                numerosLidos[contador] = atoi(numeroTexto);
                contador++;
            }

            for(int i=0; i<contador; i++){

                somaValores += numerosLidos[i];

                if(i==0 || numerosLidos[i] > maiorValor)
                    maiorValor = numerosLidos[i];

                if(i==0 || numerosLidos[i] < menorValor)
                    menorValor = numerosLidos[i];

                if(numerosLidos[i]%2==0)
                    quantidadePares++;

            }

            printf("\nM�dia dos valores: %.2f\nMenor valor: %d\nMaior valor: %d\nQuantidade de pares: %d\nQuantidade de �mpares: %d\n", float(somaValores)/contador, menorValor, maiorValor, quantidadePares, contador-quantidadePares);

    }else
        cout << "\nErro ao abrir o arquivo\n";


    ler.close();
}
