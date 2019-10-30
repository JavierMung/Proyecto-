#include <stdio.h>
#include <stdlib.h>

struct Lista
{
  int dato;
  struct Lista *siguiente;
};

void inicializar ();
void mostrar (struct Lista *);
struct Lista *menu (struct Lista *);
struct Lista *insertar (struct Lista *, int, int);
struct Lista *pedir (struct Lista *lista, int opcion);

int
main ()
{
  inicializar ();
  return 0;
}

void
inicializar ()
{
  struct Lista *lista = (struct Lista *) malloc (sizeof (struct Lista));
  lista = NULL;
  menu (lista);
  free (lista);

}

struct Lista *
menu (struct Lista *lista)
{
  int opcion;
  printf
    ("\tMENU\n\n1.Insertar al inicio\n2.Insertar al final\n3.Borrar\n4.mostrar\n5.Salir\n: ");
  scanf ("%d", &opcion);
  switch (opcion)
    {
    case 1:
      system ("clear");
      lista = pedir (lista, opcion);
      menu (lista);
      break;
    case 2:
      system ("clear");
      lista = pedir (lista, opcion);
      menu (lista);
      break;

    case 3:
      printf ("Proximamente\n");
      break;
    case 4:
      system ("clear");
      mostrar (lista);
      menu (lista);
      break;
    case 5:
      system ("clear");
      printf ("Hasta pronto\n");
      return 0;
      break;
    default:
      printf ("\nFavor de ingresar una opcion valida\n");
      menu (lista);
      break;
    }
  return lista;
}

struct Lista *
pedir (struct Lista *lista, int opcion)
{
  int dato = -1;
  printf ("Si no desea ingresar mas datos, presione 0\n");
  while (dato != 0)
    {
      printf ("\nIngrese un dato: ");
      scanf ("%d", &dato);
      if (dato != 0)
	lista = insertar (lista, dato, opcion);
    }
  return lista;
}


struct Lista *
insertar (struct Lista *lista, int dato, int opcion)
{
  struct Lista *aux;
  struct Lista *listanuevaa = (struct Lista *) malloc (sizeof (struct Lista));
  listanuevaa->dato = dato;
  listanuevaa->siguiente = NULL;
  if (lista == NULL)		//Insertar dato si la lista esta vacia
    lista = listanuevaa;
  else
    {
      if (opcion == 1)
	{			//Insertar al inicio
	  listanuevaa->siguiente = lista;
	  lista = listanuevaa;
	}
      else
	{			// Insertar al final
	  aux = lista;
	  while (aux->siguiente != NULL)
	    aux = aux->siguiente;
	  aux->siguiente = listanuevaa;
	}
    }
  return lista;
  free (listanuevaa);
}

void
mostrar (struct Lista *lista)
{
  while (lista != NULL)
    {
      printf ("%d->", lista->dato);
      lista = lista->siguiente;
    }
  printf ("NULL\n");
}
