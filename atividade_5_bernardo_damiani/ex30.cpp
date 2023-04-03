#include <iostream>
using namespace std;

/*
Tempo da atividade (em horas), Distância percorrida (em km), Frequência cardíaca., identificado pelo número da sua camisa
e deve ter a informação da sua idade e seu peso corporal

0 – Sair
1 – Cadastrar atleta (O sistema deve funcionar com qualquer quantidade de atletas
cadastrados)
2 – Mostrar todos os cadastrados (exibir todos os dados separando cada atleta por uma linha
pontilhada)
3 – Velocidade média de cada jogador
4 – Distância percorrida em ordem decrescente
5 – Maior e menor consumo de calorias
*/
struct atv
{
    float horas;
    int frequencia; //cardíaca
    float distancia;

};
struct atletas
{
    int nCamisa;
    int idade;
    float peso;
    atv atividade;

};

void line();
void cadastrar(atletas jogador[], int n, float vDist[]);
void mostrarUm(atletas jogador[], int n, bool apenasVM=0);
void mostrarTodos(atletas jogador[], int n, bool apenasVM=0);
float calcKcal(atletas jogador[], int n);
void maiorMenorKcal(atletas jogador[], int n, float vKcal[]);
void ordenarVetorDistancias(float vDist[], int n);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct atletas jogador[100]; //número "qualquer" de atletas pode ser cadastrado
    int op, n=-1;
    bool ok=0;
    float vDist[100], vKcal[100];

    do
    {
        system("cls");
        cout << "\n0 - Sair\n1 - Cadastrar atleta\n2 - Mostrar cadastrados\n3 - Velocidade média de cada jogador\n4 - Distâncias percorridas (ordem decrescente)\n5 - Maior e menor número de calorias\n\n\t\tOpção: ";
        cin >> op;

        if(op<0 || op>5)
        {
            cout << "\nOpção inválida! Digite novamente!\n";
            system("pause");
            continue;
        }
        else if(op==0)
            cout << "\nVocê sairá do programa!\n";

        else if(op==1)
        {
            n++;
            cadastrar(jogador, n, vDist);
            ok=1;
        }
        else if(op==2 && ok==1)
        {
            cout << "\nAtletas:\n";
            mostrarTodos(jogador, n);
            cout  << "\n";
            system("pause");
        }
        else if(op==3 && ok==1)
        {
            cout << "\nVelocidades médias:\n";
            mostrarTodos(jogador, n, 1);
            cout  << "\n";
            system("pause");
        }
        else if(op==4 && ok==1)
        {
            ordenarVetorDistancias(vDist, n);
            cout << "\nDistâncias dos jogadores em ordem decrescente: ";
            for(int i=0; i<=n; i++)
            {
                printf("%.1f", vDist[i]);
                if(i<n)
                    cout << "; ";
            }
            cout << "\n\n";
            system("pause");
        }
        else if(op==5 && ok==1)
        {
            maiorMenorKcal(jogador, n, vKcal);
            system("pause");
        }
        else
        {
            cout << "\nAinda não há nenhum jogador cadastrado! Cadastre algum para realizar esta operação!\n";
            system("pause");
        }
    }
    while(op!=0);

    return 0;
}
void line()
{
    for(int i=0; i<50; i++)
        cout << "-";
}
void cadastrar(atletas jogador[], int n, float vDist[])
{
    bool ok;
    do
    {
        cout << "\nNúmero da camisa: ";
        cin >> jogador[n].nCamisa;

        if(jogador[n].nCamisa<1 || jogador[n].nCamisa>99)
        {
            cout << "\nNúmero inválido! Digite novamente!\n";
            system("pause");
        }
        else
        {
            for(int i=0; i<=n; i++)
            {
                if(i != n && jogador[n].nCamisa == jogador[i].nCamisa)
                {
                     cout << "\nNúmero inválido! Digite novamente!\n";
                     system("pause");
                     ok=0;
                     break;
                }
                ok=1;
            }
        }
    }
    while(jogador[n].nCamisa<1 || jogador[n].nCamisa>99 || ok!= 1);

    do
    {
        cout << "\nIdade: ";
        cin >> jogador[n].idade;

        if(jogador[n].idade<0)
        {
            cout << "\nNúmero inválido! Digite novamente!\n";
            system("pause");
        }
    }
    while(jogador[n].idade<0);

    do
    {
        cout << "\nPeso: ";
        cin >> jogador[n].peso;

        if(jogador[n].peso<=0)
        {
            cout << "\nNúmero inválido! Digite novamente!\n";
            system("pause");
        }
    }
    while(jogador[n].peso<=0);

    do
    {
        cout << "\nHoras da atividade: ";
        cin >> jogador[n].atividade.horas;

        if(jogador[n].atividade.horas<=0)
        {
            cout << "\nNúmero inválido! Digite novamente!\n";
            system("pause");
        }
    }
    while(jogador[n].atividade.horas<=0);

    do
    {
        cout << "\nDistância da atividade(km): ";
        cin >> jogador[n].atividade.distancia;

        if(jogador[n].atividade.distancia<=0)
        {
            cout << "\nNúmero inválido! Digite novamente!\n";
            system("pause");
        }
        else
            vDist[n] = jogador[n].atividade.distancia;

    }
    while(jogador[n].atividade.distancia<=0);

    do
    {
        cout << "\nFrequência cardíaca média em atividade(bpm, arredondada): ";
        cin >> jogador[n].atividade.frequencia;

        if(jogador[n].atividade.frequencia<=0)
        {
            cout << "\nNúmero inválido! Digite novamente!\n";
            system("pause");
        }
    }
    while(jogador[n].atividade.frequencia<=0);
}
void mostrarUm(atletas jogador[], int n, bool apenasVM)
{
    if(apenasVM==1)
    {
        float vm = jogador[n].atividade.distancia / jogador[n].atividade.horas;
        line();
        printf("\nCamisa: %d\nDistância(km): %.1f\nTempo(h): %.1f\nVelocidade Média(km/h): %.1f\n", jogador[n].nCamisa, jogador[n].atividade.distancia, jogador[n].atividade.horas, vm);
    }
    else
    {
        line();
        printf("\nCamisa: %d\nIdade: %d\nPeso: %.1f\n\nHoras de Atividade: %.1f\nDistância percorrida(km): %.1f\nFrequência cardíaca média(bpm): %d\n", jogador[n].nCamisa, jogador[n].idade, jogador[n].peso, jogador[n].atividade.horas, jogador[n].atividade.distancia, jogador[n].atividade.frequencia);
    }
}
void mostrarTodos(atletas jogador[], int n, bool apenasVM)
{
    for(int i=0; i<=n; i++)
    {
        if(apenasVM==1)
            mostrarUm(jogador, i, 1);
        else
            mostrarUm(jogador, i);
    }
    line();
}
float calcKcal(atletas jogador[], int n)
{
    float vm = jogador[n].atividade.distancia / jogador[n].atividade.horas, kcal;

    kcal = vm * jogador[n].peso * 0.0175 * 60 * jogador[n].atividade.horas;

    return kcal;
}
void maiorMenorKcal(atletas jogador[], int n, float vKcal[])
{
    for(int i=0; i<=n; i++)
        vKcal[n] = calcKcal(jogador, n);
    float maior, menor;
    int maiorCamisa, menorCamisa;
    for(int i=0; i<=n; i++)
    {
        if(i==0)
        {
            maior = vKcal[i];
            maiorCamisa = jogador[i].nCamisa;
            menor = vKcal[i];
            menorCamisa = jogador[i].nCamisa;
        }
        else
        {
            if(vKcal[i]>maior)
            {
                maior = vKcal[i];
                maiorCamisa = jogador[i].nCamisa;
            }
            if(vKcal[i]<menor)
            {
                menor = vKcal[i];
                menorCamisa = jogador[i].nCamisa;
            }
        }
    }
    printf("\nO jogador que consumiu mais calorias foi o camisa %d, que consumiu %.1f kcal.\nO jogador que consumiu menos calorias foi o camisa %d, que consumiu %.1f kcal.\n", maiorCamisa, maior, menorCamisa, menor);
}
void ordenarVetorDistancias(float vDist[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(vDist[i]<vDist[j])
            {
                float aux = vDist[i];
                vDist[i] = vDist[j];
                vDist[j] = aux;
            }
        }
    }
}

