Avance 2 PROYECTO FINAL (PROGRAMACION I)

INTRODUCCIÓN

En este segundo avance del proyecto final se amplía el sistema de gestión de ventas e inventario desarrollado en el primer avance, incorporando nuevas funcionalidades orientadas a la administración completa de productos y el inicio del módulo de ventas.
El sistema está desarrollado en C++ utilizando programación estructurada y archivos binarios, permitiendo la persistencia de datos y la gestión básica de una tienda mediante consola.

OBJETIVOS DEL AVANCE
· Ampliar la gestión de productos con nuevas operaciones.
· Implementar búsquedas dentro del inventario.
· Permitir modificación y actualización de productos existentes.
· Desactivar productos sin eliminarlos del archivo.
· Iniciar el módulo de ventas.
· Aplicar cálculos de IVA y descuentos.
· Mejorar la lógica general del sistema.

FUNCIONALIDADES IMPLEMENTADAS
|| Gestión de Productos

En este avance se amplían las funcionalidades del sistema de productos, permitiendo:

·Registro de productos.
·Listado de productos activos.
·Búsqueda de productos por código.
·Modificación del precio de productos.
·Actualización del stock disponible.
·Desactivación lógica de productos (sin eliminación física del archivo).

||Módulo Inicial de Ventas

·Seleccionar productos registrados.
·Ingresar cantidad de productos vendidos.
·Validar existencia de stock disponible.
·Calcular subtotal de la venta.
·Aplicar descuento del 5% cuando el subtotal es mayor a Q500.
·Calcular IVA sobre el total.
·Generar el total final de la venta.

||Manejo de Archivos

·Se continúa utilizando archivos binarios para la persistencia de datos:
·productos.dat → almacenamiento de productos.

||ESTRUCTURAS UTILIZADAS

Producto: contiene la información del inventario.
Venta: estructura inicial para el registro de ventas.
 
||PRUEBAS REALIZADAS

·Registro correcto de productos.
·Lectura adecuada desde archivo binario.
·Funcionamiento de búsqueda por código.
·Modificación de precios.
·Actualización de stock.
·Desactivación de productos.
·Cálculo correcto de descuentos e IVA en ventas iniciales.

|| DIAGRAMA DE FLUJO

┌───────────────┐
│    INICIO     │
└──────┬────────┘
       │
       ▼
┌───────────────────────────────┐
│ Mostrar menú principal        │
│ 1. Registrar producto         │
│ 2. Listar productos           │
│ 3. Buscar producto            │
│ 4. Modificar precio           │
│ 5. Actualizar stock           │
│ 6. Desactivar producto        │
│ 7. Realizar venta             │
│ 8. Salir                      │
└──────────────┬────────────────┘
               │
               ▼
        ┌───────────────────────┐
        │ Leer opción del menú  │
        └─────────┬─────────────┘
                  │
        ┌─────────┴─────────┐
        │                   │
        ▼                   ▼
 ────────────────────────────┐
│ Ingresar datos del producto│
│ código, nombre, precio,    │
│ stock                      │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Guardar en productos.dat   │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Mostrar mensaje de éxito   │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Abrir productos.dat        │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Leer productos activos     │
│ Mostrar en pantalla        │
└────────────┬───────────────┘
             ▼   
┌────────────────────────────┐
│ Ingresar código            │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Buscar en archivo          │
└──────┬───────────────┬─────┘
       │               │
     Encontrado     No encontrado
       │               │
       ▼               ▼
Mostrar datos     Mensaje error 
┌────────────────────────────┐
│ Buscar producto por código │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Mostrar precio actual      │
│ Ingresar nuevo precio      │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Guardar cambios en archivo │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Buscar producto            │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Ingresar nuevo stock      │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Guardar en archivo        │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Buscar producto            │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Cambiar activo = false     │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Guardar cambios           │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Seleccionar producto       │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Ingresar cantidad          │
└────────────┬───────────────┘
             ▼
┌────────────────────────────┐
│ Validar stock disponible   │
└──────┬───────────────┬─────┘
       │               │
     OK              No OK
       │               │
       ▼               ▼
┌────────────────────┐   ┌──────────────────┐
│ Calcular subtotal  │   │ Error de stock   │
└────────┬───────────┘   └──────────────────┘
         ▼
┌────────────────────────────┐
│ Aplicar descuento (>Q500)  │
└────────┬───────────────────┘
         ▼
┌────────────────────────────┐
│ Calcular IVA               │
└────────┬───────────────────┘
         ▼
┌────────────────────────────┐
│ Calcular total final       │
└────────┬───────────────────┘
         ▼
┌────────────────────────────┐
│ Descontar stock            │
│ Guardar venta              │
└────────┬───────────────────┘
         ▼
┌───────────────┐
│      FIN      │
└───────────────┘