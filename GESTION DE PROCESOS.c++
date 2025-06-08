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

// NODO PARA LA COLA DE PRIORIDAD
struct NodoCola {
    Proceso* proceso;
    NodoCola* siguiente;
};
// COLA DE PRIORIDAD PARA EL PLANIFICADOR DE CPU
class PlanificadorCPU {
private:
    NodoCola* cabeza;                // Puntero al primer nodo de la cola
public:
    PlanificadorCPU() {
        cabeza = NULL;               // Inicialmente, la cola estÃ¡ vacÃ­a
    }
    // Encolar un proceso segÃºn su prioridad
    void encolarProceso(Proceso* proceso) {
        NodoCola* nuevoNodo = new NodoCola;
        nuevoNodo->proceso = proceso;
        nuevoNodo->siguiente = NULL;
        if (cabeza == NULL || proceso->prioridad > cabeza->proceso->prioridad) {
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        } else {
            NodoCola* temporal = cabeza;
            while (temporal->siguiente != NULL && proceso->prioridad <= temporal->siguiente->proceso->prioridad) {
                temporal = temporal->siguiente;
            }
            nuevoNodo->siguiente = temporal->siguiente;
            temporal->siguiente = nuevoNodo;
        }
        cout << "Su proceso fue encolado correctamente (^^)\n";
    }
    // Desencolar y 'ejecutar' un proceso
    void desencolarProceso() {
        if (cabeza == NULL) {
            cout << "No hay procesos en la cola (T-T)\n";
            return;
        }
        NodoCola* nodo = cabeza;
        cabeza = cabeza->siguiente;
        cout << "Ejecutando proceso: ID " << nodo->proceso->identificador << ", Nombre " << nodo->proceso->nombre << ", Prioridad " << nodo->proceso->prioridad << " (O.O)\n";
        delete nodo;
    }
    // Mostrar la cola actual
    void mostrarCola() {
        NodoCola* temporal = cabeza;
        if (temporal == NULL) {
            cout << "La cola estÃ¡ vacÃ­a (T-T)\n";
            return;
        }
        while (temporal != NULL) {
            cout << "ID: " << temporal->proceso->identificador << ", Nombre: " << temporal->proceso->nombre << ", Prioridad: " << temporal->proceso->prioridad << " (O.O)\n";
            temporal = temporal->siguiente;
        }
    }
};
