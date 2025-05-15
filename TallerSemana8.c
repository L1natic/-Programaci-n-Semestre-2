#include <stdio.h>
#include "FuncionesTaller8.h"

int main() {
    char nombres[MaximoProductos][MaximoNombre];
    float precios[MaximoProductos];
    int cantidad = pedirCantidad();


    // Variables para tiempo y recursos
    int TiempoDisponible;
    int RecursosDisponibles;


    // Pedir tiempo y recursos disponibles
    printf ("Ingrese el tiempo total disponible (horas): ");
    scanf("%d", &TiempoDisponible);
    printf ("Ingrese los recursos totales disponibles: ");
    scanf("%d", &RecursosDisponibles);

    ingresarProductos(nombres, precios, cantidad);
    mostrarProductos(nombres, precios, cantidad);

    int opcion;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Buscar producto por nombre\n");
        printf("2. Mostrar todos los productos\n");
        printf("3. Editar nombre del producto\n");
        printf("4. Editar cantidades\n");
        printf("5. Editar tiempo de fabricacion\n");
        printf("6. Verificar si cumple con la demanda (horas - recursos)\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1: buscarProducto(nombres, precios, cantidad); 
                break;
            case 2: mostrarProductos(nombres, precios, cantidad); 
                break;
            case 3: mostrarMasCaro(nombres, precios, cantidad); 
                break;
            case 4: mostrarMasBarato(nombres, precios, cantidad); 
                break;
            case 5: calcularPromedio(precios, cantidad); 
                break;
            case 6: printf("Saliendo del programa...\n"); 
                break;
            default: printf("Opcion no válida. Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}






