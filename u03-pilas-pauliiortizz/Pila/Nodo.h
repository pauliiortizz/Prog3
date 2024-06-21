//
// Created by BANGHO on 31/08/2023.
//

#ifndef U03_PILAS_PAULIIORTIZZ_NODO_H
#define U03_PILAS_PAULIIORTIZZ_NODO_H

template<class T>
class Nodo{
private:
    T dato;
    Nodo<T> *siguiente;

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
};


#endif //U03_PILAS_PAULIIORTIZZ_NODO_H
