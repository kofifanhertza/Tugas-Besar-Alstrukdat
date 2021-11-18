/* Kamus Umum */

#include "boolean.h"

#ifndef ARRAY_H 
#define ARRAY_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1


/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef char ElType;

typedef struct
{
	ElType Map [IdxMax-IdxMin+1]; /* penyimpanan isi peta; "." atau "#" atau "*" */
	int Length;
	IdxType Curr; 
	int MaxRoll;
} Player;

typedef struct
{
   int BeforeTele [IdxMax-IdxMin+1]; /*array BeforeTele berisikan indeks-indeks pada peta yang mengandung teleporter*/
   int AfterTele [IdxMax-IdxMin+1]; /* array AfterTele berisikan indeks letak tujuan teleporter */
   int bykTele;
} Tele;

void SetPlayer (Player P); /* untuk menginisialisasi player dengan peta kosong */
void outputPlayerMap(Player P); /*mengeluarkan peta player*/

#endif