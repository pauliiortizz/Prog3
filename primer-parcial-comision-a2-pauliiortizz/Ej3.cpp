#include <iostream>
#include "Estructuras/Cola.h"

using namespace std;

/*
 * Implementar una funcion que reciba una cola de numeros enteros y una pila entera vacia,
 * y separe los elementos de la cola, de tal manera que en la cola pemanezcan los pares
 * y en la pila se almacenen los impares
 */


/*void ParImpar(Pila<int> pila, Cola<int> cola, int dato, int n) {
//Creo un puntero al cual se le asigna la cola inresada por el usuario
    Cola<int> aux = cola;

    for (int i = 0; i < n; i++) {
        //Verifico si el dato en el tope tiene resto 0 cuando se divide por 2
        if (aux.peek() % 2 == 0) {
            //Si se cumple(es par), encola el dato en el aux y desencola en la cola original.
            aux.encolar(dato);
            cola.desencolar();
        } else {
            //Si no se cumple la condicion, osea que el dato es impar; el dato se guardara en la pila.
            pila.push(dato);
            pila.pop();
        }
    }
}*/

template <class T>
void ParImpar(Pila<T>& pila, Cola<T>& cola, int n) {
    for (int i = 0; i < n; i++) {
        if (cola.peek() % 2 == 0) {
            cola.encolar(cola.peek());
        } else {
            pila.push(cola.peek());
        }
        cola.desencolar();
    }
}

int main() {
    Cola<int> cola;
    Pila<int> pila;

    int n, dato;
    cout << "Ingrese el tamano de la cola: " << endl;
    cin >> n;

    cout << "----- COLA -----" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> dato;
        cola.encolar(dato);
    }

    cout << "Cola original: ";
    cola.print();
    cout << "Cola modificada: ";
    ParImpar(pila, cola, n);
    cola.print();
    cout << "Pila: ";
    pila.print();


    return 0;
}
