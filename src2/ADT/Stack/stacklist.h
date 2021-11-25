/* File : stacklist.h */
#ifndef _STACKLIST_H
#define _STACKLIST_H

#include "boolean.h"
#include <stdlib.h>
#include "stackundo.h"
/* Konstanta */
//#define Nil NULL

/* Deklarasi infotype */
typedef Round infotypeR;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * addressR;
typedef struct tElmtStack { 
  infotypeR Info;
  addressR Next; 
} ElmtStack; 

/* Type stack dengan ciri TOP : */
/*
typedef struct { 
  address TOP;  /* alamat TOP: elemen puncak
} Stack;*/

typedef struct {
  addressR TOP;
} RoundStack;
extern RoundStack Game;
/* Selektor */
#define TopR(S) (S).TOP
#define InfoTopR(S) (S).TOP->Info 
#define NextR(P) (P)->Next
#define InfoR(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiR (addressR *P, infotypeR X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiR (addressR P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsRSEmpty (RoundStack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyRS (RoundStack * S);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void PushR(RoundStack * S, infotypeR *X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void PopR(RoundStack * S, infotypeR * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
#endif