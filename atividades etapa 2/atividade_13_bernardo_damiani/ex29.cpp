#include <iostream>
#include <fstream>
using namespace std;

/*
Escreva um programa que leia um arquivo texto contendo vários números float, no
máximo 50, separados por ponto e vírgula, o programa deverá mostrar a soma, média, maior e
menor valor existente no arquivo e deverá mostrar os valores em ordem crescente, separando
cada elemento com uma vírgula e exibindo no máximo 10 elementos em cada linha.
*/

/*
    **OBSERVAÇÃO:
    PROFESSOR, por algum motivo meu atof() não funciona quando coloco '.' no arquivo texto para indicar as casas decimais,
    porém com ',' funciona corretamente

*/
void exibirVetor(float vetor[], int tamanho){

  for(int i=0; i<tamanho; i++){

      if(i%10==0)
        cout << "\n";

    printf("%.2f", vetor[i]);

      if(i<tamanho-1)
        cout << " , ";
  }
  cout << "\n";
}

void ordemCrescente(float vetor[], int tamanho){

    for(int i=0; i<tamanho; i++){

         for(int j=0; j<tamanho-1; j++){

            if(vetor[j] > vetor[i])
            {
                float aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
         }
    }
}

main()
{
    setlocale(LC_ALL, "Portuguese");
    string nomeArquivo;


    cout << "**OBSERVAÇÃO: Por algum motivo meu atof() não funciona quando coloco '.' no arquivo texto para indicar as casas decimais, porém com ',' funciona corretamente, favor colocar ',' no arquivo texto!\n\nInforme o nome do arquivo texto a ser lido (completo, com .txt no final): ";
    getline(cin, nomeArquivo);

    ifstream ler;
    ler.open(nomeArquivo, ios::in);

    char numeroTexto[20];
    float numerosLidos[50];
    int contador=0;
    float somaValores=0, maiorValor, menorValor;

    if(ler.is_open()){
            cout << "\nArquivo lido com sucesso!\n\n";

            while( ler.getline(numeroTexto, 20, ';') ){
                cout << numeroTexto << "\n";

                numerosLidos[contador] = atof(numeroTexto);
                contador++;
            }

            ordemCrescente(numerosLidos, contador);
            exibirVetor(numerosLidos, contador);

            for(int i=0; i<contador; i++){

                somaValores += numerosLidos[i];

                if(i==0 || numerosLidos[i] > maiorValor)
                    maiorValor = numerosLidos[i];

                if(i==0 || numerosLidos[i] < menorValor)
                    menorValor = numerosLidos[i];

            }

            printf("\nSoma dos valores: %.2f\nMédia dos valores: %.2f\nMenor valor: %.2f\nMaior valor: %.2f\n\n", somaValores, somaValores/contador, menorValor, maiorValor);

    }else
        cout << "\nErro ao abrir o arquivo\n";


    ler.close();
}
