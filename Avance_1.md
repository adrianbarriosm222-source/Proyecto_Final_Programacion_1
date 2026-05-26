Avance 1 PROYECTO FINAL (PROGRAMACION I)

Sistema de Gestión de Ventas e Inventario para Tienda

INTRODUCCIÒN:
Mi proyecto consiste en el desarrollo de un sistema de gestión de ventas e inventario para una tienda, utilizando el lenguaje de programación C++. Mi objetivo principal es automatizar el control de productos, ventas y reportes mediante programación estructurada y el uso de archivos binarios.

OBJETIVOS DEL AVANCE
· Implementar la estructura principal para el manejo de productos.
· Crear funciones para registrar y listar productos.
· Utilizar archivos binarios para almacenar información.

Desarrollo realizado
Para almacenar la información de cada producto se creó la siguiente estructura:

struct Producto {
    int codigo;
    char nombre[50];
    float precio;
    int stock;
    int vendidos;
    bool activo;
};

EXPLICACION DE ESTRUCTURA 
Cada atributo cumple una función específica:

Codigo: identificador único del producto.
Nombre: almacena el nombre del producto.
Precio: guarda el costo del producto.
Stock: controla la cantidad disponible en inventario.
Vendidos: registra la cantidad vendida para futuros reportes.
Activo: permite desactivar productos sin eliminarlos físicamente del archivo.

FUNCIONALIDAD IMPLEMENTADAS
Registro de productos
Se desarrolló una función que permite ingresar productos desde consola solicitando:

Código
Nombre
Precio
Stock
Posteriormente, los datos son almacenados automáticamente en el archivo binario.
Durante el registro se inicializan también los campos:

p.vendidos = 0;
p.activo = true;

Esto garantiza que todos los productos comiencen activos y sin ventas registradas.

MODULARIZACION DEL SISTEMA

El programa fue dividido en diferentes funciones independientes para mejorar la organización y mantenimiento del código.

Entre las funciones implementadas se encuentran:

registrarProducto()
listarProductos()

La modularización facilita futuras ampliaciones del sistema y evita repetir código innecesariamente.

PRUEBAS REALIZADAS

Durante las pruebas se verificó:

·Registro correcto de productos
·Almacenamiento permanente en el archivo
·Lectura adecuada de registros
·Funcionamiento del menú principal
·Visualización correcta de datos

Tambien realize un mimi algoritmo y un digrama de flujo ya que el pseudocódigo esta en el archivo (Primer_Avance_1.cpp) 

ALGORITMO 

INICIO

Mostrar menú principal

Leer opción


SI opción = Registrar producto ENTONCES 

      Solicitar Còdigo
      Solicitar Nombre
      Solicitar Precio
      Solicitar Stock

      Guardar producto en archivo binario

      Mostrar mensaje de exito

FIN SI

FIN

DIAGRAMA DE FLUJO

             ┌───────────────┐
             │    INICIO     │
             └──────┬────────┘
                    │
                    ▼
         ┌─────────────────────┐
         │ Mostrar menú        │
         │ principal           │
         └────────┬────────────┘
                  │
                  ▼
       ┌─────────────────────────┐
       │ ¿Registrar producto?    │
       └────────┬────────────────┘
                │ Sí
                ▼
      ┌──────────────────────────┐
      │ Ingresar código          │
      │ del producto             │
      └────────┬─────────────────┘
               │
               ▼
      ┌──────────────────────────┐
      │ Ingresar nombre          │
      │ del producto             │
      └────────┬─────────────────┘
               │
               ▼
      ┌──────────────────────────┐
      │ Ingresar precio          │
      └────────┬─────────────────┘
               │
               ▼
      ┌──────────────────────────┐
      │ Ingresar stock           │
      └────────┬─────────────────┘
               │
               ▼
      ┌──────────────────────────┐
      │ Guardar producto         │
      │ en productos.dat         │
      └────────┬─────────────────┘
               │
               ▼
      ┌──────────────────────────┐
      │ Mostrar mensaje          │
      │ de éxito                 │
      └────────┬─────────────────┘
               │
               ▼
          ┌───────────┐
          │    FIN    │
          └───────────┘

Y en el archivo (Primer_Avance_1.cpp) esta el codigo de lo que se llevo acabo de la primer avance.