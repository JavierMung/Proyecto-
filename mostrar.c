#include <stdio.h>
#include <stdlib.h>

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
