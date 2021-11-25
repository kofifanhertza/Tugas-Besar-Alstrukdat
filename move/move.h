#include "ADT/PlayerMap/map.h"
/*#ifndef ARRAY_H 
#define ARRAY_H

#define IdxMax 100
#define IdxMin 1


/* Definisi elemen dan koleksi objek 
typedef int IdxType;
typedef char ElType;

typedef int IdxType;
typedef char ElType;
typedef struct
{
   int BeforeTele [IdxMax-IdxMin+1];
   int AfterTele [IdxMax-IdxMin+1];
   int bykTele;
} Tele;*/

int search (Tele T,User P);
int teleport (Tele T, User P);
void Inspectt(Tele T, Player P);
Tele copyTele(Tele Tawal);
void roll2(User *U, Tele T, Player P);
#endif