#include "batallanaval.h"

/*------------------------SE GENERA MATRIZ--------------------------------------------*/
struct Matriz *
crearmatriz (struct Matriz *matriz)
{
  matriz = (struct Matriz *) malloc (sizeof (struct Matriz));
  if (matriz != NULL)
    {
      matriz = NULL;
      return matriz;
    }

  else
    printf ("\n Sin espacio");
  return matriz;
}

/*---------------GENERA LAS COORDENADAS DE LOS BARCOS-----------------------*/
struct Matriz *
generarcoordenadas (struct Matriz *matriz)
{
  int i, j;
  for (i = 1; i <= 10; i++)
    {
      for (j = 1; j <= 10; j++)
	matriz = insertar (matriz, 0, j, i);
    }

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
      matriznueva->anterior = NULL;

      if (matriz == NULL)
	matriz = matriznueva;
      else
	{
	  aux = matriz;
	  while (aux->siguiente != NULL)
	    aux = aux->siguiente;
	  aux->siguiente = matriznueva;
	  matriznueva->anterior = aux;
	}
      return matriz;
    }
  else
    printf ("\n Sin espacio");
  return matriz;
}

/*----------------COLOCAR HACIA ARRIBA----------------------------------*/
struct Matriz *
ColocarArriba (struct Matriz *matriz, int x, int y, int tambarco,
	       int numbarcos)
{
  struct Matriz *aux = matriz;
  int cont = 1;
  if (tambarco > y || tambarco <= 0)
    recolocar (matriz, numbarcos);
  else
    {
      while (aux != NULL)
	{
	  if (aux->x == x && aux->y >= ((y - tambarco) + 1))
	    {
	      aux->dato = tambarco;
	      if (cont == tambarco)
		break;
	      cont++;
	    }
	  aux = aux->siguiente;
	}
    }
  return matriz;
}

/*----------------COLOCAR HACIA ABAJO-------------------*/
struct Matriz *
ColocarAbajo (struct Matriz *matriz, int x, int y, int tambarco,
	      int numbarcos)
{
  struct Matriz *aux = matriz;
  int cont = 1;
  if ((tambarco + y) > 11 || tambarco <= 0)
    recolocar (matriz, numbarcos);
  else
    {
      while (aux != NULL)
	{
	  if (aux->x == x && aux->y >= y)
	    {
	      if (aux->dato != 0)
		{
		  printf ("Barco demasiado grande\n");
		  return matriz;
		}
	      aux->dato = tambarco;
	      if (cont == tambarco)
		break;
	      cont++;
	    }
	  aux = aux->siguiente;
	}
    }
  return matriz;
}

/*---------------------COLOCAR HACIA LA IZQUIERDA------------------*/
struct Matriz *
ColocarIzquierda (struct Matriz *matriz, int x, int y, int tambarco,
		  int numbarcos)
{
  struct Matriz *aux = matriz;
  int cont = 1;
  if (tambarco > x || tambarco <= 0)
    recolocar (matriz, numbarcos);
  else
    {
      while (aux != NULL)
	{
	  if (aux->x > (x - tambarco) && aux->y == y)
	    {			//COLOCAR IZQUIERDA
	      aux->dato = tambarco;
	      if (cont == tambarco)
		break;
	      cont++;
	    }
	  aux = aux->siguiente;
	}
    }
  return matriz;
}

/*----------------COLOCAR HACIA LA DERECHA-------------------------*/
struct Matriz *
ColocarDerecha (struct Matriz *matriz, int x, int y, int tambarco,
		int numbarcos)
{
  struct Matriz *aux = matriz;
  int cont = 1, aux2 = 1;
  if ((x + tambarco) > 11 || tambarco <= 0)
    recolocar (matriz, numbarcos);
  else
    {
      while (aux != NULL)
	{

	  if (aux->y == y && aux->x >= x)
	    {
	      if (aux->dato != 0)
		{
		  aux = aux->anterior;
		  while (aux2 != cont)
		    {
		      aux->dato = cont - 1;
		      aux = aux->anterior;
		      aux2++;
		    }

		  break;
		}

	      aux->dato = tambarco;
	      if (cont == tambarco)
		break;
	      cont++;
	    }
	  aux = aux->siguiente;
	}
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

void
menu ()
{
  int opcion = 0;
  struct Matriz *matriz;
  matriz = NULL;
  system ("clear");
  printf
    ("\t\t\t\t\t\t***BIENVENIDO A ***\n\n\t\t\t\t\t  ****BATALLA NAVAL ****\n\n\n\n\n\nPresione ENTER para continuar\n");
  __fpurge (stdin);
  getchar ();
  system ("clear");
  printf ("\n\t\t\t MENU 	\n");
  printf ("-----------------------------\n");
  printf ("1. 1 VS 1\n");
  printf ("2. Instrucciones\n");
  printf ("3. Salir del Juego\n");
  printf ("Opcion: ");
  scanf ("%d", &opcion);
  system ("clear");
  if (opcion <= 0 || opcion > 3)
    {
      printf
	("\n\n\n \t\t\t\t\tESCOGA UNA OPCION VALIDA...\t\t\t\t\tPRESIONE ENTER PARA CONTINUAR\n");
      __fpurge (stdin);
      getchar ();
      menu ();
    }
  else
    {
      switch (opcion)
	{

	case 1:
	  vs ();
	  break;
	case 2:
	  instrucciones ();
	  break;
	case 3:
	  printf ("Gracias por jugar :D\n");
	  system ("exit");
	}
    }
}

struct Matriz *
colocacion (struct Matriz *matriz, int numbarcos)
{
  int opcion = 0, cont = 1;
  system ("clear");
  printf ("Tienes : %d Barcos\n¿En donde quieres colocarlo?\n\n", numbarcos);
  printf ("1. Colocar barco Abajo\n");
  printf ("2. Colocar Barco Arriba\n");
  printf ("3. Colocar Barco Derecha\n");
  printf ("4. Colocar Barco Izquierda\n");
  printf ("5. Llenar aleatoriamente y comenzar\n");
  printf ("6. SALIR\n");
  printf ("Escoje la opcion: ");
  __fpurge (stdin);
  scanf ("%d", &opcion);
  system ("clear");
  mostrar (matriz);
  switch (opcion)
    {
    case 1:
      matriz = coordenadas (matriz, opcion, numbarcos);
      break;
    case 2:
      matriz = coordenadas (matriz, opcion, numbarcos);
      break;
    case 3:
      matriz = coordenadas (matriz, opcion, numbarcos);
      break;
    case 4:
      matriz = coordenadas (matriz, opcion, numbarcos);
      break;
    case 5:
      matriz = aleatorios (matriz);
      break;
    case 6:
      exit (-1);
    }


  printf ("ESTE ES TU CAMPO DE JUEGO: \n ");
  mostrar (matriz);

  return matriz;
}

struct Matriz *
coordenadas (struct Matriz *matriz, int direccion, int numbarcos)
{
  int x, y, tambarco;
  printf ("Dame la coordenada en x: \n");
  scanf ("%d", &x);
  printf ("Dame la coordenada en y: \n");
  scanf ("%d", &y);
  printf ("Dime el tamaño del barco: \n");
  scanf ("%d", &tambarco);
  if (direccion == 1)
    matriz = ColocarAbajo (matriz, x, y, tambarco, numbarcos);
  else if (direccion == 2)
    matriz = ColocarArriba (matriz, x, y, tambarco, numbarcos);
  else if (direccion == 3)
    matriz = ColocarDerecha (matriz, x, y, tambarco, numbarcos);
  else
    matriz = ColocarIzquierda (matriz, x, y, tambarco, numbarcos);
  return matriz;
}

void
vs ()
{
  struct Matriz *tablero1;
  struct Matriz *tablero2;
  struct Matriz *tablero3;
  tablero1 = comenzar (tablero1, 1);
  campodebatalla (tablero1);
  tablero2 = comenzar (tablero2, 2);
  campodebatalla (tablero2);

}

void
campodebatalla (struct Matriz *matriz)
{
  system ("clear");
  printf ("\n TU CAMPO DE BATALLA QUEDO ASI:\n");
  mostrar (matriz);
  printf ("\t\t\t\t\t********Presiona ENTER para continuar************\n");
  __fpurge (stdin);
  getchar ();
  system ("clear");
  system ("clear");

}

void
recolocar (struct Matriz *matriz, int numbarcos)
{
  system ("clear");
  printf
    ("\n\n\n\t\t\tELIGUE OTRA COORDENADA O CAMBIA EL TAMAÑO DEL BARCO\n\n\n\n\n");
  printf ("\t\t\t\t\t********Presiona ENTER para continuar************\n");
  __fpurge (stdin);
  getchar ();
  colocacion (matriz, numbarcos);
  system ("clear");
  system ("clear");

}

struct Matriz *
comenzar (struct Matriz *matriz, int jugador)
{
  system ("clear");
  int i;
  matriz = tablero (matriz);;
  printf
    ("\n\n\n\n\n\t\t\t\t\t\t\t**********TURNO DEL %d JUGADOR**********\n\t\t\t\t\t\t\t**********COLOCA TUS BARCOS A CONTINUACION.... \n\n\n\n\t\t\t\t\t\t\t****Presiona la tecla ENTER****",
     jugador);
  __fpurge (stdin);
  getchar ();
  for (i = 5; i >= 1; i--)
    matriz = colocacion (matriz, i);
  return matriz;
}

struct Matriz *
tablero (struct Matriz *tableros)
{
  tableros = crearmatriz (tableros);
  tableros = generarcoordenadas (tableros);
  return tableros;

}

void
instrucciones ()
{
  printf ("\n\tPara este juego es necesario ... \n ");
  printf ("presione enter para continuar: ");
  __fpurge (stdin);
  getchar ();
  menu ();
}

struct Matriz *
aleatorios (struct Matriz *matriz)
{
  int direccion = 0;
  int x, y, tambarco;
  srand (time (NULL));
  direccion = 1 + rand () % (5 - 1);
  x = 1 + rand () % (11 - 1);
  y = 1 + rand () % (11 - 1);
  tambarco = 1 + rand () % (5 - 1);
  if (direccion == 1)
    matriz = ColocarAbajo (matriz, x, y, tambarco, 0);
  else if (direccion == 2)
    matriz = ColocarArriba (matriz, x, y, tambarco, 0);
  else if (direccion == 3)
    matriz = ColocarDerecha (matriz, x, y, tambarco, 0);
  else
    (direccion == 4);
  matriz = ColocarIzquierda (matriz, x, y, tambarco, 0);
  return matriz;
}
