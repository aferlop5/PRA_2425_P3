#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T>
class BSNode {
public:
    T elem;               // Elemento almacenado en el nodo
    BSNode<T>* left;      // Puntero al subárbol izquierdo
    BSNode<T>* right;     // Puntero al subárbol derecho

    // Constructor: inicializa el nodo con un elemento y punteros a los sucesores
    BSNode(T elem, BSNode<T>* left = nullptr, BSNode<T>* right = nullptr)
        : elem(elem), left(left), right(right) {}

    // Sobrecarga del operador << para imprimir el nodo
    friend std::ostream& operator<<(std::ostream& out, const BSNode<T>& bsn) {
        out << bsn.elem;
        return out;
    }
};

#endif // BSNODE_H

