/* Nama : Salimatussholati Az Zahra
NIM : 18220054
LATIHAN MESIN KATA*/

# include "mesin_kata.h"
# include <stdio.h>

static FILE * pita;
boolean EndKata;
Kata CKata;
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
void IgnoreBlank() {
    while ((CC == ' ' || CC == '\n') && CC != EOF) {
        ADV();
    } 
}

/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
Map readConfig(Map M){
    int i = 0;
    while ((CC != MARK)) {
            i += 1;
            int j;
            if (i == 1) {
                M.Length = intConverter(CKata);
                ADVKATA();
            } else if (i == 2) {
                for(j=IdxMin;j<=M.Length;j++) {
                    M.TI[j] =  CKata.TabKata[j];}
                ADVKATA(); //untuk ngecopas CKata yang isinya '.' sama '#' ke array peta. M.TI adalah peta
            } else if (i == 3) {
                M.MaxRoll = intConverter(CKata);
                ADVKATA();
            }
    }
    return M;
}
void SalinKata() {
    int i;
    i = 1;
    while ((CC != MARK) && (CC != '\n') && (i < NMax)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
}

/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
void STARTKATA() {
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
void ADVKATA() {
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        SalinKata();
    }
}

int intConverter(Kata W){
    int result = 0;
    int temp;
    for(int i = IdxMin; i <= W.Length; i++){
        temp = W.TabKata[i] - '0';
        result = result * 10 + temp;
    }
    return result;
}

void MakeEmpty (Map *M){
    (*M).Length = 0;
    (*M).MaxRoll = 0;
    (*M).curr = IdxMin;
}
void outputMap(Map M) {
    // untuk membaca map
    int i;
    for(i=IdxMin;i<=M.Length;i++) {
        printf("%c", M.TI[i]);
    }
    printf("\n");
}