#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define nameMax 20
#define logsHistorial 150

typedef struct jugador{
    char nombre[nameMax];
    int nivel;
    int orden;
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

typedef struct  criatura{
    char nombre[nameMax];
    char tipo[nameMax];
    int nivel;
    int hp;
    int ataque;
}criatura; //Las cartas del juego

typedef struct nodeMano {
    criatura carta;
    struct nodeMano* siguiente;
} nodeMano;



typedef struct tablero {
    struct criatura* criaturaInvocada;
    struct tablero* siguiente;
}tablero;

//Creacion de las Criaturas

criatura plantillas[] = {
    { "Lobo Plateado", "atacante", 1, 3, 2 },
    { "Tortuga Terrestre", "tanque", 1, 5, 0 },
    { "Aguila Real", "atacante", 1, 2, 3 }
};

//Fin de la creacion de las criaturas

//Creacion del deck
deck* CrearDeck() {
    deck* mazo = malloc(sizeof(deck));
    int indice;
    int aleatorio;
    int temporal;

    if(mazo == NULL) {
        return NULL;
    }

    for(indice = 0; indice < 60; indice++) {
        mazo->arr[indice] = indice % 3;
    }

    for(indice = 59; indice > 0; indice--) {
        aleatorio = rand() % (indice + 1);

        temporal = mazo->arr[indice];
        mazo->arr[indice] = mazo->arr[aleatorio];
        mazo->arr[aleatorio] = temporal;
    }

    mazo->top = 59;
    return mazo;
}

int PopDeck(deck* mazo) {
    if(mazo->top < 0) {
        return -1;
    }

    return mazo->arr[mazo->top--];
}


// Fin del creacion del deck


jugador* CrearJugador(char nombre[], int n_orden) {
    jugador* nuevo_jugador = malloc(sizeof(jugador));

    if(nuevo_jugador == NULL) return NULL;

    //copia el contenido del string a la propiedad de la structura
    strcpy(nuevo_jugador->nombre, nombre);

    //evita el desborde en la propiedad y garantiza que este terminado correctamente
    nuevo_jugador->nombre[nameMax - 1] = '\0';
    nuevo_jugador->nivel = 0;
    nuevo_jugador->orden = n_orden;
    return nuevo_jugador;
}



//Creacion de la mano//Pila

// Mete carta arriba (Push)
void PushMano(nodeMano** tope, criatura nuevaCarta) {
    nodeMano* nuevo = malloc(sizeof(nodeMano));
    if (nuevo == NULL) return;

    nuevo->carta = nuevaCarta;
    nuevo->siguiente = *tope;
    *tope = nuevo;
}

//  Saca la primera carta (Pop)
criatura PopMano(nodeMano** tope) {
    criatura vacia = {"", "", 0, 0, 0};
    if (*tope == NULL) return vacia;

    nodeMano* temp = *tope;
    criatura sacada = temp->carta;

    *tope = temp->siguiente;
    free(temp);

    return sacada;
}

// Contar cartas
int ContarMano(nodeMano* tope) {
    int total = 0;

    while (tope != NULL) {
        total++;
        tope = tope->siguiente;
    }
    return total;
}

// 4. Muestra la mano
void MostrarMano(nodeMano* tope) {
    if (tope == NULL) {
        printf("La mano esta vacia\n");
        return;
    }

    int i = 1;
    while (tope != NULL) {
        printf("[%d] %s | Tipo: %s | Nivel: %d | HP: %d | ATK: %d\n",i, tope->carta.nombre, tope->carta.tipo, tope->carta.nivel, tope->carta.hp, tope->carta.ataque);
        tope = tope->siguiente; //Se pas a la siguiente
        i++;
    }
}

// 5. Sacar Carta
criatura SacarCartaMano(nodeMano** tope, int posicion) {
    criatura SacarCartaMano(nodeMano** tope, int posicion) {
        criatura vacia = {"", "", 0, 0, 0};
        if (*tope == NULL || posicion < 1)
            return vacia;


        if (posicion == 1)
            return PopMano(tope);

        nodeMano* temp = *tope;
        nodeMano* anterior = NULL;

        // Se avanza hasta la posicion
        for (int i = 1; i < posicion && temp != NULL; i++) {
            anterior = temp;
            temp = temp->siguiente;
        }

        //
        if (temp == NULL)
            return vacia;

        // Se junta el nodo anterior y el siguiente
        anterior->siguiente = temp->siguiente;

        criatura sacada = temp->carta;
        free(temp);

        return sacada;
    }//Fin de sacar carta de mano

    // Liberar Memoria
    void LiberarMano(nodeMano** tope) {
        while (*tope != NULL) {
            nodeMano* temp = *tope;
            *tope = (*tope)->siguiente;
            free(temp);
        }
    }




}//Fin de Sacar carta de mano


//Fin de la mano



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
    char nombre[nameMax];
    jugador* jugadores[2]; //aqui se guardan los jugadores
    for (int i = 0; i < 2; i++) { //i es el orden de los jugadores
        printf("Ingrese el nombre del jugador %d: \n",i+1);
        scanf("%s",nombre);
        jugadores[i]= CrearJugador(nombre,i);
    }

    printf("\nverificacion:\n");
    for (int i = 0; i < 2; i++) {
        printf("Jugador: %s | Orden asignado: %d | Nivel: %d\n",
                jugadores[i]->nombre,
                jugadores[i]->orden,
                jugadores[i]->nivel);
    }

    return 0;

}