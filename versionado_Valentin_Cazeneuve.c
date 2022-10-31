// Alumno: Valentin Cazeneuve
// Comision: 6 TUP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Productos {
    int codigoBarra;
    int cantidadStock;
    char descripcion;
};

int main () {
    int tam = 0;
    int opc = 0;
    int i = 0;
    int banderaNoStock = 0;
    int banderaBuscado = 0;
    int codigoBarraBuscado = 0;

    printf("Cantidad de productos a cargar: ");
    scanf("%i", &tam);
    while(tam < 1 || tam > 100) {
        printf("Cantidad inv%clida, reintente: ", 160);
        scanf("%i", &tam);
    }

    struct Productos producto[tam];

    do {
        printf("\n1. Cargar productos \n");
        printf("2. Modificar stock \n");
        printf("3. Mostrar productos sin stock \n");
        printf("4. Listar productos \n");
        printf("5. Salir \n");

        printf("\nOpci%cn: ", 162);
        scanf("%i", &opc);
        while(opc < 1 || opc > 5) {
            printf("Opci%cn inv%clida, reintente: ", 162, 160);
            scanf("%i", &opc);
        }

       switch(opc) {
            case 1:     // Cargar productos
                for(i=0; i<tam; i++) {
                    printf("\nElectrodom%cstico n%c %i \n", 130, 248, i+1);

                    printf("C%cdigo de barra: ", 162);
                    scanf("%i", &producto[i].codigoBarra);

                    while(producto[i].codigoBarra>99999999) {
                        printf("C%cdigo de barra muy largo (m%cximo 8 num): ", 162, 160);
                        scanf("%i", &producto[i].codigoBarra);
                    }

                    printf("Descripci%cn: ", 162);
                    fflush(stdin);
                    scanf("%[^\n]", &producto[i].descripcion);

                    printf("Cantidad: ");
                    scanf("%i", &producto[i].cantidadStock);

                    while(producto[i].cantidadStock<0) {
                        printf("No puede haber stock negativo, reintente: ");
                        scanf("%i", &producto[i].cantidadStock);
                    }
                }
                break;
            
            case 2:     // Modificar stock
                banderaBuscado = 0;

                printf("C%cdigo de barra del electrodom%cstico a modificar: ", 162, 130);
                scanf("%i", &codigoBarraBuscado);

                while(codigoBarraBuscado>99999999) {
                    printf("C%cdigo de barra muy largo (m%cximo 8 num): ", 162, 160);
                    scanf("%i", &codigoBarraBuscado);
                }

                for (i=0; i<tam; i++) {
                    if (codigoBarraBuscado == producto[i].codigoBarra) {
                        printf("Cantidad en stock nueva: ");
                        scanf("%i", &producto[i].cantidadStock);
                        
                        while(producto[i].cantidadStock < 0) {
                            printf("No puede haber stock negativo, reintente: ");
                            scanf("%i", &producto[i].cantidadStock);
                        }

                        banderaBuscado = 1;
                    }
                }

                if(banderaBuscado == 0) {
                    printf("Electrodom%cstico inexistente\n\n", 130);
                }
                
                break;
            
            case 3:     // Mostrar productos sin stock
                banderaNoStock = 0;

                printf("----------------------------\n");
                printf("Electrodom%csticos sin stock \n", 130);
                printf("----------------------------\n");

                for (i=0; i<tam; i++) {

                    if (producto[i].cantidadStock == 0) {
                        printf("C%cdigo de barra: %i \n", 162, producto[i].codigoBarra);
                        printf("Descripci%cn: %s \n\n", 162, producto[i].descripcion);

                        banderaNoStock = 1;
                    }

                }

                    if (banderaNoStock == 0) {
                        printf("No hay electrodom%csticos sin stock\n\n", 130);
                    }
                break;

            case 4:     // Listar productos
                printf("------------------\n");
                printf("Lista de productos\n");
                printf("------------------\n");

                for(i=0; i<tam; i++) {
                    printf("\nC%cdigo de barra: %i \n", 162, producto[i].codigoBarra);
                    printf("Descripci%cn: %s \n", 162, producto[i].descripcion);
                    printf("Cantidad en stock: %i \n", producto[i].cantidadStock);
                }
                break;

            default:
                printf("Saliendo...\n");
       }
    } while (opc != 5);

    system("pause");
}