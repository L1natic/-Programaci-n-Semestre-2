void buscarcod(char nombres[][MaximoNombre],int codigo[], float precios[], int cantidad) {
    int cod;
    printf("\nIngrese el código del producto a buscar: ");
    fflush(stdin);
    scanf("%d",&cod);
    

   
    for (int i = 0; i < cantidad; i++) {
        if (cod==codigos[i]) {
            printf("Producto encontrado -> %d: %s\n", codigos[i],nombres[i]);
           
            break;
        }
    else {
        printf("Producto no encontrado.\n");
    }
    }
}
