#ifndef U2E1_NODO_H
#define U2E1_NODO_H

template<class T>
class Nodo {
private:
    T dato;
    Nodo<T> *siguiente;

public:
    // Default constructor
    Nodo() : siguiente(nullptr) {}

    // Constructor to initialize dato
    Nodo(T d) : dato(d), siguiente(nullptr) {}

    T getDato() {
        return dato;
    }

    void setDato(T d) {
        dato = d;
    }

    Nodo<T> *getSiguiente() {
        return siguiente;
    }

    void setSiguiente(Nodo<T> *siguiente) {
        this->siguiente = siguiente;
    }
};

#endif //U2E1_NODO_H
