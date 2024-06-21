#include <iostream>

using namespace std;

int potencia(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    }
    //Funcion Recursiva
    return base * potencia(base, exponente - 1);
}

int main() {
    int base, exponente;

    cout << "Ingrese base: ";
    cin >> base;
    cout << "Ingrese exponente: ";
    cin >> exponente;

    cout << "El resultado de la potencia es: " << potencia(base, exponente) << endl;
}

