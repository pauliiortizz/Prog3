#include <iostream>
#include "../Pila/Pila.h"

using namespace std;

//Escriba un programa que ingresada una función matemática,
//informe si la cantidad de (, [, { que abren están balanceados con los que cierran.

int main() {
    std::cout << "Ejercicio 03/04\n" << std::endl;
    string expresion;
    cout << "Ingrese una operacion matematica: ";
    cin >> expresion;

    if (verificacion(expresion)) {
        cout << "Los (, [, y { estan bien" << endl;
    } else {
        cout << "Los (, [, y { NO estan bien" << endl;
    }

    return 0;
}
