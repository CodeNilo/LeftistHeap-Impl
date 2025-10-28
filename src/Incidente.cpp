#include "Incidente.h"
#include <iostream>

// Constructor
Incidente::Incidente(int p, const std::string& d, const std::string& u)
    : prioridad(p), descripcion(d), ubicacion(u) {}

// Getters
int Incidente::getPrioridad() const { return prioridad; }
std::string Incidente::getDescripcion() const { return descripcion; }
std::string Incidente::getUbicacion() const { return ubicacion; }

// Mostrar informacion
void Incidente::mostrarInfo() const {
    std::cout << "[Prioridad: " << prioridad
              << ", Descripcion: " << descripcion
              << ", Ubicacion: " << ubicacion << "]" << std::endl;
}

// Sobrecarga de <
bool Incidente::operator<(const Incidente& other) const {
    return prioridad < other.prioridad; // menor prioridad = mas urgente
}

// Sobrecarga de >
bool Incidente::operator>(const Incidente& other) const {
    return prioridad > other.prioridad;
}
