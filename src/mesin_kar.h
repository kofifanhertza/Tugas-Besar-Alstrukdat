/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"
extern boolean EndKata;
/* State Mesin */
extern char CC;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != EndKata maka EOP akan padam (false)
          Jika CC = EndKata maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != EndKata
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = EndKata
          Jika  CC = EndKata maka EOP akan menyala (true) */
#endif