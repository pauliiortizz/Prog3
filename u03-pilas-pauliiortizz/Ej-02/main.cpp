#include <iostream>
#include "Pila.h"

using namespace std;

//Escriba una función que indique si dos pilas son iguales.
//Se entiende que dos pilas son iguales cuando sus elementos son idénticos y aparecen en el mismo orden.


int main() {
    Pila pila1, pila2;

    //Pilas por defecto
    //pila1.push(56);
    //pila1.push(103);
    //pila1.push(-44);

    //pila2.push(56);
    //pila2.push(103);
    //pila2.push(-44);

    int n1, n2, valor;

    cout << "Ingrese el tamano de la pila 1: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "Elemento " << i << ":";
        cin >> valor;
        pila1.push(valor);
    }

    cout << endl;

    cout << "Ingrese el tamano de la pila 2: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "Elemento " << i << ":";
        cin >> valor;
        pila2.push(valor);
    }

    // Verificar si las pilas son iguales
    if (sonPilasIguales(pila1, pila2)) {
        cout << "Las pilas son iguales." << endl;
    } else {
        cout << "Las pilas no son iguales." << endl;
    }

    return 0;
}






