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
  int datoex;
  int dato;
  struct Matriz *siguiente;
  struct Matriz *anterior;
};

struct Matriz *crearmatriz (struct Matriz *);
struct Matriz *generarcoordenadas (struct Matriz *);
struct Matriz *insertar (struct Matriz *, int, int, int);
struct Matriz *ColocarArriba (struct Matriz *, int, int, int, int, int);
struct Matriz *ColocarAbajo (struct Matriz *, int, int, int, int, int);
struct Matriz *ColocarIzquierda (struct Matriz *, int, int, int, int, int);
struct Matriz *ColocarDerecha (struct Matriz *, int, int, int, int, int);
struct Matriz *tablero (struct Matriz *);
struct Matriz *coordenadas (struct Matriz *, int, int);
struct Matriz *comenzar (struct Matriz *, int);
struct Matriz *colocacion (struct Matriz *, int);
struct Matriz *aleatorios (struct Matriz *, int);
struct Matriz *ledio (struct Matriz *, struct Matriz *, int, int, int);
struct Matriz *coordenadasatacar (struct Matriz *, struct Matriz *, int);
void iniciar (struct Matriz *, struct Matriz *, int);
int gano (struct Matriz *);
void mostrar (struct Matriz *, int);
void menu ();
void instrucciones ();
void vs ();
void campodebatalla (struct Matriz *);
void recolocar (struct Matriz *, int, int);
void dio (struct Matriz *, struct Matriz *, int);
void fallo ();
void gane_ ();
void salir ();
#endif
