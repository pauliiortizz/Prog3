#include <iostream>
#include <initializer_list>
#include "Nodo.h"

using namespace std;

/*
 * Clase que implementa una Lista Enlazada genérica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Lista {
private:
    Nodo<T> *inicio;
    T dato;
public:
    Lista();

    Lista(const Lista<T> &li);

    Lista(initializer_list<T> initList);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    int* obtenerPosiciones(T dato);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void imprimirHastaPosicion(int pos) const;

    void vaciar();

    void imprimir();

    void fnInvierte();
};

/**
 * Constructor de la clase Lista
 * @tparam T
 **/
template <class T> Lista<T>::Lista() {
    inicio = nullptr;
}

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 **/
template <class T> Lista<T>::Lista(const Lista<T> &li) {
    inicio = nullptr;
}

/**
 * Constructor que acepta una lista de inicialización
 * @tparam T
 * @param initList lista de inicialización
 **/
template <class T> Lista<T>::Lista(initializer_list<T> initList) {
    inicio = nullptr;
    for (const T &value : initList) {
        insertarUltimo(value);
    }
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 **/
template <class T> Lista<T>::~Lista() {
    vaciar();
}

/**
 * Método para saber si la lista está vacía
 * @tparam T
 * @return true si la lista está vacía, sino false
 **/
template <class T> bool Lista<T>::esVacia() {
    return inicio == nullptr;
}

/**
 * Método para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 **/
template <class T> int Lista<T>::getTamanio() {
    Nodo<T> *aux = inicio;
    int tam = 0;

    while (aux != nullptr) {
        aux = aux->getSiguiente();
        tam++;
    }
    return tam;
}

/**
 * Inserta un nodo con el dato en la posición pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato dato a insertar
 **/
template <class T> void Lista<T>::insertar(int pos, T dato) {
    Nodo<T> *aux = inicio;
    int posActual = 0;
    Nodo<T> *nuevo = new Nodo<T>(dato);

    if (pos == 0) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux != nullptr && posActual < pos - 1) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Inserta un nodo con el dato en la primera posición
 * @tparam T
 * @param dato dato a insertar
 **/
template <class T> void Lista<T>::insertarPrimero(T dato) {
    insertar(0, dato);
}

/**
 * Inserta un nodo con el dato en la última posición
 * @tparam T
 * @param dato dato a insertar
 **/
template <class T> void Lista<T>::insertarUltimo(T dato) {
    Nodo<T> *aux = inicio;
    Nodo<T> *nuevo = new Nodo<T>(dato);
    if (aux == nullptr) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    aux->setSiguiente(nuevo);
}

/**
 * Elimina el nodo en la posición 'pos' de la lista enlazada
 * @tparam T
 * @param pos posición del nodo a eliminar
 */
template <class T> void Lista<T>::remover(int pos) {
    Nodo<T> *auxNodo = inicio;
    Nodo<T> *aBorrar;
    int posActual = 0;

    if (esVacia()) throw 404;

    if (pos == 0) {
        inicio = inicio->getSiguiente();
        delete auxNodo;
        return;
    }

    while (auxNodo != nullptr && posActual < pos - 1) {
        auxNodo = auxNodo->getSiguiente();
        posActual++;
    }

    if (auxNodo == nullptr) throw 404;

    aBorrar = auxNodo->getSiguiente();
    auxNodo->setSiguiente(auxNodo->getSiguiente()->getSiguiente());
    delete aBorrar;
}

/**
 * Obtener el dato del nodo en la posición pos
 * @tparam T
 * @param pos posición del dato
 * @return dato almacenado en el nodo
 */
template <class T> T Lista<T>::getDato(int pos) {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }
    return aux->getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posición donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 **/
template <class T> void Lista<T>::reemplazar(int pos, T dato) {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }
    aux->setDato(dato);
}

/**
 * Función que vacía la lista enlazada
 * @tparam T
 **/
template <class T> void Lista<T>::vaciar() {
    Nodo<T> *aux = inicio, *aBorrar;

    while (aux != nullptr) {
        aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }
    inicio = nullptr;
}

/**
 * Implementar la función fnInvierte(lista).
 * Esta función invertirá el orden original de los elementos en la lista,
 * de tal forma que el último elemento será ahora el primero, el penúltimo será el segundo,
 * y así hasta que el primero sea el último. Considere que la lista no está vacía y que no se construirá una nueva,
 * sólo se invertirá el orden de los elementos de la lista original.
 **/

template <class T> void Lista<T>::fnInvierte() {
    Nodo<T> *aux = inicio, *anterior = nullptr, *siguiente = nullptr;

    while (aux != nullptr) {
        siguiente = aux->getSiguiente();
        aux->setSiguiente(anterior);
        anterior = aux;
        aux = siguiente;
    }
    inicio = anterior;
}

template <class T> void Lista<T>::imprimir() {
    Nodo<T> *aux = inicio;
    while (aux != nullptr) {
        cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}



template <class T>
int* Lista<T>::obtenerPosiciones(T dato) {
    int count = 0;
    Nodo<T> *auxNodo = inicio;

    // Contar la cantidad de posiciones
    while (auxNodo != nullptr) {
        if (auxNodo->getDato() == dato) {
            count++;
        }
        auxNodo = auxNodo->getSiguiente();
    }

    // Crear un arreglo dinámico para almacenar las posiciones
    int* posiciones = new int[count + 1]; // +1 para el valor especial de fin
    int index = 0;
    auxNodo = inicio;
    int posicion = 0;

    // Almacenar las posiciones
    while (auxNodo != nullptr) {
        if (auxNodo->getDato() == dato) {
            posiciones[index++] = posicion;
        }
        auxNodo = auxNodo->getSiguiente();
        posicion++;
    }

    // Agregar el valor especial de fin al final del array
    posiciones[count] = -1;

    return posiciones;
}

template <class T>
void Lista<T>::imprimirHastaPosicion(int pos) const {
    Nodo<T> *aux = inicio;
    cout << "Lista invertida hasta la posicion " << pos << ": ";
    for (int i = 0; i < pos; ++i) {
        cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}