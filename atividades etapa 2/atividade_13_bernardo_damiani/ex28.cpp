#include <iostream>
#include <fstream>
using namespace std;

/*
Faça um programa para ler um arquivo texto (o usuário deve fornecer o nome do arquivo)
e o programa deverá imprimir seu conteúdo na tela. E em seguida mostrar quantos caracteres
existem no arquivo, quantas vogais e quantas consoantes.
*/


main()
{
    setlocale(LC_ALL, "Portuguese");
    string nomeArquivo;

    cout << "Informe o nome do arquivo texto a ser lido (completo, com .txt no final): ";
    getline(cin, nomeArquivo);

    //ifstream --> input
    ifstream ler;
    ler.open(nomeArquivo, ios::in);

    char linhaTexto[100];
    char charTexto;
    int contadorCaracteres = 0, contadorVogais = 0, contadorConsoantes = 0;

    if(ler.is_open()){
            cout << "\nArquivo lido com sucesso!\n\n";

            while(ler.getline(linhaTexto, 100))
                cout << linhaTexto << "\n";

            ler.close();
            ler.open(nomeArquivo, ios::in); // arquivo já chegou ao fim é preciso reabrir

            while(ler.get(charTexto)){

                if(!isspace(charTexto)){

                    contadorCaracteres++;

                    if(tolower(charTexto) == 'a' ||tolower(charTexto) == 'e' ||tolower(charTexto) == 'i' ||tolower(charTexto) == 'o' ||tolower(charTexto) == 'u')
                        contadorVogais++;
                    else if(isalpha(charTexto))
                        contadorConsoantes++;
                }
            }

            cout << "\nO texto teve " << contadorCaracteres << " caracteres, sendo " << contadorVogais << " vogais e " << contadorConsoantes << " consoantes!\n";

    }else
        cout << "\nErro ao ler o arquivo!\n";

    ler.close();

}
