#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

/*
Crie um programa para controlar o estoque de mercadorias de uma pequena mercearia,
para cada produto é necessário armazenar as seguintes informações: código, nome, preço e
quantidade, os dados devem ser lidos do arquivo “produtos.txt”, sempre que o programa iniciar
e mantidos neste mesmo arquivo, sempre que o programa for encerrado. No arquivo os
produtos devem estar em uma linha contínua, separando as informações com um “#” sustenido.
O sistema deve possibilitar as seguintes ações:
0 - Sair
1 - Incluir um novo produto (não permitir código duplicado)
2 - Vender produto (validar se existe quantidade suficiente e atualizar a quantidade vendida)
3 - Listar produto com estoque zerado
4 - Consultar produto (informar o nome e o sistema lista os dados do produto)
5 - Listar todos os produtos (separando cada registro por uma linha pontilhada)
*/
struct item{
    string nome;
    int codigo, quantidade;
    float preco;
};
void linha(){
    cout << "\n";
    for(int i=0; i<50; i++)
        cout << "-";
    cout << "\n";
}
void lerProdutos(item produtos[], int& proximo){
    ifstream ler("produtos.txt");

    char infoTexto[100];
    int cont=1;

    proximo=0;

    if(ler.is_open()){
        while(ler.getline(infoTexto, 100, ';')){

            if(cont==1){
                produtos[proximo].nome = infoTexto;
                cont++;
            }else if(cont==2){
                produtos[proximo].codigo = atoi(infoTexto);
                cont++;
            }else if(cont==3){
                produtos[proximo].quantidade = atoi(infoTexto);
                cont++;
            }else if(cont==4){
                produtos[proximo].preco = atof(infoTexto);
                cont = 1;
                proximo++;
            }
        }
    }

    ler.close();
}
void gravarProdutos(item produtos[], int proximo){
     ofstream escrever("produtos.txt");

    if(escrever.is_open()){

        for(int i=0; i<proximo; i++)
            escrever << produtos[i].nome << "#" << produtos[i].codigo << "#" << produtos[i].quantidade << "#" << produtos[i].preco << "#";

    }

    escrever.close();
}
void incluirProduto(item produtos[], int& proximo){

    cout << "\nInforme um nome para o produto: ";
    fflush(stdin);
    getline(cin, produtos[proximo].nome);

    int codigoTeste;
    bool ok;

    do{
        ok=true;
        cout << "\nInforme um código para o produto: ";
        cin >> codigoTeste;

        for(int i=0; i<proximo; i++){

            if(codigoTeste == produtos[i].codigo){
                cout << "\nEsse código já existe!\n";
                ok = false;
                system("pause");
                break;
            }
        }

    }while(!ok);

    produtos[proximo].codigo = codigoTeste;

    do{
        ok=true;
        cout << "\nInforme a quantidade: ";
        cin >> produtos[proximo].quantidade;

        if(produtos[proximo].quantidade < 0){
            cout << "\nA quantidade não pode ser menor que zero!\n";
            ok = false;
        }

    }while(!ok);

    do{
        ok=true;
        cout << "\nInforme o preço: ";
        cin >> produtos[proximo].preco;

        if(produtos[proximo].preco < 0){
            cout << "\nO preço não pode ser menor que zero!\n";
            ok = false;
        }

    }while(!ok);

    proximo++;

}
void venderProduto(item produtos[], int proximo){

    int codigoTeste;
    cout << "\nInforme o código do produto: ";
    cin >> codigoTeste;

    bool ok=false;
    int posicao;

    for(int i=0; i<proximo; i++){

        if(produtos[i].codigo == codigoTeste){
            posicao = i;
            ok=true;
            break;
        }

    }
   if(!ok){
    cout << "\nEsse código não existe!\n";
    system("pause");
    return;
   }

   int qtd;
    do{
        ok=true;
        cout << "\nInforme a quantidade: ";
        cin >> qtd;

        if(qtd < 1){
            cout << "\nA quantidade a ser vendida não pode ser menor do que um!\n";
            ok = false;
        }

    }while(!ok);

   if(qtd > produtos[posicao].quantidade){
    cout << "\nQuantidade insuficiente!\n";
    system("pause");
    return;
   }else{
    produtos[posicao].quantidade -= qtd;
    cout << "\nVenda realizada com sucesso!\n";
   }
}
void produtosZerados(item produtos[], int proximo){
    cout << "\nProdutos sem estoque:\n";
    for(int i=0; i<proximo; i++){
        if(produtos[i].quantidade==0){
            cout << produtos[i].codigo << "\t" << produtos[i].nome;
            linha();
        }
    }

    cout << "\n\n";
}
void consultarProduto(item produtos[], int proximo){

    string nome;
    cout << "\nInforme o nome do produto: ";
    fflush(stdin);
    getline(cin, nome);

    bool ok=0;

    for(int i=0; i<proximo; i++){

        if(nome==produtos[i].nome){
            cout << produtos[i].codigo << "  " << produtos[i].nome << "  qtd.:" << produtos[i].quantidade << "  R$" << produtos[i].preco << "\n";
            ok=true;
        }
    }
    if(!ok){
        cout << "\nNenhum produto com esse nome!\n";
    }

    cout << endl;
    system("pause");
}
void mostrarProdutos(item produtos[], int proximo){
    cout << "\nProdutos:\n\n";
    cout << "Código\tNome\tQtd.\tPreço\n\n";
    for(int i=0; i<proximo; i++){
        if(produtos[i].quantidade!=0){
            cout << produtos[i].codigo << "\t" << produtos[i].nome << "\t" << produtos[i].quantidade << "\t" << produtos[i].preco;
            linha();
        }
    }

    cout << "\n\n";
}
main(){
    setlocale(LC_ALL, "Portuguese");

    struct item produtos[100]; //limite de produtos: 100;
    int proximoProduto;

    cout << fixed;
    cout.precision(2);

    lerProdutos(produtos, proximoProduto);

    int op;
    do{
        system("cls");
        cout << "0 - Sair\n1 - Incluir um novo produto (não permitir código duplicado)\n2 - Vender produto (validar se existe quantidade suficiente e atualizar a quantidade vendida)\n3 - Listar produto com estoque zerado\n4 - Consultar produto (informar o nome e o sistema lista os dados do produto)\n5 - Listar todos os produtos (separando cada registro por uma linha pontilhada)\n\n\tOpção: ";
        cin >> op;

        if(op<0 || op>5){
            cout << "\nOpção inválida!\n";
            system("pause");
        }else if(op==0){
            cout << "\nVocê sairá do programa e os dados serão gravados!\n";
            gravarProdutos(produtos, proximoProduto);
        }else if(op==1){
            incluirProduto(produtos, proximoProduto);
        }else if(op==2){
            venderProduto(produtos, proximoProduto);
            system("pause");
        }else if(op==3){
            produtosZerados(produtos, proximoProduto);
            system("pause");
        }else if(op==4){
            consultarProduto(produtos, proximoProduto);
            system("pause");
        }else if(op==5){
            mostrarProdutos(produtos, proximoProduto);
            system("pause");
        }

    }while(op!=0 && proximoProduto<100);

    if(proximoProduto>=100){
        cout << "\nO limite de produtos foi alcançado!\n";
    }

}
