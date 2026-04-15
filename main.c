#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define nameMax 20
#define logsHistorial 150

typedef struct jugador{
    char nombre[nameMax];
    int vida;
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

typedef struct mano{
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

int main() {
    //ejemplo
    jugador* jugador1 = CrearJugador("el sabueso");
    historial* datosJ1 = CrearDatosHistorial("hizo 2 ataques");

    printf("[%s]: %s \n",jugador1->nombre,datosJ1->datosbatalla);

    free(jugador1);
    free(datosJ1);
    //-------------------
}