/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesin_kar.h"

#define NMax 100
#define BLANK ' '

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

////////////////////////////////////////////////////////////////////BUAT MAP

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

////////////////////////////////////////////////////////////////////////////////

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void MakeEmpty (Map *M);
void outputMap(Map M);
void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
          
void STARTKATA();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
int intConverter(Kata W);
void readConfig(Map M);

#endif