#include <iostream>
using namespace std;

/*
 * Implementar una funcion recursiva que determine la suma de los "n" primeros numeros naturales.
 */

// Función recursiva para calcular la suma de los primeros n números naturales
int sumaNaturales(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumaNaturales(n - 1);
    }
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    int resultado = sumaNaturales(n);
    cout << "La suma de los primeros " << n << " numeros naturales es: " << resultado << endl;

    return 0;
}
