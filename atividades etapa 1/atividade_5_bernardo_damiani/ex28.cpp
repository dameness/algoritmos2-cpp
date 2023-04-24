#include <iostream>
using namespace std;

/*
O IBGE realizou uma pesquisa entre habitantes de uma cidade. De cada habitante foram
coletados os dados:

 idade, sexo(M - Masculino, F- Feminino), salário e número de filhos.

 Crie a estrutura de dados adequada para armazenar estas informações e faça uma função que
armazene as informações digitadas pelo usuário na estrutura de dados criada.
O programa deverá possibilitar a exibição dos seguintes dados a qualquer momento:

- Média de salário das pessoas do sexo Masculino;
- Média de salário das pessoas do sexo Feminino;
- Sexo e salário da pessoa com a maior idade;
- Sexo e salário da pessoa com menor idade;
- Salário da pessoa com o maior número de filhos;
Crie as opções necessárias no menu.

OBS: o programa deverá funcionar para qualquer quantia de cadastros realizados.
*/
struct dados
{
    int idade;
    int filhos;
    char sexo;
    float salario;
};
void invalido();
void cadastrarHab(dados hab[], int n);
float mediaSalM(dados hab[], int n);
float mediaSalF(dados hab[], int n);
int olderHab(dados hab[], int n);
int youngerHab(dados hab[], int n);
int maisFilhosHab(dados hab[], int n);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    dados hab[500]; // número grande para o programa suportar "qualquer" quantia de cadastros
    int op, n=-1;
    bool ok=0;

    do
    {
        system("cls");

        cout << "\tIBGE\n\n1 - Cadastrar habitante\n2 - Média salarial homens\n3 - Média salarial mulheres\n4 - Sexo e salário da pessoa com a maior idade\n5 - Sexo e salário da pessoa com menor idade\n6 - Salário da pessoa com o maior número de filhos\n\n\tOpção:  ";
        cin >> op;
        fflush(stdin);

        if(op==0)
            cout << "\nVocê sairá do programa!\n";

        else if(op<0 || op>6)
            invalido();

        else if(op==1)//cadastro
        {
            n++;
            cadastrarHab(hab, n);
            ok=1;
        }
        else if(op==2 && ok==1)
        {
            if(mediaSalM(hab, n) == -1)
                cout << "\nNão houveram habitantes do sexo masculino!\n\n";
            else
                printf("\nMédia de salário das pessoas de sexo masculino: R$ %.2f\n\n", mediaSalM(hab, n));
            system("pause");

        }
        else if(op==3 && ok==1)
        {
            if(mediaSalF(hab, n) == -1)
                cout << "\nNão houveram habitantes do sexo feminino!\n\n";
            else
                printf("\nMédia de salário das pessoas de sexo feminino: R$ %.2f\n\n", mediaSalF(hab, n));
            system("pause");
        }
        else if(op==4 && ok==1)
        {
            int x = olderHab(hab, n);
            printf("\nSalário da pessoa de maior idade: R$ %.2f\nSexo da pessoa de maior idade: ", hab[x].salario);

            if(hab[x].sexo=='m')
                cout << "Masculino\n\n";
            else
                cout << "Feminino\n\n";
            system("pause");
        }
        else if(op==5 && ok==1)
        {
            int x = youngerHab(hab, n);
            printf("\nSalário da pessoa de menor idade: R$ %.2f\nSexo da pessoa de menor idade: ", hab[x].salario);

            if(hab[x].sexo=='m')
                cout << "Masculino\n\n";
            else
                cout << "Feminino\n\n";
            system("pause");
        }
        else if(op==6 && ok==1)
        {
            int x = maisFilhosHab(hab, n);
            printf("\nSalário da pessoa com mais filhos: R$ %.2f\n\n", hab[x].salario);
            system("pause");
        }
        else
        {
            cout << "\nNão há nenhuma pessoa cadastrada! Cadastre pessoas para mostrar estatísticas!\n";
            system("pause");
        }


    }
    while(op!= 0);
    return 0;
}
void invalido()
{
    cout << "\nEntrada inválida! Digite novamente!\n";
    system("pause");
}
void cadastrarHab(dados hab[], int n)
{
    do
    {
        cout << "\nIdade: ";
        cin >> hab[n].idade;

        if(hab[n].idade < 0)
            invalido();
    }
    while(hab[n].idade < 0);

    do
    {
        cout << "\nQtd. de filhos: ";
        cin >> hab[n].filhos;

        if(hab[n].filhos < 0)
            invalido();
    }
    while(hab[n].filhos < 0);

    do
    {
        cout << "\nSalário: ";
        cin >> hab[n].salario;

        if(hab[n].salario < 0)
            invalido();
    }
    while(hab[n].salario < 0);

    do
    {
        cout << "\nSexo (M ou F): ";
        cin >> hab[n].sexo;

        hab[n].sexo = tolower(hab[n].sexo);

        if(hab[n].sexo != 'm' && hab[n].sexo != 'f')
            invalido();
    }
    while(hab[n].sexo != 'm' && hab[n].sexo != 'f');
}
float mediaSalM(dados hab[], int n)
{
    int h=0;
    float s=0, ma=0;

    for(int i=0; i<=n; i++)
    {
        if(hab[i].sexo == 'm')
        {
            s+=hab[i].salario;
            h++;
        }
    }
    if(h==0)
        return -1;

    ma = s / h;
    return ma;
}
float mediaSalF(dados hab[], int n)
{
    int f=0;
    float s=0, ma=0;

    for(int i=0; i<=n; i++)
    {
        if(hab[i].sexo == 'f')
        {
            s+=hab[i].salario; // CUIDAR o habitante que estou manipulando
            f++;
        }
    }
    if(f==0)
        return -1;

    ma = s / f;
    return ma;


}
int olderHab(dados hab[], int n)
{
    int older;

    for(int i=0; i<=n; i++)
    {
        if(hab[n].idade > hab[older].idade || i==0)
            older = i;
    }
    return older;
}
int youngerHab(dados hab[], int n)
{
    int younger;

    for(int i=0; i<=n; i++)
    {
        if(hab[n].idade < hab[younger].idade || i==0)
            younger = i;
    }
    return younger;
}
int maisFilhosHab(dados hab[], int n)
{
    int mf;

    for(int i=0; i<=n; i++)
    {
        if(hab[n].filhos > hab[mf].filhos || i==0)
            mf = i;
    }
    return mf;
}

