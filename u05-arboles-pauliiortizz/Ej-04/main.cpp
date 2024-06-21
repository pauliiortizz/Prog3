#include <iostream>
#include "../Arbol/ArbolBinario.h"
using namespace std;

//Especificar la operación espejo que devuelve la imagen especular de un árbol binario.

int main() {
  std::cout << "Ejercicio 05/03\n" << std::endl;

    ArbolBinario<int> arbol;
    ArbolBinario<int> arbolEspejado;

    int valor;
    char opcion;

    do {
        cout << "Ingrese un valor para el nodo: ";
        cin >> valor;
        arbol.put(valor);
        arbolEspejado.putEspejado(valor);

        cout << "Ingresar otro nodo? (S/N): ";
        cin >> opcion;
    } while (opcion == 'S' || opcion == 's');

    cout << "Arbol Original: " << endl;
    arbol.print();

    cout << endl;

    cout << "Arbol Espejado: " << endl;
    arbolEspejado.print();


  return 0;
}
