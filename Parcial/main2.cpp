#include "Cola.h"
#include "Lista.h"

#include <iostream>

using namespace std;

//Ejercicio 1
/*
 * #include <iostream>

using namespace std;


 INVERTIR ARREGLO

void invertir(int arreglo[5], int principio, int final) {
    if (principio >= final) {
        return;
    }
    int aux;

    aux = arreglo[principio];
    arreglo[principio] = arreglo[final];
    arreglo[final] = aux;

    return invertir(arreglo, principio + 1, final - 1);



}

int main() {
    int arreglo[5] = {1, 0, 5, 2, 9};
    int n = 5;

    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i];
    }

    invertir(arreglo, 0, n - 1);

    cout << endl;

    cout << "El arreglo invertido es: ";
    for (int i=0; i<n; i++) {
        cout << arreglo[i];
    }

    return 0;
}*/



// Ejercicio 2
/* BORRA ELEMENTO LISTA
#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    Lista<int> tlista;
    int n, dato, t;
    cout << "Ingrese tamano de la lista: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el dato del elemento " << i << ": ";
        cin >> dato;
        tlista.insertar(i, dato);
    }

    cout << "Ingrese el numero que desea quitar de la lista: ";
    cin >> t;

    cout << "Lista original: ";
    tlista.imprimir();

    cout << endl;

    cout << "Lista Modificada: ";
    tlista.borrarElemento(t);


    return 0;
}
 */

//Ejercicio 3
/*
 * ENCOLAR DATO EN COLA
#include <iostream>
#include "Cola.h"

using namespace std;

int main() {
    Cola<int> cola;
    int n;
    cout << "Ingrese el tamano de la cola:";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el valor del elemento " << i << ": ";
        int dato;
        cin >> dato;
        cola.encolar(dato);
    }
};
*/

//Implemente una función recursiva que reciba como parámetros un array de tipo entero (Con signo y sin singo)
//y devuelva el dato más chico que hay en el array. (3 puntos)

//Ejercicio 1 (Parcial 2)

/*
 * DATO MAS CHICO
int datoMasChico(int arreglo[3], int n) {
    int masChico;
    if (n == 1) {
        return arreglo[0];
    } else {
        masChico = datoMasChico(arreglo + 1, n - 1);
        return min(masChico, arreglo[0]);
    }
}

int main() {
    int arreglo[3] = {-2, -4, 3};
    int n = 3;

    cout << "El elemento mas chico del arreglo es: " << datoMasChico(arreglo, n);
}
 */

/*
 * Implementar un metodo de la clase lista que reciba como parametro un valor Pos.
 * El metodo debe buscar el nodo en la posicion Pos y moverlo a la primera posicion.
 * Realizar moviendo conexiones. No creando nodos nuevos
 *
 * MOVER A PRIMER POSICION PILA
 */
/*
int main(){
    Lista<int> lista;
    int n;
    cout << "Ingrese tamano de la lista: ";
    cin >> n;
    int dato;

    for (int i=0; i<n; i++){
       cout << "Ingrese el valor del elemento " << i << ": " << endl;
       cin >> dato;
       lista.insertar(i, dato);
    }

    cout << "Ingrese la posicion del nodo que desea mover a la primera posicion: ";
    int posicion;
    cin >> posicion;

    cout << "Lista original: ";
    lista.imprimir();

    lista.reemplazarTope(posicion);
    cout << "Lista modificada: ";
    lista.imprimir();
}
 */
/*
 *
Implementar un metodo de la clase lista que reciba como parametro un valor Pos.
 El metodo debe buscar el nodo en la posicion Pos y moverlo a la ultima posicion. Realizar moviendo conexiones. No creando nodos nuevos

 MOVER A ULTIMA POSICION LISTA

 */

/*
int main(){
    Lista<int> lista;
    int n;
    cout << "Ingrese tamano de la lista: ";
    cin >> n;
    int dato;

    for (int i=0; i<n; i++){
        cout << "Ingrese el valor del elemento " << i << ": " << endl;
        cin >> dato;
        lista.insertar(i, dato);
    }

    cout << "Ingrese la posicion del nodo que desea mover a la ultima posicion: ";
    int posicion;
    cin >> posicion;

    cout << "Lista original: ";
    lista.imprimir();

    lista.reemplazarFinal(posicion);
    cout << "Lista modificada: ";
    lista.imprimir();
}*/

//Implementar una función Reemplazar que tenga como argumentos una pila de enteros y dos valores enteros:
// nuevo y viejo, de forma que si viejo aparece en algún lugar de la pila, sea reemplazado por nuevo.

/*
Pila<int> reemplazarNuevoViejo(int nuevo, int viejo, Pila<int> pila) {
    int aux;
    while (pila.esVacia()){
        throw 404;
    }

    Pila<int> pilaaux;

    while (!pila.esVacia()){      //
        aux=pila.pop();
        if (aux==viejo){
            pilaaux.push(nuevo);
        }
        else {
            cout << "El valor no se encuentra en la pila.";
            throw 404;
            //pilaaux.push(aux);
        }
    }

    return pilaaux;
}


int main() {
    Pila<int> pila;
    int nuevo, viejo, n, valor;

    cout << "Ingrese el tamano de la pila: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << " Ingrese el valor del elemento " << i << ": ";
        cin >> valor;

        pila.push(valor);
    }

    cout << "Ingrese un valor NUEVO: ";
    cin >> nuevo;

    cout << "Ingrese un valor VIEJO: ";
    cin >> viejo;

    cout << "Pila Original: ";
    pila.imprimir();

    Pila<int> pilA = reemplazarNuevoViejo(nuevo, viejo, pila);

    cout << "Pila Modificada: ";
    for (int i = 0; i < n; ++i) {
        cout <<  pilA.pop() << endl;
    }

}

*/
/* Implementar una función que reciba 2 Colas con números  enteros y devuelva una nueva Cola con sus elementos sumados uno a uno.
Ejemplo:
C1 = 1, 2, 3
C2 = 2, 3, 4
CR = 3, 5, 7
 */


/*
int main(){
    int n;
    Cola<int> cola1;
    Cola<int> cola2;
    cout << "Ingrese el tamano de las colas: ";
    cin >> n;

    cout << "------ COLA 1 ------" << endl;
    for (int i=0; i<n; i++){
        cout << "Ingrese un valor para el elemento " << i << ": ";
        int valor;
        cin >> valor;
        cola1.encolar(valor);
    }

    cout << "------ COLA 2 ------" << endl;
    for (int i=0; i<n; i++){
        cout << "Ingrese un valor para el elemento " << i << ": ";
        int valor;
        cin >> valor;
        cola2.encolar(valor);
    }
    cout << "La Suma de las Colas es: ";
    cola1.sumaCola(cola2);
}*/
#include <iostream>
/*
// Función auxiliar para encontrar el índice del elemento mínimo en el arreglo
int encontrarIndiceMinimo(int arreglo[], int inicio, int fin) {
    int indiceMinimo = inicio;
    for (int i = inicio + 1; i <= fin; ++i) {
        if (arreglo[i] < arreglo[indiceMinimo]) {
            indiceMinimo = i;
        }
    }
    return indiceMinimo;
}

// Función auxiliar para intercambiar dos elementos en el arreglo
void intercambiarElementos(int arreglo[], int i, int j) {
    int temp = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = temp;
}

// Función recursiva para ordenar un arreglo de enteros de menor a mayor
void ordenarArreglo(int arreglo[], int inicio, int fin) {
    // Caso base: si el rango tiene un solo elemento, ya está ordenado
    if (inicio == fin) {
        return;
    }

    // Encontrar el índice del elemento mínimo en el rango
    int indiceMinimo = encontrarIndiceMinimo(arreglo, inicio, fin);

    // Intercambiar el elemento mínimo con el primer elemento del rango
    intercambiarElementos(arreglo, inicio, indiceMinimo);

    // Llamar recursivamente para ordenar el resto del arreglo
    ordenarArreglo(arreglo, inicio + 1, fin);
}

// Función para imprimir un arreglo
void imprimirArreglo(int arreglo[], int tamano) {
    for (int i = 0; i < tamano; ++i) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int tamano = 5;
    int arreglo[tamano] = {5, 2, 7, 1, 9};

    std::cout << "Arreglo original: ";
    imprimirArreglo(arreglo, tamano);

    // Llamar a la función recursiva para ordenar el arreglo
    ordenarArreglo(arreglo, 0, tamano - 1);

    std::cout << "Arreglo ordenado: ";
    imprimirArreglo(arreglo, tamano);

    return 0;
}
*/
/*
#include <iostream>

int main() {
    int N;

    // Solicitar al usuario que ingrese un número N
    std::cout << "Ingrese un número entero positivo: ";
    std::cin >> N;

    // Verificar si N es impar
    if (N % 2 != 0) {
        std::cout << "Error: El número ingresado es impar. Debe ingresar un número par." << std::endl;
        return 1; // Salir con código de error
    }

    // Inicializar la suma
    int suma = 0;

    // Calcular la suma de los enteros positivos pares desde N hasta 2
    for (int i = N; i >= 2; i -= 2) {
        suma += i;
    }

    // Mostrar la suma
    std::cout << "La suma de los enteros positivos pares desde " << N << " hasta 2 es: " << suma << std::endl;

    return 0;
}*/
#include <iostream>
/*
void invertirArreglo(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        // Intercambiar el primer y último elemento del rango
        std::swap(arreglo[inicio], arreglo[fin]);

        // Llamar recursivamente para el resto del arreglo
        invertirArreglo(arreglo, inicio + 1, fin - 1);
    }
}

void imprimirArreglo(int arreglo[], int tamano) {
    for (int i = 0; i < tamano; ++i) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int tamano = 5;
    int arreglo[tamano] = {1, 2, 3, 4, 5};

    std::cout << "Arreglo original: ";
    imprimirArreglo(arreglo, tamano);

    // Llamar al método recursivo para invertir el arreglo
    invertirArreglo(arreglo, 0, tamano - 1);

    std::cout << "Arreglo invertido: ";
    imprimirArreglo(arreglo, tamano);

    return 0;
}*/
/*
#include <iostream>
#include <cmath>

int convertirBinarioAEntero(const std::string& binario, int indice) {
    // Caso base: si llegamos al final de la cadena binaria, retornamos 0.
    if (indice == -1) {
        return 0;
    }

    // Convertimos el dígito binario en entero y lo multiplicamos por 2^(posición).
    int digito = binario[indice] - '0';
    return digito * pow(2, binario.length() - 1 - indice) + convertirBinarioAEntero(binario, indice - 1);
}

int main() {
    // Ingresa el número binario como una cadena.
    std::string numeroBinario;
    std::cout << "Ingresa un número binario: ";
    std::cin >> numeroBinario;

    // Llamamos al método recursivo para convertir el número binario a entero.
    int resultado = convertirBinarioAEntero(numeroBinario, numeroBinario.length() - 1);

    // Mostramos el resultado.
    std::cout << "El número en decimal es: " << resultado << std::endl;

    return 0;
}*/
/*
#include <iostream>

void convertirEnteroABinario(int numero) {
    // Caso base: si el número es 0, detenemos la recursión.
    if (numero == 0) {
        return;
    }

    // Llamada recursiva con el cociente entero.
    convertirEnteroABinario(numero / 2);

    // Imprimimos el residuo, que será el dígito binario actual.
    std::cout << numero % 2;
}

int main() {
    // Ingresa el número entero positivo.
    int numero;
    std::cout << "Ingresa un número entero positivo: ";
    std::cin >> numero;

    // Validamos que el número sea positivo.
    if (numero < 0) {
        std::cout << "Por favor, ingresa un número entero positivo." << std::endl;
        return 1;
    }

    // Llamamos al método recursivo para convertir el número a binario.
    std::cout << "El número en binario es: ";
    convertirEnteroABinario(numero);
    std::cout << std::endl;

    return 0;
}
*/

#include <iostream>
/*
bool esPalindromo(const std::string& cadena, int inicio, int fin) {
    // Caso base: cuando el índice de inicio es mayor o igual al índice de fin.
    if (inicio >= fin) {
        return true;
    }

    // Comparamos los caracteres en los índices de inicio y fin, sin importar mayúsculas o minúsculas.
    if (cadena[inicio] != cadena[fin]) {
        return false;
    }

    // Llamada recursiva con los índices actualizados.
    return esPalindromo(cadena, inicio + 1, fin - 1);
}

int main() {
    // Ingresa la cadena a verificar como un palíndromo.
    std::string cadena;
    std::cout << "Ingresa una cadena: ";
    std::getline(std::cin, cadena);

    // Llamamos a la función recursiva para verificar si es un palíndromo.
    if (esPalindromo(cadena, 0, cadena.length() - 1)) {
        std::cout << "La cadena es un palíndromo." << std::endl;
    } else {
        std::cout << "La cadena no es un palíndromo." << std::endl;
    }

    return 0;
}
*/

#include <iostream>
/*
int main() {
    // Ejemplo de uso:
    Pila<int> pila;

    // Apilamos algunos elementos en la pila.
    pila.push(8);
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);

    // Mostramos la pila original.
    cout << "Pila original: ";
    pila.imprimir();

    // Invertimos la pila y mostramos la pila invertida.
    cout << "Pila invertida: ";
    pila.invertir();


    return 0;
}*/
/*
int main() {
    // Ejemplo de uso...
    Cola<int> cola1, cola2;
    cout << "Ingrese el tamano de las colas:";
    int n;
    cin >> n;

    // Llenar las colas con algunos elementos
    cout << "---------- COLA 1 ------------" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "Elemento " << i << ":";
        int dato;
        cin >> dato;
        cola1.encolar(dato);
    }

    cout << endl;
    cout << "---------- COLA 2 ------------" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "Elemento " << i << ":";
        int dato;
        cin >> dato;
        cola2.encolar(dato);
    }
    cout << endl;

    // Mostrar las colas antes del intercambio
    cout << "COLA 1 ORIGINAL: ";
    cola1.imprimir();
    cout << "COLA 1 ORIGINAL: ";
    cola2.imprimir();

    // Intercambiar los contenidos de las colas
    cola1.intercambiarColas(cola2);

    cout << endl;

    // Mostrar las colas después del intercambio
    cout << "COLA 1 MODIFICADA: ";
    cola1.imprimir();
    cout << "COLA 2 MODIFICADA: ";
    cola2.imprimir();

    return 0;
}*/
/*
int main() {
    // Ejemplo de uso...
    Cola<int> cola;

    // Insertar elementos en la cola
    cola.encolar(2);
    cola.encolar(2);
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(4);

    // Mostrar la cola antes de la inserción
    cola.imprimir();

    // Insertar después de la enésima ocurrencia (por ejemplo, después de la segunda ocurrencia de 2)
    cola.insertarDespuesEnesimaOcurrencia(2, 3);

    // Mostrar la cola después de la inserción
    cola.imprimir();

    return 0;
}
 */
#include <iostream>
/*
int encontrarMinimoRecursivo(const int arr[], int tamano, int indice) {
    // Caso base: si el índice llega al final del array, devolver el último elemento
    if (indice == tamano - 1) {
        return arr[indice];
    }

    // Llamada recursiva para encontrar el mínimo en el resto del array
    int minRestoArray = encontrarMinimoRecursivo(arr, tamano, indice + 1);

    // Comparar el mínimo encontrado en el resto del array con el elemento actual
    return (arr[indice] < minRestoArray) ? arr[indice] : minRestoArray;
}

int main() {
    const int tamano = 5;
    int array[] = {5, 2, 8, 1, 4};

    // Llamada a la función recursiva
    int minimo = encontrarMinimoRecursivo(array, tamano, 0);

    std::cout << "El valor mínimo en el array es: " << minimo << std::endl;

    return 0;
}
 */

#include <iostream>
#include <iostream>

#include <iostream>
/*
void invertirRecursivo(int num) {
    if (num == 0) {
        return;
    }
    std::cout << num % 10;
    invertirRecursivo(num / 10);
}

void invertirNumero(int numero) {
    if (numero < 0) {
        std::cerr << "Error: No se permite invertir números negativos." << std::endl;
        return;
    }

    std::cout << "Número original: " << numero << std::endl;

    // Llamamos a la función recursiva para invertir el número
    cout << "Numero Invertido: ";
    invertirRecursivo(numero);

    std::cout << "\n";
}

int main() {
    int numero;
    std::cout << "Ingrese un número entero: ";
    std::cin >> numero;

    invertirNumero(numero);

    return 0;
}*/
/*
#include <iostream>

int encontrarMaximo(const int arr[], int n) {
    // Caso base: Si el tamaño del arreglo es 1, el único elemento es el máximo.
    if (n == 1) {
        return arr[0];
    }

    // Llamada recursiva para encontrar el máximo en el subarreglo restante.
    int maximoEnResto = encontrarMaximo(arr + 1, n - 1);

    // Comparar el máximo en el subarreglo restante con el primer elemento del arreglo actual.
    return (arr[0] > maximoEnResto) ? arr[0] : maximoEnResto;
}

int main() {
    const int tamano = 5;
    int numeros[tamano];

    std::cout << "Ingrese " << tamano << " numeros enteros:\n";
    for (int i = 0; i < tamano; ++i) {
        std::cin >> numeros[i];
    }

    // Llamada a la función para encontrar el máximo.
    int maximo = encontrarMaximo(numeros, tamano);

    std::cout << "El numero mas grande es: " << maximo << std::endl;

    return 0;
}*/


Cola<int> reemplazarNuevoViejo(int nuevo, int viejo, Cola<int> cola) {
    Cola<int> colaaux;

    while (!cola.esVacia()) {
        int aux = cola.desencolar();

        if (aux == viejo) {
            colaaux.encolar(nuevo);
        } else {
            colaaux.encolar(aux);
        }
    }

    return colaaux;
}

int main() {
    Cola<int> cola;
    int nuevo, viejo, n, valor;

    cout << "Ingrese el tamaño de la cola: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el valor del elemento " << i << ": ";
        cin >> valor;

        cola.encolar(valor);
    }

    cout << "Ingrese un valor NUEVO: ";
    cin >> nuevo;

    cout << "Ingrese un valor VIEJO: ";
    cin >> viejo;

    cout << "Cola Original: ";
    cola.imprimir();

    Cola<int> colaModificada = reemplazarNuevoViejo(nuevo, viejo, cola);

    cout << "Cola Modificada: ";
    while (!colaModificada.esVacia()) {
        cout << colaModificada.desencolar() << " ";
    }

    return 0;
}






