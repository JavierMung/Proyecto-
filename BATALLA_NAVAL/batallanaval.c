#include "batallanaval.h"

/*------------------------SE GENERA MATRIZ--------------------------------------------*/
struct Matriz*
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
      if (aux->x == x  && aux->y >= y)
	{			//COLOCAR HACIA ABAJO
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

void menu(){
	int op= 0;
	struct Matriz * matriz;
	matriz= NULL;
	printf("                           ***Bienvenido al juego --BATALLA NAVA--***\n");

	printf("\n\t\t\t MENU 	\n");
	printf("-----------------------------\n");
	printf("1. Iniciar Juego\n");
	printf("2. Instrucciones\n");
	printf("3. Salir del Juego\n");
	while(1){
		scanf("%d", & op);
		if(op >3 || op < 1){
		printf("Seleccion invalida-");
		}
		else{
			break;
		}
	}
	switch(op){
		
		case 1: menu2(); break;
		case 2: instrucciones(); break;
		case 3: printf("Gracias por jugar :D"); 
					exit(1);
			
	
			
	}
}

void menu2(){
	int op=0, x= 0, y= 0, tam= 0;
	system("cls");	
	struct Matriz * matriz;
	matriz= NULL;
	matriz = crearmatriz (matriz);
	matriz = pedir(matriz);
	printf("Antes de comenzar es necesario que indiques donde quieres colacar tu barco y la posicion\n");
	printf("1. Colocar barco Abajo\n");
	printf("2. Colocar Barco Arriba\n");
	printf("3. Colocar Barco Derecha\n");
	printf("4. Colocar Barco Izquierda\n");
	printf("5. Comenzar\n");
	printf("6. SALIR\n");
	scanf("%d",&op);
	switch(op){
		case 1: printf("Dame la coordenada en x: \n");
				scanf("%d", &x);
				printf("Dame la coordenada en y: \n");
				scanf("%d", &y);
				printf("Dime el tamaño del barco: \n");
				scanf("%d", &tam);
				matriz= ColocarAbajo(matriz, x, y, tam);
				break;
		case 2: printf("Dame la coordenada en x: \n");
                                scanf("%d", &x);
                                printf("Dame la coordenada en y: \n");
                                scanf("%d", &y);
                                printf("Dime el tamaño del barco: \n");
                                scanf("%d", &tam);
				matriz= ColocarArriba(matriz, x, y, tam);
				break;	
	}	
		printf("Este es el tablero de juego:       ");
		
				mostrar(matriz); 

}
void instrucciones(){
	system("cls");
	printf("\n\tPara este juego es necesario ... \n ");
	system("pause");
	system("cls");
	menu();
}


