#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H

#include <iostream>
#include "Incidente.h"

using namespace std;


struct Nodo {
    Incidente dato;
    int npl;

    Nodo* izq;
    Nodo* der;

    Nodo(const Incidente& dx) : dato(dx), npl(0), izq(nullptr), der(nullptr) {}

};

Nodo* merge(Nodo* heap, Nodo* nuevoNodo){
    if(!heap) return nuevoNodo;
    if(!nuevoNodo) return heap;
    
     /* El codigo original estaba hecho considerando que dato era un int
       Pero ahora dato es un objeto Incidente, entonces hay que crear
       metodos que le especifiquen a estos objetos como compararse
    */
   
    if(heap->dato > nuevoNodo->dato)
        swap(heap, nuevoNodo);
    
    heap->der = merge(heap->der, nuevoNodo);
    
    int nplD = heap->der ? heap->der->npl : -1;
    int nplI = heap->izq ? heap->izq->npl : -1;

    if(nplI < nplD){
        swap(heap->der, heap->izq);
    }
    
    heap->npl = (heap->der ? heap->der->npl : -1) + 1;
    
    return heap;

}

Nodo* insertar(Nodo* heap, const Incidente& dx){
    Nodo* nuevoNodo = new Nodo(dx);
    return merge(heap, nuevoNodo);
}

Nodo* eliminarMin(Nodo* head){
    if(!head) return nullptr;

    Nodo *nuevoNodo = merge(head->izq, head->der);
    delete head;
    return nuevoNodo;
}

void printHeap(Nodo* heap, const Incidente* padre = nullptr) {
    if (!heap) return;

    cout << "\nValor actual: ";
    heap->dato.mostrarInfo();
    if (padre) {
        cout << ", Padre: ";
        padre->mostrarInfo();
    }
    cout << ", NPL: " << heap->npl;

    cout << "\nHijo Izquierdo:";
    printHeap(heap->izq, &heap->dato);

    cout << "\nHijo Derecho:";
    printHeap(heap->der, &heap->dato);
}

#endif // LEFTISTHEAP_H