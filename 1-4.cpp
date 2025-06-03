#include <iostream>
#include <cstring> // Para usar strstr()

using namespace std;

// ESTRUCTURA DEL PROCESO
struct Proceso {
    int id;
    string nombre;
    int prioridad;
    Proceso* siguiente;
};

// LISTA ENLAZADA DEL GESTOR DE PROCESOS
class GestorProcesos {
private:
    Proceso* cabeza;
public:
    GestorProcesos() {
        cabeza = NULL;
    }

    void insertarProceso(int id, string nombre, int prioridad) {
        Proceso* nuevo = new Proceso;
        nuevo->id = id;
        nuevo->nombre = nombre;
        nuevo->prioridad = prioridad;
        nuevo->siguiente = NULL;

        if (cabeza == NULL) {
            cabeza = nuevo;
        } else {
            Proceso* temp = cabeza;
            while (temp->siguiente != NULL) temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
        cout << "Proceso insertado.\n";
    }

    void eliminarProceso(int id) {
        Proceso* temp = cabeza;
        Proceso* anterior = NULL;
        while (temp != NULL && temp->id != id) {
            anterior = temp;
            temp = temp->siguiente;
        }
        if (temp == NULL) {
            cout << "Proceso no encontrado.\n";
            return;
        }
        if (anterior == NULL) cabeza = temp->siguiente;
        else anterior->siguiente = temp->siguiente;
        delete temp;
        cout << "Proceso eliminado.\n";
    }

    void buscarProceso(int id) {
        Proceso* temp = cabeza;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "ID: " << temp->id << " | Nombre: " << temp->nombre << " | Prioridad: " << temp->prioridad << endl;
                return;
            }
            temp = temp->siguiente;
        }
        cout << "Proceso no encontrado.\n";
    }

    void modificarPrioridad(int id, int nuevaPrioridad) {
        Proceso* temp = cabeza;
        while (temp != NULL) {
            if (temp->id == id) {
                temp->prioridad = nuevaPrioridad;
                cout << "Prioridad modificada.\n";
                return;
            }
            temp = temp->siguiente;
        }
        cout << "Proceso no encontrado.\n";
    }

    void mostrarProcesos() {
	    Proceso* temp = cabeza;
	    while (temp != NULL) {
	        cout << "ID: " << temp->id << ", Nombre: " << temp->nombre << ", Prioridad: " << temp->prioridad << endl;
	        temp = temp->siguiente;
	    }
	}
};

