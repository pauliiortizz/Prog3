#include "digitos.h"

#include <iostream>

using namespace std;

unsigned int cociente(unsigned int a, unsigned int b) {
    int resultado;
    if (a < b) {
        resultado = 0;
    } else {
        resultado = 1 + cociente(a - b, b);
    }
    return resultado;
}

unsigned int resto(unsigned int a, unsigned int b) {
    int resultado;
    if (a < b) {
        resultado = a; // Caso base: Cuando a < b, el resto es simplemente a.
    } else {
        resultado = resto(a - b, b);
    }
    return resultado;
}

void escribir_espaciado(unsigned int num) {
    int resultado;
    if (num >= 10){
        escribir_espaciado(cociente(num,10));
    }
    cout << resto(num,10) << " | " ;
}
