# Implementación de Leftist Heap

Implementación de la estructura de datos Leftist Heap con gestión de elementos mediante cola de prioridad (min-heap).

## Compilación y Ejecución
```bash
g++ src/Incidente.cpp src/AtencionIncidentes.cpp src/main.cpp -o main.exe && main.exe
```

## Funcionalidad
El programa ofrece un menú interactivo para gestionar 3 zonas (A, B, C) de Leftist Heaps:

- Insertar elementos con prioridad
- Ver elemento de mayor prioridad (sin eliminar)
- Extraer elemento de mayor prioridad
- Fusionar dos zonas (merge)
- Procesar todos los elementos de una zona
- Salir

## Estructura
**Incidente**: Clase que representa elementos con prioridad, descripción y ubicación

**LeftistHeap**: Implementa el Leftist Heap con operaciones merge, insertar y eliminarMin

**AtencionIncidentes**: Funciones auxiliares para manipular el heap

**Menu**: Interfaz de usuario para interactuar con las zonas

El Leftist Heap mantiene la propiedad de min-heap y la propiedad izquierdista (NPL del hijo izquierdo ≥ NPL del hijo derecho). Todas las operaciones se basan en la función merge.

## Complejidad Temporal
| Operación | Complejidad |
|-----------|-------------|
| merge() | O(log n) |
| insertar() | O(log n) |
| eliminarMin() | O(log n) |
| findMin() | O(1) |
