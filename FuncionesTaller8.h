#include <string.h>

#define MaximoProductos 5

struct Producto {
    char nombre[5];
    float precio;
    int codigo;
    int cantidad;
    int CantidadFabricada;
    float tiempoFabricacion; 
};
// Funciones
int pedirCantidad();
void ingresarProductos(struct Producto productos[], int cantidad);
void mostrarProductos(struct Producto productos[], int cantidad);


// Definiciones de funciones
int pedirCantidad() {
    int cantidad;

REPETIR:
    printf("Ingrese la cantidad de productos (maximo %d): ", MaximoProductos);
    scanf("%d", &cantidad);
    fflush(stdin);

    if (cantidad < 1 || cantidad > MaximoProductos) {
        printf("Cantidad invalida. Intente nuevamente.\n");
        goto REPETIR;
    }

    return cantidad;
}


void ingresarProductos(struct Producto productos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("Nombre: ");
        fgets(productos[i].nombre, sizeof(productos[i].nombre), stdin);
        productos[i].nombre[strcspn(productos[i].nombre, "\n")] = '\0'; // Eliminar el salto de línea
        printf("Precio: $ ");
        scanf("%f", &productos[i].precio);
        printf("Codigo: ");
        scanf("%d", &productos[i].codigo);
        printf("Cantidad demandada: ");
        scanf("%d", &productos[i].cantidad);
        printf("Tiempo por unidad (horas): ");
        scanf("%f", &productos[i].tiempoFabricacion);
    }
}


void mostrarProductos (struct Producto productos[], int cantidad) {
    printf("\n--- Lista de Productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s | Precio: %.2f | Codigo: %d | Cantidad: %d | Tiempo/u: %.2f h\n", i + 1, productos[i].nombre, productos[i].precio, productos[i].codigo, productos[i].cantidad, productos[i].tiempoFabricacion);
    }
}


