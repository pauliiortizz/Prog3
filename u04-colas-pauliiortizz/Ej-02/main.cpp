#include <iostream>
#include "../Cola/Cola.h"

//Utilizando una pila y una cola, realizar una función que reciba una cadena y devuelva el valor
//lógico verdadero si dicha cadena es un palidromo. No se deben tener en cuenta los espacios y signos de puntuación.

int main() {
  std::cout << "Ejercicio 04/02\n" << std::endl;
    string cadena;
    cout << "Ingrese una cadena para verificar si es un palindromo: ";
    getline(cin, cadena);

    if (esPalindromo(cadena)) {
        cout << "Es un palindromo." << endl;
    } else {
        cout << "No es un palindromo." << endl;
    }

    return 0;
  return 0;
}
