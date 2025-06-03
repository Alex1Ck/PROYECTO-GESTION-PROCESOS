#include <iostream>
#include <cstring> // Para usar strstr()

using namespace std;

int main() {
    char cadena[200];
    char subcadena[100];
    char* posicion;

    cout << "Introduce la cadena principal: ";
    cin.getline(cadena, 200);

    cout << "Introduce la subcadena a buscar: ";
    cin.getline(subcadena, 100);

    // Buscar la subcadena en la cadena principal
    posicion = strstr(cadena, subcadena);

    if (posicion != NULL) {
        // Calcular la posicion encontrando la distancia desde el inicio
        int indice = posicion - cadena;
        cout << "La subcadena se encontro en la posicion: " << indice << endl;
    } else {
        cout << "La subcadena no se encontro en la cadena principal." << endl;
    }

    return 0;
}

