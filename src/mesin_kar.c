/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesin_kar.h"
#include <stdio.h>

char CC;
boolean EOP;
boolean EndKata;
static FILE * pita;
static int retval;

void START() {
    pita = fopen("config.txt", "r");
    EOP = false;
    ADV();
}

void ADV() {
   retval = fscanf(pita, "%c", &CC);
   EOP = (EndKata == true);
   if (EOP) {
      fclose(pita);
   }
}