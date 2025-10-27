
#include <iostream>
#include "../include/LeftistTree.h"
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
