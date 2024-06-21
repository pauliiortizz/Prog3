#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "../Arbol/ArbolBinario.h"

using namespace std;


/*
 * Diseñar una aplicación que permita: Cargar en un array 30 números generados aleatoriamente entre 100 y 500.
 * Imprimir los números. Crear un árbol binario de búsqueda con los datos del array.
 */

int main() {
    std::cout << "Ejercicio 05/01\n" << std::endl;
    ArbolBinario<int> arbol;

    srand(time(NULL));
    rand() % 10;

    int num;
    for (int i = 0; i < 30; i++) {
        num = rand() % 400 + 100;
        try {
            arbol.put(num);
        } catch (int error) {
            if (error == 200) {
                cout << "dato repetido, se saltea" << endl;
            } else {
                cout << "error desconocido";
            }
        }
    }
    arbol.print();


    return 0;
}
