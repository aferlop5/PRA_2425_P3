#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <iostream>
#include <string>

template <typename V>
class TableEntry {
public:
    // Atributos públicos
    std::string key;  // Clave del par
    V value;          // Valor del par

    // Constructor que inicializa con clave y valor
    TableEntry(std::string key, V value)
        : key(key), value(value) {}

    // Constructor que inicializa solo con la clave
    TableEntry(std::string key)
        : key(key), value(V{}) {}

    // Constructor por defecto con clave vacía y valor predeterminado
    TableEntry()
        : key(""), value(V{}) {}

    // Sobrecarga del operador == para comparar solo la clave
    friend bool operator==(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key == te2.key;
    }

    // Sobrecarga del operador != para comparar solo la clave
    friend bool operator!=(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key != te2.key;
    }

    // Sobrecarga del operador << para imprimir el contenido de la entrada
    friend std::ostream& operator<<(std::ostream& out, const TableEntry<V>& te) {
        out << "{" << te.key << " -> " << te.value << "}";
        return out;
    }
    
    // Sobrecarga del operador < para comparar las claves
    friend bool operator<(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key < te2.key;  // Comparación lexicográfica de las claves
    }

    // Sobrecarga del operador > para comparar las claves
    friend bool operator>(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key > te2.key;  // Comparación lexicográfica de las claves
    }
};


#endif

