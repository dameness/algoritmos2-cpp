#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float n;

    cout << fixed;
    cout.precision(2);

    cout << "Informe um valor: ";
    cin >> n;
    fflush(stdin); //limpa o buffer do teclado! usar!

    cout << "\nReajustes de 5%:\n";

    for(int i=1; i<=10; i++)
    {

        cout.width(6);
        cout.fill(' ');
        cout << i;
        cout.width(50);
        cout.fill('.');
        cout << n << endl;

        n += (5.0/100)*n;

    }


    return EXIT_SUCCESS;
}
