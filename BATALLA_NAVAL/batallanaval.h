#ifndef _BATALLANAVAL_H_
#define _BATALLANAVAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

struct Matriz
{
  int x;
  int y;
  int dato;
  struct Matriz *siguiente;
  struct Matriz *anterior;
};

struct Matriz * crearmatriz();
struct Matriz *pedir (struct Matriz *); 
struct Matriz *insertar (struct Matriz *, int, int, int);
struct Matriz *ColocarArriba (struct Matriz *, int, int, int);
struct Matriz *ColocarAbajo (struct Matriz *, int, int, int);
struct Matriz *ColocarIzquierda (struct Matriz *, int, int, int);
struct Matriz *ColocarDerecha (struct Matriz *, int, int, int);
void mostrar(struct Matriz *);
struct Matriz *coordenadas(struct Matriz *, int );
void menu();
void menu2();
void instrucciones();
#endif
