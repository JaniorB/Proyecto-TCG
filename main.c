#include <stdio.h>
#include <stdlib.h>
#define nameMax 20

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
    char datosbatalla;
    struct historial* siguente;
    struct historial* anterior;
}historial;//Estrucuta del historial de batalla de la partida

typedef struct mano{
    struct carta;
    struct mano* next;
    struct mano* prev;

}mano; //mano del jugador

typedef struct  criatura{
    char nombre[nameMax];
    char tipo[nameMax];
    int nivel;
    int hp;
    int ataque;
}criatura; //Las cartas del juego

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

historial* CrearDatosHistorial(char datosbatalla) {
    historial* nuevo_historial = malloc(sizeof(historial));

    if(nuevo_historial == NULL)return NULL;

    nuevo_historial->datosbatalla = datosbatalla;
    nuevo_historial->siguente = NULL;
    nuevo_historial->anterior = NULL;
    return nuevo_historial;
}

void InsertarAlfinal(historial** inicio, char datosbatalla) {
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

void EliminarAlinicio(historial** inicio) {
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
        printf("%c\n",nuevo_historial->datosbatalla);
        nuevo_historial = nuevo_historial->siguente;
    }
    printf("\n");
}

void crearJugadores();

int main() {


}



