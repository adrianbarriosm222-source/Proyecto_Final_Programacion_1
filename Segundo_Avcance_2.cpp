#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// ============================
// ESTRUCTURAS
// ============================

struct Producto {
    int codigo;
    char nombre[50];
    float precio;
    int stock;
    int vendidos;
    bool activo;
};

struct Venta {
    int codigoProducto;
    int cantidad;
    float subtotal;
    float descuento;
    float iva;
    float total;
};

// ============================
// PROTOTIPOS
// ============================

void menuPrincipal();
void registrarProducto();
void listarProductos();
void buscarProducto();
void modificarPrecio();
void actualizarStock();
void desactivarProducto();
void realizarVenta();

// ============================
// MAIN
// ============================

int main() {
    menuPrincipal();
    return 0;
}

// ============================
// MENU
// ============================

void menuPrincipal() {

    int opcion;

    do {
        cout << "\n====================================";
        cout << "\n SISTEMA INVENTARIO Y VENTAS";
        cout << "\n====================================";

        cout << "\n1. Registrar producto";
        cout << "\n2. Listar productos";
        cout << "\n3. Buscar producto";
        cout << "\n4. Modificar precio";
        cout << "\n5. Actualizar stock";
        cout << "\n6. Desactivar producto";
        cout << "\n7. Realizar venta";
        cout << "\n8. Salir";

        cout << "\n\nOpcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1: registrarProducto(); break;
            case 2: listarProductos(); break;
            case 3: buscarProducto(); break;
            case 4: modificarPrecio(); break;
            case 5: actualizarStock(); break;
            case 6: desactivarProducto(); break;
            case 7: realizarVenta(); break;
        }

    } while(opcion != 8);
}

// ============================
// REGISTRAR PRODUCTO
// ============================

void registrarProducto() {

    Producto p;

    ofstream archivo("productos.dat", ios::binary | ios::app);

    cout << "\nCodigo: ";
    cin >> p.codigo;

    cin.ignore();

    cout << "Nombre: ";
    cin.getline(p.nombre, 50);

    cout << "Precio: ";
    cin >> p.precio;

    cout << "Stock: ";
    cin >> p.stock;

    p.vendidos = 0;
    p.activo = true;

    archivo.write((char*)&p, sizeof(Producto));
    archivo.close();

    cout << "\nProducto registrado\n";
}

// ============================
// LISTAR
// ============================

void listarProductos() {

    Producto p;
    ifstream archivo("productos.dat", ios::binary);

    while(archivo.read((char*)&p, sizeof(Producto))) {

        if(p.activo) {
            cout << "\n--------------------";
            cout << "\nCodigo: " << p.codigo;
            cout << "\nNombre: " << p.nombre;
            cout << "\nPrecio: Q" << p.precio;
            cout << "\nStock: " << p.stock;
        }
    }

    archivo.close();
}

// ============================
// BUSCAR
// ============================

void buscarProducto() {

    int codigo;
    bool encontrado = false;
    Producto p;

    cout << "\nCodigo a buscar: ";
    cin >> codigo;

    ifstream archivo("productos.dat", ios::binary);

    while(archivo.read((char*)&p, sizeof(Producto))) {

        if(p.codigo == codigo && p.activo) {

            cout << "\nNombre: " << p.nombre;
            cout << "\nPrecio: Q" << p.precio;
            cout << "\nStock: " << p.stock;

            encontrado = true;
        }
    }

    archivo.close();

    if(!encontrado)
        cout << "\nNo encontrado";
}

// ============================
// MODIFICAR PRECIO
// ============================

void modificarPrecio() {

    int codigo;
    Producto p;

    cout << "\nCodigo: ";
    cin >> codigo;

    fstream archivo("productos.dat", ios::binary | ios::in | ios::out);

    while(archivo.read((char*)&p, sizeof(Producto))) {

        if(p.codigo == codigo) {

            cout << "\nNuevo precio: ";
            cin >> p.precio;

            archivo.seekp(-sizeof(Producto), ios::cur);
            archivo.write((char*)&p, sizeof(Producto));

            break;
        }
    }

    archivo.close();
}

// ============================
// ACTUALIZAR STOCK
// ============================

void actualizarStock() {

    int codigo;
    Producto p;

    cout << "\nCodigo: ";
    cin >> codigo;

    fstream archivo("productos.dat", ios::binary | ios::in | ios::out);

    while(archivo.read((char*)&p, sizeof(Producto))) {

        if(p.codigo == codigo) {

            cout << "\nNuevo stock: ";
            cin >> p.stock;

            archivo.seekp(-sizeof(Producto), ios::cur);
            archivo.write((char*)&p, sizeof(Producto));

            break;
        }
    }

    archivo.close();
}

// ============================
// DESACTIVAR
// ============================

void desactivarProducto() {

    int codigo;
    Producto p;

    cout << "\nCodigo: ";
    cin >> codigo;

    fstream archivo("productos.dat", ios::binary | ios::in | ios::out);

    while(archivo.read((char*)&p, sizeof(Producto))) {

        if(p.codigo == codigo) {

            p.activo = false;

            archivo.seekp(-sizeof(Producto), ios::cur);
            archivo.write((char*)&p, sizeof(Producto));

            break;
        }
    }

    archivo.close();
}

// ============================
// VENTA SIMPLE
// ============================

void realizarVenta() {

    int codigo, cantidad;
    Producto p;
    Venta v;

    cout << "\nCodigo producto: ";
    cin >> codigo;

    cout << "Cantidad: ";
    cin >> cantidad;

    ifstream archivo("productos.dat", ios::binary);

    bool encontrado = false;

    while(archivo.read((char*)&p, sizeof(Producto))) {

        if(p.codigo == codigo && p.activo) {

            if(cantidad <= p.stock) {

                v.subtotal = p.precio * cantidad;

                if(v.subtotal > 500)
                    v.descuento = v.subtotal * 0.05;
                else
                    v.descuento = 0;

                float base = v.subtotal - v.descuento;
                v.iva = base * 0.12;
                v.total = base + v.iva;

                p.stock -= cantidad;
                p.vendidos += cantidad;

                cout << "\nSubtotal: " << v.subtotal;
                cout << "\nDescuento: " << v.descuento;
                cout << "\nIVA: " << v.iva;
                cout << "\nTotal: " << v.total;

                encontrado = true;
            }
        }
    }

    archivo.close();

    if(!encontrado)
        cout << "\nVenta no realizada";
}