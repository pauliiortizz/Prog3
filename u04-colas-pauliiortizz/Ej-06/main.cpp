/*Agregue un método a la clase Cola que inserte un nodo con un nuevo dato después de la enésima ocurrencia de
        ese mismo dato partiendo la búsqueda desde el tope. Si no hay ocurrencias de mencionado dato, encolarlo al
fondo. Considerar el uso excepciones de ser necesario
*/

#include <iostream>
#include "../Cola/Cola.h"

int main() {
    Cola <int> cola;

    cout << "Ingrese el tamano de la cola: ";
    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "Num: ";
        int num;
        cin >> num;
        cola.encolar(num);
    }

    cout << "Cola Original: ";
    cola.imprimir();
    cout << endl;
    cola.insertarDespuesDeNesimaOcurrencia(3, 436, 2);
    cout << "Cola Modificada: ";
    cola.imprimir();
}

