#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    string nombre;
    string carnet;
    int edad;
};

// Función para agregar estudiante (CREATE)
void agregarEstudiante() {
    Estudiante e;
    cout << "Nombre (sin espacios): ";
    cin >> e.nombre;
    cout << "Carnet: ";
    cin >> e.carnet;
    cout << "Edad: ";
    cin >> e.edad;

    ofstream archivo("estudiantes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << e.nombre << " " << e.carnet << " " << e.edad << endl;
        archivo.close();
        cout << "Estudiante agregado correctamente.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// Función para mostrar estudiantes (READ)
void mostrarEstudiantes() {
    ifstream archivo("estudiantes.txt");
    Estudiante e;

    if (archivo.is_open()) {
        cout << "\n--- Lista de Estudiantes ---\n";
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            cout << "Nombre: " << e.nombre 
                 << ", Carnet: " << e.carnet
                 << ", Edad: " << e.edad << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// Función para modificar estudiante (UPDATE)
void modificarEstudiante() {
    ifstream archivo("estudiantes.txt");
    ofstream temp("temp.txt");
    Estudiante e;
    string buscado;
    bool modificado = false;

    cout << "Ingrese carnet a modificar: ";
    cin >> buscado;

    if (archivo.is_open() && temp.is_open()) {
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            if (e.carnet == buscado) {
                Estudiante nuevo;
                cout << "Nuevo nombre (sin espacios): ";
                cin >> nuevo.nombre;
                cout << "Nuevo carnet: ";
                cin >> nuevo.carnet;
                cout << "Nueva edad: ";
                cin >> nuevo.edad;

                temp << nuevo.nombre << " " << nuevo.carnet << " " << nuevo.edad << endl;
                modificado = true;
            } else {
                temp << e.nombre << " " << e.carnet << " " << e.edad << endl;
            }
        }
        archivo.close();
        temp.close();
        remove("estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");

        if (modificado)
            cout << "Estudiante modificado correctamente.\n";
        else
            cout << "Carnet no encontrado.\n";
    } else {
        cout << "Error abriendo los archivos.\n";
    }
}

// -----------------------------
// 👇 TU TAREA: Completa esta función (DELETE)
void eliminarEstudiante() {
    ifstream archivo("estudiantes.txt"); 
    ofstream temp("temp.txt");           
    string carnetEliminar;               
    Estudiante estudiante;               
    bool eliminado = false;

    if (archivo.is_open() && temp.is_open()) {
        // Escribe aquí la función que elimine un estudiante por su carnet.
        // Puedes usar o no el manejo de archivos.
        // Si lo haces con archivos, ganarás **2 puntos extra**.

        // Ingreso de datos
        cout << "Ingrese carnet a Eliminar:\n";
        cin >> carnetEliminar;

        // Recorrer cada linea en el archivo
        while (archivo >> estudiante.nombre >> estudiante.carnet >> estudiante.edad) {
            if (estudiante.carnet == carnetEliminar) {
                // Si encuentra una coincidencia con el carnet en el archivo con el carnet ingresado, entoces eliminar
                temp << " " <<endl; // Con un espacio vacio
                eliminado = true;
            } else {
                temp << estudiante.nombre << " " << estudiante.carnet << " " << estudiante.edad << endl;
            }
        }
        archivo.close();
        temp.close();
        remove("estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");

        if (eliminado) {
            // Mensaje de exito
            cout << "El estudiante con carnet: " << carnetEliminar << " ha sido Eliminado Correctamente\n";
        } else {
            // Mensaje en dado caso que no se haya podido eliminar
            cout << "No se pudo encontrar el estudiante con carnet " << carnetEliminar << endl;
        }
    }
    else {
        cout << "Error: No se pudo abrir el archivo\n";
    }

}
// -----------------------------

// Menú principal
int main() {
    int opcion;
    do {
        cout << "\n=== CRUD de Estudiantes ===\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar todos\n";
        cout << "3. Modificar estudiante\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarEstudiante(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: modificarEstudiante(); break;
            case 4: eliminarEstudiante(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }

    } while (opcion != 5);

    return 0;
}