#include <iostream>
#include "../Cola/Cola.h"

int main() {
  std::cout << "Ejercicio 04/03\n" << std::endl;
    Cola<int> cola;

    int prioridad, n;

    cout << "Ingrese el tamano de la cola: ";
    cin >> n;
    for (int i=0; i<n; i++){
        cout << "Ingrese la prioridad del elemento " << i << ": ";
        cin >> prioridad;
        cout << endl;
        cola.encolarConPrioridad(i, prioridad);
    }

    while (!cola.esVacia()) {
        cout << cola.desencolar() << " ";
    }

    return 0;
}
