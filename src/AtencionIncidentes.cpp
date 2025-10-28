
#include <iostream>
#include "../include/LeftistHeap.h"
#include "../include/Incidente.h"   

using namespace std;

//Atiende al de mayor prioridad, como es un leftist heap es la raiz (que es la menor)
Nodo* atenderIncidente(Nodo* root) {

    if (root == nullptr) {
        cout << "\n>> No hay incidente pendientes." << endl;
        return nullptr;
    }

    Incidente incidenteAtendido = root->dato;

    Nodo* hijoIzquierdo = root->izq;
    Nodo* hijoDerecho = root->der;

    delete root;

    cout << "\n--- INCIDENTE ATENDIDO  ---" << endl;
    incidenteAtendido.mostrarInfo();
    cout << "---------------------------------" << endl;

    return merge(hijoIzquierdo, hijoDerecho);
}

void verMasUrgente(Nodo* root) {
    if (root == nullptr) {
        cout << "\n>> No hay incidentes pendientes" << endl;
        return;
    }

    Incidente masUrgente = root->dato;

    cout << "\n---Incidente mas urgente sin atender ---" << endl;
    masUrgente.mostrarInfo(); 
    cout << "------------------------------------------------" << endl;
}