#include <iostream>
#include "../Ej-01/Lista.h"

using namespace std;

int main() {
    Lista<int> tlista = {1, 2, 3, 4, 3, 5, 3};
    cout << "Lista Original: ";
    tlista.imprimir();

    int n;

    cout << "Ingrese el numero que desea borrar: ";
    cin >> n;

    // Obtener las posiciones donde se encuentra el número
    int* posiciones = tlista.obtenerPosiciones(n);
    int posicion;

    // Eliminar todas las ocurrencias del número
    // Recorrer las posiciones en orden inverso
    for (int i = posiciones[0]; i >= 0; i--) {
        posicion = posiciones[i];
        tlista.remover(posicion);
    }

    // Liberar la memoria del array de posiciones
    delete[] posiciones;

    cout << "Lista despues de eliminar " << n << ": ";
    tlista.imprimir();

    return 0;
}
