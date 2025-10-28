# Implementación de Leftist Heap

Sistema de gestión de emergencias implementado con Leftist Heap (Montículo Izquierdista) para optimizar la gestión de prioridades (donde menor valor = mayor prioridad) de los incidentes.

## Compilación y Ejecución
```b
g++ src/Incidente.cpp src/LeftistHeap.cpp src/main.cpp -o main.exe && main.exe
```

## Funcionalidad 
El programa debe gestionar incidentes con prioridad, descripción y ubicación, ofreciendo un menú interactivo con las siguientes opciones:

**Insertar nuevos incidentes**: Agrega un incidente al sistema, respetando la propiedad de Leftist Heap.

**Atender el incidente de mayor prioridad**: Extrae y elimina el incidente cuya prioridad sea la menor (raíz del Leftist Heap).

**Fusionar dos zonas de atención**: Realiza la operación de fusión (merge) entre dos Leftist Heaps (ej. los incidentes de dos distritos que se combinan temporalmente).

**Visualizar el incidente más urgente sin eliminarlo**: Consulta el incidente de mayor prioridad (raíz), sin modificar la estructura del heap.

**Salir**: Finaliza el programa.

## Estructura
**Incidente**: Implementa la estructura de datos que representa un incidente, incluyendo su prioridad (valor entero, llave del heap), descripción y ubicación.

**LeftistHeap**: Implementa la estructura de datos del Leftist Heap.

**Propiedad de Heap**: La llave de cada nodo (prioridad) debe ser menor o igual que las llaves de sus hijos (Min-Heap).

**Propiedad de Montículo Izquierdista**: Para cada nodo, la Longitud de Camino Nulo (Null Path Length - NPL) del hijo izquierdo debe ser mayor o igual a la NPL del hijo derecho.

**Operación Clave**: La implementación se centra en la operación de fusión (merge) de dos Leftist Heaps, ya que las operaciones de inserción y eliminación del mínimo se implementan usando merge.

**Menu**: Interfaz de usuario para interactuar con el sistema de gestión de emergencias.
