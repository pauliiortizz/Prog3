/*Implementar un método en la clase lista que reciba como parámetro un valor entero “pos”. El método debe
        buscar el nodo en la posición “pos” y moverlo al inicio. Considerar el uso excepciones de ser necesario. (Solo
        moviendo enlaces. No creando nodos nuevos)*/
#include <iostream>
#include "../Ej-01/Lista.h"

using namespace std;

int main() {
    Lista<int> tlista;

    cout << "Ingrese el tamano de la lista: ";
    int size;
    cin >> size;
    cout << endl;

    for (int i=0; i<size; i++){
        tlista.insertarPrimero(i);
    }

    cout << "Lista: ";
    tlista.imprimir();
    cout << endl;

    cout << "Ingrese la posicion del numero que desea insertar primero en la lista:    ";
    int pos;
    cin >> pos;
    while (pos<=0 || pos>size){
        cout << "Posicion no existente. Ingrese Nuevamente:    ";
        cin >> pos;
    }
    int dato = tlista.getDato(pos);
   // cout << dato;
    tlista.insertarPrimero(dato);
    tlista.remover(pos);
    tlista.imprimir();
}