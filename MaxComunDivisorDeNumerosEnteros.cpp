
/***************************************************************************************************************
* Programa: MaximoComunDivisorDeNumerosEnteros
*
* Descripción:  Programa que calcula el máximo común divisor de dos números enteros.
*              
***************************************************************************************************************/

#include <stdio.h>

int main () {

  int 	divisor = 1;
  int 	PrimNum, SegNum, NuMayor, NuMenor;
  
  
/*=============================================================================================================
												LEER NÚMEROS
=============================================================================================================*/

  printf ("Primer Número?\n");
  scanf ("%5d", &PrimNum);
  printf ("Segundo Número?\n");
  scanf ("%5d", &SegNum);
  
/*=============================================================================================================
												IMPRIMIR EL RESULTADO
=============================================================================================================*/ 

  /*--- Ordenar los números ---*/
  if (PrimNum > SegNum){
	  NuMayor = PrimNum;
	  NuMenor = SegNum;
  } else {
	  NuMayor = SegNum;
	  NuMenor = PrimNum;
	  }
    
   /*--- efectuar todas la divisiones y actualizar divisor ---*/ 
    
    for ( int k=1; k<= NuMayor; k++){
	  if ( (NuMayor % k == 0 ) && ( NuMenor % k == 0 ) ){
		  divisor = k;	
	  }		
	}		

  /*--- Impresión del resultado ---*/

  printf ("El máximo común divisor es %5d", divisor);
}
