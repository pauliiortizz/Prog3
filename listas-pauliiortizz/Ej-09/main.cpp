#include <iostream>
#include "../Ej-01/Lista.h"

using namespace std;

int main() {
    Lista<int> tlista = {1, 2, 3, 4, 3, 5, 3};
    cout << "Lista Original: ";
    tlista.imprimir();
    int tam= tlista.getTamanio();

    tlista.fnInvierte();

    cout << "Ingrese una posicion: ";
    int pos;
    cin >> pos;

    while (pos<0 || pos >tam){
        cout << "Posicione Invalida. Ingrese nuevamente: ";
        cin >> pos;
    }

    tlista.imprimirHastaPosicion(pos);
}
