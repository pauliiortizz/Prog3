#include "../Ej-01/Lista.h"
#include <list>

    list<int> unirListas(const std::list<int> &lista1, const std::list<int> &lista2) {
        list<int> listaUnida;

        for (const int &num: lista1) {
            listaUnida.push_back(num);
        }

        for (const int &num: lista2) {
            listaUnida.push_back(num);
        }

        return listaUnida;
    }
