/***********************************************************************                                                          
 * Programa: CalculadoraDeFracciones
 * 
 * Descripción:	Este programa opera como una calculadora pero con 
 * 		fracciones. Las operaciones que se pueden hacer son
 * 		sumar, restar, multiplicar o dividir. El resultado es
 * 		presentado con una fracción simplificada.
 * 		Cada operación se realiza entre un valor acumulado y un 
 * 		nuevo operando. Para iniciar una nueva serie de 
 * 		operaciones se pulsa (N) y para finalizar el programa, 
 * 		se pulsa (F)
 * 
 * ********************************************************************/
 
 #include <stdio.h>
 
 

/***********************************************************************
 *	Procedimiento para simplificar la fracción N/D
 **********************************************************************/

void SimplificarFraccion ( int & Num , int & Den ) {
	
	int divisor = 2;
	
	while ( (divisor <= Num) && (divisor <= Den) ) {
		while ((Num%divisor==0) && (Den%divisor==0)) {
			Num = Num / divisor;
			Den = Den / divisor;
			}
		divisor ++;
		}
	
		
	}
	
/***********************************************************************
 *	Procedimiento para sumar fracciones N3/D3 = N2/D2 + N1/D1
 **********************************************************************/
 
 void SumarFraccion ( int N1, int D1, int N2, int D2, int & N3, int & 
			D3 ){
	 
	 N3 = (N1 * D2) + (N2 * D1);
	 D3 = D1 * D2;
	 
	 SimplificarFraccion (N3, D3);
	 }
	 
/***********************************************************************
 *	Procedimiento para restar fracciones N3/D3 = N2/D2 - N1/D1
 **********************************************************************/
 
  void RestarFraccion (int N1, int D1, int N2, int D2, int & N3, int 
			& D3) {
	  
	  SumarFraccion ( N1, D1, -N2, D2, N3, D3);
	  }
	  
/***********************************************************************
 *	Procedimiento para multiplicar fracciones N3/D3 = N2/D2 * N1/D1
 **********************************************************************/
 
  void MultiplicarFraccion 	(int N1, int D1, int N2, int D2, int & 
				N3, int & D3) {
	  
	 N3 = N2 * N1;
	 D3 = D2 * D1;
	 
	 SimplificarFraccion ( N3, D3);
	  }	 	  
	  	
	  	
/***********************************************************************
 *	Procedimiento para dividir fracciones N3/D3 = N2/D2 * N1/D1
 **********************************************************************/
 
  void DividirFraccion 	(int N1, int D1, int N2, int D2, int & N3, 
				int & D3) {
	N3 = N2 * D1;
	D3 = N1 * D2;
	
	SimplificarFraccion ( N3, D3);				
	}

/***********************************************************************
 *	Procedimiento para leer una fraccion N/D 
 * 	y simplificarla
 **********************************************************************/
 
  void LeerFraccion (int &Num, int &Den) {
	  scanf ("%d/%d", &Num, &Den);
	  SimplificarFraccion ( Num, Den);
	  }
	  

/***********************************************************************
 *	Procedimiento para escribir una fraccion como N/D
 **********************************************************************/
 
 void EscribirFraccion (int N, int D) {
	 printf ("%d/%d\n", N, D);
	 
	 }

/***********************************************************************
 *	Programa principal
 **********************************************************************/	  
	  
int main() {	  
	
 
 char tecla = ' ';			/*tecla de opción*/
 int Num=0; 				/*numerador almacenado*/
 int Den=0; 				/*denominador almacenado*/
 int NN;				/*numerador operando*/
 int DD; 				/*denominador operando*/ 
 

 while (tecla != 'F') {
	 
	 printf (">> ");
	 scanf (" %c", &tecla);
	 
	 
	if (tecla == '+') {
		LeerFraccion (NN, DD);
		SumarFraccion (Num, Den, NN, DD, Num, Den);
		 
	} else if (tecla == '-'){
		LeerFraccion (NN, DD);
		RestarFraccion (Num, Den, NN, DD, Num, Den);
		
	} else if (tecla == '*') {
		LeerFraccion (NN, DD);
		MultiplicarFraccion (Num, Den, NN, DD, Num, Den);
		
	} else if (tecla == '/') {
		LeerFraccion (NN, DD);
		DividirFraccion (Num, Den, NN, DD, Num, Den);
		
	} else if (tecla == 'N') {

		LeerFraccion (Num, Den); 
		
	} else if (tecla == '=') {
		printf ("     ");
		EscribirFraccion (Num, Den);
			 		 
	} else if (tecla != 'F') {
		 printf ("Pulse +,-,/,*, =, N o F\n");
		
		 }		 
	 }

}

