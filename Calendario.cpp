/*************************************************************************************************************
 * Programa:	Calendario
 * 
 * Descripción:	Programa para el cálculo del día de la semana que corresponde a una fecha comprendida entre:
 * 		1/1/1989 y 31/12/2088 
 ************************************************************************************************************/
 
 #include <stdio.h>
 
 /*====================
  * Definición de tipos
  *==================*/
  

	  
typedef enum TipoMes {
  Enero, Febrero, Marzo, Avril, Mayo, Junio, Julio, Agosto, Setiembre, Octubre, Noviembre, Diciembre
};
	  
typedef enum TipoDia {
  Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo
};	  
	  
typedef struct TipoFecha {
  int dia;
  TipoMes mes;
  int anno;
};	  
	  
	  
  /*===========================================================================
   * Procedimiento para leer fechas y convertir un mes numérico en valor de mes
   * =========================================================================*/
   
   void LeerFecha ( TipoFecha &fecha ) {
	   
	   int mes;
	   
	   scanf ( "%d/%d/%d", &fecha.dia, &mes , &fecha.anno );
	   fecha.mes = TipoMes (mes-1);
	   if (fecha.anno >= 100) {
		   fecha.anno = fecha.anno % 100;
		   }
	   }
	   
  /*================================
   * Procedimiento escribir fechas
   * =============================*/	
   
   void EscribirFecha ( TipoFecha fecha ) {
	   printf ("%2d/%2d/%2d", fecha.dia, int (fecha.mes +1), fecha.anno);
	   } 
	   
  /*========================================================
   * Procedimiento para sumar días de la semana cíclicamente
   * =====================================================*/
   
   TipoDia SumarDias (TipoDia dia , int N) {	/* N = el numéro por el que se incrementa la fecha */
	   
	   const  int DiasSemana = 7;
	   int aux;
	   
	   aux = (int (dia) + N ) % DiasSemana;	/* Aux = ( Día referencia + incremento ) 
							menos semanas enteras */
	   
	   return TipoDia (aux); 
	   }		   	   
	   
  /*===========================================
   * Procedimiento calcular el día de la semana 
   * que corresponde a una fecha
   * ========================================*/
   
   TipoDia DiaDeLaSemana ( TipoFecha fecha ) {
	      
	   TipoMes M = fecha.mes;
	   int A = fecha.anno;
	   int IncreDias;			/* Incremento en días de la semana */
	   int IncreAnnos; 			/* Incremento en días por años enteros */
	   int IncreBisiestos;			/* Incremento en días por años bisiestos */
	   const int AnnoReferencia = 89;	/* Año a partir del cual determinamos el día */
	   const TipoDia DiaReferencia = Sabado;/* Día a partir del cual determinamos el día*/
	   bool bisiesto;			/* Condición de año bisesto */


	   
	   
	   if (M == Enero) {
		   IncreDias = 0;
	   } else if (M == Febrero ){
		   IncreDias = 3;
	   } else if (M == Marzo ) {
		   IncreDias = 3;
	   } else if (M == Avril ) {
		   IncreDias = 1;
	   } else if (M == Mayo) {
		   IncreDias = 	1;			
	   } else if (M == Junio) {
		   IncreDias =  4;
	   } else if (M == Julio) {
		   IncreDias = 6;
	   } else if (M == Agosto) {
		   IncreDias = 2;
	   } else if (M == Setiembre) {
		   IncreDias = 5;
	   } else if (M == Octubre) {
		   IncreDias = 0;
	   } else if (M == Noviembre) {
		   IncreDias = 3;
	   } else {IncreDias = 5;
	   }
	
	   if (A < AnnoReferencia) {		/* Corrección para años superiores al 2000 */
		   A = A + 100;
		   }
	   bisiesto = ( A / 4 == 0);		/* Definir condición de año bisiesto */	   	
	   IncreAnnos = A - AnnoReferencia;	/* Cálculo de incremento de días por años completos
						desde año referencia */	
	   
	   IncreBisiestos = ( IncreAnnos / 4 );	/* Añadir un día por año bisiesto, y los años bisiestos
						ocurren cada cyclo completo de 4 años (división entera) */
			
	   if ( bisiesto && 			/* añadir un día si la fecha a evaluar cae en un ano 
						bisiesto despues del día 29 de febrero */
		( M > Febrero )) {
		   IncreDias ++;
		   }	   
	   
	   IncreDias = IncreDias + IncreAnnos 	/* Cálculo de incremento total de días */
			+ IncreBisiestos 
			+ fecha.dia;
			
	
	   return SumarDias (DiaReferencia, IncreDias);			
	   }

  /*===========================================
   * Procedimiento escribir día de la semana 
   * ========================================*/	   
   
   void EscribirDia (TipoDia S) {
	   if (S == Lunes) {
		   printf ("Lunes");		   
	   } else if (S == Martes) {
		   printf ("Martes");		
	   } else if (S == Miercoles) {
		   printf ("Miercoles");
	   } else if (S == Jueves) {
		   printf ("Jueves");		 
	   } else if (S == Viernes) {
		   printf ("Viernes");
	   } else if (S == Sabado) {
		   printf ("Sabado");
	   } else  {
		   printf ("Domingo");
	   }
   }
	   
 
 /*===================
  * Programa Principal 
  * ================*/
  
  int main () {
	  
  char tecla;					/* Tecla para decidir si el prog. debe seguir funcionando */
  TipoFecha FechaAEvaluar;			/* Fecha a evalurar */	  

  tecla = 'S';
  while (tecla != 'N') {
	  
	  printf ("¿Día Mes Año (DD/MM/AA)?");
	  LeerFecha ( FechaAEvaluar ); 
	  printf ("Fecha: " );
	  EscribirFecha (FechaAEvaluar); 
	  printf ("    Día de la semana: ");
	  EscribirDia (DiaDeLaSemana (FechaAEvaluar));	  
	  tecla = ' ';				/* Preguntar si se quiere seguir utilizando el prog.*/
	  printf ("\n\n¿Otra Fecha? (S/N)?  ");
	  while ((tecla != 'S') && (tecla != 'N')) {
		  scanf (" %c", &tecla);
		  }
	  
	  }
  }
