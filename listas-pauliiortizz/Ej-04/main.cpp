#include <iostream>
#include "union.h"

using namespace std;

/*
 * Crear una función que dada dos listas enlazadas, pasadas como parámetro,
 * devuelva una lista enlazada que es la unión de las otras dos.
 */


int main() {
    list<int> lista1 = {56, -3, 1, 6, -3};
    list<int> lista2 = {8, 4};

    list<int> listaUnida = unirListas(lista1, lista2);

    cout << "Lista Unida: ";
    for (const int &num: listaUnida) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
