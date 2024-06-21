#include <iostream>
#include "../Pila/Pila.h"
using namespace std;

//Escriba un programa que introduzca una palabra y utilice una pila para imprimir la misma palabra invertida

int main() {
  cout << "Ejercicio 03/01\n" << endl;
  char letra='.';

  Pila<char>pInvertidad;

  cout << "Ingrese la palabra a invertir (para finalizar presionar '.' ): ";
  cin >> letra;

  while (letra!='.'){
      cin >> letra;
      pInvertidad.push(letra);
  }
  cout << "La palabra invertida es: ";
  pInvertidad.pop();

  while(!pInvertidad.esVacia()){
      cout << pInvertidad.pop();
  }
  return 0;
}
