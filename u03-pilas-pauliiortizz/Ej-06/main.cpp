/*Implementar una función Reemplazar que tenga como argumentos una pila de enteros y
 * dos valores enteros: nuevo y viejo, de forma que si viejo aparece en algún lugar de la pila,
 * sea reemplazado por nuevo.
 */

#include <iostream>
#include "../Pila/Pila.h"
using namespace std;

int main() {
    Pila<int> pila;

    for (int i=0; i<5; i++){
        pila.push(i);
    }
    cout << "Pila Original: ";
    pila.imprimir();

    // Reemplazar todas las ocurrencias de 3 por 5
    pila.reemplazar(3, 5);

    // Imprimir la pila después del reemplazo
    cout << "Pila Modificada: ";
    pila.imprimir();
}
