/*
 * Escribir una función recursiva que devuelva la suma de los primeros N enteros
 */
#include <iostream>
using namespace std;

int Suma(int A[], int n) {

    if (n == 1) {
        return A[0];
    }
    // Llamar recursivamente para ordenar el resto del arreglo
    return A[0] + Suma(A + 1, n - 1);
}

int main() {
    int A[10];

    for (int i=0; i<10; i++){
        cout << "NUMERO:";
        cin >>A[i];
    }

    cout << "Arreglo original: ";
    for (int i=0; i<10; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    int n;
    cout << "Numero: ";
    cin >> n;
    while (n<=0 || n>10){
        cout << "Incorrecto. Numero: ";
        cin >> n;
    }
    int suma = Suma(A, n);
    cout << "La suma de los primeros " << n << " elementos es: " << suma << endl;

    return 0;

}

