#include <iostream>
#include <fstream>
using namespace std;

/*
Escreva um programa para cadastrar uma turma de alunos, de cada aluno será fornecido o
nome, nota 1, nota 2 e nota 3, os dados devem ser mantidos em um arquivo texto, colocando
os dados de cada aluno em uma linha diferente, o sistema deverá apresentar um menu com as
seguintes opções:
0 – Sair
1 – Cadastrar aluno
2 – Mostrar todos os cadastrados exibindo a média aritmética de cada aluno
3 – Mostrar a maior, menor e a média da turma
4 – Calcular o percentual de alunos aprovados (média >= 6) e reprovados (média < 6)
*/
struct info{

    string nome;
    float nota1, nota2, nota3;
};
void lerDados(ifstream& ler, string nomeArquivo, info alunos[], int& proximoAluno){

    ler.open(nomeArquivo, ios::in);

    char infoTexto[100];

    proximoAluno=0;
    int cont = 1;
    if(ler.is_open()){

        while(ler.getline(infoTexto, 100, ',')){

            if(cont==1){
                alunos[proximoAluno].nome = infoTexto;
                cont++;
            }else if(cont==2){
                alunos[proximoAluno].nota1 = atof(infoTexto);
                cont++;
            }else if(cont==3){
                alunos[proximoAluno].nota2 = atof(infoTexto);
                cont++;
            }else if(cont==4){
                alunos[proximoAluno].nota3 = atof(infoTexto);
                cont=1;
                proximoAluno++;
            }
        }
    }

    ler.close();
}
void escreverDados(ofstream& escrever, string nomeArquivo, info alunos[], int proximoAluno){

    escrever.open(nomeArquivo, ios::out);

    if(escrever.is_open()){

        for(int i=0; i<proximoAluno; i++)
            escrever << alunos[i].nome << "," << alunos[i].nota1 << "," << alunos[i].nota2 << "," << alunos[i].nota3 << ",\n";
    }
    escrever.close();

}
void cadastrarAluno(info alunos[], int& proximoAluno){

    cout << "\nNome do aluno: ";
    fflush(stdin);
    getline(cin, alunos[proximoAluno].nome);

    do{
        cout << "\nNota 1: ";
        cin >>alunos[proximoAluno].nota1;

        if(alunos[proximoAluno].nota1<0 || alunos[proximoAluno].nota1>10){
            cout << "\nValor inválido!\n";
            system("pause");
        }

    }while(alunos[proximoAluno].nota1<0 || alunos[proximoAluno].nota1>10);

    do{
        cout << "\nNota 2: ";
        cin >>alunos[proximoAluno].nota2;

        if(alunos[proximoAluno].nota2<0 || alunos[proximoAluno].nota2>10){
            cout << "\nValor inválido!\n";
            system("pause");
        }

    }while(alunos[proximoAluno].nota2<0 || alunos[proximoAluno].nota2>10);

    do{
        cout << "\nNota 3: ";
        cin >>alunos[proximoAluno].nota3;

        if(alunos[proximoAluno].nota3<0 || alunos[proximoAluno].nota3>10){
            cout << "\nValor inválido!\n";
            system("pause");
        }

    }while(alunos[proximoAluno].nota3<0 || alunos[proximoAluno].nota3>10);

    proximoAluno++;
}
void mostrarMedias(info alunos[], int proximoAluno){

    if(proximoAluno==0){
        cout << "\nAinda não há alunos!\n";
        system("pause");
        return;
    }else{
        float mediaAluno;
        cout << "\nAlunos:\n\n";

        for(int i=0; i<proximoAluno; i++){
            mediaAluno = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3.0;
            cout << alunos[i].nome << "\n";
            cout << "Média: " << mediaAluno<< "\n\n";
        }
        cout << "\n";
        system("pause");
    }

}
void calcularMedias(info alunos[], int quantidadeAlunos){

    if(quantidadeAlunos==0){
        cout << "\nAinda não há alunos!\n";
        system("pause");
        return;
    }else{

        float mediasTurma[quantidadeAlunos], maiorMedia, menorMedia, mediaGeral=0;

        for(int i=0; i<quantidadeAlunos; i++){
            mediasTurma[i] = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3.0;
        }
        for(int i=0; i<quantidadeAlunos; i++){
            if(i==0 || mediasTurma[i] > maiorMedia){
                maiorMedia = mediasTurma[i];
            }if(i==0 || mediasTurma[i] < menorMedia){
                menorMedia = mediasTurma[i];
            }
            mediaGeral+=mediasTurma[i];
        }
        mediaGeral = mediaGeral/quantidadeAlunos;
        cout << "\n\nMaior média: " << maiorMedia;
        cout << "\n\nMenor média: "<< menorMedia;
        cout << "\n\nMédia Geral: "<< mediaGeral << "\n\n";
        system("pause");
    }
}
void percentualAprovacao(info alunos[], int quantidadeAlunos){

    if(quantidadeAlunos==0){
        cout << "\nAinda não há alunos!\n";
        system("pause");
        return;
    }else{
        float mediasTurma[quantidadeAlunos], percentual;
        int aprovados=0;

        for(int i=0; i<quantidadeAlunos; i++){
            mediasTurma[i] = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3.0;
        }
        for(int i=0; i<quantidadeAlunos; i++){
            if(mediasTurma[i]>=6)
                aprovados ++;
        }
        percentual = (float(aprovados)/quantidadeAlunos)*100.0;

        cout << "\nPercentual aprovados: " << percentual << "%";
        cout << "\n\nPercentual reprovados: " << 100.0-percentual << "%\n\n";
        system("pause");
    }

}
main(){
    setlocale(LC_ALL, "Portuguese");
    cout << fixed;
    cout.precision(2);


    ifstream ler;
    ofstream escrever;

    string nomeArquivo;

    cout << "\nInforme o nome do arquivo: ";
    fflush(stdin);
    getline(cin, nomeArquivo);

    struct info alunos[100];
    int proximoAluno;

    lerDados(ler, nomeArquivo, alunos, proximoAluno);

    int op;

    do{
            system("cls");
            cout << "BOLETIM ESCOLAR";
            cout << "\n\n0 - Sair do programa\n1 - Cadastrar Aluno\n2 - Mostrar todos os cadastrados exibindo a média aritmética de cada aluno\n3 – Mostrar a maior média, menor média e a média da turma\n4 – Calcular o percentual de alunos aprovados (média >= 6) e reprovados (média < 6)\n\n\tOpção: ";
            cin >> op;

            if(op<0 || op>4){
                cout << "\nOpção inválida!\n";
                system("pause");
            }else if(op==0){
                cout << "\nO programa será finalizado e os dados serão gravados!\n";
                escreverDados(escrever, nomeArquivo, alunos, proximoAluno);
            }else if(op==1){
                cadastrarAluno(alunos, proximoAluno);
            }else if(op==2){
                mostrarMedias(alunos, proximoAluno);
            }else if(op==3){
                calcularMedias(alunos, proximoAluno);
            }else if(op==4){
                percentualAprovacao(alunos, proximoAluno);
            }

    }while(op!=0);


}
