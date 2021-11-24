#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"

/* Nama : Salimatussholati Az Zahra
NIM : 18220054
Topik : Stack dalam Representasi List Linier
Tanggal : 10/11/2021
Deskripsi : Implementasi ADT Stack Representasi List Linier */
/* Prototype manajemen memori */
void Alokasi (address *P, Round X) {
    (*P) = (address) malloc (sizeof (ElmtStack));
    if ((*P) != Nil) {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address P) {
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsRSEmpty (RoundStack S){
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyRS (RoundStack * S) {
    Top(*S) = Nil;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void PushR (RoundStack * S, infotype X) {
    address P;
    Alokasi(&P, X);
    if (P != Nil) {
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void PopR (RoundStack * S, infotype * X) {
    address P;
    P = Top(*S);
    (*X) = Info(P);
    Top(*S) = Next(Top(*S));
    Next(P) = Nil;
    Dealokasi(P);
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */