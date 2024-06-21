/*Implementar una funcion que reciba por parametro una pila P1 e invierta sus elementos.
 */

#include <iostream>
#include "../Pila/Pila.h"
using namespace std;

int main() {
    Pila<int> pila1;
    Pila<int> pila2;

    for (int i=0; i<5; i++){
        pila1.push(i);
    }
    cout << "Pila Original: ";
    pila1.imprimir();

    for (int i=0; i<5; i++){
        pila2.push(pila1.pop());
    }

    cout << "Pila Modificada: ";
    pila2.imprimir();
}
