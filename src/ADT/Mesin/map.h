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
char CheckPetak (Player P, IdxType i); /* mengecheck kondisi suatu petak dalam peta*/
int GetCurrPlace (Player P); /*mengeluarkan indeks lokasi Player berada */
void ChangeCurrPlace(Player P, IdxType idxAfter); /*memindahkan posisi player*/

#endif