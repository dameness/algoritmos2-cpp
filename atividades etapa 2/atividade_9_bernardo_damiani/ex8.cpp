#include <iostream>
#include <ctime>
using namespace std;

/*
Escreva um programa que manipule dois vetores x1 e x2 com 6 valores inteiros, os quais devem ser
preenchidos de forma rand�mica com valores menores que 20 e sem n�meros repetidos no mesmo vetor.
Ap�s implemente uma fun��o que dever� gerar um vetor x3, contendo a intersec��o de x1 e x2,
exemplo:
Sendo x1 = {1, 4, 3, 5, 6, 7} e x2 = {1, 2, 3, 9, 6, 8}, x3 ir� conter {1, 3, 6}.
*/
void exibir(int *x, int tam)
{
    int i=0;
    while(i<tam)
    {
        cout << *x;
        if(i < tam-1)
            cout << ", ";

        x++;
        i++;
    }
    x-=i;
}
void gerar(int **pArr, int n)
{
    int i=0;
    while(i<n)
    {
        int x = rand()%20, ok=1;

        for(int j=0; j<n; j++)
        {
            if( *((*pArr) - i + j) == x) //pos inicial + j, para comparar desde o inicio
            {
                ok=0;
                break;
            }
        }

        if(ok==1)
        {
            **pArr = x; // se nenhum termo at� ent�o � igual ao novo termo, atribui o valor e incrementa o ponteiro
            (*pArr)++;
            i++;
        }
    }
    *pArr-=i;//volta ao valor original
}
void intersec(int *x1, int *x2, int *x3)
{
    gerar(&x1, 6);//chama a fun��o que gera ponteiros a partir do uso de ponteiro para ponteiro
    gerar(&x2, 6);

    cout << "Vetor x1: ";
    exibir(x1, 6);
    cout << "\nVetor x2: ";
    exibir(x2, 6);

    //intersec em x3
    int cx3 = 0;

    int *p1 = x1, *p2 = x2;

    while(p1 < x1 + 6) // regula o la�o para o m�x. de 6 termos do vetor x1
    {
        while(p2 < x2 + 6) // compara todos os 6 termos de x2 com cada um de x1
        {
            if(*p1 == *p2) //se o termo � igual em p1 e p2, x3 recebe esse termo e seu contador � incrementado para que este vetor de interse��o possa ser exibido no final
            {
                *x3 = *p1;
                x3++;
                cx3++;

                p2 = x2;//reseta p2, para que o pr�ximo termo de x1 compare desde o in�cio;

                break; // encerra o la�o e parte para o incremento de x1, pois j� encontrou um termo igual
            }
            p2++; //parte para pr�ximo termo de x2 a ser comparado

            if(p2 == x2 + 6) // se � a �ltima rodagem desse la�o, reseta p2 , para que no pr�ximo encremento de x1, todas as compara��es sejam feitas
            {
                p2 = x2;
                break;
            }

        }

        p1++;//ap�s tudo estar certo, passa para o pr�ximo termo de x1 a ser comparado
    }
    x3 -= cx3; // reseta x3 poder ser passado como par�metro corretamente na fun��o exibir()

    cout << endl;
    cout << "\nIntersec��o: ";
    exibir(x3, cx3);
    cout << endl;

}
main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int x1[6], x2[6], x3[6];

    intersec(x1, x2, x3);


}

