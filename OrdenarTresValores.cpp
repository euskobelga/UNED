/***********************************************************************
*
* Programa: 	OrdenarTresValores
* 
* Descripción:	Este programa ordena tres valores en orden creciente 
* 				utilizando procedimientos. Este programa permanece en 
* 				un bucle hasta que se indique que no se necesita ordenar 
* 				más datos.
*
***********************************************************************/

#include <stdio.h>
#include <math.h>

/*======================================================================
* 							SUBPROGRAMAS
* ====================================================================*/

/*--- Procedimiento para leer un dato---*/
void LeerDato ( int NumeroDato, int &ValorAsignado ) {
	printf ("¿Dato %d?\n", NumeroDato);
	scanf ("%5d", &ValorAsignado);
	}
	

/*--- Procedimiento para ordenar dos datos---*/	
void OrdenarValores ( int & Valor1, int & Valor2) {
	
	int aux ;
	
	if ( Valor1 > Valor2 ) {
		aux = Valor1;
		Valor1 = Valor2;
		Valor2 = aux;
		
		}
		
	}	


 
/*======================================================================
* 							PROGRAMA PRINCIPAL
* ====================================================================*/


int main () {
	
	char tecla ;
	int ValorA, ValorB, ValorC; 
	
	tecla = 'S';
	while ( tecla == 'S' )  {
		
/*--- Leer los valores a ordenar ---*/				
		
		LeerDato ( 1, ValorA );
		LeerDato ( 2, ValorB );
		LeerDato ( 3, ValorC );
		
/*--- Ordenar Valores---*/		
		
		OrdenarValores ( ValorA, ValorB );
		OrdenarValores ( ValorA, ValorC );
		OrdenarValores ( ValorB, ValorC );
		
/*--- Imprimir el resultado ---*/		
		
		printf ("Datos ordenados = %10d,%10d,%10d\n", 
				ValorA, ValorB, ValorC);
				
/*--- Vaciar tecla y repetir proceso si necesario ---*/				
		
		tecla = ' ';
		
		while ((tecla != 'S') && (tecla != 'N')) {
			printf ("¿ Desea continuar ? (S/N) \n");
			scanf ("%c", &tecla);
			}
		}
	}
