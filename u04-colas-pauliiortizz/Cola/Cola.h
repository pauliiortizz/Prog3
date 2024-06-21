#include <iostream>
#include <string>
#include "Nodo.h"
#include "../Cola/Pila.h"

using namespace std;

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Cola {
private:
    Nodo<T> *tope, *fondo;
    int contadorPrioridad = 0;
public:
    Cola();

    ~Cola();

    void encolar(T dato);

    T desencolar();

    bool esVacia();

    T peek();

    bool colasIguales(Cola<T> cola2);

    T getTamanio();

    void encolarConPrioridad(T dato, int prioridad);

    int getCantidadPrioridad() const {
        return contadorPrioridad;
    }

    void insertarDespuesDeNesimaOcurrencia(T dato, T nuevoDato, int n);

    void imprimir();

    void suma(Cola<T> cola2);

};

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template<class T>
Cola<T>::Cola() {
    tope = nullptr;
    fondo = nullptr;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template<class T>
Cola<T>::~Cola() {
    while (!esVacia()) {
        desencolar();
    }
}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Cola<T>::encolar(T dato) {
    Nodo<T> *nuevo = new Nodo<T>;

    nuevo->setDato(dato);
    nuevo->setSiguiente(nullptr);

    if (esVacia()) {
        tope = nuevo;
        fondo = nuevo;
    } else {
        fondo->setSiguiente(nuevo);
        fondo = nuevo;
    }
}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Cola<T>::desencolar() {
    if (esVacia()) {
        throw 404;
    }
    T dato = tope->getDato();
    Nodo<T> *aBorrar = tope;
    tope = tope->getSiguiente();

    if (tope == nullptr) {
        fondo = nullptr;
    }

    delete aBorrar;
    return dato;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool Cola<T>::esVacia() {
    return tope == nullptr;
}

/**
 * Muestra el dato que contiene el tope
 * @tparam T
 * @return
 */
template<class T>
T Cola<T>::peek() {
    if (esVacia()) {
        throw 404;
    }
    return tope->getDato();
}

template<class T>
T Cola<T>::getTamanio() {
    Nodo<T> *aux = tope;
    int tam = 0;

    while (aux != nullptr) {
        aux = aux->getSiguiente();
        tam++;
    }
    return tam;
}


template<class T>
bool Cola<T>::colasIguales(Cola<T> cola2) {
        if (getTamanio() != cola2.getTamanio()) {
            return false; // Si las colas tienen tamaños diferentes, no son iguales
        }

        Nodo<T> *aux1 = tope;
        Nodo<T> *aux2 = cola2.tope;

        while (aux1 != nullptr) {
            if (aux1->getDato() != aux2->getDato()) {
                return false; // Si encuentra elementos diferentes, las colas no son iguales
            }
            aux1 = aux1->getSiguiente();
            aux2 = aux2->getSiguiente();
        }

        return true; // Si no se encontraron diferencias, las colas son iguales
}

bool esPalindromo(string cadena) {

    // Crear una pila y una cola para comparar caracteres
    Pila<char> pila;
    Cola<char> cola;

    // Eliminar espacios y signos de puntuación de la cadena
    for (char c : cadena) {
            pila.push(c);
            cola.encolar(c);
    }

    // Comparar caracteres de la pila y la cola
    while (!pila.esVacia() && !cola.esVacia()) {
        if (pila.pop() != cola.desencolar()) {
            return false;
        }
    }

    // Si tanto la pila como la cola están vacías, la cadena es un palíndromo
    return pila.esVacia() && cola.esVacia();
}

template<class T>
void Cola<T>::encolarConPrioridad(T dato, int prioridad) {
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);

    if (esVacia() || prioridad == 0) {
        // Si la cola está vacía o la prioridad es máxima (0), insertar al frente.
        nuevo->setSiguiente(tope);
        tope = nuevo;
        if (fondo == nullptr) {
            fondo = nuevo;
        }
        if (prioridad == 0) {
            contadorPrioridad++;
        }
    } else {
        Nodo<T> *actual = tope;
        Nodo<T> *anterior = nullptr;

        // Buscar el lugar adecuado para insertar según la prioridad
        while (actual != nullptr && actual->getPrioridad() <= prioridad) {
            anterior = actual;
            actual = actual->getSiguiente();
        }

        // Insertar el nodo con prioridad
        nuevo->setSiguiente(actual);
        if (anterior != nullptr) {
            anterior->setSiguiente(nuevo);
        } else {
            // Si no hay nodo anterior, el nuevo nodo será el tope
            tope = nuevo;
        }

        if (actual == nullptr) {
            // Si el nuevo nodo es el último, actualizar el fondo
            fondo = nuevo;
        }
    }
}


template<class T>
void Cola<T>::insertarDespuesDeNesimaOcurrencia(T dato, T nuevoDato, int n) {
    if (n <= 0) {
        throw invalid_argument("El valor de n debe ser mayor que 0");
    }

    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(nuevoDato);

    Nodo<T> *actual = tope;
    int contador = 0;

    // Buscar la enésima ocurrencia del dato
    while (actual != nullptr && contador < n) {
        if (actual->getDato() == dato) {
            contador++;
        }
        if (contador < n) {
            actual = actual->getSiguiente();
        }
    }

    if (contador < n) {
        // Si no se encontraron suficientes ocurrencias, encolar al fondo
        encolar(nuevoDato);
    } else {
        // Insertar el nuevo dato después del nodo actual
        nuevo->setSiguiente(actual->getSiguiente());
        actual->setSiguiente(nuevo);

        // Si el nodo actual es el último, actualizar el fondo
        if (actual == fondo) {
            fondo = nuevo;
        }
    }
}

template<class T>
void Cola<T>::imprimir() {
    Nodo<T> *temp = tope;
    while (temp != nullptr) {
        cout << temp->getDato() << " ";
        temp = temp->getSiguiente();
    }
    cout << "NULL" << endl;
}

template<class T>
void Cola<T>::suma(Cola<T> cola2) {
    Cola<T> resultado;
    Nodo<T> *actual1 = this->tope;
    Nodo<T> *actual2 = cola2.tope;

    // Recorrer ambas colas simultáneamente
    while (actual1 != nullptr && actual2 != nullptr) {
        T suma = actual1->getDato() + actual2->getDato();
        resultado.encolar(suma);
        actual1 = actual1->getSiguiente();
        actual2 = actual2->getSiguiente();
    }

    // Si la primera cola tiene más elementos
    while (actual1 != nullptr) {
        resultado.encolar(actual1->getDato());
        actual1 = actual1->getSiguiente();
    }

    // Si la segunda cola tiene más elementos
    while (actual2 != nullptr) {
        resultado.encolar(actual2->getDato());
        actual2 = actual2->getSiguiente();
    }

    // Imprimir la cola resultante
    resultado.imprimir();
}



