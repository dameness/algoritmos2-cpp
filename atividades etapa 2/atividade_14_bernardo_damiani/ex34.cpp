#include <iostream>
#include <fstream>
using namespace std;

/*
Escreva um programa que leia uma sequência de valores de um arquivo texto, separados
por um espaço, a seguir ordene esses valores em ordem crescente e escreva novamente no
arquivo os valores ordenados.
*/


void ordemCrescente(int vetor[], int tamanho){

    for(int i=0; i<tamanho; i++){

         for(int j=0; j<tamanho-1; j++){

            if(vetor[j] > vetor[i])
            {
                int aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
         }
    }
}

main(){
    setlocale(LC_ALL, "Portuguese");
    string nomeArquivo;

    cout << "Informe o nome do arquivo texto a ser lido (completo, com .txt no final): ";
    getline(cin, nomeArquivo);

    ifstream ler(nomeArquivo); // ios::in --> default

    char numeroTexto[20];
    int contador=0;

    if(ler.is_open()){

            while(ler.getline(numeroTexto, 20, ' '))
                contador++;

            int numerosLidos[contador];

            ler.close();
            ler.open(nomeArquivo, ios::in);

            int j=0;
            while(ler.getline(numeroTexto, 20, ' ')){
                numerosLidos[j++] = atoi(numeroTexto);
            }

            ofstream escrever(nomeArquivo); //ios::out --> default

            ordemCrescente(numerosLidos, contador);

            for(int i=0; i<contador; i++)
                escrever << numerosLidos[i] << " ";

            escrever.close();

            cout << "\nArquivo modificado com sucesso!\n\n";

    }else
        cout << "\nErro ao abrir o arquivo\n";


    ler.close();
}
