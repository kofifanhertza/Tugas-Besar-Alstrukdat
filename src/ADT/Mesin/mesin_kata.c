# include "mesin_kata.h"
# include "map.h"
# include <stdio.h>

static FILE * pita;
Kata CKata;

void IgnoreBlank() {
    while ((CC == ' ' || CC == '\n') && EndKata != true) {
        ADV();
    } 
}


Player readPlayer(Player P){
    int i,k=0;
    int temp=0;
    while ((EndKata != true)) {
            i += 1;
            int j;
            if (i == 1) {
                P.Length = intConverter(CKata);
                ADVKATA();
            } else if (i == 2) {
                for(j=IdxMin;j<=P.Length;j++) {
                    P.Map[j] =  CKata.TabKata[j];}
                ADVKATA(); //untuk ngecopas CKata yang isinya '.' sama '#' ke array peta. M.TI adalah peta
            } else if (i == 3) {
                temp = intConverter(CKata);
                P.MaxRoll = temp;
                EndKata = true;
            }  
     }  
 
    return P;
}
Tele readTele(Tele T){
    int i;
    EndKata = false;
    ADVKATA();
    T.bykTele = intConverter(CKata);
    for(i=IdxMin;i<=T.bykTele;i++){
        ADVKATA();
        T.BeforeTele[i] = intConverter(CKata);
        ADVKATA();
        T.AfterTele[i] = intConverter(CKata);    
    }
    return T;
}
void SalinKata() {
    int i;
    i = 1;
    while ((EndKata != true) && (CC != '\n') && (i < NMax) && (CC != BLANK)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
}


void STARTKATA() {
    START();
    IgnoreBlank();
    if (EndKata != true){
        SalinKata();
    }
}

void ADVKATA() {
    IgnoreBlank();
    if (EndKata != true) {
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