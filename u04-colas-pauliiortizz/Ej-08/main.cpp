//SUMA DE COLAS

#include <iostream>
#include "../Cola/Cola.h"

int main() {
    Cola<int> cola1;
    Cola<int> cola2;

    for (int i = 0; i < 5; i++) {
        cola1.encolar(i);
    }

    for (int i = 5; i < 12; i++) {
        cola2.encolar(i);
    }

    cout << "Cola 1: ";
    cola1.imprimir();
    cout << "Cola 2: ";
    cola2.imprimir();

    cout << endl;

    cout << "Suma de colas: ";
    cola1.suma(cola2);
}

