#include <stdio.h>
#include <stdlib.h>

struct Matriz
{
  int posicion;
  int x;
  int y;
  int dato;
  struct Matriz *siguiente;
};

void crearmatriz ();
struct Matriz *pedir (struct Matriz *);
struct Matriz *insertar (struct Matriz *, int, int, int);
void mostrar (struct Matriz *);

void
crearmatriz ()
{
  struct Matriz *matrz = (struct Matriz *) malloc (sizeof (struct Matriz));
  if (matrz != NULL)
    {
      matrz = NULL;
      pedir (matrz);
      free (matrz);
    }
  else
    printf ("\n Sin espacio");
}

struct Matriz *
pedir (struct Matriz *matriz)
{
  int i, j,pos=1;
  for (i = 0; i < 10; i++)
    {
      for (j = 0; j < 10; j++)
	{
	  matriz = insertar (matriz, pos, i, j);
		pos++;
	}
    }
  mostrar (matriz);
  return matriz;
}

struct Matriz *
insertar (struct Matriz *matriz, int dato, int x, int y)
{
  struct Matriz *aux;
  struct Matriz *matriznueva =
    (struct Matriz *) malloc (sizeof (struct Matriz));
  if (matriznueva != NULL)
    {
      matriznueva->dato = dato;
      matriznueva->x = x;
      matriznueva->y = y;
      matriznueva->posicion += 1;
      matriznueva->siguiente = NULL;
      if (matriz == NULL)	//Insertar dato si la lista esta vacia
	matriz = matriznueva;
      else
	{
	  aux = matriz;
	  while (aux->siguiente != NULL)
	    aux = aux->siguiente;
	  aux->siguiente = matriznueva;
	}
    }
  else
    printf ("\n Sin espacio");
  return matriz;
}

int
main ()
{
  crearmatriz ();
  return 0;
}

void
mostrar (struct Matriz *matriz)	/*Funcion para darle formato al tablero y colocar los datos */
{
  int i, j, b = 4;
  printf ("\n");
  for (i = 0; i <= 10; i++)

    {
      if (i == 0)
	printf ("     ");

      else
	printf (" %2i  ", i);
    }
  printf ("\n");
  for (i = 0; i < 55; i++)

    {
      if (i < 4)
	printf (" ");

      else
	printf ("_");
    }
  printf ("\n");
  for (i = 0; i < 10; i++)

    {
      printf ("%2i  |", i + 1);
      for (j = 0; j < 10; j++)

	{
	  if (i == 10)

	    {
	      for (i = 0; i < 10; i++)

		{
		  printf (" | %d ", i + 1);
		}
	      printf ("|");
	    }
	  if (matriz != NULL)
	    {
	      printf (" %2d |", matriz->dato);
	      matriz = matriz->siguiente;
	    }
	}
      printf ("\n");
      for (j = 0; j < 55; j++)

	{
	  if (j == b)

	    {
	      printf ("|");
	      b += 5;
	    }

	  else if (j < 4)
	    printf (" ");

	  else if (i == 9)
	    printf ("_");

	  else
	    printf ("-");
	}
      b = 4;
      printf ("\n");
    }
  printf ("\n\n");
}
