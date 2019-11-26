#ifndef _BATALLANAVAL_H_
#define _BATALLANAVAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
struct Matriz
{
  int x;
  int y;
  int aciertos;
  int dato;
  struct Matriz *siguiente;
  struct Matriz *anterior;
};

struct Matriz * crearmatriz(struct Matriz *);
struct Matriz *generarcoordenadas(struct Matriz *); 
struct Matriz *insertar (struct Matriz *, int, int, int);
struct Matriz *ColocarArriba (struct Matriz *, int, int, int);
struct Matriz *ColocarAbajo (struct Matriz *, int, int, int);
struct Matriz *ColocarIzquierda (struct Matriz *, int, int, int);
struct Matriz *ColocarDerecha (struct Matriz *, int, int, int);
struct Matriz *tablero(struct Matriz *);
void mostrar(struct Matriz *);
struct Matriz *coordenadas(struct Matriz *, int );
struct Matriz *comenzar(struct Matriz *, int);
void menu();
struct Matriz *colocacion(struct Matriz *, int);
void instrucciones();

struct Matriz *aleatorios(struct  Matriz *);

void vs();
void campodebatalla(struct Matriz *);

#endif
