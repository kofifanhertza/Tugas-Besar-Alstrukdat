#include <stdio.h>
#include "stack.h"
/* Nama : Salimatussholati Az Zahra
NIM : 18220054
Program : Queue
Tanggal : 29/09/2021
Deskripsi : Pre-Praktikum */
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
boolean IsFull (Stack S) {
    return ((S).TOP == MaxEl);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X) {
    (*S).TOP += 1;
    (*S).T[(*S).TOP] = X;

}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X) {
    *X = (*S).T[(*S).TOP];
    (*S).TOP = (*S).TOP - 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */