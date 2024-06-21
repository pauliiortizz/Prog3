#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo
{
private:
    T dato;
    Nodo<T> *siguiente;
    Nodo<T> *anterior;

public:
    T getDato()
    {
        return dato;
    }

    void setDato(T d)
    {
        dato = d;
    }

    Nodo<T> *getSiguiente()
    {
        return siguiente;
    }

    void setSiguiente(Nodo<T> *s)
    {
        this->siguiente = s;
    }

    Nodo<T> *getAnterior(){
        return anterior;
    }

    void setAnterior(Nodo<T> *a){
        this->anterior = a;
    }
};

#endif //NODO_H
