#include "../PlayerMap/map.h"
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

int search (Tele T,User *U);
// menampilkan idx dari U.Curr pada Tele
void Inspectt(Tele T, Player P);
//melakukan command inspect
Tele copyTele(Tele Tawal);
void roll2(User *U, Tele T, Player P);
//melakukan command roll
