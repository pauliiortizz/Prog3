#include <iostream>
using namespace std;

void buscar(int x, int v[], int ini, int fin, int pos, bool &retorno);

void buscarRecursiva(int x, int v[], int ini, int fin, int pos, bool &retorno);

bool busquedaBinaria(int *arr, int size, int dato){
    int primero=0, ultimo=size-1, x=0, mitad;

    while(primero<=ultimo && x==0){
        mitad =(primero + ultimo)/2;
        if(dato==arr[mitad]){
            x=1; //bandera
        }
        if(dato<arr[mitad]){
            ultimo = mitad-1;
        }
        if(dato>arr[mitad]){
            primero = mitad+1;
        }
    }

    if(x==1){
        return true;
    } else {
        return false;
    }
}

int main() {
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int dato;
    bool band;

    cout << "Ingrese el numero a buscar: " << endl;
    cin >> dato;

    band = busquedaBinaria(arr, size, dato);

    if(band){
        cout << "El numero " << dato << " se encuentra en el arreglo" << endl;
    } else {
        cout << "El numero NO se encuentra en el arreglo" << endl;
    }

}