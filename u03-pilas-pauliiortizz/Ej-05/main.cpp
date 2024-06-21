#include <iostream>
#include "../Pila/Pila.h"

using namespace std;

//Se tiene la siguiente expresión infija:

//(6+2)∗5−8/4

//Realizar un programa en C++ que me calcule la expresión postfija.

int main() {
    cout << "Ejercicio 03/05\n" << std::endl;
    string expresionInfija;

    cout << "Ingrese una expresion INFIJA: ";
    cin >> expresionInfija;

    string expresionPostfija = infijoAPostfijo(expresionInfija);

    cout << "Expresion Postfija: " << expresionPostfija << std::endl;

    return 0;
}
