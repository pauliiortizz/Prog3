#include "Nodo.h"
#include <iostream>

using namespace std;

/*
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    Nodo<T> *inicio;
    T dato;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();

    void imprimir();

    void fnInvierte();

    void borrarElemento(int n);

    int obtenerPosicion(T elemento);

    void reemplazarTope(int pos);

    void reemplazarFinal(int pos);

    void invertirLista();

    void Sumar(T n);

    void sumarANumeroEnPosicion();

    int sumaListas(Lista<T> lista1,Lista<T> lista2);

    int obtenerInicio();

    Nodo<T>* obtenerCabeza() const {
        return inicio;
    }

    void removerNum(T dato);
};

/**
 * Constructor de la clase Lista
 * @tparam T
 **/
template<class T>
Lista<T>::Lista() {
    inicio = nullptr;
}

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 **/
template<class T>
Lista<T>::Lista(const Lista<T> &li) {
    inicio = nullptr;
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 **/
template<class T>
Lista<T>::~Lista() {}

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 **/
template<class T>
bool Lista<T>::esVacia() {
    return inicio == nullptr;
}

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 **/
template<class T>
int Lista<T>::getTamanio() {
    Nodo<T> *aux = inicio;
    int tam = 0;

    while (aux != nullptr) {
        aux = aux->getSiguiente();
        tam++;
    }
    return tam;
}


/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 **/
template<class T>
void Lista<T>::insertar(int pos, T dato) {
    Nodo<T> *aux = inicio;
    int posActual = 0;
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);

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
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 **/
template<class T>
void Lista<T>::insertarPrimero(T dato) {
    insertar(0, dato);
}

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 **/
template<class T>
void Lista<T>::insertarUltimo(T dato) {
    Nodo<T> *aux = inicio;
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    if (aux == nullptr) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);

}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(int pos) {
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
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos - 1) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    aux->getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 **/
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 **/
template<class T>
void Lista<T>::vaciar() {
    Nodo<T> *aux = inicio, *aBorrar;
    int posActual = 0;

    while (aux != nullptr) {
        aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }
    if (aux == nullptr) {
        throw 404;
    }
    inicio = nullptr;

}

/*
 * Implementar la función fnInvierte(lista).
 * Esta función invertirá el orden original de los elementos en la lista,
 * de tal forma que el último elemento será ahora el primero, el penúltimo será el segundo,
 * y así hasta que el primero sea el último. Considere que la lista no está vacía y que no se construirá una nueva,
 * sólo se invertirá el orden de los elementos de la lista original.
 */

template<class T>
void Lista<T>::fnInvierte() {
    Nodo<T> *aux = inicio, *anterior = nullptr, *siguiente = inicio;

    if (esVacia()) {
        return;
    }
    siguiente = siguiente->getSiguiente();

    while (siguiente != nullptr) {
        aux->setSiguiente(anterior);
        anterior = aux;
        aux = siguiente;
        siguiente = siguiente->getSiguiente();
    }
    aux->setSiguiente(anterior);
    inicio = aux;
}

template<class T>
void Lista<T>::imprimir() {
    Nodo<T> *aux = inicio;
    while (aux != nullptr) {
        cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}

template<class T>
void Lista<T>::borrarElemento(int t) {
    Nodo<T> *aux = inicio;
    Nodo<T> *anterior = nullptr;

    while (aux != nullptr) {
        if (aux->getDato() == t) {
            if (anterior == nullptr) {
                inicio = aux->getSiguiente();
                delete aux;
                aux = inicio;
            } else {
                anterior->setSiguiente(aux->getSiguiente());
                delete aux;
                aux = anterior->getSiguiente();
            }
        } else {
            anterior = aux;
            aux = aux->getSiguiente();
        }
    }
    imprimir();
}


template<class T>
int Lista<T>::obtenerPosicion(T elemento) {
    Nodo<T> *aux = inicio;
    int pos = 0;

    while (aux != nullptr) {
        if (aux->getDato() == elemento) {
            return pos;
        }
        aux = aux->getSiguiente();
        pos++;
    }

    return -1;
}

template<class T>
void Lista<T>::reemplazarTope(int pos){
    //Usar la funcion getDato() para obtener el dato que se encuentra en el posicion
    //Una vez encontrado, se reemplaza el dato de dicha posicion en el inicio.
    insertar(0, getDato(pos));
    remover(pos);

}

template<class T>
void Lista<T>::reemplazarFinal(int pos){
    //Usar la funcion getDato() para obtener el dato que se encuentra en la posicion
    //Una vez encontrado, se reemplaza el dato de dicha posicion al ultimo.
    insertarUltimo(getDato(pos));
    remover(pos);
}

template <class T>
void Lista<T>::invertirLista() {
    Nodo<T> *anterior = nullptr;
    Nodo<T> *actual = inicio;
    Nodo<T> *siguiente = nullptr;

    while (actual != nullptr) {
        siguiente = actual->getSiguiente();
        actual->setSiguiente(anterior);
        anterior = actual;
        actual = siguiente;
    }

    inicio = anterior;
    imprimir();
}

template<class T>
void Lista<T>::Sumar(T n) {
    Nodo<T> *aux=inicio;
    while (aux!= nullptr){
        aux ->setDato(aux->getDato()+n);
        aux=aux->getSiguiente();
    }
}

template<class T>
void Lista<T>::sumarANumeroEnPosicion() {
    T n;
    cout << "Ingrese el numero que desea sumar: ";
    cin >> n;

    int posicion;
    cout << "Ingrese la posicion del elemento al que desea sumar el numero: ";
    cin >> posicion;

    Nodo<T> *actual = inicio;
    int contador = 0;

    while (actual != nullptr) {
        if (contador == posicion) {
            actual->setDato(actual->getDato() + n);
            return;
        }
        actual = actual->getSiguiente();
        contador++;
    }

    cout << "La posicion ingresada no es valida." << endl;
}

template<class T>
int Lista<T>::sumaListas(Lista<T> lista1,Lista<T> lista2) {
    Lista<T> resultado;

    // Mientras ambas listas tengan elementos, sumar los elementos y poner el resultado en la lista 'resultado'
    Nodo<T>* actualLista1 = lista1.obtenerCabeza();
    Nodo<T>* actualLista2 = lista2.obtenerCabeza();

    while (actualLista1 != nullptr && actualLista2 != nullptr) {
        T suma = actualLista1->dato + actualLista2->dato;
        resultado.insertarInicio(suma);
        actualLista1 = actualLista1->siguiente;
        actualLista2 = actualLista2->siguiente;
    }

    // Si alguna de las listas originales aún tiene elementos, agregarlos a la lista 'resultado'
    while (actualLista1 != nullptr) {
        resultado.insertarInicio(actualLista1->dato);
        actualLista1 = actualLista1->siguiente;
    }

    while (actualLista2 != nullptr) {
        resultado.insertarInicio(actualLista2->dato);
        actualLista2 = actualLista2->siguiente;
    }

    return resultado;
}

template<class T>
void Lista<T>::removerNum(T dato){
    Nodo<T> *actual = inicio;
    Nodo<T> *anterior = nullptr;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->getDato() == dato) {
            Nodo<T> *aBorrar = actual;
            if (anterior != nullptr) {
                // No estamos al inicio de la lista
                anterior->setSiguiente(actual->getSiguiente());
                actual = actual->getSiguiente();
            } else {
                // Estamos al inicio de la lista
                inicio = actual->getSiguiente();
                actual = inicio;
            }
            delete aBorrar;
            encontrado = true;
        } else {
            // Avanzar al siguiente nodo
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }

    if (!encontrado) {
        cout << "El dato no se encuentra en la lista." << endl;
        throw 404;
    }
    cout << "COLA 1 MODIFICADA: ";
    imprimir();
}

