/**********************************************************************************************************************
*
* Programa: DibujarCalendario
*
* Descripción:  Este programa imprime la hoja del calendario del mes que se le proporciona como dato.
*               Fechas entre enero 1989 y diciembre 2088.
*
***********************************************************************************************************************/

#include <stdio.h>

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




/*======================================================================
                      Subprogramas
======================================================================*/

  /*--- Procedimiento calcular el día de la semana que corresponde a una fecha ---*/

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


/*======================================================================
                      Programa principal
======================================================================*/

int main () {

  tipofecha hoja;

  /*--- Preguntar datos ---*/



  /*--- Determinar número total de días en el mes ---*/

  switch (hoja.mes) {

    case febrero:

    if (hoja.anno%4==0) {
      TotalDias = 29
      } else {TotalDias = 28;
      }

    break;

    case avril:
    case junio:
    case setiembre:

    TotalDias = 30;
    break;

    default:
    TotalDias = 31;
    }





  }
