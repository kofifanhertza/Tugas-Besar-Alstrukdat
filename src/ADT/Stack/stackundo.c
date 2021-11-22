#include <stdio.h>
#include "stackundo.h"
#include "boolean.h"
#include "../ADT/Mesin/map.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */

void CreateEmpty (Stack *S) {
    (*S).TOP = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S) {
    return ((S).TOP == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
//boolean IsFull (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushU (Stack * S, User P1) {
    if (!IsEmpty(*S))
    {
        Top(*S)++;
    }
    else
    {
        Top(*S) = 1;
    }
    InfoTop(*S) = P1;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopU (Stack * S, User P2) {
    *P2 = InfoTop(*S);
    Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */