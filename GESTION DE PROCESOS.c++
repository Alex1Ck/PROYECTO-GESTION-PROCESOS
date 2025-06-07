#include <iostream>
#include <cstring>

using namespace std;

// ESTRUCTURA DEL PROCESO: representa un nodo en una lista enlazada
struct Proceso {
    int identificador;               // ID del proceso
    string nombre;                   // Nombre del proceso
    int prioridad;                   // Prioridad del proceso
    Proceso* siguiente;              // Puntero al siguiente nodo
};

// LISTA ENLAZADA PARA GESTIONAR PROCESOS
class GestorDeProcesos {
private:
    Proceso* cabeza;                 // Puntero al primer proceso en la lista

public:
    GestorDeProcesos() {
        cabeza = NULL;               // Inicialmente, la lista está vacía
    }

    // Inserta un nuevo proceso al final de la lista
    void insertarProceso(int identificador, string nombre, int prioridad) {
        Proceso* nuevoProceso = new Proceso;
        nuevoProceso->identificador = identificador;
        nuevoProceso->nombre = nombre;
        nuevoProceso->prioridad = prioridad;
        nuevoProceso->siguiente = NULL;

        if (cabeza == NULL) {
            cabeza = nuevoProceso;
        } else {
            Proceso* temporal = cabeza;
            while (temporal->siguiente != NULL)
                temporal = temporal->siguiente;
            temporal->siguiente = nuevoProceso;
        }
        cout << "Proceso insertado correctamente.\n";
    }

    // Elimina un proceso por su ID
    void eliminarProceso(int identificador) {
        Proceso* temporal = cabeza;
        Proceso* anterior = NULL;
        while (temporal != NULL && temporal->identificador != identificador) {
            anterior = temporal;
            temporal = temporal->siguiente;
        }
        if (temporal == NULL) {
            cout << "Proceso no encontrado.\n";
            return;
        }
        if (anterior == NULL)
            cabeza = temporal->siguiente;
        else
            anterior->siguiente = temporal->siguiente;
        delete temporal;
        cout << "Proceso eliminado correctamente.\n";
    }

    // Busca un proceso por su ID y lo muestra
    void buscarProceso(int identificador) {
        Proceso* temporal = cabeza;
        while (temporal != NULL) {
            if (temporal->identificador == identificador) {
                cout << "ID: " << temporal->identificador << " | Nombre: " << temporal->nombre << " | Prioridad: " << temporal->prioridad << endl;
                return;
            }
            temporal = temporal->siguiente;
        }
        cout << "Proceso no encontrado.\n";
    }

    // Modifica la prioridad de un proceso existente
    void modificarPrioridad(int identificador, int nuevaPrioridad) {
        Proceso* temporal = cabeza;
        while (temporal != NULL) {
            if (temporal->identificador == identificador) {
                temporal->prioridad = nuevaPrioridad;
                cout << "Prioridad modificada correctamente.\n";
                return;
            }
            temporal = temporal->siguiente;
        }
        cout << "Proceso no encontrado.\n";
    }

    // Muestra todos los procesos registrados
    void mostrarProcesos() {
        Proceso* temporal = cabeza;
        if (temporal == NULL) {
            cout << "No hay procesos registrados.\n";
            return;
        }
        while (temporal != NULL) {
            cout << "ID: " << temporal->identificador << ", Nombre: " << temporal->nombre << ", Prioridad: " << temporal->prioridad << endl;
            temporal = temporal->siguiente;
        }
    }
    
    // Devuelve el puntero al primer proceso de la lista
	Proceso* obtenerCabeza() {
	    return cabeza;
	}
};
