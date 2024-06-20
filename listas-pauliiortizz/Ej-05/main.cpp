#include <iostream>
#include "CircList.h"
#include "../Ej-01/Lista.h"
using namespace std;


int main() {
    ListaCircular <int> tcircular;
    Lista<int> tlista;

    tcircular.insertarPrimero(45);
    tcircular.insertarPrimero(-32);
    tcircular.insertarPrimero(3);

    tcircular.imprimir();

    cout << endl;
    tlista.insertarPrimero(45);
    tlista.insertarPrimero(-32);
    tlista.insertarPrimero(3);
    cout << "Lista ";
    tlista.imprimir();

    return 0;
}