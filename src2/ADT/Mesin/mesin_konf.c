# include "mesin_konf.h"
# include "../PlayerMap/map.h"
# include <stdio.h>

static FILE * pita;
Kata CKata;

void IgnoreBlank() {
    while ((CC == ' ' || CC == '\n') && EndKata != true) {
        ADV();
    } 
}
void readConfig(User *U, Tele *T, char fileconfig[]){
    int i;
    SetUser(U);

    STARTKATA(fileconfig);
    (*U).P = readPlayer((*U).P);
    
    *T = readTele(*T);
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
                P.MaxRollAwal = temp;
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


void STARTKATA(char fileconfig[]) {
    START(fileconfig);
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


void Konfigurasi(char fileconfig[], User *U1, User *U2, Tele *TP){
    //Memulai permainan
    /*
    int nplayer;
    scanf("Masukkan jumlah pemain: %d", &nplayer);

    for(int i = 0;i<nplayer;i++){
        char name;scanf("Masukkan nama pemain: %s",name);
        Player P1;
        Tele TP1;
        readConfig(&P,&TP); 
    }*/
    
    printf("Masukkan Nama Player 1 : ");scanf("%s", ((*U1).Nama));
    printf("\nMasukkan Nama Player 2 : ");scanf("%s", ((*U2).Nama));
    readConfig(&(*U1),&(*TP), fileconfig);
    printf("\n*****************************\n\n");
    (*U1).MaxRoll = (*U1).P.MaxRollAwal;
    printf("Player 1 : %s\n", (*U1).Nama);
    // printConfig(&((*U1).P), &(*TP));
    // printf("MaxRoll Player 1 saat ini: %d\n", (*U1).MaxRoll); //MaxRoll seorang user dapat berubah di tengah permainan
    ((*U2).P) = copyPlayer((*U1).P);
    
    //TPdup = copyTele(TP1);
    (*U2).MaxRoll = (*U2).P.MaxRollAwal;
    printf("Player 2 : %s\n", (*U2).Nama);
    // printConfig(&((*U2).P), &(*TP));
    // printf("MaxRoll Player 2 saat ini: %d\n", (*U2).MaxRoll);
}

void printConfig(Player *P, Tele *T){

    printf("Panjang peta: %d\n", (*P).Length);
    
    outputPlayerMap((*P));printf("\n");
    
    printf("MaxRoll Awal:%d\n", (*P).MaxRollAwal); //MaxRollAwal sesuai dengan file konfigurasi

    printf("Byk tele:%d\n", (*T).bykTele);
    
    printf("Before: ");
    for(int i=1;i<=(*T).bykTele;i++) {   
        printf("%d ", (*T).BeforeTele[i]);}
    printf("\n");
    
    printf("After: ");
    for(int i=1;i<=(*T).bykTele;i++) {   
        printf("%d ", (*T).AfterTele[i]);
    }
    
    printf("\n");
    
}