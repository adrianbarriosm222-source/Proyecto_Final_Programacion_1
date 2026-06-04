#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

// ================= STRUCTS =================

struct Producto {
    int codigo;
    char nombre[50];
    double precio;
    int stock;
    int vendidos;
    bool activo;
};

struct DetalleVenta {
    int codigo;
    char nombre[50];
    int cantidad;
    double precio;
    double subtotal;
};

struct Venta {
    int numero;
    int dia;
    int mes;
    int totalArticulos;
    double subtotal;
    double iva;
    double descuento;
    double total;
};

// ================= MATRIZ =================
double ventasPorMes[12][31] = {0};

// ================= FECHA REAL =================

int obtenerDia() {
    time_t t = time(0);
    tm* now = localtime(&t);
    return now->tm_mday - 1;
}

int obtenerMes() {
    time_t t = time(0);
    tm* now = localtime(&t);
    return now->tm_mon;
}

// ================= PRODUCTOS =================

void registrarProducto() {
    Producto p;

    cout << "\nCODIGO: ";
    cin >> p.codigo;

    cin.ignore();
    cout << "NOMBRE: ";
    cin.getline(p.nombre, 50);

    cout << "PRECIO: ";
    cin >> p.precio;

    cout << "STOCK: ";
    cin >> p.stock;

    p.vendidos = 0;
    p.activo = true;

    ofstream file("productos.dat", ios::binary | ios::app);
    file.write((char*)&p, sizeof(p));
    file.close();

    cout << "Producto registrado.\n";
}

void listarProductos() {
    Producto p;
    ifstream file("productos.dat", ios::binary);

    cout << "\n--- PRODUCTOS ---\n";

    while (file.read((char*)&p, sizeof(p))) {
        if (p.activo) {
            cout << p.codigo << " | " << p.nombre
                 << " | Q" << p.precio
                 << " | Stock: " << p.stock
                 << " | Vendidos: " << p.vendidos << endl;
        }
    }
    file.close();
}

// ================= BÚSQUEDA =================

int buscarProducto(int cod) {
    Producto p;
    ifstream file("productos.dat", ios::binary);

    int pos = 0;
    while (file.read((char*)&p, sizeof(p))) {
        if (p.codigo == cod && p.activo) {
            file.close();
            return pos;
        }
        pos++;
    }

    file.close();
    return -1;
}

// ================= ACTUALIZAR =================

void actualizarProducto(int codigo, int cant) {
    Producto p;
    fstream file("productos.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&p, sizeof(p))) {
        if (p.codigo == codigo) {
            p.stock -= cant;
            p.vendidos += cant;

            file.seekp(-sizeof(p), ios::cur);
            file.write((char*)&p, sizeof(p));
            break;
        }
    }
    file.close();
}

// ================= VENTA =================

void crearVenta() {
    Venta v;
    v.subtotal = 0;
    v.totalArticulos = 0;

    cout << "\nNUMERO VENTA: ";
    cin >> v.numero;

    char op;

    do {
        Producto p;
        int cod, cant;

        cout << "Codigo producto: ";
        cin >> cod;

        ifstream file("productos.dat", ios::binary);

        while (file.read((char*)&p, sizeof(p))) {
            if (p.codigo == cod && p.activo) {

                cout << "Cantidad: ";
                cin >> cant;

                if (cant > p.stock) {
                    cout << "Sin stock.\n";
                    break;
                }

                v.subtotal += cant * p.precio;
                v.totalArticulos += cant;

                actualizarProducto(cod, cant);

                int m = obtenerMes();
                int d = obtenerDia();
                ventasPorMes[m][d] += cant * p.precio;

                break;
            }
        }

        file.close();

        cout << "Agregar otro? (s/n): ";
        cin >> op;

    } while (op == 's');

    // IVA
    v.iva = v.subtotal * 0.12;

    // DESCUENTOS
    v.descuento = 0;

    if (v.subtotal > 500)
        v.descuento += v.subtotal * 0.05;

    if (v.totalArticulos % 5 == 0)
        v.descuento += 25;

    v.total = v.subtotal + v.iva - v.descuento;
    v.total = round(v.total * 100) / 100;

    ofstream file("ventas.dat", ios::binary | ios::app);
    file.write((char*)&v, sizeof(v));
    file.close();

    cout << "\nTOTAL: Q" << v.total << endl;
}

// ================= ORDENAMIENTOS =================

void ordenarPrecio() {
    Producto p[100];
    int n = 0;

    ifstream file("productos.dat", ios::binary);

    while (file.read((char*)&p[n], sizeof(Producto)))
        n++;

    file.close();

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j].precio > p[j + 1].precio)
                swap(p[j], p[j + 1]);

    cout << "\n--- ORDENADOS POR PRECIO ---\n";

    for (int i = 0; i < n; i++)
        cout << p[i].nombre << " Q" << p[i].precio << endl;
}

// ================= EXPORTAR =================

void exportarTXT() {
    ofstream file("reporte.txt");
    Producto p;

    file << "REPORTE DE PRODUCTOS\n\n";

    ifstream in("productos.dat", ios::binary);

    while (in.read((char*)&p, sizeof(p))) {
        if (p.activo)
            file << p.codigo << " " << p.nombre << " Q" << p.precio << endl;
    }

    in.close();
    file.close();

    cout << "Reporte exportado.\n";
}

// ================= MATRIZ =================

void reporteMes() {
    cout << "\n--- VENTAS POR MES ---\n";

    for (int i = 0; i < 12; i++) {
        double total = 0;

        for (int j = 0; j < 31; j++)
            total += ventasPorMes[i][j];

        cout << "Mes " << i + 1 << ": Q" << total << endl;
    }
}

// ================= MENU =================

void menu() {
    int op;

    do {
        cout << "\n===== SISTEMA TIENDA =====\n";
        cout << "1. Registrar producto\n";
        cout << "2. Listar productos\n";
        cout << "3. Crear venta\n";
        cout << "4. Ordenar por precio\n";
        cout << "5. Reporte mensual\n";
        cout << "6. Exportar TXT\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op) {
            case 1: registrarProducto(); break;
            case 2: listarProductos(); break;
            case 3: crearVenta(); break;
            case 4: ordenarPrecio(); break;
            case 5: reporteMes(); break;
            case 6: exportarTXT(); break;
        }

    } while (op != 0);
}

// ================= MAIN =================

int main() {
    menu();
    return 0;
    
    cout << "Rodrigo Adrian Barrios Monterroso" ;

}