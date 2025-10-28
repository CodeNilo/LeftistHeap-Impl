
#include <iostream>
#include <string>
#include "../include/LeftistTree.h"
#include "../include/Incidente.h"

Nodo* atenderIncidente(Nodo* root);
void verMasUrgente(Nodo* root);

using namespace std;

void mostrarMenu() {
    cout << "\n=== SISTEMA DE ATENCION DE INCIDENTES (Leftist Heap) ===\n";
    cout << "1) Simular llegada de incidente\n";
    cout << "2) Ver incidente mas urgente (sin atender)\n";
    cout << "3) Atender incidente (extraer minimo)\n";
    cout << "4) Fusionar zonas (A <- A U B)\n";
    cout << "5) Procesar todos los incidentes de una zona (vaciar)\n";
    cout << "6) Estado rapido de tamanios (no destructivo no disponible)\n";
    cout << "0) Salir\n";
    cout << "Selecciona opcion: ";
}

int elegirZona() {
    int z;
    cout << "Elige zona: 1=A, 2=B, 3=C : ";
    if (!(cin >> z)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return -1; }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return z;
}

int main() {
    Nodo* zonaA = nullptr;
    Nodo* zonaB = nullptr;
    Nodo* zonaC = nullptr; // puede usarse para fusiones intermedias

    bool running = true;
    while (running) {
        mostrarMenu();
        int opt;
        if (!(cin >> opt)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opt) {
            case 1: { // llegada incidente
                int z = elegirZona();
                if (z < 1 || z > 3) { cout << "Zona invalida.\n"; break; }

                int prioridad;
                string descripcion, ubicacion;
                cout << "Prioridad (entero, menor = mas urgente): ";
                if (!(cin >> prioridad)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Prioridad invalida.\n"; break; }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Descripcion: ";
                getline(cin, descripcion);
                cout << "Ubicacion: ";
                getline(cin, ubicacion);

                Incidente inc(prioridad, descripcion, ubicacion);
                if (z == 1) zonaA = insertar(zonaA, inc);
                else if (z == 2) zonaB = insertar(zonaB, inc);
                else zonaC = insertar(zonaC, inc);

                cout << "Incidente aniadido a la zona " << (z==1? "A": z==2? "B": "C") << ".\n";
                break;
            }

            case 2: { // ver mas urgente
                int z = elegirZona();
                if (z == 1) verMasUrgente(zonaA);
                else if (z == 2) verMasUrgente(zonaB);
                else if (z == 3) verMasUrgente(zonaC);
                else cout << "Zona invalida.\n";
                break;
            }

            case 3: { // atender incidente
                int z = elegirZona();
                if (z == 1) zonaA = atenderIncidente(zonaA);
                else if (z == 2) zonaB = atenderIncidente(zonaB);
                else if (z == 3) zonaC = atenderIncidente(zonaC);
                else cout << "Zona invalida.\n";
                break;
            }

            case 4: { // fusionar A <- A U B
                cout << "Fusionando zona A y B (resultado en A). Esto dejara B vacia.\n";
                zonaA = merge(zonaA, zonaB);
                zonaB = nullptr;
                cout << "Fusion completa.\n";
                break;
            }

            case 5: { // procesar todos incidentes de una zona
                int z = elegirZona();
                Nodo** target = nullptr;
                if (z == 1) target = &zonaA;
                else if (z == 2) target = &zonaB;
                else if (z == 3) target = &zonaC;
                else { cout << "Zona invalida.\n"; break; }

                cout << "Procesando (atendiendo) todos los incidentes de la zona "
                     << (z==1? "A": z==2? "B": "C") << "...\n";
                int contador = 1;
                while (*target) {
                    cout << "Incidente #" << contador << " -> ";
                    *target = atenderIncidente(*target);
                    contador++;
                }
                cout << "Zona procesada y vaciada.\n";
                break;
            }

            case 6: {
                cout << "Nota: no hay funcion de tamanio no destructiva disponible en el API actual.\n";
                cout << "Puedes ver el incidente mas urgente o procesar la zona para inspeccionarla.\n";
                break;
            }

            case 0:
                running = false;
                break;

            default:
                cout << "Opcion no valida.\n";
                break;
        }
    }

    cout << "Saliendo. Liberando memoria restante (atendiendo elementos restantes)...\n";
    while (zonaA) zonaA = atenderIncidente(zonaA);
    while (zonaB) zonaB = atenderIncidente(zonaB);
    while (zonaC) zonaC = atenderIncidente(zonaC);

    cout << "Terminado.\n";
    return 0;
}
