#include <stdio.h>
#include "FuncionesTaller8.h"

int main() {
    int cantidad = pedirCantidad();


    // Variables para tiempo y recursos
    int TiempoDisponible;
    int RecursosDisponibles;


    // Pedir tiempo y recursos disponibles
    printf ("Ingrese el tiempo total disponible (horas): ");
    scanf("%d", &TiempoDisponible);
    printf ("Ingrese los recursos totales disponibles: ");
    scanf("%d", &RecursosDisponibles);

    struct Producto productos[MaximoProductos];
    ingresarProductos(productos, cantidad);
    printf("\n--- Productos Ingresados ---\n");
    mostrarProductos(productos, cantidad);

    int opcion;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Buscar producto por codigo\n");
        printf("2. Mostrar todos los productos\n");
        printf("3. Editar nombre del producto por codigo\n");
        printf("4. Editar cantidades\n");
        printf("5. Editar tiempo de fabricacion por codigo\n");
        printf("6. Verificar si cumple con la demanda (horas - recursos)\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                buscarProducto(productos, cantidad);
                break;

            case 2:
                mostrarProductos(productos, cantidad);
                break;

            case 3:
                EditarNombre(productos, cantidad);
                break;
                
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}






