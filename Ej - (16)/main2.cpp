#include <iostream>
#include "Cola.h"
#include "Lista.h"
using namespace std;


/*int main(){
    Pila<int> pila;
    int p, n, valor;

    cout << "Ingrese el tamano de la pila:";
    cin >> p;

    for (int i=0; i<p; i++){
        cout << "Elemento " << i << ": ";
        cin >> valor;
        pila.push(valor);
    }

    cout << endl;

    cout << "Ingrese n: ";
    cin >> n;

    cout << "PILA ORIGINAL: ";
    pila.imprimir();
    cout << endl;
    pila.sumarAElementos(n);
    cout << "PILA MODIFICADA: ";
    pila.imprimir();
}*/
/*
int main (){
    Cola<int> cola1;
    Cola<int> cola2;
    int p,n, valor;

    cout << "Ingrese el tamano de la pila 1:";
    cin >> p;

    for (int i=0; i<p; i++){
        cout << "Elemento " << i << ": ";
        cin >> valor;
        cola1.encolar(valor);
    }

    cout << "Ingrese el tamano de la pila 2:";
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "Elemento " << i << ": ";
        cin >> valor;
        cola2.encolar(valor);
    }

    cout << endl;

    cout << "PILA 1 ORIGINAL: ";
    cola1.imprimir();
    cout << "PILA 2 ORIGINAL: ";
    cola2.imprimir();

    cout << endl;
    Cola<int> aux;

    aux = cola1;
    cola1 = cola2;
    cola2 = aux;

    cout << "PILA 1 MODIFICADA: ";
    cola1.imprimir();
    cout << "PILA 2 MODIFICADA: ";
    cola2.imprimir();

}*/
/*

int main (){
    Cola<int> cola1;
    int p,n, valor;

    cout << "Ingrese el tamano de la pila 1:";
    cin >> p;

    for (int i=0; i<p; i++){
        cout << "Elemento " << i << ": ";
        cin >> valor;
        cola1.encolar(valor);
    }
    cout << endl;
    cout << "Ingrese n: ";
    cin >> n;

    cout << "COLA 1 ORIGINAL: ";
    cola1.imprimir();

    cola1.Sumar(n);

    cout << "COLA 1 MODIFICADA: ";
    cola1.imprimir();
}*/

template<class T>
Lista<T> sumaListas(Lista<T>& lista1,Lista<T>& lista2) {
    Lista<T> resultado;

    // Mientras ambas listas tengan elementos, sumar los elementos y poner el resultado en la lista 'resultado'
    Nodo<T>* actualLista1 = lista1.obtenerCabeza();
    Nodo<T>* actualLista2 = lista2.obtenerCabeza();

    while (actualLista1 != nullptr && actualLista2 != nullptr) {
        T suma = actualLista1->getDato() + actualLista2->getDato();
        resultado.insertarUltimo(suma);
        actualLista1 = actualLista1->getSiguiente();
        actualLista2 = actualLista2->getSiguiente();
    }

    return resultado;
}

int main (){
    Pila<int> cola1;
    int p,valor;

    cout << "Ingrese el tamano de la pilas";
    cin >> p;

    for (int i=0; i<p; i++){
        cout << "Elemento " << i << ": ";
        cin >> valor;
        cola1.push(valor);
    }

    cout << "Ingrese numero: ";
    int num;
    cin >> num;
    cout << "COLA 1 ORIGINAL: ";
    cola1.imprimir();

    cola1.removerNum(num);
}