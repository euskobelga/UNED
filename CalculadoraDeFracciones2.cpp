/***********************************************************************
 * Programa: CalculadoraDeFracciones2
 * 
 *    Descripción:	Este programa opera como una calculadora pero con 
 * 		fracciones. Las operaciones que se pueden hacer son
 * 		sumar, restar, multiplicar o dividir. El resultado es
 * 		presentado con una fracción simplificada.
 * 		Este programa siempre utiliza funciones para devolver 
 * 		un resultado de tipo registro.
 * 		Cada operación se realiza entre un valor acumulado y un 
 * 		nuevo operando. Para iniciar una nueva serie de 
 * 		operaciones se pulsa (N) y para finalizar el programa, 
 * 		se pulsa (F)
 * 
 * ********************************************************************/
 
 #include <stdio.h>
 
/***********************************************************************
 *	Declaración de tipos
 **********************************************************************/ 
 
  typedef struct TipoFraccion {
	  int N;					/* Numerador de la fracción */
	  int D; 					/* Denominador de la fracción */
	  };
 
 
 
/***********************************************************************
 *	Procedimiento para simplificar la fracción 
 **********************************************************************/
 
  void SimplificarFraccion (  TipoFraccion &FraccionASimplificar ) {
	  
	  int divisor = 2;
	  
	  while ((divisor <= FraccionASimplificar.N) 
		&& (divisor <= FraccionASimplificar.D)) {
			
			if ((FraccionASimplificar.N % divisor == 0) &&
				(FraccionASimplificar.D % divisor == 0)) {
				FraccionASimplificar.N = 
				FraccionASimplificar.N / divisor;
				FraccionASimplificar.D = 
				FraccionASimplificar.D / divisor;
				}
		  divisor ++;
		  } 
	  
	  } 
 
 
 

	
/***************************************************************************************************
 *	Función para sumar fracciones 
 **************************************************************************************************/
 
  TipoFraccion SumarFraccion (TipoFraccion operando1, TipoFraccion operando2) {
	  
	  TipoFraccion resultado;
	  
	  resultado.N = (operando1.N * operando2.D) + (operando2.N * operando1.D);
	  resultado.D = operando1.D * operando2.D;
	  SimplificarFraccion (resultado);
	  return resultado;	  
	  }
 

	 
/***************************************************************************************************
 *	Procedimiento para restar fracciones 
 **************************************************************************************************/
 
  TipoFraccion RestarFraccion (TipoFraccion operando1, TipoFraccion operando2) {
	  
	  operando2.N = - operando2.N;
	  return SumarFraccion (operando1, operando2);
	  }
   
 

	  
/***************************************************************************************************
 *	Función para multiplicar fracciones 
 **************************************************************************************************/
 
  TipoFraccion MultiplicarFraccion (TipoFraccion operando1, TipoFraccion operando2) {
	  
	  TipoFraccion resultado;
	  resultado.N = operando1.N * operando2.N; 
	  resultado.D = operando1.D * operando2.D;
	  SimplificarFraccion (resultado);
	  return (resultado); 	  
	  }
 

	  	
/***************************************************************************************************
 *	Procedimiento para dividir fracciones 
 **************************************************************************************************/
 
   TipoFraccion DividirFraccion (TipoFraccion operando1, TipoFraccion operando2) {
	  
	  TipoFraccion resultado;
	  resultado.N = operando1.N * operando2.D; 
	  resultado.D = operando1.D * operando2.N;
	  SimplificarFraccion (resultado);
	  return (resultado); 	  
	  }
		
	
 
/***********************************************************************
 *	Procedimiento para leer una fraccion
 **********************************************************************/
 
  void LeerFraccion ( TipoFraccion &fraccion ) {	  
	  scanf ("%d/%d", &fraccion.N, &fraccion.D);
	  SimplificarFraccion (fraccion);
	  }
  
  
/***********************************************************************
 *	Procedimiento para escribir una fraccion como N/D
 **********************************************************************/
 
  void EscribirFraccion (TipoFraccion fraccion) {
	 printf ("%d/%d\n", fraccion.N, fraccion.D);
	 
	 }
 
/***************************************************************************************************
 *	Programa principal
 **************************************************************************************************/	  
	  
  int main() {	 
	
	char  operador = ' ';				  /* Operador o orden de finalizar, iniciar o dar resultado */
	TipoFraccion fraccion;				/* Fraccion de almacenamiento de los valores acumulados*/
	fraccion.N = 0;
	fraccion.D = 0;
	TipoFraccion operando;				/* Nuevo operando */						
								

	
	while (operador != 'F') {
		
		printf ("\n\n");					
		printf (">>");
		scanf (" %c", &operador);
		
		if (operador == 'N') {			/* Reinicializar el acumulador para nuevos calculos*/			
			LeerFraccion (fraccion);		
		} else if (operador == '='){
			printf ("           ");
			EscribirFraccion (fraccion); 
		} else if (operador == '*' ) {
			LeerFraccion (operando);
			fraccion = MultiplicarFraccion 
			(fraccion, operando);
		} else if (operador == '/') {	
			LeerFraccion (operando);
			fraccion = DividirFraccion 
			(fraccion, operando);
		} else if (operador == '+') {
			LeerFraccion (operando);
			fraccion = SumarFraccion (fraccion, operando);
		} else if (operador == '-') {
			LeerFraccion (operando);
			fraccion = RestarFraccion (fraccion, operando);				
		} else { printf ("Pulse N, F, +, -, *, /, o =\n");
		}
	
		
			
	}
	
  }
	
