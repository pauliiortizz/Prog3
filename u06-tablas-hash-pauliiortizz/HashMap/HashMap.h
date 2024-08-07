#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_
#include <iostream>
#include "HashEntry.h"
using namespace std;


template <class K, class T>
class HashMap
{
private:
    HashEntry<K, T> **tabla;
    unsigned int tamanio;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    explicit HashMap(unsigned int tam);

    HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool esVacio();

    void print();
};

template <class K, class T>
HashMap<K, T>::HashMap(unsigned int tam)
{
    tamanio = tam;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++)
    {
        tabla[i] = NULL;
    }
    hashFuncP = hashFunc;
}

template <class K, class T>
HashMap<K, T>::HashMap(unsigned int k, unsigned int (*fp)(K))
{
    tamanio = k;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++)
    {
        tabla[i] = NULL;
    }
    hashFuncP = fp;
}

template <class K, class T>
HashMap<K, T>::~HashMap()
{
    for (int i = 0; i < tamanio; i++)
    {
        HashEntry<K, T> *actual = tabla[i];
        while (actual != NULL)
        {
            HashEntry<K, T> *siguiente = actual->getSiguiente();
            delete actual;
            actual = siguiente;
        }
    }
    delete[] tabla;
}


/*template <class K, class T>
HashMap<K, T>::~HashMap()
{
    for (int i = 0; i < tamanio; i++)
    {
        if (tabla[i] != NULL)
        {
            delete tabla[i];
        }
    }
}*/

template <class K, class T>
T HashMap<K, T>::get(K clave)
{
    unsigned int pos = hashFuncP(clave) % tamanio;
    if (tabla[pos] == NULL)
    {
        throw 404;
    }
    if(tabla[pos]->getClave() == clave){
        return tabla[pos]->getValor();
    }else{
        throw 409;
    }
}

template <class K, class T>
void HashMap<K, T>::put(K clave, T valor)
{
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] != NULL)
    {
        //Manejar la Colision!!!!
        throw 409;
    }

    tabla[pos] = new HashEntry<K, T>(clave, valor); //Corresponde a una fila en la tabla HASH
}

template <class K, class T>
void HashMap<K, T>::remove(K clave)
    {
        unsigned int pos = hashFuncP(clave) % tamanio;

        if (tabla[pos] == NULL)
        {
            // No hay elemento en esta posición
            return;
        }

        HashEntry<K, T> *actual = tabla[pos];
        HashEntry<K, T> *anterior = NULL;

        while (actual != NULL)
        {
            if (actual->getClave() == clave)
            {
                if (anterior == NULL)
                {
                    // El elemento a eliminar es el primero en la lista
                    tabla[pos] = actual->getSiguiente();
                }
                else
                {
                    // El elemento a eliminar está en medio o al final de la lista
                    anterior->setSiguiente(actual->getSiguiente());
                }

                delete actual;
                return;
            }

            // Avanzar en la lista
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }

template <class K, class T>
bool HashMap<K, T>::esVacio()
{
    for (int i = 0; i < tamanio; i++)
    {
        if (tabla[i] != NULL)
        {
            return false;
        }
    }
    return true;
}

template <class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave)
{
    return (unsigned int)clave;
}

template <class K, class T>
void HashMap<K, T>::print()
{

    std::cout << "i"
              << " "
              << "Clave"
              << "\t\t"
              << "Valor" << std::endl;
    std::cout << "--------------------" << std::endl;
    for (int i = 0; i < tamanio; i++)
    {
        std::cout << i << " ";
        if (tabla[i] != NULL)
        {
            std::cout << tabla[i]->getClave() << "\t\t";
            std::cout << tabla[i]->getValor();
        }
        std::cout << std::endl;
    }
}

#endif // U05_HASH_HASHMAP_HASHMAP_H_