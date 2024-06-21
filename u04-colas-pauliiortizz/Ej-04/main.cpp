#include <iostream>
#include "../Cola/Cola.h"

 /*
 * En un supermercado, se tiene sólo una caja habilitada para que los clientes puedan pagar sus compras.
 * La caja tiene prioridad para mujeres embarazadas. Dada esta situación, se pide que se implemente un sistema que
 * calcule la cantidad de productos comprados por cada cliente y el monto total gastado, también la cantidad de
 * embarazadas que accedieron a la cola.
 */


void monto_Gastado(int cantProducto) {
    int monto;
    while (cantProducto == 1) {
        monto = 1500;
        cout << " gasto $" << monto << endl;
        cout << endl;
        break;
    }
    while (cantProducto > 1 && cantProducto < 15) {
        monto = 10000;
        cout << " gasto $" << monto << endl;
        cout << endl;
        break;
    }

    while (cantProducto > 15) {
        monto = 50000;
        cout << " gasto $" << monto << endl;
        cout << endl;
        break;
    }
}

int main() {
    Cola<int> cola;
    int cantClientes, prioridad, cantProd = 0;

    cout << "---------- BIENVENIDO AL SITIO WEB DE WALMART -------------" << endl;
    cout << endl;
    cout << "Ingrese la cantidad de clientes que desea registrar: ";
    cin >> cantClientes;

    for (int i = 0; i < cantClientes; i++) {
        cout << "El cliente N  " << i << "  esta en situacion de embarazo? (Presione 0 = si, 1 = no): ";
        cin >> prioridad;
        cout << endl;
        cola.encolarConPrioridad(i, prioridad);
        cout << "Ingrese la cantidad de productos que compro el Cliente N  " << i << ": ";
        cin >> cantProd;
        monto_Gastado(cantProd);
    }

    int cantidadPrioridad = cola.getCantidadPrioridad();
    cout << "Cantidad de clientes con prioridad: " << cantidadPrioridad << endl;

}

