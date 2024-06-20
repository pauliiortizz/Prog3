#include <iostream>
#include "Lista.h"
using namespace std;

int main() {
    Lista<int> tlista; //Crea el objeto lista de tipo entero

    for (int i=0; i<5; i++){
        cout << "Inserte un numero: ";
        cin >> i; //El usuario ingresa un numero
        tlista.insertarUltimo(i); //El numero ingresado, se inserta en la lista
    }
    tlista.imprimir(); //Se muestra la lista que armo el usuario
    tlista.fnInvierte(); //Se invierte la lista armada por el usuario
    tlista.imprimir(); //Se imprime la lista invertida
}
