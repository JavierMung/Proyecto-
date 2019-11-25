#include "batallanaval.h"

/*------------------------SE GENERA MATRIZ--------------------------------------------*/
struct Matriz *
crearmatriz ()
{
  struct Matriz *matrz = (struct Matriz *) malloc (sizeof (struct Matriz));
  if (matrz != NULL)
    {
      matrz = NULL;
      return matrz;
    }

  else
    printf ("\n Sin espacio");
  return matrz;
}

/*---------------GENERA LAS COORDENADAS DE LOS BARCOS-----------------------*/
struct Matriz *
pedir (struct Matriz *matriz)
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
  if ((10 - tambarco) < y)
    {

      printf ("Barco demasiado grande \n");
      return matriz;
    }
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
  int cont = 1, aux2 = 1;
  if ((10 - tambarco) < x)
    {
      printf ("Barco demasiado grande:D\n");
      return matriz;
    }

  while (aux != NULL)
    {

      if (aux->y == y && aux->x >= x)
	{
	  if (aux->dato != 0)
	    {
	      printf ("Barco demasiado grande \n ");
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
  printf ("1. Iniciar Juego\n");
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
	  menu2 ();
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

void
menu2 ()
{
  int opcion = 0, x = 0, y = 0, tam = 0;
  system ("clear");
  struct Matriz *matriz;
  matriz = NULL;
  matriz = crearmatriz (matriz);
  matriz = pedir (matriz);
  printf
    ("Antes de comenzar es necesario que indiques donde quieres colocar tu barco y la posicion\n");
  printf ("1. Colocar barco Abajo\n");
  printf ("2. Colocar Barco Arriba\n");
  printf ("3. Colocar Barco Derecha\n");
  printf ("4. Colocar Barco Izquierda\n");
  printf ("5. Comenzar\n");
  printf ("6. SALIR\n");

  printf ("Escoje la opcion: ");
  scanf ("%d", &opcion);
  system ("clear");
  mostrar (matriz);
  switch (opcion)
    {

    case 1:
      printf ("Dame la coordenada en x: \n");
      scanf ("%d", &x);
      printf ("Dame la coordenada en y: \n");
      scanf ("%d", &y);
      printf ("Dime el tamaño del barco: \n");
      scanf ("%d", &tam);
      matriz = ColocarAbajo (matriz, x, y, tam);
      break;
    case 2:
      printf ("Dame la coordenada en x: \n");
      scanf ("%d", &x);
      printf ("Dame la coordenada en y: \n");
      scanf ("%d", &y);
      printf ("Dime el tamaño del barco: \n");
      scanf ("%d", &tam);
      matriz = ColocarArriba (matriz, x, y, tam);
      break;
    case 3:
      printf ("Dame la coordenada en x: \n");
      scanf ("%d", &x);
      printf ("Dame la coordenada en y: \n");
      scanf ("%d", &y);
      printf ("Dime el tamaño del barco: \n");
      scanf ("%d", &tam);
      matriz = ColocarDerecha (matriz, x, y, tam);
      break;
    case 4:
      printf ("Dame la coordenada en x: \n");
      scanf ("%d", &x);
      printf ("Dame la coordenada en y: \n");
      scanf ("%d", &y);
      printf ("Dime el tamaño del barco: \n");
      scanf ("%d", &tam);
      matriz = ColocarIzquierda (matriz, x, y, tam);
      break;
    case 5:
      break;

    case 6:
      system ("exit");

    }
  printf ("Este es el tablero de juego:       ");

  mostrar (matriz);

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
