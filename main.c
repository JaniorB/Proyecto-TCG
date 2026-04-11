// Created by JaniorB on 4/8/2026.
#include <stdio.h>
#include <stdlib.h>
#define nameMax 20

struct jugador {
    char nombre[nameMax];
    int nivel = 0;
    bool orden;
};

typedef struct criatura {
    char nombre[nameMax];
    char tipo[nameMax];
    int nivel;
    int hp;
    int ataque;
};

criatura lobo{
    char nombre[nameMax] "Lobo Plateado";
    char[ tipo[nameMax] = "atacante";
    int nivel = 1
    int hp = 3;
    int ataque = 2;

};

criatura tortuga{
    char nombre[nameMax] = "Tortuga Terrestre";
    char tipo[nameMax] = "tanque";
    int nivel = 1;
    int hp = 5;
    int ataque = 0;
}

void fusionar();

int main() {

}



