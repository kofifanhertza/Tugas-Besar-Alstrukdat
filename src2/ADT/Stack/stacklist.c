#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"

/* Nama : Salimatussholati Az Zahra
NIM : 18220054
Topik : Stack dalam Representasi List Linier
Tanggal : 10/11/2021
Deskripsi : Implementasi ADT Stack Representasi List Linier */
/* Prototype manajemen memori */
void AlokasiR (addressR *P, Round X) {
    (*P) = (addressR) malloc (sizeof (ElmtStack));
    if ((*P) != Nil) {
        InfoR(*P) = X;
        NextR(*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiR (addressR P) {
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsRSEmpty (RoundStack S){
    return (TopR(S) == Nil);
}
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyRS (RoundStack * S) {
    TopR(*S) = Nil;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void PushR (RoundStack * S, infotypeR *X) {
    addressR P;
    AlokasiR(&P, *X);
    if (P != Nil) {
        NextR(P) = TopR(*S);
        TopR(*S) = P;
    }
}
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void PopR (RoundStack * S, infotypeR * X) {
    addressR P;
    P = TopR(*S);
    (*X) = InfoR(P);
    TopR(*S) = NextR(TopR(*S));
    NextR(P) = Nil;
    DealokasiR(P);
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */