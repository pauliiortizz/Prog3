
/*
template <class K, class T>
class HashEntry
{
private:
    K clave;
    T valor;
public:
    HashEntry(K c, T v){
        clave = c;
        valor = v;
    }

    K getClave(){
        return clave;
    }
    void setClave(K c){
        clave = c;
    }

    T getValor(){
        return valor;
    }
    void setValor(T v){
        valor = v;
    }
};

*/

template <class K, class T>
class HashEntry {
private:
    K clave;
    T valor;

public:
    HashEntry(K c, T v) : clave(c), valor(v) {}

    K getClave() const {
        return clave;
    }

    void setClave(K c) {
        clave = c;
    }

    T getValor() const {
        return valor;
    }

    void setValor(T v) {
        valor = v;
    }
};


