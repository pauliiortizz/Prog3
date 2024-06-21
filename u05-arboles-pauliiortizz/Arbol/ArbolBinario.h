#include <iostream>
#include "NodoArbol.h"

using namespace std;

template<class T>
class ArbolBinario {
protected:
    NodoArbol<T> *root;
private:
    T search(T data, NodoArbol<T> *r);

    NodoArbol<T> *put(T data, NodoArbol<T> *r);

    NodoArbol<T> *putEspejado(T data, NodoArbol<T> *r);

    NodoArbol<T> *remove(T data, NodoArbol<T> *r);

    NodoArbol<T> *buscaMaxyRemueve(NodoArbol<T> *r, bool *found);

    NodoArbol<T> *r;

    int NodosporNivel(int n, int nActual, NodoArbol<T> *r) {
        if (r == nullptr || nActual > n) {
            return 0;
        }
        if (nActual == n) {
            return 1;
        }
        return NodosporNivel(n, nActual + 1, r->getLeft()) + NodosporNivel(n, nActual + 1, r->getRight());
    }

public:
    ArbolBinario();

    void put(T dato);

    void putEspejado(T dato);

    T search(T dato);

    void remove(T dato);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinario();

    bool esVacio();

    void print();

    void preorder(NodoArbol<T> *r);

    void inorder(NodoArbol<T> *r);

    void postorder(NodoArbol<T> *r);

    int NodosporNivel(int n) {
        return NodosporNivel(n, 0, this->root);
    }
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template<class T>
ArbolBinario<T>::ArbolBinario() {
    root = nullptr;
}

/**
 * Destructor del Arbol
 */
template<class T>
ArbolBinario<T>::~ArbolBinario() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param dato Valor a buscar
 * @return el valor buscado
 */
template<class T>
T ArbolBinario<T>::search(T dato) {
    return search(dato, root);
}

template<class T>
T ArbolBinario<T>::search(T data, NodoArbol<T> *r) {
    if (r == nullptr) {
        throw 404;
    }
    if (r->getData() == data) {
        return r->getData();
    }
    if (r->getData() > data) {
        return search(data, r->getLeft());
    } else {
        return search(data, r->getRight());
    }
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template<class T>
void ArbolBinario<T>::put(T dato) {
    root = put(dato, root);
}

template<class T>
NodoArbol<T> *ArbolBinario<T>::put(T data, NodoArbol<T> *r) {
    if (r == nullptr) {
        return new NodoArbol<T>(data);
    }

    if (r->getData() == data) {
        throw 200;
    }

    if (r->getData() > data) {
        r->setLeft(put(data, r->getLeft()));
    } else {
        r->setRight(put(data, r->getRight()));
    }

    return r;
}

/**
 * Elimina un dato del árbol
 * @param dato Clave para identificar el nodo a borrar
 */
template<class T>
void ArbolBinario<T>::remove(T dato) {
    root = remove(dato, root);
}

template<class T>
NodoArbol<T> *ArbolBinario<T>::remove(T data, NodoArbol<T> *r) {
    NodoArbol<T> *aux;

    if (r == nullptr) {
        throw 404;
    }
    if (r->getData() == data) {
        delete r;
        return nullptr;
    } else {
        if (r->getLeft() != nullptr && r->getRight() == nullptr) {
            aux = r->getLeft();
            delete r;
            return aux;
        } else {
            if (r->getLeft() == nullptr && r->getRight() != nullptr) {
                aux = r->getRight();
                delete r;
                return aux;
            } else {
                if (r->getLeft() != nullptr && r->getRight() != nullptr) {
                    if (r->getLeft()->getRight() != nullptr) {
                        // ACA BUSCAMOS EL VALOR MAXIMO
                        bool found;
                        aux = ArbolBinario::buscaMaxyRemueve(r->getLeft(), &found);
                        aux->setRight(r->getRight());
                        aux->setLeft(r->getLeft());
                    } else {
                        aux = r->getLeft();
                        r->getLeft()->setRight(r->getRight());
                    }
                    delete r;
                    return aux;
                } else {
                    if (r->getData() > data) {
                        r->setLeft(remove(data, r->getLeft()));
                    } else {
                        r->setRight(remove(data, r->getRight()));
                    }
                }
            }
        }
    }
}

template<class T>
NodoArbol<T> *buscaMaxyRemueve(NodoArbol<T> *r, bool *found) {
    NodoArbol<T> ret;
    *found = false;

    if (r->getRight() == nullptr) {
        *found = true;
        return r;
    }
    ret = buscaMaxyRemueve(r->getRight(), found);
    if (*found) {
        r->getRight(nullptr);
        *found = false;
    }

}


/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T>
bool ArbolBinario<T>::esVacio() {

    return root == nullptr;
}

/**
 * Recorre un árbol en preorden
 */
template<class T>
void ArbolBinario<T>::preorder() {
    preorder(root);
}

//Raiz-Izq-Der
template<class T>
void ArbolBinario<T>::preorder(NodoArbol<T> *r) {
    if (r == nullptr) {
        return;
    }
    cout << r->getData();
}

/**
 * Recorre un árbol en orden
 */
template<class T>
void ArbolBinario<T>::inorder() {
    inorder(root);
}

//Izq-Raiz-Der
template<class T>
void ArbolBinario<T>::inorder(NodoArbol<T> *r) {
    if (r == nullptr) {
        return;
    }
    inorder(r->getLeft());
    cout << r->getData();
    inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
template<class T>
void ArbolBinario<T>::postorder() {
    postorder(root);
}

//Izq-Der-R
template<class T>
void ArbolBinario<T>::postorder(NodoArbol<T> *r) {
    if (r == nullptr) {
        return;
    }
    postorder(r->getLeft());
    postorder(r->getRight());
    cout << r->getData();
}

/**
 * Muestra un árbol por consola
 */
template<class T>
void ArbolBinario<T>::print() {
    if (root != NULL) {
        root->print(false, "");

    }
}

template<class T>
void ArbolBinario<T>::putEspejado(T dato) {
    root = putEspejado(dato, root);
}

template<class T>
NodoArbol<T> *ArbolBinario<T>::putEspejado(T data, NodoArbol<T> *r) {
    if (r == nullptr) {
        return new NodoArbol<T>(data);
    }

    if (data > r->getData()) {
        r->setLeft(putEspejado(data, r->getLeft()));
    } else if (data < r->getData()) {
        r->setRight(putEspejado(data, r->getRight()));
    } else {
        throw 404;
    }

    return r;
}


