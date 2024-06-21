#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

class Pila {
private:
    Nodo *tope;

public:
    Pila() : tope(nullptr) {}

    void push(int valor) {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
    }

    void pop() {
        if (!esVacia()) {
            Nodo *temp = tope;
            tope = tope->siguiente;
            delete temp;
        }
    }

    int peek() const {
        if (!esVacia()) {
            return tope->dato;
        }
    }

    bool esVacia() const {
        return tope == nullptr;
    }

    Nodo *obtenerTopeNodo() const {
        return tope;
    }
};

// Función para verificar si dos pilas son iguales
bool sonPilasIguales(const Pila &pila1, const Pila &pila2) {
    // Si las pilas tienen tamaños diferentes, no pueden ser iguales
    if (pila1.esVacia() != pila2.esVacia()) {
        return false;
    }

    // Comparamos elemento por elemento
    Nodo *actual1 = pila1.obtenerTopeNodo();
    Nodo *actual2 = pila2.obtenerTopeNodo();

    while (actual1 != nullptr) {
        if (actual1->dato != actual2->dato) {
            return false;
        }
        actual1 = actual1->siguiente;
        actual2 = actual2->siguiente;
    }

    return true;
}

