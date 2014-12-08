/**********************************
* NOMBRE: #Iker#
* PRIMER APELLIDO: #Peeters#
* SEGUNDO APELLIDO: #Pradera#
* DNI: #79077647J#
* EMAIL: #ipeeters1@alumno.uned.es#
***********************************/

/***************************************************************************************************************
* Programa: practica_2
*
* Descripción:  Programa que imprime por pantalla rombos concéntricos dibujados con los caracteres '@', 'o', y
*              '.'.
* Limitaciones:   La longitud del lado más externo del rombo, dato de entrada, que consiste en el numéro de
*                 caracteres tiene que ser un número entre 1 y 20.
*
***************************************************************************************************************/

#include <stdio.h>

int main () {

  int lado;                                                   /* longitud del lado más externo del rombo */
  int linea;                                                  /* número de linea */
  int num;                                                    /* contador de carácteres */
  int k;                                                      /* contador de blancos */



  /*=============================================================================================================
                                              LEER EL LADO DEL ROMBO
  ==============================================================================================================*/

  printf ("¿Lado del Rombo?");
  scanf ("%d", &lado);
  printf ("\n");

  /*=============================================================================================================
                                              IMPRIMIR EL ROMBO
  ==============================================================================================================*/

  if ( lado == 1) {
      printf ("@\n");
      }

  if  ( lado > 1) {

    if ( lado <= 20 ){

      /*--- Imprimir triángulo superior ---*/

      for ( int linea = 1; linea <= lado; linea ++ ) {        /* definición del número de lineas en el triangulo
                                                              superior */
        /*--- Imrimir mitad izquierda
        triángulos superiores ---*/

        for ( int k = 1; k <= (lado - linea ); k ++) {        /* imprimir espacios en blanco entre margen y rombo*/
          printf (" ");
          }

        for  (int num = 1; num <= linea; num ++) {            /* definición del número de carácteres en la parte
                                                              superior izquierda del rombo */
          if ( num % 4 == 1){                                  /* secuencia de carácteres que forma la parte superior
                                                              izquierda del rombo */
            printf ("@");
            }
          if ( num % 4 == 2){
            printf (".");
            }
          if ( num % 4 == 3){
            printf ("o");
            }
          if ( num % 4 == 0){
            printf (".");
            }
          }

        /*--- Imprimir mitad derecha
        triángulos superiores ---*/

        for ( int num = linea; num >= 2 ; num -- ){            /* definición del número de carácteres en la parte
                                                                  superior derecha del rombo */

          if ( num % 4 == 2){                                  /* secuencia de caráctres que forman el lado derecho
                                                                  del rombo*/
            printf ("@");
            }
          if ( num % 4 == 3) {
            printf (".");
            }
          if ( num % 4 == 0){
            printf ("o");
            }
          if ( num % 4 == 1){
            printf (".");
            }
          }
        printf ("\n");
        }

      /*--- Imprimir triángulo inferior ---*/

      for ( int linea = 1; linea <= lado ; linea ++){             /* definición del número de lineas en el triangulo
                                                                  inferior */

        /*--- Imprimir mitad izquierda
        triángulos inferior ---*/
        for ( int k = 1;  k <= linea; k ++){                    /* imprimir espacios en blanco entre margen y rombo*/
          printf (" ");
          }
        for (int num = 1 ; num <= ( lado - linea ); num ++ ) {  /*  definición del número de carácteres a imprimir en
                                                                  en la parte inferior izquierda */
          if (num %4 == 1 ){                                    /* definición de la secuencia de carácteres para
                                                                  dibujar la parte inferior izquierda */
            printf ("@");
            }
          if (num %4 == 2 ){
            printf (".");
            }
          if (num %4 == 3 ) {
            printf ("o");
            }
          if (num %4 ==0 ) {
            printf (".");
            }
          }
        /*--- Imprimir mitad derecha
        triángulos inferior ---*/
        for ( int num = (lado - linea); num >= 2; num -- ) {     /* definición del número de carácteres que forman
                                                                    la mitad derecha del triángulo inferior */
          if ( num %4 == 2){                                      /* definición de la secuencia de carácteres para dibujar
                                                                    la mitad derecha del triángulo inferior */
            printf ("@");
            }
          if ( num %4 == 3){
            printf (".");
            }
          if (num %4 == 0){
            printf ("o");
            }
          if (num %4 == 1){
            printf (".");
            }
          }
        printf ("\n");
        }
      }
    }
  }
