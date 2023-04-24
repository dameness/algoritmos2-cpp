#include <iostream>
#include <cstring>
using namespace std;

/*
A professora de matemática do IFSUL, necessita elaborar um controle para registro das
suas turmas de alunos, para cada registro é necessário saber o número da matricula, nome,
turma, curso, média e frequência.
Conforme ocorre os fechamentos dos diários a professora registra os resultados dos alunos no
cadastro, após ela poderá usufruir dos relatórios emitidos pelo sistema, conforme apresentados.
O sistema deve permitir as seguintes ações:

0 - Sair

1 - Cadastrar aluno (não permitir cadastro com matrícula duplicada)

2 - Listar aluno por turma (Recebe o número da turma e lista todos os alunos (todos os dados)
que pertencem a referida turma, separando cada aluno com uma linha pontilhada, caso não
tenha alunos na turma deverá exibir uma mensagem com tal informação).

3 – Listar aprovados por curso (Recebe o nome do curso e lista todos os alunos pertencentes ao
curso que obtiveram média igual ou superior a 6.0 e frequência igual ou superior à 75).

4 – Média por turma (lista a maior, menor e a média das notas de cada turma, juntamente com
o número da turma, separando cada turma com uma linha pontilhada)

Obs: as ações devem funcionar para qualquer quantidade de pessoas cadastradas e serão no
máximo 50.
*/

// número da matricula, nome, turma, curso, média e frequência.

struct alunos
{
    int matricula;
    int turma;
    string nome;
    string curso;
    float media;
    float frequencia;
};
struct turmas
{
    int num;
    int qtd;
    int alunoPos[50];
};

void cadastrar(alunos aluno[], int &n, turmas vTurmas[], int &auxV);
void line();
void mostrarAluno(alunos aluno[], int n);
void mostrarTurma(alunos aluno[], int n, int turma);
void mostrarAprovCurso(alunos aluno[], int n, string curso);
float nMax(alunos aluno[], turmas vTurmas[], int n);
float nMin(alunos aluno[], turmas vTurmas[], int n);
float nMed(alunos aluno[], turmas vTurmas[], int n);
void mediaTurmas(alunos aluno[], turmas vTurmas[], int auxV);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct alunos aluno[50];
    struct turmas vTurmas[50];
    int n=-1, op, auxV=-1;
    bool ok=0;

    do
    {
        system("cls");
        cout << "\n0 - Sair\n1 - Cadastrar aluno\n2 - Listar alunos de turma\n3 - Aprovados por curso\n4 - Média por turma\n\n\tOpção: ";
        cin >> op;

        if(op<0 || op>4)
        {
            cout << "\nOpção inválida\n";
            system("pause");
        }
        else if(op==0)
        {
            cout << "\nPrograma finalizado!\n";
        }
        else if(op==1)
        {
            cadastrar(aluno, n, vTurmas, auxV);
            ok=1;
        }
        else if(ok==1)
        {
            if(op==2)
            {
                int turma;
                cout << "\nTurma: ";
                cin >> turma;
                mostrarTurma(aluno, n, turma);
                system("pause");
            }
            else if(op==3)
            {
                string c;
                cout << "\nCurso(exatamente como informado anteriormente): ";
                fflush(stdin);
                getline(cin, c);
                mostrarAprovCurso(aluno, n, c);
                system("pause");
            }
            else if(op==4)
            {
                mediaTurmas(aluno, vTurmas, auxV);

                cout << endl;
                system("pause");
            }
        }
        else
        {
            cout << "\nCadastre um aluno antes de realizar esta operação!\n";
            system("pause");
        }


    }
    while(op!=0);

    return 0;
}

void cadastrar(alunos aluno[], int &n, turmas vTurmas[], int &auxV)
{
    n++;

    cout << "\nNome:";
    fflush(stdin);
    getline(cin, aluno[n].nome);

    cout << "\nCurso:";
    fflush(stdin);
    getline(cin, aluno[n].curso);

    cout << "\nTurma(int):";
    fflush(stdin);
    cin >> aluno[n].turma;

    if(auxV==-1)
    {
        auxV++;
        vTurmas[auxV].num = aluno[n].turma;
        vTurmas[auxV].qtd=1;
        vTurmas[auxV].alunoPos[vTurmas[auxV].qtd-1] = n;
    }

    else
    {
        bool turmaJaExiste = false;
        for(int i=0; i<=n; i++)/////////////////////////////////////////////////
        {
            if(i!= n && aluno[i].turma ==  aluno[n].turma)
            {
                turmaJaExiste = true;
                for(int j=0; j<=auxV; j++)
                {
                    if(aluno[n].turma == vTurmas[j].num)
                    {
                        vTurmas[j].qtd++;
                        vTurmas[j].alunoPos[vTurmas[j].qtd-1] = n;
                        break;
                    }
                }
                break;
            }
        }

        if(turmaJaExiste==false)
        {
            auxV++;
            vTurmas[auxV].num = aluno[n].turma;
            vTurmas[auxV].qtd=1;
            vTurmas[auxV].alunoPos[vTurmas[auxV].qtd-1] = n;
        }

    }

    bool ok;
    do
    {
        cout << "\nMatrícula(int):";
        cin >> aluno[n].matricula;

        ok=0;
        for(int i=0; i<=n; i++)
        {
            if( i!=n && aluno[i].matricula == aluno[n].matricula)
            {
                cout << "\nMatrícula repetida!\n";
                system("pause;");
                break;
            }
            else if(i==n)
                ok=1;
        }

    }
    while(ok==0);

    do
    {
        cout << "\nMédia:";
        cin >> aluno[n].media;

        if(aluno[n].media<0 || aluno[n].media>10)
        {
            cout << "\nMédia inválida!\n";
            system("pause");
        }
    }
    while(aluno[n].media<0 || aluno[n].media>10);

    do
    {
        cout << "\nFrequência:";
        cin >> aluno[n].frequencia;

        if(aluno[n].frequencia<0 || aluno[n].frequencia>100)
        {
            cout << "\nFrequência inválida!\n";
            system("pause;");

        }
    }
    while(aluno[n].frequencia<0 || aluno[n].frequencia>100);

}
void line()
{
    for(int i=0; i<50; i++)
        cout << "-";
}
void mostrarAluno(alunos aluno[], int n)
{
    line();
    printf("\nNome: %s\nCurso: %s\nTurma: %d\nMatrícula: %d\nMédia: %.1f\nFrequência: %.1f\n", aluno[n].nome.c_str(), aluno[n].curso.c_str(), aluno[n].turma, aluno[n].matricula, aluno[n].media, aluno[n].frequencia);
}
void mostrarTurma(alunos aluno[], int n, int turma)
{
    bool ok=0;
    for(int i=0; i<=n; i++)
    {
        if(aluno[i].turma == turma)
        {
            ok=1;
            mostrarAluno(aluno, i);
        }
    }
    if(ok==1)
    {
        line();
        cout << endl;
    }
    else
    {
        cout << "\nNão há alunos nessa turma!\n";
    }
}
void mostrarAprovCurso(alunos aluno[], int n, string curso)
{
    bool ok=0;
    for(int i=0; i<=n; i++)
    {
        if(aluno[i].curso == curso && aluno[i].frequencia>=75 && aluno[i].media>=6)
        {
            ok=1;
            mostrarAluno(aluno, i);
        }
    }
    if(ok==1)
    {
        line();
        cout << endl;
    }
    else
    {
        cout << "\nNão há alunos aprovados nesse curso!\n";
    }
}
float nMax(alunos aluno[], turmas vTurmas[], int n)
{
    int M;
    for(int i=0; i<vTurmas[n].qtd; i++)
    {
        if(i==0 || aluno[vTurmas[n].alunoPos[i]].media > M)
        {
            M = aluno[vTurmas[n].alunoPos[i]].media;
        }
    }

    return M;
}
float nMin(alunos aluno[], turmas vTurmas[], int n)
{
    int m;
    for(int i=0; i<vTurmas[n].qtd; i++)
    {
        if(i==0 || aluno[vTurmas[n].alunoPos[i]].media < m)
        {
            m = aluno[vTurmas[n].alunoPos[i]].media;
        }
    }

    return m;
}
float nMed(alunos aluno[], turmas vTurmas[], int n)
{
    float soma=0;

    for(int i=0; i<vTurmas[n].qtd; i++)
    {
        soma += aluno[vTurmas[n].alunoPos[i]].media;
    }
    return soma/vTurmas[n].qtd;
}
void mediaTurmas(alunos aluno[], turmas vTurmas[], int auxV)
{
    for(int i=0; i<=auxV; i++)
    {
        line();
        printf("\nTurma: %d\nNota máx: %.1f\nNota mín: %.1f\nNota méd.: %.1f\n", vTurmas[i].num, nMax(aluno, vTurmas, i), nMin(aluno, vTurmas, i), nMed(aluno, vTurmas, i) );
    }
    line();
}


