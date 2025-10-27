#include <iostream>

using namespace std;


struct Nodo {
    int dato;
    int npl;

    Nodo* izq;
    Nodo* der;

    Nodo(int dx) : dato(dx), npl(0), izq(nullptr), der(nullptr) {} 

};

Nodo* merge(Nodo* heap, Nodo* nuevoNodo){
    if(!heap) return nuevoNodo;
    if(!nuevoNodo) return heap;
    
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

Nodo* insertar(Nodo* heap, int dx){
    Nodo* nuevoNodo = new Nodo(dx);
    return merge(heap, nuevoNodo);
}

Nodo* eliminarMin(Nodo* head){
    if(!head) return nullptr;

    Nodo *nuevoNodo = merge(head->izq, head->der);
    delete head;
    return nuevoNodo;
}

void printHeap(Nodo* heap, int padre){
    if(!heap) return;

    cout<<endl<<"Valor actual: "<<heap->dato;
    cout<<", Padre" << padre;
    cout<<", NPL: "<<heap->npl;

    cout<<endl<<"Hijo Izquierdo: ";
    printHeap(heap->izq, heap->dato);
    cout<<endl<<"Hijo Derecho: ";
    printHeap(heap->der, heap->dato);
}