#include <stdlib.h>
#define MAXTAMQ 100

typedef struct
{
    TipoDato Elemento[MAXTAMQ];
    int frente, final;
} Cola;

/* Operaciones sobre la Cola */
void crearCola(Cola* cola);
Cola *crearColaDim();
void insertar(Cola* cola, TipoDato elemento);
TipoDato quitar(Cola* cola);

/* Operacion de acceso a Cola */
TipoDato frente(Cola cola);

/*Verificacion de estado de la cola */
int colaVacia(Cola cola);
int colaLlena(Cola cola);
