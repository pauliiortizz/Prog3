//
// Created by BANGHO on 30/08/2023.
//
#include <iostream>
using namespace std;

class Nodos {
public:
    int valor;
    Nodos* siguiente;
    Nodos(int val) : valor(val), siguiente(nullptr) {}
};

class ListaEnlazada {
private:
    Nodos* inicio;

public:
    ListaEnlazada() : inicio(nullptr) {}

    ~ListaEnlazada() {
        while (inicio != nullptr) {
            Nodos* temp = inicio;
            inicio = inicio->siguiente;
            delete temp;
        }
    }

    void agregar(int valor) {
        Nodos* nuevoNodo = new Nodos(valor);
        if (inicio == nullptr) {
            inicio = nuevoNodo;
        } else {
            Nodos* actual = inicio;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    void imprimir() {
        Nodos* actual = inicio;
        while (actual != nullptr) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    void insertAfter2(int oldValue, int n, int newValue) {
        Nodos* actual = inicio;
        int ocurrencias = 0;

        while (actual != nullptr) {
            if (actual->valor == oldValue) {
                ocurrencias++;

                if (ocurrencias == n) {
                    Nodos* nuevoNodo = new Nodos(newValue);
                    nuevoNodo->siguiente = actual->siguiente;
                    actual->siguiente = nuevoNodo;
                    break;
                }
            }

            actual = actual->siguiente;
        }
    }
};

