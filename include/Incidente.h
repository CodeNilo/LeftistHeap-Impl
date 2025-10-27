/* 

(Piero)

- Diseñar la estructura de la clase Incidente.
- Definir los atributos necesarios (prioridad, descripción, ubicación).
- Declarar los métodos públicos (constructores, getters, mostrar info, comparación).
- Este archivo solo contiene las DECLARACIONES (no implementaciones).

*/ 

#ifndef INCIDENTE_H
#define INCIDENTE_H

#include <string>

class Incidente {
private:
    int prioridad;             // menor = más urgente
    std::string descripcion;
    std::string ubicacion;

public:
    // Constructor
    Incidente(int p, const std::string& d, const std::string& u);

    // Getters
    int getPrioridad() const;
    std::string getDescripcion() const;
    std::string getUbicacion() const;

    // Mostrar información del incidente
    void mostrarInfo() const;

    // Comparación (para heaps de mínimo)
    bool operator<(const Incidente& other) const;
};

#endif // INCIDENTE_H