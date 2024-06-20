#include <iostream>
#include "ListaEnlazada.h"
using namespace std;
/*
 * Agregue el método: insertAfter2(int oldValue, int n, int newValue)
 * que inserte un nodo con el valor newValue después de la enésima ocurrencia de oldValue.
 */

int main() {
    ListaEnlazada tlista;
    tlista.agregar(65);
    tlista.agregar(6);
    tlista.agregar(32);
    tlista.agregar(4);
    tlista.agregar(4);
    tlista.agregar(6);
    tlista.agregar(65);
    tlista.agregar(65);
    tlista.agregar(65);
    tlista.agregar(65);

    cout << "Lista original->";
    tlista.imprimir();

    tlista.insertAfter2(6,1, 567);

    cout << "Cambiada-> ";
    tlista.imprimir();

    return 0;
}
