/*****************************************************************************************************************************
 * Programa: EscribirFactorial
 * 
 * Descripción:	Este programa escribe las factoriales de 5 a -2
 * 		y de 6 a 15 para ilustrar el tratamiento de excepciones
 * 		con "try" y "catch".
 * 
 * **************************************************************************************************************************/
#include <stdio.h>
#include <limits.h>


/*****************************************************************************************************************************
 *	Subprogramas
 ****************************************************************************************************************************/
 
int FactorialRobusto (int N) {
	
	int F = 1;
	
	if (N<0) {
		throw 0;
	}  
	for ( int K = 2; K <= N; K++) {
			
			if ( F > (INT_MAX / K)) {
			throw F;
			}
			
			F = F * K;
		}
	return F;

} 

void EscribirFactorial ( int G ) {
	try {	printf ("%2d! vale:%10d\n", G, FactorialRobusto ( G ));
		}
	catch (int e) {
		if (e==0) {
			printf ("%2d! excepción: Factorial de número negativo\n", G);
			}
		else {	printf ("%2d! excepción: Superado el límite al evaluar %2d\n", G, e);
			}
		
		}	
	}


 


/*****************************************************************************************************************************
 *	Programa principal
 ****************************************************************************************************************************/	  
	  
  int main ()	{
	  
	  for (int k=5; k >= -2; k--) {
		  EscribirFactorial ( k );
		  }
	 
	  printf ("\n");
		  
	  for (int k = 6; k <= 15; k++){
		  EscribirFactorial ( k );
		  }
	  }  
