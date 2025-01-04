#ifndef DICT_H
#define DICT_H

#include <string>
#include <stdexcept>

template <typename V>
class Dict {
public:
    virtual ~Dict() = default; // Destructor virtual para garantizar destrucción adecuada de clases derivadas

    // Inserta el par key->value en el diccionario
    // Lanza std::runtime_error si la clave ya existe
    virtual void insert(std::string key, V value) = 0;

    // Busca el valor asociado a la clave key
    // Devuelve el valor si la clave existe
    // Lanza std::runtime_error si la clave no se encuentra
    virtual V search(std::string key) = 0;

    // Elimina el par key->value asociado a la clave
    // Lanza std::runtime_error si la clave no se encuentra
    virtual V remove(std::string key) = 0;

    // Devuelve el número de elementos en el diccionario
    virtual int entries() = 0;
};

#endif // DICT_H

