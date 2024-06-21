#include <iostream>
#include "../Cola/Cola.h"

using namespace std;

//Diseñe un programa que sea capaz de leer dos colas y mediante un mensaje indicar si son iguales.
//Nota: los elementos constitutivos de las colas son caracteres.
int main() {
    std::cout << "Ejercicio 04/01\n" << std::endl;

    Cola<int> cola1;
    Cola<int> cola2;

    cout << "Ingrese elementos para la primera cola (ingrese '0' para finalizar):\n";
    char elemento;
    while (true) {
        cin >> elemento;
        if (elemento == '0') {
            break;
        }
        cola1.encolar(elemento);
    }

    cout << "Ingrese elementos para la segunda cola (ingrese '0' para finalizar):\n";
    while (true) {
        cin >> elemento;
        if (elemento == '0') {
            break;
        }
        cola2.encolar(elemento);
    }

    bool sonIguales = cola1.colasIguales(cola2);

    if (sonIguales) {
        cout << "Las colas son iguales.\n";
    } else {
        cout << "Las colas no son iguales.\n";
    }

    return 0;

}