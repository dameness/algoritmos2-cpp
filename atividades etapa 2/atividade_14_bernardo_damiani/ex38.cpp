#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

/*
Crie um programa que manipule um vetor de dimensão variável (o usuário informa o
tamanho do vetor menor que 100) os valores para preencher o vetor devem ser gerados
dinamicamente, não sendo permitido números duplicados e devem ser menores que a 500.
Após os valores do vetor devem ser escritos em um arquivo texto chamado “valores.txt”
separando cada valor por uma virgula e colocando os valores em ordem crescente.
O programa deve permitir:
Excluir valores do vetor (o usuário informa o valor se existir no vetor deve ser eliminado,
ajustando os elementos na ordem novamente)
Mostrar vetor na tela.
*/

void escreverValores(int vetor[], int tamanho){
    ofstream escrever("valores.txt");

    if(escrever.is_open()){
        for(int i=0; i<tamanho; i++)
            escrever << vetor[i] << ",";

    }else{
        cout << "\nHouve um problema ao abrir o arquivo!\n";
        system("pause");
    }

    escrever.close();
}
void exibirVetor(int vetor[], int tamanho){

    cout << "\nVetor: ";
    for(int i=0; i<tamanho; i++){

        cout << vetor[i] << " ";
    }
    cout << "\n";
    system("pause");
}
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
void gerarVetor(int vetor[], int tamanho){

    int teste, i=0;
    bool ok;

    while(i<tamanho){

        teste = rand()%500;
        ok = true;

        for(int j=0; j<i; j++){

            if(teste == vetor[j]){
                ok=false;
                break;
            }
        }

        if(!ok){
            continue;
        }else{
            vetor[i] = teste;
            i++;
        }
    }

    ordemCrescente(vetor, tamanho);
    escreverValores(vetor, tamanho);

}
void excluirValor(int vetor[], int& tamanho){

    int teste;

    cout << "\nInforme um valor para excluir: ";
    cin >> teste;

    bool ok = false;
    int posicao;
    for(int i=0; i<tamanho; i++){
        if(vetor[i] == teste){
            posicao = i;
            ok = true;
            break;
        }
    }

    if(!ok){

        cout << "\nValor inexistente no vetor!\n";
        system("pause");
        return;
    }else{

        int aux = vetor[posicao];
        vetor[posicao] = vetor[tamanho-1];
        vetor[tamanho-1] = aux;

        tamanho -= 1;

        ordemCrescente(vetor, tamanho);
        escreverValores(vetor, tamanho);
    }
}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int tamanho;
    do{
        cout << "\nInforme o tamanho do vetor: ";
        cin >> tamanho;

        if(tamanho<1 || tamanho>=100){
            cout << "\nTamanho inválido!\n";
            system("pause");
        }

    }while(tamanho<1 || tamanho>=100);

    int *vetor = new int[tamanho];
    gerarVetor(vetor, tamanho);

    int op;
    do{
        system("cls");
        cout << "0 - Sair\n1 - Mostrar vetor\n2 - Excluir Valor\n\n\tOpção: ";
        cin >> op;

        if(op<0 || op>2){
            cout << "\nOpção inválida!\n";
            system("pause");
        }else if(op==1){
            exibirVetor(vetor, tamanho);
        }else if(op==2){
            excluirValor(vetor, tamanho);
        }

    }while(op!=0);

    delete[] vetor;

}
