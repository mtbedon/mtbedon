#include <stdio.h>
int validarID (char id [6]){
    if (!(id[0]>='0' && id[0]<='9')) return 0;
    if (!(id[1]>='0' && id[1]<='9')) return 0;
    if (!(id[2]>='0' && id[2]<='9')) return 0;
    if (!(id[3]>='A' && id[3]<='Z')) return 0;
    if (!(id[4]>='A' && id[4]<='Z')) return 0;
    if (!(id[5]>='A' && id[5]<='Z')) return 0;
    return 1;
}
int main() {
    char id [6];
    char nombre[50];
    int stock = 0;
    float precio = 0.0;
    float ganancias = 0.0;

    int opcion;
    int registrado = 0;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Consultar producto\n");
        printf("5. Mostrar ganancias\n");
        printf("6. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:{
                int val=0;
                do
                {
                    printf("Ingrese el ID del producto: (Formato: 123ABC)");
                    scanf("%6s", &id);
                    val=validarID(id);
                    if (val!=1){
                        printf("Ingrese el ID correctamente:\n ");
                    }
                } while (!val);
                printf("Ingrese el nombre del producto (una sola palabra): ");
                scanf(" %s", &nombre);
                printf("Ingrese la cantidad en stock: ");
                scanf("%d", &stock);
                do{
                    printf("Ingrese la cantidad en stock: ");
                    scanf("%d", &stock);
                    printf("El stock debe superar 0\n");
                }while(stock<=0);
                printf("Ingrese el precio unitario: ");
                scanf("%f", &precio);
                do{
                    printf("Ingrese el precio unitario: ");
                    scanf("%f", &precio);
                    printf("El precio debe ser positivo\n");
                }while (precio<=0.0);
                ganancias = 0.0;
                registrado = 1;
                break;
            }
            case 2:{
                if (registrado) {
                    int cantidad;
                    printf("Ingrese la cantidad a vender: ");
                    scanf("%d", &cantidad);
                    if (cantidad <= 0) {
                        printf("La cantidad debe ser positiva.\n");
                    } else if (cantidad > stock) {
                        printf("No hay suficiente stock disponible.\n");
                    } else {
                        stock -= cantidad;
                        ganancias += cantidad * precio;
                        printf("Venta realizada. Se vendieron %d unidades.\n", cantidad);
                    }
                } else {
                    printf("Primero debe registrar un producto.\n");
                }
                break;
            }
            case 3:{
                if (registrado) {
                       int cantidad;
                    printf("Ingrese la cantidad a reabastecer: ");
                    scanf("%d", &cantidad);

                    if (cantidad > 0) {
                        stock += cantidad;
                        printf("Reabastecimiento exitoso. Stock actual: %d\n", stock);
                    } else {
                        printf("La cantidad debe ser positiva.\n");
                    }
                } else {
                    printf("Primero debe registrar un producto.\n");
                }
                break;
            }
            case 4:{
                if (registrado) {
                    printf("\n--- Informacion del producto ---\n");
                    printf("ID: %s\n", id);
                    printf("Nombre: %s\n", nombre);
                    printf("Stock: %d\n", stock);
                    printf("Precio unitario: %.2f\n", precio);
                    printf("Ganancias acumuladas: %.2f\n", ganancias);
                    printf("--------------------------------\n");
                } else {
                    printf("Primero debe registrar un producto.\n");
                }
                break;
            }
            case 5:
                if (registrado) {
                    printf("Ganancias acumuladas: %.2f\n", ganancias);
                } else {
                    printf("Primero debe registrar un producto.\n");
                }
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 6);

    return 0;
}
