#include <iostream>
#include "../Ej-01/Lista.h"
using namespace std;

int main() {
    Lista<int> tlista;

    int num;
    int size;
    cout << "Ingrese tamano:";
    cin >> size;
    //Se ingresa el tamaño

    cout << "Ingrese los valores";
    for (int i=0; i<size; i++){
        tlista.insertarUltimo(i);
    }
    //Se ingresan los valores, y se insertan en la lista

    cout << "Lista original: ";
    tlista.imprimir();
    cout << endl;

    //Se m la lista

    int indice;
    cout << "Ingrese el indice del elemento a borrar: ";
    cin >> indice;

    //Se ingresa la posicion del elemento a borrar

    while (indice<0 || indice>=size){
        cout<< "ingresa un elemento valido de la lista para eliminar: ";
        cin>>indice;
    }
    //Si no existe la posicion se vuelve a preguntar.


    tlista.remover(indice);
    //Borra el elemento

    cout << endl;
        tlista.imprimir();
    //Se imprime la lista

    return 0;
}
