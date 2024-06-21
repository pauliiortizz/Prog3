#include <iostream>
#include "Estructuras/Lista.h"
using namespace std;


/*
 * Funcion que imprima elementos de una lista enlazada de forma invertida
 * hasta cierta posicion, asignada por el usuario.
 */

int main() {
    Lista<int> lista;
    int n, valor, nInvertir;

    cout << "Ingrese el tamano de la lista: ";
    cin >> n;

    cout << "----- LISTA -----" << endl;
    for (int i=0; i<n; i++){
        cout << "Elemento " << i << ": ";
        cin >> valor;
        lista.insertar(i, valor);
    }

    cout << "Ingrese el elemento de la posicion al cual desea invertir la lista: ";
    cin >> nInvertir;

    while(nInvertir<0 || nInvertir>=n){
        cout << "La posicion ingresada no se encuentra en el arreglo." << endl;
        cout << "Ingrese nuevamente: ";
        cin >> nInvertir;
    }

    cout << "Lista original: ";
    lista.print();

    cout << "Lista Inversa: ";
    lista.printInverso(nInvertir);
    return 0;
}
