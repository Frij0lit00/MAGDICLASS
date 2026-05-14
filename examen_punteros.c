#include <stdio.h>
#include <stdlib.h>

struct Dato {
    int numero;
    struct Dato *siguiente;
    struct Dato *anterior;
};

struct Dato *inicio = NULL;

void insertar(int numero) {
    struct Dato *nuevo;
    struct Dato *ultimo;

    nuevo = (struct Dato*) malloc(sizeof(struct Dato));

    if (nuevo == NULL) {
        printf("No se pudo reservar memoria.\n");  return;
    }

    nuevo->numero = numero;

    if (inicio == NULL) {
        inicio = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
    } else {
        ultimo = inicio->anterior;

        nuevo->siguiente = inicio;
        nuevo->anterior = ultimo;

        ultimo->siguiente = nuevo;
        inicio->anterior = nuevo;
    }

    printf("Dato insertado correctamente.\n");
}


void mostrar() {
    struct Dato *recorrido;

    if (inicio == NULL) {
        printf("La lista esta vacia.\n"); return;
    }

    recorrido = inicio;

    printf("Datos de la lista: ");

    do {
        printf("%d ", recorrido->numero);
        recorrido = recorrido->siguiente;
    } while (recorrido != inicio);

    printf("\n");
}
/* Se tiene que recorrer y buscar al nodo en su parte siguiente que sea 
Null entonces sabiendo que es null eliminamos el ultimo y liberamos 
memoria y asi hasta que el *ptr sea igual a Null */

void liberarDatos(struct Dato **ptr)
{
    struct Dato *axptr;
    struct Dato *temp;

    axptr = *ptr;

    
    do{
        temp = axptr;
        axptr = axptr->siguiente;
        free(temp);
    } while (axptr != NULL);

    *ptr = NULL;
}

/*struct Dato liberardatos(struct Dato *ptr){
    struct Dato *axptr, *temp;
    axptr = *ptr;

 do{
      
        temp = axptr;
        axptr = axptr->ptrSig;
        free(temp);

    }while(axptr != NULL);
        *ptr = NULL;


}  */

void eliminar(int numero) {
    struct Dato *bus;

    if (inicio == NULL) {
        printf("La lista esta vacia.\n");  return;
        
    } bus = inicio;

    do {
        if (bus->numero == numero) {

            if (bus->siguiente == bus) {
                inicio = NULL;
            } else {
                bus->anterior->siguiente = bus->siguiente;
                bus->siguiente->anterior = bus->anterior;

                if (bus == inicio) {
                    inicio = bus->siguiente;
                }
            }

            free(bus);
            printf("Dato eliminado correctamente.\n");
            return;
        }

        bus = bus->siguiente;

    } while (bus != inicio);

    printf("El dato no se encontro en la lista.\n");
}

int main() {
    int opcion;
    int numero;

    do {
        printf("\n Menu de opciones favor de sleccionar una");
        printf("\n 1 Insertar elemento \n");
        printf("\n 2 Eliminar elemento \n");
        printf("\n 3 Mostrar elementos \n");
        printf("\n 4 Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa el numero: ");
                scanf("%d", &numero);
                insertar(numero);
                break;

            case 2:
                printf("Ingresa el numero a eliminar: ");
                scanf("%d", &numero);
                eliminar(numero);
                break;

            case 3:
                mostrar();
                break;

            case 4:
                printf("Programa finalizado.\n");
                break;
        }

    } while (opcion != 4);

    return 0;
}
