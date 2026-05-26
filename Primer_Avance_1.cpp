#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// ============================
// ESTRUCTURA PRINCIPAL
// ============================

struct Producto {

    int codigo;
    char nombre[50];
    float precio;
    int stock;
    int vendidos;
    bool activo;
};

// ============================
// PROTOTIPOS
// ============================

void registrarProducto();
void listarProductos();
void menuPrincipal();

// ============================
// FUNCION PRINCIPAL
// ============================

int main() {

    menuPrincipal();

    return 0;
}

// ============================
// MENU PRINCIPAL
// ============================

void menuPrincipal() {

    int opcion;

    do {

        cout << "\n====================================";
        cout << "\n SISTEMA DE INVENTARIO Y VENTAS";
        cout << "\n====================================";

        cout << "\n1. Registrar producto";
        cout << "\n2. Listar productos";
        cout << "\n3. Salir";

        cout << "\n\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                registrarProducto();
                break;

            case 2:
                listarProductos();
                break;

            case 3:
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                cout << "\nOpcion invalida\n";
        }

    } while(opcion != 3);
}

// ============================
// REGISTRAR PRODUCTO
// ============================

void registrarProducto() {

    Producto p;

    ofstream archivo("productos.dat", ios::binary | ios::app);

    if(!archivo) {

        cout << "\nError al abrir archivo\n";
        return;
    }

    cout << "\n========== REGISTRO ==========\n";

    cout << "Codigo: ";
    cin >> p.codigo;

    cin.ignore();

    cout << "Nombre: ";
    cin.getline(p.nombre, 50);

    cout << "Precio: ";
    cin >> p.precio;

    cout << "Stock: ";
    cin >> p.stock;

    // Inicializacion
    p.vendidos = 0;
    p.activo = true;

    // Guardar en archivo binario
    archivo.write((char*)&p, sizeof(Producto));

    archivo.close();

    cout << "\nProducto registrado correctamente\n";
}

// ============================
// LISTAR PRODUCTOS
// ============================

void listarProductos() {

    Producto p;

    ifstream archivo("productos.dat", ios::binary);

    if(!archivo) {

        cout << "\nNo existe archivo de productos\n";
        return;
    }

    cout << "\n========== LISTA DE PRODUCTOS ==========\n";

    while(archivo.read((char*)&p, sizeof(Producto))) {

        if(p.activo) {

            cout << "\nCodigo   : " << p.codigo;
            cout << "\nNombre   : " << p.nombre;
            cout << "\nPrecio   : Q" << fixed << setprecision(2) << p.precio;
            cout << "\nStock    : " << p.stock;
            cout << "\nVendidos : " << p.vendidos;
            cout << "\n-----------------------------------";
        }
    }

    archivo.close();
}