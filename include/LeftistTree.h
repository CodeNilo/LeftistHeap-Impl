#include <iostream>
#include <utility>
#include "Incidente.h"  // ← usa tu clase Incidente

using namespace std;

struct Nodo {
    Incidente dato;   // ← antes: int
    int npl;

    Nodo* izq;
    Nodo* der;

    // constructor desde Incidente
    explicit Nodo(const Incidente& x) : dato(x), npl(0), izq(nullptr), der(nullptr) {}
};

// merge de Leftist Heap (mínimo)
Nodo* merge(Nodo* heap, Nodo* nuevoNodo){
    if(!heap) return nuevoNodo;
    if(!nuevoNodo) return heap;

    // Usamos operator< de Incidente (menor prioridad = más urgente)
    if(nuevoNodo->dato < heap->dato)
        swap(heap, nuevoNodo);

    heap->der = merge(heap->der, nuevoNodo);

    int nplD = heap->der ? heap->der->npl : -1;
    int nplI = heap->izq ? heap->izq->npl : -1;

    // invariante leftist: npl(izq) >= npl(der)
    if(nplI < nplD){
        swap(heap->der, heap->izq);
        // recalcular después del swap (opcional, pero claro)
        nplD = heap->der ? heap->der->npl : -1;
    }

    // en leftist: npl = npl(hijo derecho) + 1 (ya garantizado que der tiene el menor npl)
    heap->npl = nplD + 1;

    return heap;
}

// INSERCIÓN: crea singleton y fusiona 
Nodo* insertar(Nodo* heap, const Incidente& inc){
    Nodo* nuevoNodo = new Nodo(inc);
    return merge(heap, nuevoNodo);
}

