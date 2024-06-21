#include <iostream>
#include "../Pila/Pila.h"

using namespace std;

//Agregar la función peek a la clase pila que permita ver el valor del tope de pila sin sacarlo.

int main() {
    cout << "Ejercicio 03/03\n" << endl;

    Pila<int> pila;
    int valor, n;

    cout << "Ingrese el tamano de la pila: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> valor;
        pila.push(valor);
    }

    cout << "El tope de la pila es: " << pila.peek() << endl;

    cout << "Vaciando Pila" << endl;
    while (!pila.esVacia()) {
        cout << pila.pop() << endl;
        cout << "|" << endl;
    }
    return 0;
}
