#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define nameMax 20
#define logsHistorial 150

//S43G 4/10/2026
typedef struct jugador{
    char nombre[nameMax];
    int nivel;
    bool orden;
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



typedef struct criatura{
    char nombre[nameMax];
    char tipo[nameMax];
    int nivel;
    int hp;
    int ataque;
}criatura; //Las cartas del juego



typedef struct mano{
    // struct carta;
    criatura carta; 
    struct mano* siguiente;
    struct mano* anterior;

}mano; //mano del jugador


void statsCriaturasIniciales() {
    criatura lobo = {
        "Lobo Plateado",
        "atacante",
        1,
        3,
        2
    };

    criatura tortuga = {
        "Tortuga Terrestre",
        "tanque",
        1,
        5,
        0
    };
}

jugador* CrearJugador(char nombre[]) {
    jugador* nuevo_jugador = malloc(sizeof(jugador));
    jugador* nuevo_jugador2 = malloc(sizeof(jugador));

    if(nuevo_jugador == NULL && nuevo_jugador2 == NULL ||
       nuevo_jugador == NULL || nuevo_jugador2 == NULL) return NULL;

    printf("Ingresa un nombre jugador 1: \n");
    scanf("%s",nuevo_jugador->nombre);

    nuevo_jugador->orden = 0;

    printf("Ingresa un nombre jugador 2: \n");
    scanf("%s",nuevo_jugador2->nombre);

    nuevo_jugador2->orden = 1;
}

historial* CrearDatosHistorial(char datosbatalla[]) {
    historial* nuevo_historial = malloc(sizeof(historial));

    if(nuevo_historial == NULL)return NULL;

    strcpy(nuevo_historial->datosbatalla, datosbatalla),logsHistorial-1;

    nuevo_historial->datosbatalla[logsHistorial -1] = '\0';
    nuevo_historial->siguente = NULL;
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
    while (temp->siguente != NULL) {
        temp = temp->siguente;
    }
    temp->siguente = nuevo_historial;
    nuevo_historial->anterior = temp;
}

void EliminarAlinicioHistorial(historial** inicio) {
    if(*inicio == NULL) {
        printf("no hay datos del historial\n");
        return;
    }
    historial* temp = *inicio;
    *inicio = (*inicio)->siguente;
    if(*inicio != NULL) {
        (*inicio)->anterior = NULL;
    }

    free(temp);
}

void MostrarHistorial(historial* inicio) {
    historial* nuevo_historial = inicio;
    while(nuevo_historial != NULL) {
        printf("%s\n",nuevo_historial->datosbatalla);
        nuevo_historial = nuevo_historial->siguente;
    }
    printf("\n");
}

void crearJugadores();

int main() {

}



