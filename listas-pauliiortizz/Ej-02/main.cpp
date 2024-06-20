#include <iostream>
#include "../Ej-01/Lista.h"

using namespace std;

int main() {
    Lista<int> tlista;
    int size;
    cout << "Ingrese el tamano: ";
    cin >> size;
    //Se ingresa el tamaño de la lista

    for (int i = 0; i < size; i++) {
        tlista.insertarUltimo(i);
    } //Se insertan los numeros desde el 0 hasta el tamaño de la lista

    cout << "Lista original: ";
    tlista.imprimir();
    //Se imprime la lista

    char si_no;
    do {
        cout << "Ingrese un numero: ";
        int num;
        cin >> num;
        //Se ingresa un numero

        cout << "-- POSICION DEL NUMERO --" << endl;
        cout << "1. Al principio" << endl;
        cout << "2. Al final" << endl;
        cout << "3. En el medio" << endl;
        cout << "Seleccione una opcion: ";
        int opcion;
        cin >> opcion;


        switch (opcion) {
            case 1:
                tlista.insertarPrimero(num);
                //El numero ingresado se agrega al principio
                break;
            case 2:
                tlista.insertarUltimo(num);
                //El numero ingresado se agrega al final
                break;
            case 3:
                size = size / 2;

                tlista.insertar(size, num);
                //Se divide el tamaño de la lista. Con ese nuevo tamaño se obtiene la posicion del medio, y alli se inserta el numero
                break;
        }
        cout << "Agregar Otro numero? (s/n): ";
        cin >> si_no;
        //Si se agrega otro numero se vuelve al menu.
    } while (si_no == 's');

    cout << "Lista Nueva:" << endl;
    tlista.imprimir();
    //Se imprime la lista nueva

    return 0;
}

