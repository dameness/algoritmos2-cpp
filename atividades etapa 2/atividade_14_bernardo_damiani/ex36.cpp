#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

/*
Escreva um programa que gere de forma aleatória uma matriz 8 x 8 de números inteiros,
após gerar a matriz o programa deverá escreve os seguintes dados em um arquivo texto
chamado “exer_36.txt”:
- Os dados da matriz (no formato linha coluna)
- Os elementos das diagonais (principal e secundária)
- Os elementos acima da DP
- Os elementos abaixo da DP
*/

void gerarMatriz(int matriz[][8]){

    for(int linha=0; linha<8; linha++){
        for(int coluna=0; coluna<8; coluna++){
            matriz[linha][coluna] = rand()%100;
        }
    }
}
void gravarDados(int matriz[][8]){

    ofstream escrever("exer_36.txt");

    if(escrever.is_open()){
        escrever << "DADOS DA MATRIZ:\n\n";

        for(int linha=0; linha<8; linha++){
            for(int coluna=0; coluna<8; coluna++){
                escrever << matriz[linha][coluna] << "\t";
            }
            escrever << "\n";
        }

        escrever << "\nElementos da diagonal principal: ";
        for(int linha=0; linha<8; linha++){
            for(int coluna=0; coluna<8; coluna++){
               if(linha==coluna)
                     escrever << matriz[linha][coluna] << "\t";
            }

        }
        escrever << "\nElementos da diagonal secundária: ";
        for(int linha=0; linha<8; linha++){
            for(int coluna=0; coluna<8; coluna++){
               if(linha+coluna == 7)
                     escrever << matriz[linha][coluna] << "\t";
            }

        }
        escrever << "\nElementos acima da diagonal principal: ";
        for(int linha=0; linha<8; linha++){
            for(int coluna=0; coluna<8; coluna++){
               if(linha<coluna)
                     escrever << matriz[linha][coluna] << "\t";
            }

        }
        escrever << "\nElementos abaixo da diagonal principal: ";
        for(int linha=0; linha<8; linha++){
            for(int coluna=0; coluna<8; coluna++){
               if(linha>coluna)
                     escrever << matriz[linha][coluna] << "\t";
            }

        }

        cout << "\nDados gravados com sucesso!\n";
    }else{
        cout << "\nHouve um erro ao abrir o arquivo!\n";
    }

    escrever.close();

}
main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int matriz[8][8];

    gerarMatriz(matriz);
    gravarDados(matriz);

}
