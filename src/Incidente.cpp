/* 

(Piero)

- Implementar los métodos declarados en Incidente.h
- Constructor que inicializa los atributos.
- Métodos getter.
- Método mostrarInfo() que imprime todos los datos del incidente.
- Sobrecarga del operador < para comparar prioridades.

*/ 

#include "Incidente.h"
#include <iostream>

// Constructor
Incidente::Incidente(int p, const std::string& d, const std::string& u)
    : prioridad(p), descripcion(d), ubicacion(u) {}

// Getters
int Incidente::getPrioridad() const { return prioridad; }
std::string Incidente::getDescripcion() const { return descripcion; }
std::string Incidente::getUbicacion() const { return ubicacion; }

// Mostrar información
void Incidente::mostrarInfo() const {
    std::cout << "[Prioridad: " << prioridad
              << ", Descripción: " << descripcion
              << ", Ubicación: " << ubicacion << "]" << std::endl;
}

// Sobrecarga de <
bool Incidente::operator<(const Incidente& other) const {
    return prioridad < other.prioridad; // menor prioridad = más urgente
}