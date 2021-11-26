/* File : stacklist.h */
#ifndef _STACKLIST_H
#define _STACKLIST_H

#include "boolean.h"
#include <stdlib.h>
#include "../PlayerMap/map.h"
#include <string.h>
/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */


/* Stack dengan representasi berkait dengan pointer */


/* Type stack dengan ciri TOP : */
/*
typedef struct { 
  address TOP;  /* alamat TOP: elemen puncak
} Stack;*/

typedef struct {
  User Player[2]; /* tabel penyimpan elemen */
  int rondeN;
  /* alamat TOP: elemen puncak */
} roundInfo;

typedef struct tElmtStack * addressR;
typedef struct tElmtStack { 
  roundInfo Info;
  addressR Next;
} ElmtRound; 

typedef struct {
  addressR TOP;
} Round;

/* Selektor */
#define CurrRonde(S) (S).TOP->Info //Element roundInfo
#define TopR(S) (S).TOP
#define InfoTopR(S) (S).TOP->Info 
#define NextR(P) (P)->Next
#define InfoR(P) (P)->Info

extern Round Base;
extern int rondeKe;
extern boolean undo;



/* Prototype manajemen memori */
void AlokasiR (addressR *P, roundInfo X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiR (addressR P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsRSEmpty (Round S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyRS (Round * S);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void PushR(Round * S, roundInfo X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void PopR(Round * S, roundInfo * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

//void CreateEmptyRound (Round *R);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
//boolean IsEmpty (Round R);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
//boolean IsFull (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
User AddU (User *U, User *U1);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
//void PopU (Stack * S, User P2);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
//void saveRound(User *U1, User *U2, Round *R, Round *Game);

#endif