/**********************************************************************************************************************
*
* Programa: DibujaHojaCalendario
*
* Descripción:  Este programa imprime la hoja del calendario del mes del año que se introduce como dato.
*               Este programa funciona para cualquier mes de año comprendido entre los años 1601 y 3000.
*
*
**********************************************************************************************************************/

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


bool bisiesto ( int anno ) { return ((anno % 4 == 0) && (anno % 100 != 0)) || ( anno % 400 == 0 );
}



  /*========================================================
   * Procedimiento para sumar días de la semana cíclicamente
   * =====================================================*/

   TipoDia SumarDias (TipoDia dia , int N) {	                              /* N = el numéro por el que se
                                                                            incrementa la fecha */

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
	   int IncreBisiesto;			/* Incremento en días por años bisiestos */
	   const int AnnoReferencia = 1601;	/* Año a partir del cual determinamos el día */
	   const TipoDia DiaReferencia = Domingo;/* Día a partir del cual determinamos el día*/






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


	   IncreAnnos = A - AnnoReferencia;	                                       /* Cálculo de incremento de días por
                                                                            años completos desde año referencia */


    IncreBisiesto = 0;                                                     /* Añadir dias por años bisiestos */

    for (int N=1602; N<A; N++) {
      if (bisiesto (N)) {
        IncreBisiesto ++;
        }
      }

	   if ( bisiesto (A) && 			                                             /* añadir un día si la fecha a evaluar
                                                                            cae en un ano bisiesto despues del día 29 de
                                                                            febrero */
		( M > Febrero )) {
		   IncreDias ++;
		   }

	   IncreDias = IncreDias + IncreAnnos 	                                  /* Cálculo de incremento total de días */
			+ IncreBisiesto
			+ fecha.dia;


	   return SumarDias (DiaReferencia, IncreDias);
	   }




  /*===========================================
   * Función para calcular el número de dias
   * que contiene un mes
   * ========================================*/

   int DiasDelMes (TipoFecha fecha) {
     switch (fecha.mes) {
       case Febrero:
          if (bisiesto (fecha.anno)) {
            return (29);
          } else { return (28);
          };
          break;
        case Avril:
        case Junio:
        case Setiembre:
          return (30);
          break;
        default:
          return (31);
       }
     }


 /*======================
  * Programa principal
  *====================*/

int main () {

  int mes;
  int ind = 0;                                                           /* contador de carácteres del calendario */
  TipoFecha fecha;
  TipoDia PrimerDia;



/*--- Preguntar datos ---*/

  do  {
    printf ("Mes? (MM)");
    scanf ("%d", &mes);
    } while ((mes < 1) || (mes > 12));

  fecha.mes = TipoMes (mes - 1);

  printf ("Año? (AAAA)");
  scanf ("%d", &fecha.anno);
  fecha.dia = 1;                                                        /* definir el día de la fecha como siendo el
                                                                        primer día del mes */


  if ((fecha.anno > 1600 ) && (fecha.anno <= 3000)) {                    /* El programa no imprime nada para años
                                                                            fuera del rango 1601 al 3000*/

/*--- Dibujar cabecera ---*/

  printf ("\n\n");
  printf ("            ");
  switch (fecha.mes) {
    case Enero:
      printf ("ENERO ");
      break;
    case Febrero:
      printf ("FEBRERO ");
      break;
    case Marzo:
      printf ("MARZO ");
      break;
    case Avril:
      printf ("AVRIL ");
      break;
    case Mayo:
      printf ("MAYO ");
      break;
    case Junio:
      printf ("JUNIO ");
      break;
    case Julio:
      printf ("JULIO ");
      break;
    case Agosto:
      printf ("AGOSTO ");
      break;
    case Setiembre:
      printf ("SETIEMBRE ");
      break;
    case Octubre:
      printf ("OCTUBRE ");
      break;
    case Noviembre:
      printf ("NOVIEMBRE ");
      break;
    case Diciembre:
      printf ("DICIEMBRE ");
      break;
     }
  printf ("%d\n\n", fecha.anno);
  printf ("  LU   MA   MI   JU   VI   SA   DO\n");

/*--- Dibujar cuerpo de la hoja ---*/

 PrimerDia = DiaDeLaSemana (fecha);                                         /* Imprimir blancos si es necesario y
                                                                            actualizar contador */
 for ( int k = int (PrimerDia); k >= 1 ; k -- ) {
   printf ("     ");
   ind = int (PrimerDia);
   }

 for ( int L=1; L <= DiasDelMes (fecha); L++) {                        /* Imprimir todos los días del mes */
   if ( ind % 7 == 0) {                                                     /* Saltar de linea al final de la semana*/
     printf ("\n");
     }
   printf ("  %2d ", L);
   ind ++;
   }
  }
 printf ("\n\n");

}
