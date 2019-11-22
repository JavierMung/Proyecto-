#include "batallanaval.h"

/*------------------------SE GENERA MATRIZ--------------------------------------------*/
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

/*---------------OBTENEMOS COORDENADAS DADAS POR USUARIO--------------------------*/
struct Matriz *
pedir (struct Matriz *matriz)
{
  int i, j, x = 0, y = 0, tam = 0;
  printf ("\nDame el valor de x: ");
  scanf ("%d", &y);
  printf ("\nDame el valor de y: ");
  scanf ("%d", &x);
  printf ("\nDame el tamañano del barco: ");
  scanf ("%d", &tam);
  for (i = 1; i <= 10; i++)
    {
      for (j = 1; j <= 10; j++)
	matriz = insertar (matriz, 0, i, j);
    }
  mostrar (matriz);
  matriz = ColocarArriba (matriz, x, y, tam);
  matriz = ColocarAbajo (matriz, x, y, tam);
  matriz = ColocarIzquierda (matriz, x, y, tam);
  matriz = ColocarDerecha (matriz, x, y, tam);
  mostrar (matriz);
  return matriz;
}

/*-----------------INSERTA LAS COORDENADAS EN CADA NODO, ASI COMO INCIALIZA LAS CASILLAS EN '0'---------------------*/
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
      matriznueva->siguiente = NULL;
      if (matriz == NULL)
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

/*----------------COLOCAR HACIA ARRIBA----------------------------------*/
struct Matriz *
ColocarArriba (struct Matriz *matriz, int x, int y, int tambarco)
{
  struct Matriz *aux = matriz;
  int cont = 1;
  while (aux != NULL)
    {
      if (aux->y == y && aux->x < 10)
	{			//COLOCAR HACIA ARRIBA
	  aux->dato = 1;
	  if (cont == tambarco)
	    break;
	  cont++;
	}
      aux = aux->siguiente;
    }
  return matriz;
}

/*----------------COLOCAR HACIA ABAJO-------------------*/
struct Matriz *
ColocarAbajo (struct Matriz *matriz, int x, int y, int tambarco)
{
  struct Matriz *aux = matriz;
  int cont = 1;
  while (aux != NULL)
    {
      if (aux->y == y && aux->x >= x)
	{			//COLOCAR HACIA ABAJO
	  aux->dato = 2;
	  if (cont == tambarco)
	    break;
	  cont++;
	}
      aux = aux->siguiente;
    }
  return matriz;
}

/*---------------------COLOCAR HACIA LA IZQUIERDA------------------*/
struct Matriz *
ColocarIzquierda (struct Matriz *matriz, int x, int y, int tambarco)
{
  struct Matriz *aux = matriz;
  int cont = 1;
  while (aux != NULL)
    {
      if (aux->x == x && aux->y < 10)
	{			//COLOCAR IZQUIERDA
	  aux->dato = 3;
	  if (cont == tambarco)
	    break;
	  cont++;
	}
      aux = aux->siguiente;
    }
  return matriz;
}

/*----------------COLOCAR HACIA LA DERECHA-------------------------*/
struct Matriz *
ColocarDerecha (struct Matriz *matriz, int x, int y, int tambarco)
{
  struct Matriz *aux = matriz;
  int cont = 1;
  while (aux != NULL)
    {
      if (aux->x == x && aux->y >= y)
	{			//COLOCAR derecha
	  aux->dato = 4;
	  if (cont == tambarco)
	    break;
	  cont++;
	}
      aux = aux->siguiente;
    }
  return matriz;
}

/*------------------------FORMATO DE TABLERO ASI COMO SU DEMOSTRACION------------------*/
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
