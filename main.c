// Created by JaniorB on 4/8/2026.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define nameMax 20

//S43G 4/10/2026
typedef struct{
    char nombre[nameMax];
    int nivel;
    bool orden;
} jugador;

typedef struct  {
    char nombre[nameMax];
    char tipo[nameMax];
    int nivel;
    int hp;
    int ataque;
}criatura;

void StatsCriaturasIniciales() {
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

void fusionar();

//funcion donde inciara el juego
void Boot();

int main() {

}



