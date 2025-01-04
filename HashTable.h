#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "../PRA_2425_P1/ListLinked.h" // Cambia la ruta si es necesario

template <typename V>
class HashTable : public Dict<V> {
private:
    int n; // Número de elementos actuales
    int max; // Número total de cubetas
    ListLinked<TableEntry<V>>* table; // Array de punteros a listas enlazadas

    // Función hash
    int h(std::string key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c); // Suma valores ASCII de los caracteres
        }
        return sum % max; // Devuelve el resto de la división
    }

public:
    // Constructor
    HashTable(int size) : n(0), max(size) {
        table = new ListLinked<TableEntry<V>>[max]; // Reserva memoria para la tabla
    }

    // Destructor
    ~HashTable() {
        delete[] table; // Libera la memoria dinámica
    }

    // Método insert
    void insert(std::string key, V value) override {
        int index = h(key); // Calcula la cubeta
        TableEntry<V> entry(key, value);

        // Verifica si la clave ya existe
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == entry) {
                throw std::runtime_error("Key already exists in the dictionary");
            }
        }

        table[index].push_front(entry); // Inserta al inicio de la lista
        ++n; // Incrementa el contador de elementos
    }

    // Método search
    V search(std::string key) override {
        int index = h(key); // Calcula la cubeta
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                return it->value; // Devuelve el valor si se encuentra
            }
        }
        throw std::runtime_error("Key not found in the dictionary");
    }

    // Método remove
    V remove(std::string key) override {
        int index = h(key); // Calcula la cubeta
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                V value = it->value;
                table[index].erase(it); // Elimina el elemento de la lista
                --n; // Decrementa el contador de elementos
                return value; // Devuelve el valor eliminado
            }
        }
        throw std::runtime_error("Key not found in the dictionary");
    }

    // Método entries
    int entries() override {
        return n; // Devuelve el número de elementos
    }

    // Método capacity
    int capacity() {
        return max; // Devuelve el número de cubetas
    }

    // Sobrecarga de operador []
    V operator[](std::string key) {
        return search(key); // Llama al método search
    }

    // Sobrecarga de operador <<
    friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& ht) {
        for (int i = 0; i < ht.max; ++i) {
            out << "Bucket " << i << ": ";
            for (auto it = ht.table[i].begin(); it != ht.table[i].end(); ++it) {
                out << *it << " ";
            }
            out << "\n";
        }
        return out;
    }
};

#endif // HASHTABLE_H

