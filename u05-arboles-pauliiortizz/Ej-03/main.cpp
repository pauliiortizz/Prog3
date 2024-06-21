#include <iostream>
#include "../Arbol/ArbolBinario.h"

using namespace std;
//Implementar el método contarPorNivel que devuelve el número de nódos del nivel iésimo de un árbol binario.


int main() {
    std::cout << "Ejercicio 05/03\n" << std::endl;
    ArbolBinario<int> arbol;

    int valor;
    char opcion;

    do {
        cout << "Ingrese un valor para el nodo: ";
        cin >> valor;
        arbol.put(valor);

        cout << "Otro Nodo?: ";
        cin >> opcion;
    } while (opcion == 'S' || opcion == 's');

    arbol.print();


    int nivel;

    cout << "Nivel: ";
    cin >> nivel;

    int nodos = arbol.NodosporNivel(nivel);
    cout << "Cantidad de nodos en el nivel " << nivel << ": " << nodos << endl;

    return 0;
}
