/******************************************************************************************************************************************
*
* Programa: Mostrador2
*
* Descripción:  Versión mas completa del programa ya presentado en el tema 10 para realizar la gestión de las plazas
*               de un avión e imprimir las tarjetas de embarque. Ahora se puede asignaar una plaza del avión de manera
*               individual. También se puede reservar un grupo de dos a seis plazas de forma automática asignando
*                asientos de la misma fila cuando sea posible.
*
*
*                            SIN ACABAR !!!!! falta el debugging  
******************************************************************************************************************************************/

#include <stdio.h>
#include <ctype.h>

/*** Variables y tipos del programa ***/

const int NumFilas = 10;                                            /* número de filas del avión */
const int AsientosFila = 6;                                         /* número de asientos por fila */
const int pasillo = AsientosFila / 2;                              /* determinar el asiento de se situa despues del pasillo */

typedef enum TipoEstado {vacio, ocupado, reservado};
typedef TipoEstado TipoOcupa [AsientosFila];                        /* tipo que contiene para cada asiento un TipoEstado */
typedef struct  TipoFila {                                          /* tipo que corresponde a una fila con 5 campos */

  TipoOcupa AsientoCabina;                                           /* dato que contiene el estado de cada asiento */
  int juntas;                                                       /* plazas seguidas sin pasillo por medio */
  int desde;                                                        /* primera plaza libre de "juntas" */
  int juntasP;                                                      /* plazas seguidas con pasillo por medio */
  int desdeP;                                                       /* primera plaza libre de "juntasP" */

};

typedef TipoFila TipoPlazas [NumFilas];                             /* variable que designa todas las filas del avión */



/*** Subprogramas ***/

void CalcularPlazasJuntas ( TipoFila & fila ) {

  int juntas = 0;
  int juntasP = 0;                                                  /* iniciar variables internas al subprograma, que contienen
                                                                    número de plazas libres, a 0 */

  fila.juntas = 0;                                                  /* iniciar el número de plazas libres de cada fila a 0 */
  fila.juntasP = 0;

  for (int j = 0; j < AsientosFila; j++ ) {                         /* para cada asiento de la fila */
    if ( j == pasillo ) {                                           /* actualizar las plazas juntas a 0 si el asiento considerado
                                                                    esta justo despues del pasillo */
      juntas = 0;
      }
    if (fila.AsientoCabina [j]  == vacio) {
      juntas ++;
      juntasP ++;                                                   /* si el asiento considerado está vacío, actualizar las variables
                                                                    de plazas libres juntas */
      if ( juntas > fila.juntas ) {                                 /* actualizar el número de plazas libres de la fila con el valor
                                                                    mayor que la variable interna al subprograma consiga */
        fila.juntas = juntas;
        fila.desde = j - juntas + 1;                                /* actualizar la primera plaza libre de la fila para cada variable
                                                                    de asientos libres */
        }

      if ( juntasP > fila.juntasP) {
        fila.juntasP = juntasP;
        fila.desde = j - juntasP + 1;
      }
    } else {
        juntas = 0;
        juntasP = 0;                                                /* mientras los asientos considerados no esten vacíos, mantener los valores
                                                                    de las variables correspondientes a 0 */
    }

  }
}

void ImprimirTarjeta ( int fila, char LetraFila ) {

  LetraFila = toupper (LetraFila);

  printf (".----------------------------.\n");
  printf ("|     TARJETA DE EMBARQUE    |\n");
  printf ("|   Fila :%3d  Asiento :%3c  |\n", fila, LetraFila);
  printf ("'----------------------------'\n\n");
  }

void ImprimirCabina ( const TipoPlazas P ) {

  const char SimboloAsiento [3] = { ' ', '#', 'R' };                /* los tres valores que puede adoptar el simbolo de un asiento*/

  printf ("     A   B   C      D   E   F\n\n");
  for (int ind = 0; ind < NumFilas; ind ++) {                       /* imprimir cada fila */
    printf ("%3d", ind + 1 );
    for (int ass = 0; ass < AsientosFila; ass++ ){                  /* imprimir cada asiento */
      if (ass == pasillo) {                                         /* si el asiento a imprimir esta despues del pasillo,
                                                                    imprimir un pasillo primero */
        printf ("   ");
      }
      printf (" (%c)", SimboloAsiento                               /* imprimir el simbolo de asiento correspondiente a su valor estado */
      [P[ind].AsientoCabina [ass]]);
    }
     printf ("\n");                                                 /* saltar de linea cuando se hayan imprimido todos los asientos
                                                                    de una fila */
  }
  printf ("\n");                                                    /* imprimir un salto de linea despues de imprimir la cabina */
}

bool MarcarPlazasJuntasConPasillo
    ( int candidatos, TipoFila &fila) {                             /* procedimiento para reservar plazas juntas con pasillo por
                                                                    medio*/
  if (candidatos > fila.juntasP) {
    return false;
  } else {
  for ( int k = 1; k <= candidatos; k++   ) {
    fila.AsientoCabina [fila.desdeP+k-1] = reservado;
    }
  return true;
  }
}

bool MarcarPlazasJuntas	( int numero, TipoFila & fila) {			/* procedimiento para reservar plazas contiguas */
  if (fila.juntas < numero) {										/* interrumpir el procedimiento si no quedan plazas juntas suf.*/
	  return false;
  } else {
	for (int j = 1;  j <= numero; j++) {							/* cambiar el estado de los asientos necesarios a partir del 
																	primer asiento libre de la fila */
		fila.AsientoCabina[fila.desde+j-1] = reservado;
	}
	return true;  
  }
}											

void MarcarPlazas (int &numero, TipoFila &fila) {
	int j = 0;
	
	while (numero > 0 && j < AsientosFila ) {
		fila.AsientoCabina [j] = reservado;
		numero --;
	}	
}

bool BuscarPlazas (int nuevas, int libres, TipoPlazas filx ) {      /* procedimiento para buscar y reservar
																	automáticamente plazas para grupos */
  int fila;

  if (nuevas <= libres) {											/* buscar plazas juntas */
	fila = 0;
	while (fila < NumFilas) {
	  if (MarcarPlazasJuntas ( nuevas, filx [fila])) {
		  return true;
	  } 
	  fila ++;	
	}
	
	fila = 0;														/* buscar plazas juntas pero con pasillo por medio*/
	while (fila < NumFilas) {
	  if (MarcarPlazasJuntasConPasillo (nuevas, filx [fila]))	{
		return true;  
	  }
	  fila++;
	}
	
	fila = 0;
	while (nuevas > 0 ) {
		MarcarPlazas (nuevas, filx [fila]);		
	}
	return true;  	  	
  } else {
	printf ("No hay plazas suficientes\n");  
  }
  return false;
}  

void ConfirmarPlazas (bool ok, TipoPlazas fila) {

  bool cambio;                                                        /* variable para iniciar la actualización de las plazas libres
                                                                      contiguas en caso de que se confirme el uso de las plazas
                                                                      reservadas */

for (int fil = 0; fil < NumFilas; fil++) {                            /* examinamos cada fila */
  cambio = false;
  for (int ax = 0; ax < AsientosFila; ax++) {                         /* examinamos cada asiento de la fila */
    if (fila [fil].AsientoCabina [ax] == reservado ) {
      if (ok) {                                                       /* si se confirma el uso de los asientos reservados*/
        fila [fil].AsientoCabina [ax] = ocupado;
        ImprimirTarjeta (fil+1, char ( ax + int ('A') ));
        cambio = true;
      } else {                                                         /* si se cancela la reserva de los asientos */
        fila [fil].AsientoCabina [ax] = vacio;
        }
      }
    }
    if (cambio) {
      CalcularPlazasJuntas (fila [fil]);
    }
  }
}

/*** Programa principal ***/

int main () {

  int SitiosLibres;
  int aux;
  int fil, col;                                                     /* variable para almacenar respuestas del usuario */
  char car;                                                         /* variable para almacenar respuestas del usuario */
  TipoPlazas EstadoCabina;                                          /* variable que representa todas las filas del avión */
  bool seguir;


    /*--- Iniciar todo vacío ---*/

    SitiosLibres = NumFilas * AsientosFila;                         /*  iniciar la variable que contiene el número de asientos libres con el
                                                                    el número total de asientos en el avión */
    for (int i = 0; i < NumFilas; i ++ ) {
      for (int j = 0; j < AsientosFila; j ++ ) {
        EstadoCabina [i].AsientoCabina [j] = vacio;                      /* iniciar cada asiento de cada fila como vacío */
      }
      CalcularPlazasJuntas ( EstadoCabina [i] );                          /* para cada fila calcular dos tipos de plazas libres y actualizar los
                                                                    datos de cada fila  */
      }

    /*--- Bucle de operaciones ---*/

    seguir = true;                                                  /* iniciar la variable de control de uso del programa*/
    while (seguir) {

      printf ("¿Opción (Plaza, Grupo, Estado, Fin)?");
      scanf (" %c", & car );
      car = toupper (car);                                          /* cambiar cualquier tipo de letra a mayuscula */

      switch (car) {

        /*--- Asignar una plaza determinada ---*/
          case 'P':
            do {                                                    /* preguntar coordenadas asiento y solo aceptar respuestas correctas */
              printf ("¿Fila (de 1 a 10)?");
              scanf ("%d", &aux );
            } while ( aux<1 || aux>10 );
            do {
              printf ("¿Asiento (de A a F)?");
              scanf (" %c", &car);
              car = toupper (car);                                  /* cambiar respuesta a mayúscula */
            } while ( car < 'A' || car > 'F' );

            fil = aux - 1;                                          /* convertir respuesta */
            col = int (car - 'A');                                  /* convertir letra a su correspondiente número y substraerle el valor
                                                                    númerico de A para obtener un número orden donde A es 0*/

            if (EstadoCabina[fil].AsientoCabina [col] == vacio) { /* asignar plaza si el asiento esta disponible */
              EstadoCabina[fil].AsientoCabina [col] = ocupado;
              SitiosLibres --;
              CalcularPlazasJuntas ( EstadoCabina [fil]);
              ImprimirTarjeta ( fil + 1, char (col + int ('A')));     /* llamar procedimiento ImprimirTarjeta con argumentos correctos
                                                                      es decir un número de fila y una letra de asiento */
            } else {
              printf ("Plaza OCUPADA \n");
            }
            break;

        /*--- Asignar automáticamente plazas contiguas ---*/

          case 'G':
            do {                                                    /* preguntar plazas a asignar hasta obtener una respuesta aceptable */
              printf ("¿Número de plazas (de 2 a 6)?");
              scanf ("%d", &aux);
            } while (aux < 2 || aux > 6);

            if (BuscarPlazas ( aux, SitiosLibres, EstadoCabina)) {
              ImprimirCabina ( EstadoCabina );
              printf ("¿Confirmar (S/N)? ");
              scanf (" %c", &car );
              if (toupper (car) == 'S') {
                ConfirmarPlazas (true, EstadoCabina);
                SitiosLibres = SitiosLibres - aux;
              } else {
                ConfirmarPlazas (false, EstadoCabina);
              }
            }
            break;

        /*--- Dibujar estado de ocupación ---*/

          case 'E':
            ImprimirCabina (EstadoCabina);
            break;

        /*--- Finalizar el programa ---*/

          case 'F':
            seguir = false;                                           /* cambiar la variable de control de uso del programa */
            break;

      }

    }
}

