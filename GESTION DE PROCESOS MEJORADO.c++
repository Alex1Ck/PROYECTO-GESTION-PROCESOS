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
        cabeza = NULL;               // Inicialmente, la lista estÃ¡ vacÃ­a
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
        cout << "Su proceso fue agregado correctamente (^^)\n";
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
            cout << "Su proceso no fue encontrado (T-T)\n";
            return;
        }
        if (anterior == NULL)
            cabeza = temporal->siguiente;
        else
            anterior->siguiente = temporal->siguiente;
        delete temporal;
        cout << "Su proceso fue eliminado correctamente (^^)\n";
    }

    // Busca un proceso por su ID y lo muestra
    void buscarProceso(int identificador) {
        Proceso* temporal = cabeza;
        while (temporal != NULL) {
            if (temporal->identificador == identificador) {
                cout << "ID: " << temporal->identificador << " | Nombre: " << temporal->nombre << " | Prioridad: " << temporal->prioridad << " (O.O)\n";
                return;
            }
            temporal = temporal->siguiente;
        }
        cout << "Su proceso no fue encontrado (T-T)\n";
    }

    // Modifica la prioridad de un proceso existente
    void modificarPrioridad(int identificador, int nuevaPrioridad) {
        Proceso* temporal = cabeza;
        while (temporal != NULL) {
            if (temporal->identificador == identificador) {
                temporal->prioridad = nuevaPrioridad;
                cout << "Su prioridad fue modificada correctamente (^^)\n";
                return;
            }
            temporal = temporal->siguiente;
        }
        cout << "Su proceso no fue encontrado (T-T)\n";
    }

    // Muestra todos los procesos registrados
    void mostrarProcesos() {
        Proceso* temporal = cabeza;
        if (temporal == NULL) {
            cout << "No hay procesos registrados (T-T)\n";
            return;
        }
        while (temporal != NULL) {
            cout << "ID: " << temporal->identificador << ", Nombre: " << temporal->nombre << ", Prioridad: " << temporal->prioridad << " (O.O)\n";
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
        cabeza = NULL;               // Inicialmente, la cola está vacía
    }
    // Encolar un proceso según su prioridad
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
        cout << "Su proceso fue encontrado correctamente (^^)\n";
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
            cout << "La cola está vacía (T-T)\n";
            return;
        }
        while (temporal != NULL) {
            cout << "ID: " << temporal->proceso->identificador << ", Nombre: " << temporal->proceso->nombre << ", Prioridad: " << temporal->proceso->prioridad << " (O.O)\n";
            temporal = temporal->siguiente;
        }
    }
};

// PILA PARA EL GESTOR DE MEMORIA

    // Asignar memoria a un proceso (push)
    void asignarMemoria(Proceso* proceso) {
        proceso->siguiente = tope;
        tope = proceso;
        cout << "La memoria fue asignada correctamente (^^)\n";
    }
    // Liberar memoria (pop)
    void liberarMemoria() {
        if (tope == NULL) {
            cout << "No hay memoria asignada (T-T)\n";
            return;
        }
        Proceso* temporal = tope;
        tope = tope->siguiente;
        cout << "La memoria fue liberada correctamente (^^)\n";
        delete temporal;
    }
    // Verificar el estado actual de la memoria
    void verificarEstadoMemoria() {
        Proceso* temporal = tope;
        if (temporal == NULL) {
            cout << "La memoria esta vacia (T-T)\n";
            return;
        }
        cout << "El estado actual de la memoria es: (O.O)\n";
        while (temporal != NULL) {
            cout << "ID: " << temporal->identificador << ", Nombre: " << temporal->nombre << ", Prioridad: " << temporal->prioridad << "\n";
            temporal = temporal->siguiente;
        }
    }
};

// INTERFAZ DE USUARIO
void mostrarMenu() {
    cout << "===== Sistema de gestion de procesos =====\n";
    cout << "1. Insertar proceso (^^)\n";
    cout << "2. Eliminar proceso (T-T)\n";
    cout << "3. Buscar proceso (O.O)\n";
    cout << "4. Modificar prioridad (^^)\n";
    cout << "5. Mostrar todos los procesos (O.O)\n";
    cout << "6. Encolar proceso en CPU (^^)\n";
    cout << "7. Desencolar y ejecutar proceso (O.O)\n";
    cout << "8. Mostrar cola de CPU (O.O)\n";
    cout << "9. Asignar memoria (^^)\n";
    cout << "10. Liberar memoria (T-T)\n";
    cout << "11. Verificar estado de memoria (O.O)\n";
    cout << "0. Salir (T-T)\n";
    cout << "========================================\n";
}

int main() {
    GestorDeProcesos gestorProcesos;
    PlanificadorCPU planificadorCPU;
    GestorDeMemoria gestorMemoria;
    int opcion;
    do {
        mostrarMenu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        switch (opcion) {
            case 1: {
                int id, prioridad;
                string nombre;
                cout << "Ingrese ID del proceso: ";
                cin >> id;
                cout << "Ingrese nombre del proceso: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese prioridad del proceso: ";
                cin >> prioridad;
                gestorProcesos.insertarProceso(id, nombre, prioridad);
                break;
            }
            case 2: {
                int id;
                cout << "Ingrese ID del proceso a eliminar: ";
                cin >> id;
                gestorProcesos.eliminarProceso(id);
                break;
            }
            case 3: {
                int id;
                cout << "Ingrese ID del proceso a buscar: ";
                cin >> id;
                gestorProcesos.buscarProceso(id);
                break;
            }
            case 4: {
                int id, nuevaPrioridad;
                cout << "Ingrese ID del proceso: ";
                cin >> id;
                cout << "Ingrese nueva prioridad: ";
                cin >> nuevaPrioridad;
                gestorProcesos.modificarPrioridad(id, nuevaPrioridad);
                break;
            }
            case 5:
                gestorProcesos.mostrarProcesos();
                break;
            case 6: {
                int id;
                cout << "Ingrese ID del proceso a encolar: ";
                cin >> id;
                Proceso* proceso = gestorProcesos.obtenerCabeza();
                while (proceso != NULL && proceso->identificador != id) {
                    proceso = proceso->siguiente;
                }
                if (proceso != NULL) {
                    planificadorCPU.encolarProceso(proceso);
                } else {
                    cout << "El proceso no fue encontrado (T-T)\n";
                }
                break;
            }
            case 7:
                planificadorCPU.desencolarProceso();
                break;
            case 8:
                planificadorCPU.mostrarCola();
                break;
            case 9: {
                int id;
                cout << "Ingrese ID del proceso a asignar memoria: ";
                cin >> id;
                Proceso* proceso = gestorProcesos.obtenerCabeza();
                while (proceso != NULL && proceso->identificador != id) {
                    proceso = proceso->siguiente;
                }
                if (proceso != NULL) {
                    gestorMemoria.asignarMemoria(proceso);
                } else {
                    cout << "EL proceso no fue encontrado (T-T)\n";
                }
                break;
            }
            case 10:
                gestorMemoria.liberarMemoria();
                break;
            case 11:
                gestorMemoria.verificarEstadoMemoria();
                break;
            case 0:
                cout << "Hasta luegoo... ^^\n";
                break;
            default:
                cout << "La opcion es invalida (T-T)\n";
        }
    } while (opcion != 0);
    return 0;
}
