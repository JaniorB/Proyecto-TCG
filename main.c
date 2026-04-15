#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define nameMax 20
#define logsHistorial 150

//Structs

typedef struct  criatura{
    char nombre[nameMax];
    char tipo[nameMax];
    int nivel;
    int hp;
    int ataque;
}criatura; //Las cartas del juego

typedef struct jugador{
    char nombre[nameMax];
    int nivel;
    bool orden;
    int vida;
} jugador; //Estructura del jugador y sus estadisticas

typedef struct deck{
    int arr[60];
    int top;
} deck; //Estructura del mazo del jugador

typedef struct historial{
    char datosbatalla[logsHistorial];
    struct historial* siguiente;
    struct historial* anterior;
}historial;//Estructura del historial de batalla de la partida

//Pila
typedef struct nodeMano {
    criatura carta;
    struct nodeMano* siguiente;
} nodeMano;

//Lista enlazada del tablero
typedef struct nodeTablero {
    criatura* carta;
    struct nodeTablero* siguiente;
} nodeTablero;

//Cola de batalla
typedef struct nodeCola {
    criatura carta;
    int pos;
    struct nodeCola* sig;
} nodeCola;

//Fin de los structs


criatura plantillas[] = {
    { "Lobo Plateado", "atacante", 1, 3, 2 },
    { "Tortuga Terrestre", "tanque", 1, 5, 0 },
    { "Aguila Real", "atacante", 1, 2, 3 }
};

jugador* CrearJugador(char nombre[]) {
    jugador* nuevo_jugador = malloc(sizeof(jugador));

    if(nuevo_jugador == NULL) return NULL;

    //copia el contenido del string a la propiedad de la structura
    strcpy(nuevo_jugador->nombre, nombre);

    //evita el desborde en la propiedad y garantiza que este terminado correctamente
    nuevo_jugador->nombre[nameMax - 1] = '\0';
    nuevo_jugador->vida = 0;
    nuevo_jugador->nivel = 0;
    nuevo_jugador->orden = 0;
    return nuevo_jugador;
}

deck* CrearDeck() {}

void EliminarJugadores(jugador** jugadores) {
    if (*jugadores == NULL) {
        printf("no hay del jugadores \n");
        return;
    }
    free(*jugadores);
}

historial* CrearDatosHistorial(char datosbatalla[]) {
    historial* nuevo_historial = malloc(sizeof(historial));

    if(nuevo_historial == NULL)return NULL;

    strcpy(nuevo_historial->datosbatalla, datosbatalla);

    //evita el desborde de propiedad y garantiza que este terminado correctamente
    nuevo_historial->datosbatalla[logsHistorial -1] = '\0';
    nuevo_historial->siguiente = NULL;
    nuevo_historial->anterior = NULL;
    return nuevo_historial;
}

void InsertarAlfinalHistorial(historial** inicio, char datosbatalla[]) {
    //Creando un nuevo nodo de historial
    historial* nuevo_historial = CrearDatosHistorial(datosbatalla);

    //en caso de que malloc falle
    if(nuevo_historial == NULL)return;

    //verificar is esta vacio
    if(*inicio == NULL) {
        *inicio = nuevo_historial;
        return;
    }

    historial* temp = *inicio;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo_historial;
    nuevo_historial->anterior = temp;
}

void EliminarAlinicioHistorial(historial** inicio) {
    if(*inicio == NULL) {
        printf("no hay datos del historial\n");
        return;
    }
    historial* temp = *inicio;
    *inicio = (*inicio)->siguiente;
    if(*inicio != NULL) {
        (*inicio)->anterior = NULL;
    }

    free(temp);
}

void MostrarHistorial(historial* inicio) {
    historial* nuevo_historial = inicio;
    while(nuevo_historial != NULL) {
        printf("%s\n",nuevo_historial->datosbatalla);
        nuevo_historial = nuevo_historial->siguiente;
    }
    printf("\n");
}

void SubirNivelJugador(jugador* player) {
    if(player->nivel > 3) {
        printf("el jugador ha alcanzado el maximo nivel\n");
        return;
    }

    player->nivel = player->nivel + 1;
    printf("el nivel del jugador es: %d\n",player->nivel);

}

void Menu() {
    int opcion = 0;
    do{
        printf("\n------------------------------------\n");
        printf("[1] - FUSIONAR\n");
        printf("[2] - ASIGNAR CARTA AL TABLERO\n");
        printf("[3] - BATALLAR Y TERMINAR TURNO\n");
        printf("-------------------------------------\n");
        printf("Ingrese una Opcion: ");
        scanf("%d",&opcion);

        switch(opcion) {
            case 1: //hacer funcion fusionar;
                break;
            case 2: //hacer funcion asigarnar carta;
                break;
            case 3: //hacer funcion batallar;
                break;
            case 4: break;
            default: printf("opcion invalida\n");
                    break;
        }
    }while(opcion != 4);
}


int main() {
    //ejemplo
     // jugador* jugador1 = CrearJugador("el sabueso");
    // historial* datosJ1 = CrearDatosHistorial("hizo 2 ataques");
    //
    // printf("[%s]: %s \n",jugador1->nombre,datosJ1->datosbatalla);
    //
    // free(datosJ1);
    //-------------------
    // SubirNivelJugador(jugador1);
    // printf("\n");
    // free(jugador1);

}