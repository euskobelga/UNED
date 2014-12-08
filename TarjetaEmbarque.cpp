/**********************************************************************************************************************
*
* Programa : TarjetaEmbarque
*
* Descripción: Este programa realiza la gestión automática de los asientos de un avión e imprime
* las tarjetas de embarque. Cuando varios pasajeros solicitan juntos las tarjetas de embarque se
* les asignan asientos de la misma fila. Si no existen asientos de la misma fila se ocupan los
* huecos libres. El número de tarjetas de embarque que se pueden solicitar simultáneamente es como
* máximo de 6.
*
*
**********************************************************************************************************************/

#include <stdio.h>


/*========== Declaración constantes ==========*/

  const int aforo = 60;                                                   /* Número de asientos en el avión */
  const int AsientosFila = 6;                                             /* Número de asientos por fila */
  const int filas = aforo / AsientosFila;

/*========== Declaración tipos ==========*/

  typedef int TipoInfoFilas [ AsientosFila ];


/*========== Subprogramas  ========== */

/*--- Procedimiento Imprimir Tarjeta ---*/

void ImprimirTarjeta ( int fila, int asiento) {

  printf (".----------------------------.\n");
  printf ("|     TARJETA DE EMBARQUE    |\n");
  printf ("|   Fila :%3d  Asiento :%3d  |\n", fila, asiento);
  printf ("'----------------------------'\n\n");
  }

/*--- Procedimiento Buscar Plazas ---*/

void BuscarPlazas (int &AsientosTotal, TipoInfoFilas AsientosLibresFilas, int pax ) {

    int k;
    int PaxSinAsiento = pax;
    int dispo;
    int PrimerAsiento;
    int utilizados;                                                      /* variable de almacenamiento auxiliar*/

  if (pax <= AsientosTotal) {

    k = 0;
    while ( (k < filas) && ( PaxSinAsiento > 0) ) {                       /* Buscar plazas contiguas */
      dispo = AsientosLibresFilas [ k ];
      if (PaxSinAsiento <= dispo) {
        PrimerAsiento = AsientosFila - dispo;
        for ( int M=1; M <= PaxSinAsiento; M++) {
          ImprimirTarjeta (k+1, PrimerAsiento+M);
          }
        AsientosLibresFilas [ k ] = dispo - PaxSinAsiento;
        AsientosTotal = AsientosTotal - PaxSinAsiento;
        PaxSinAsiento = 0 ;
        }
      k ++;
      }
    while (PaxSinAsiento > 0) {                                           /* Si no quedan plazas contiguas, buscar
                                                                          plazas en cualquier fila */
        k = 0;
        dispo = AsientosLibresFilas [k];
        if ( dispo > 0 ) {
          PrimerAsiento = AsientosFila - dispo;
          for ( int M=1; M<=dispo; M++) {
          ImprimirTarjeta (k+1, PrimerAsiento+M);
          }
        utilizados = dispo - PaxSinAsiento;
        AsientosLibresFilas [ k ] = AsientosLibresFilas [ k ] - utilizados;
        AsientosTotal = AsientosTotal - utilizados;
        PaxSinAsiento = PaxSinAsiento - utilizados;
            }
        k ++;
        }
    } else {
    printf ("No quedan asientos libres suficientes\n");
    }

  }


/*--- Procedimiento para mostrar la situación en cabina ---*/

void MostrarCabina (const TipoInfoFilas situacion){
  int pasillo = AsientosFila / 2;

  for ( int k = 0; k < filas; k++ ) {
    for ( int A = AsientosFila; A >= 1; A --){
      if (A == pasillo) {
        printf ("   ");
        }
      if (A > situacion [k]) {
        printf (" (*) ");
      } else {
        printf (" ( ) ");
        }
    }
     printf ("\n");
  }
  }


/*========== Programa principal  ========== */

  int main () {

 TipoInfoFilas AsientosLibresEnFila;
 char tecla;
 int PlazasAAsignar;
 int AsientosLibresTotal = aforo;                                      /* Declaración e inicialización del total
                                                                          de plazas libres*/


 for ( int k = 0; k < filas; k ++){                                    /* Inicializar asientos libres en cada fila*/
    AsientosLibresEnFila [ k ] = AsientosFila;
   }

  do {

  do {
  printf ("Menú : Asignar Asientos (A); Mostrar Cabina (M); Finalizar (F)\n");
  scanf (" %c", &tecla);
  } while ((tecla != 'A') && (tecla != 'M') && (tecla != 'F'));

  switch (tecla) {

    case ('A'):

      do {
      printf ("¿Número de plazas (de 1 a 6)?\n");
      scanf ("%d", &PlazasAAsignar);
      } while ((PlazasAAsignar < 0) || (PlazasAAsignar > 6));

      BuscarPlazas ( AsientosLibresTotal, AsientosLibresEnFila, PlazasAAsignar );
    break;

    case ('M'):

      MostrarCabina (AsientosLibresEnFila);
    break;

    default:
    ;
    }
  } while (tecla != 'F');
}
