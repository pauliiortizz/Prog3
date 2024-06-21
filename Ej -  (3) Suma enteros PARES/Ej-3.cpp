//
// Created by BANGHO on 07/12/2023.
//
/*
 * Escribir un programa que encuentre la suma de los enteros positivos pares desde N hasta 2.
 * Chequear que si N es impar se imprima un mensaje de error.
 */

#include <iostream>
using namespace std;

// Función recursiva para sumar los primeros N números impares
int sumaImpares(int n) {
    // Caso base: cuando n es menor o igual a 0, la suma es 0
    if (n <= 0) {
        return 0;
    }

    // Caso recursivo: la suma de los primeros N números impares es N + la suma de los primeros N-2 números impares
    return n + sumaImpares(n - 2);
}

int main() {
    cout << "Ingrese N: ";
    int n;
    cin >> n;

    // Validar que n sea impar y no 0
    while (n % 2 == 0 || n == 0) {
        cout << "NO es posible ingresar un numero PAR o el numero 0" << endl;
        cout << "Ingrese un numero impar: ";
        cin >> n;
    }

    int resultado = sumaImpares(n);
    cout << "La suma de los numeros impares desde " << n << " hasta 1 es: " << resultado;

    return 0;
}
