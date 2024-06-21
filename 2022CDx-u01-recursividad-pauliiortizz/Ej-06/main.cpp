#include <iostream>

/*
 * Escriba una función recursiva que ordene de menor a mayor un arreglo
 * de enteros basándose en la siguiente idea: coloque el elemento más pequeño
 * en la primera ubicación, y luego ordene el resto del arreglo con una llamada recursiva.
 */
using namespace std;

void Ordenar(int A[], int n) {

    if (n <= 1) {
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < A[minIndex]) {
            minIndex = i;
        }
    }

    // Intercambiar el elemento más pequeño con el primer elemento
    if (minIndex != 0) {
        swap(A[0], A[minIndex]);
    }

    // Llamar recursivamente para ordenar el resto del arreglo
    Ordenar(A + 1, n - 1);
}

int main() {
    int n, A[n];

    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "NUMERO:";
        cin >>A[i];
    }

    cout << "Arreglo original: ";
    for (int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    Ordenar(A, n);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

