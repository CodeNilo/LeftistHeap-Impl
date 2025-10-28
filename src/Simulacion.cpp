#include "../include/LeftistHeap.h"
#include "../include/incidente.h"
#include <iostream>

using namespace std;

Nodo* fusionarZonas(Nodo* zonaA, Nodo* zonaB) {
    return merge(zonaA, zonaB);
}

void simularFusionZonas(Nodo* zonaA, Nodo* zonaB) {
    cout << "=== SIMULACIÓN DE FUSIÓN DE ZONAS ===" << endl;
    cout << endl;

    cout << "--- ZONA A (antes de fusionar) ---" << endl;
    printHeap(zonaA, -1);
    cout << endl << endl;

    cout << "--- ZONA B (antes de fusionar) ---" << endl;
    printHeap(zonaB, -1);
    cout << endl << endl;

    cout << "--- FUSIONANDO ZONAS A y B ---" << endl;
    Nodo* zonaFusionada = fusionarZonas(zonaA, zonaB);
    
    cout << "--- ZONA FUSIONADA (resultado) ---" << endl;
    printHeap(zonaFusionada, -1);
    cout << endl << endl;

    cout << "--- ATENDIENDO INCIDENTES POR PRIORIDAD ---" << endl;
    int contador = 1;
    while (zonaFusionada) {
        cout << "Incidente #" << contador << " - Prioridad: " 
             << zonaFusionada->dato << " [ATENDIDO]" << endl;
        zonaFusionada = eliminarMin(zonaFusionada);
        contador++;
    }
    
    cout << endl << "✓ Todos los incidentes han sido procesados." << endl;
}
