//INTERCAMBIO DE COLAS

#include <iostream>
#include "../Cola/Cola.h"

int main() {
    Cola <int> cola1;
    Cola <int> cola2;
    Cola <int> aux1;
    Cola <int> aux2;

    for (int i=0; i<5; i++){
        cola1.encolar(i);
    }

    for (int i=5; i<10; i++){
        cola2.encolar(i);
    }

    cout << "Cola 1: ";
    cola1.imprimir();
    cout << "Cola 2: ";
    cola2.imprimir();

    cout << endl;

    aux1 = cola1;
    aux2 = cola2;

    cola1 = aux2;
    cola2 = aux1;

    cout << "Cola 1 MODIFICADA: ";
    cola1.imprimir();
    cout << "Cola 2 MODIFICADA: ";
    cola2.imprimir();
}

