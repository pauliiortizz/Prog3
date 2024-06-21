#include <iostream>

using namespace std;


int suma(int arreglo[], int n) {
    if (n == 1) {
        return arreglo[0];
    }
    if (n == 0) {
        return 0;
    }
    return (arreglo[n - 1] + suma(arreglo, n - 1));
}

int main() {
    int arreglo[3] = {1, 2, 7};
    int n = 3;

    cout << "La suma es: " << suma(arreglo, n);
}
