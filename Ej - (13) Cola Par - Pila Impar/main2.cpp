#include <iostream>
#include "Cola.h"
#include "Pila.h"

using namespace std;

/*template <class T>
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

int main(){
    Cola<int> cola;
    Pila<int> pila;

    int n;
    int valor;
    cout << "Ingrese el tamano de la cola: ";
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "Elemento " << i << ": ";
        cin >> valor;
        cola.encolar(valor);
    }


    cout << "Cola original: ";
    cola.imprimir();
    cout << "Cola modificada: ";
    ParImpar(pila, cola, n);
    cola.imprimir();
    cout << "Pila: ";
    pila.imprimir();

}*/

template <class T>
void ParImpar(Pila<T>& pila, Cola<T>& cola, int n) {
    for (int i = 0; i < n; i++) {
        if (pila.peek() % 2 == 0) {
            pila.pop();
        } else {
            cola.encolar(pila.peek());
            pila.pop();
        }
    }
}

int main() {
    Cola<int> cola;
    Pila<int> pila;

    int n;
    int valor;
    cout << "Ingrese el tamano de la pila: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> valor;
        pila.push(valor);
    }

    cout << "Pila original: ";
    pila.imprimir();
    cout << "Pila modificada: ";
    ParImpar(pila, cola, n);
    pila.imprimir();
    cout << "Cola: ";
    cola.imprimir();

    return 0;
}
