#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define nameMax 20

//S43G 4/10/2026
typedef struct{
    char nombre[nameMax];
    int nivel;
    bool orden;
} jugador; //Estructura del jugador y sus estadisticas

typedef struct {
    int arr[60];
    int top;
} deck; //Estructura del mazo del jugador

typedef struct {
    struct carta;
    struct mano* next;
    struct mano* prev;

}mano; //mano del jugador

typedef struct  {
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

void crearJugadores()

int main() {


}



