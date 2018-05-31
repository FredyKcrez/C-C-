#include<stdlib.h>
#include<stdio.h>

typedef struct s_str {
char cad;
} STRUCTSTR;
typedef STRUCTSTR *STRING;

STRING S_crear(char X);

STRING S_buscar(STRING S, char Elemento);

STRING S_copiar(STRING cad1, STRING cad2);

int S_calong(STRING S);

STRING S_invcad(STRING cad1, STRING cad2);

void S_impr(STRING S);
