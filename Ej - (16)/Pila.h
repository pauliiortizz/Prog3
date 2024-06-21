#include <iostream>
#include <cctype>
#include "Nodo.h"

using namespace std;

/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Pila {
private:
    Nodo<T> *tope;
public:
    Pila();

    ~Pila();

    void push(T dato);

    T pop();

    bool esVacia();

    T peek();

    int getTamanio();

    bool verificacion();

    void imprimir();

    void invertir();

    void sumarAElementos(T n);

    int sumaPilas(Pila<T> pila2);

    void removerNum(T dato);

};

/**
 * Constructor de la clase Pila
 * @tparam T
 */
template<class T>
Pila<T>::Pila() {
    tope = nullptr;
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template<class T>
Pila<T>::~Pila() {
    while (!esVacia()) {
        pop();
    }
    delete tope;
}

/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Pila<T>::push(T dato) {
    Nodo<T> *nuevo;
    nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    nuevo->setSiguiente(tope);
    tope = nuevo;
}

/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Pila<T>::pop() {
    if (esVacia()) {
        throw 404;
    }
    T dato = tope->getDato();
    Nodo<T> *aBorrar = tope;
    tope = tope->getSiguiente();
    delete aBorrar;
    return dato;
}

/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool Pila<T>::esVacia() {
    return tope == nullptr;
}

template<class T>
T Pila<T>::peek() {
    if (esVacia()) {
        throw 404;
    }
    return tope->getDato();
}

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 **/
template<class T>
int Pila<T>::getTamanio() {
    Nodo<T> *aux = tope;
    int tam = 0;

    while (aux != nullptr) {
        aux = aux->getSiguiente();
        tam++;
    }
    return tam;
}



/**
 * Verifica si los parentesis, corchetes y llaves etsan bien puestos
 * @param expresion
 * @return true or false
 **/
bool verificacion(string &expresion) {
    Pila<char> pila;

    for (char caracter: expresion) {
        if (caracter == '(' || caracter == '[' || caracter == '{') {
            // Si se ecnuentra un parentesis, corchete o llave que abre, se agrega a la pila
            pila.push(caracter);
        } else if (caracter == ')' || caracter == ']' || caracter == '}') {
            // Si se encuentra un parentesis, corchete o llave que cierra
            // Se verifica que la pila está vacía o si el elemento en el tope coincida
            if (pila.esVacia() ||
                (caracter == ')' && pila.peek() != '(') ||
                (caracter == ']' && pila.peek() != '[') ||
                (caracter == '}' && pila.peek() != '{')) {
                return false; // Los acaracteres no estan bien
            }
            pila.pop(); // Se elimina el elemento del tope de la pila
        }
    }

    // Si la pila esta vacia al final, los parenteiss estan bien colocados
    return pila.esVacia();
}


/**
* Otorga valores a los operadores matematicos
* @param op
**/
//Etsa funcion sirve para asignarle un valor a las operaciones, para poder ordenarlas mas facilmente, de manera jerarquica.
int jerarquias(char op) {
    if (op == '+' || op == '-'){
        return 1;
    }

    if (op == '*' || op == '/'){
        return 2;
    }
    return 0;
}

/**
* Transforma una expresion infija a Postfija
* @param infijo
* @return expresion postfija
**/
string infijoAPostfijo(const string &infijo) {
    string postfijo = "";
    //Pila propia para los operadores +, -, *, /
    Pila<char> pilaOperadores;

    for (char caracter: infijo) {
        //isdigit verifica si un caracter es un digito decimal.
        if (isdigit(caracter)) {
            postfijo += caracter; //Se guarda la expresion postfija
        } else if (caracter == '(') {
            pilaOperadores.push(caracter);
        } else if (caracter == ')') {
            while (!pilaOperadores.esVacia() && pilaOperadores.peek() != '(') {
                postfijo += pilaOperadores.pop();
            }
            if (!pilaOperadores.esVacia() && pilaOperadores.peek() == '(') {
                pilaOperadores.pop();
            }
        } else {
            while (!pilaOperadores.esVacia() && jerarquias(pilaOperadores.peek()) >= jerarquias(caracter)) {
                postfijo += pilaOperadores.pop();
            }
            pilaOperadores.push(caracter);
        }
    }

    while (!pilaOperadores.esVacia()) {
        postfijo += pilaOperadores.pop();
    }

    return postfijo;
}


template <class T>
void Pila<T>::imprimir(){
    Nodo<T>* actual = tope;
    while (actual != nullptr)
    {
        cout << actual->getDato() << " ";
        actual = actual->getSiguiente();
    }
    cout << "-> NULL" << endl;
}

// Función para invertir la pila
template <class T>
void Pila<T>::invertir() {
    if(esVacia()){
        return;
    }
    Pila<T> pilaInvertida;

    // Pasamos los elementos de la pila original a la pilaInvertida
    while (!esVacia()) {
        pilaInvertida.push(pop());
    }

    // Pasamos los elementos de la pilaInvertida de vuelta a la pila original
    if (!pilaInvertida.esVacia()) {
        T elemento = pilaInvertida.pop();
        push(elemento);
        cout << elemento << " ";
        pilaInvertida.imprimir();
    }
}

template <class T>
void Pila<T>::sumarAElementos(T n)
{
    Nodo<T> *temp = tope;
    while (temp != nullptr)
    {
        temp->setDato(temp->getDato() + n);
        temp = temp->getSiguiente();
    }
}

template<class T>
int Pila<T>::sumaPilas(Pila<T> pila2) {
    Pila<T> resultado;

    while (!esVacia() && !pila2.esVacia()) {
        int suma = peek() + pila2.peek();
        resultado.push(suma);
        pop();
        pila2.pop();
    }

    // Si alguna de las pilas originales aún tiene elementos, agregarlos a la pila 'resultado'
    while (!esVacia()) {
        resultado.push(peek());
        pop();
    }

    while (!pila2.esVacia()) {
        resultado.push(pila2.peek());
        pila2.pop();
    }

    // Invertir la pila 'resultado' para que los elementos estén en el orden correcto
    resultado.invertir();
}

template<class T>
void Pila<T>::removerNum(T dato){
    Nodo<T> *actual = tope;
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
                tope = actual->getSiguiente();
                actual = tope;
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






