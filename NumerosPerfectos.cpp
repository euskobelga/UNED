/**********************************************************************************************************************
* Programa: NumerosPerfectos
*
* Descripción:  Este programa escribe la lista de números perfectos hasta uno dado, introducido como dato al programa.
*               Un número perfecto es un número cuyo valor es igual a la suma de todos sus divisores incluyendo al 1
*               y sin incluirle a él mismo.
*
**********************************************************************************************************************/

#include <stdio.h>

/*==========================================================
                      Subprogramas
==========================================================*/


/*--- Definición de un Numero Perfecto ---*/



bool NumeroPerfecto ( int numero ) {

  int TotalDivisores = 0;                                 /* Variable de almacenamiento del total de los divisores
                                                              enteros*/

  for (int ind = 1; ind < numero; ind++) {
    if (numero % ind == 0) {
      TotalDivisores = TotalDivisores + ind;
      }
    }
  return (TotalDivisores == numero);


  }

/*==========================================================
                    Programa Principal
==========================================================*/

int main () {

  int limite;                                               /* Número hasta el cual se desea listar los números
                                                            perfectos*/

  printf ("¿Número?\n");
  scanf ("%d", &limite );

  for (int K = 1; K <= limite; K++) {
    if (NumeroPerfecto (K)) {
      printf ("%d\n", K);
      }
    }

  }





