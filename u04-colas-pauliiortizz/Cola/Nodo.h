//
// Created by BANGHO on 07/09/2023.
//

#ifndef U04_COLAS_PAULIIORTIZZ_NODO_H
#define U04_COLAS_PAULIIORTIZZ_NODO_H

template<class T>
class Nodo{
private:
    T dato;
    Nodo<T> *siguiente;
    int prioridad;
public:
    T getDato(){
        return dato;
    }

    void setDato(T d){
        dato = d;
    }

    Nodo<T> *getSiguiente(){
        return siguiente;
    }

    void setSiguiente(Nodo<T> *siguiente){
        this->siguiente = siguiente;
    }
    int valor;

    int getPrioridad() {
        return prioridad;
    }

    void setPrioridad(int p) {
        prioridad = p;
    }
};


#endif //U04_COLAS_PAULIIORTIZZ_NODO_H
