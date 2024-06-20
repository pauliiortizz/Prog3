#include <iostream>

using namespace std;

template<typename T>
class ListaCircular {
private:
    struct Node {
        T data;
        Node *siguiente;

        Node(const T &value) : data(value), siguiente(nullptr) {}
    };

    Node *inicio;
    int size;

public:
    ListaCircular() : inicio(nullptr), size(0) {}

    void insertarPrimero(const T &value) {
        Node *newNode = new Node(value);
        if (inicio == nullptr) {
            newNode->siguiente = newNode;
            inicio = newNode;
        } else {
            newNode->siguiente = inicio->siguiente;
            inicio->siguiente = newNode;
        }
        size++;
    }

    void imprimir() const {
        if (inicio != nullptr) {
            Node *actual = inicio->siguiente;
            cout << "Lista ->  ";
            do {
                cout << actual->data << " ";
                actual = actual->siguiente;
            } while (actual != inicio->siguiente);
            cout << endl;
        } else {
            cout << "La Lista esta vacia. " << endl;
        }
    }
};

