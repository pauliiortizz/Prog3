#include <iostream>
#include "../Pila/Pila.h"
using namespace std;

int main() {
    Pila<int> pila1;
    Pila<int> pila2;
    Pila<int> aux1;
    Pila<int> aux2;

    for (int i=0; i<5; i++){
        pila1.push(i);
    }
    cout << "Pila 1: ";
    pila1.imprimir();

    for (int i=5; i<10; i++){
        pila2.push(i);
    }
    cout << "Pila 2: ";
    pila2.imprimir();

    cout << endl;
    aux1 = pila1;
    aux2 = pila2;

    pila1 = aux2;
    pila2 = aux1;

    cout << "Pila 1 MODIFICADA: ";
    pila1.imprimir();

    cout << "Pila 2 MODIFICADA: ";
    pila2.imprimir();

}
