#include <string.h>

#define MaximoProductos 5
#define MaximoNombre 30


// Funciones
int pedirCantidad();
void ingresarProductos(char nombres[][MaximoNombre], float precios[], int cantidad);
void mostrarProductos(char nombres[][MaximoNombre], float precios[], int cantidad);
void buscarProducto(char nombres[][MaximoNombre], float precios[], int cantidad);
void mostrarMasCaro(char nombres[][MaximoNombre], float precios[], int cantidad);
void mostrarMasBarato(char nombres[][MaximoNombre], float precios[], int cantidad);
void calcularPromedio(float precios[], int cantidad);

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


void ingresarProductos(char nombres[][MaximoNombre], float precios[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nProducto %d:\n", i + 1);
        fflush(stdin);
        printf("  Nombre: ");
        fgets(nombres[i], MaximoNombre, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0'; // Eliminar salto de línea
        printf("  Precio: $ ");
        scanf("%f", &precios[i]);
    }
}

void mostrarProductos(char nombres[][MaximoNombre], float precios[], int cantidad) {
    printf("\n--- Lista de Productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }
}

void buscarProducto(char nombres[][MaximoNombre], float precios[], int cantidad) {
    char nombreBusqueda[MaximoNombre];
    printf("\nIngrese el nombre del producto a buscar: ");
    fflush(stdin);
    fgets(nombreBusqueda, MaximoNombre, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombreBusqueda, nombres[i]) == 0) {
            printf("Producto encontrado: %s - $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void mostrarMasCaro(char nombres[][MaximoNombre], float precios[], int cantidad) {
    int maxProducto = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[maxProducto]) {
            maxProducto = i;
        }
    }
    printf("Producto mas caro: %s - $%.2f\n", nombres[maxProducto], precios[maxProducto]);
}

void mostrarMasBarato(char nombres[][MaximoNombre], float precios[], int cantidad) {
    int minProducto = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < precios[minProducto]) {
            minProducto = i;
        }
    }
    printf("Producto mas barato: %s - $%.2f\n", nombres[minProducto], precios[minProducto]);
}

void calcularPromedio(float precios[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += precios[i];
    }
    float promedio = suma / cantidad;
    printf("Precio promedio: $%.2f\n", promedio);
}