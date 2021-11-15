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
	ElType TI [IdxMax-IdxMin+1]; /* penyimpanan isi peta; "." atau "#" atau "*" */
	int Length;
	IdxType curr; 
    int Tele [IdxMax-IdxMin+1]; 
	/* Untuk curr (indeks) = i di TI, apabila Tele[i] == i, brrti tidak ada tele. Kalau Tele[i] != i, 
	nanti TI[i] yg awalnya "*" diubah ke "." lalu TI[Tele[i]] = "*"*/ 
	int MaxRoll;
} Map;


void MakeEmpty (Map *M);

int MapLength (Map M);

int MaxNbEl (Map M);

IdxType GetFirstIdx (Map M);

IdxType GetLastIdx (Map M);
ElType GetElmt (Map M, IdxType i);

ElType GetCurrPlace (Map M); //outputnya IdxType curr
void outputMap(Map M);



#endif