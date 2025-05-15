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
void buscarProducto(struct Producto productos[], int cantidad);
void EditarNombre(struct Producto productos[], int cantidad);


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
        getchar(); // Limpiar el buffer
        fgets(productos[i].nombre, sizeof(productos[i].nombre), stdin);
        printf("Precio: $ ");
        fflush(stdin);
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


void buscarProducto(struct Producto productos[], int cantidad){
    int codigo, opc2;
    printf("Si desea buscar por codigo presione 1 y si desea buscar por nombre presione 2: ");
    scanf("%d", &opc2);
    fflush(stdin);
    if (opc2 == 1) {
        printf("Ingrese el codigo del producto a buscar: ");
        scanf("%d", &codigo);
        fflush(stdin);
        for (int i = 0; i < cantidad; i++) {
            if (productos[i].codigo == codigo) {
                printf("Producto encontrado: %s | Precio: %.2f\n", productos[i].nombre, productos[i].precio);
                return;
            }
        }
    } else if (opc2 == 2) {
        printf("Ingrese el nombre del producto a buscar: ");
        fflush (stdin); // Limpiar el buffer
        int encontrado = 0;
        char nombreBusqueda[50];
        fgets(nombreBusqueda, sizeof(nombreBusqueda), stdin);
        nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0';
        for (int i = 0; i < cantidad; i++) {
            if (strcmp(nombreBusqueda, productos[i].nombre) == 0) {
                printf("Producto encontrado: %s | Precio: %.2f\n", productos[i].nombre, productos[i].precio);
                encontrado = 1;
                break;
            }
        }
    } else {
        printf("Opcion invalida.\n");
        return;
    }
}

void Editarproducto (struct Producto productos[], int cantidad) {
    
    int code,opc2;
    printf("Ingrese el codigo del producto a editar: ");
    fflush(stdin);
    scanf("%d", &code);
    printf("Selecciona qué quieres editar-> 1.nombre 2. codigo 3. tiempo 4. cantidad fabricada 5. precio ")
    scanf("%d",&opc2);
    //casos
    switch (opc2){
        case 1: 
            for (int i = 0; i < cantidad; i++) {
             if (productos[i].codigo == code) {
                printf("Ingrese el nuevo nombre del producto: ");
                fflush(stdin); // Limpiar el buffer
                fgets (productos[i].nombre, sizeof(productos[i].nombre), stdin);
                printf("Nombre actualizado a: %s\n", productos[i].nombre);
            return;
        }
        case 2:
        for (int i = 0; i < cantidad; i++) {
        if (productos[i].codigo == code) {
            printf("Ingrese el nuevo código del producto: ");
            fflush(stdin); // Limpiar el buffer
             scanf ("%d", &productos[i].codigo);
            printf("Código actualizado a: %s\n", productos[i].codigo);
            return;
        }
    }
    case 3:
    for (int i = 0; i < cantidad; i++) {
        if (productos[i].codigo == code) {
            printf("Ingrese el nuevo Tiempo de Fabricacion del producto: ");
            fflush(stdin); // Limpiar el buffer
            scanf ("%f", &productos[i].tiempoFabricacion);
            printf("Tiempo de Fabricacion actualizado a: %f\n", productos[i].tiempoFabricacion);
            return;
        }
    case 4://cantidad fabricada
    for (int i = 0; i < cantidad; i++) {
        if (productos[i].codigo == code) {
            printf("Ingrese la nueva cantidad del producto: ");
            fflush(stdin); // Limpiar el buffer
            scanf ("%f", &productos[i].CantidadFabricada);
            printf("Tiempo deFabricacion actualizado a: %f\n", productos[i].CantidadFabricada);
            return;
        }
    case 5://precio
    
   for (int i = 0; i < cantidad; i++) {
        if (productos[i].codigo == code) {
            printf("Ingrese el nuevo precio del producto: ");
            fflush(stdin); // Limpiar el buffer
            scanf ("%f", &productos[i].precio);
            printf("precio actualizado a: %f\n", productos[i].precio);
            return;
        }
    
    }
}

