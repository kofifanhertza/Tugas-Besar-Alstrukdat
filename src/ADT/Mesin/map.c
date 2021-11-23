#include <stdio.h>
#include <stdlib.h>
#include "map.h"


void SetUser(User *U){
    (*U).P.Length = 0;
    (*U).Curr = IdxMin;
}
void outputPlayerMap(Player P) {
    // untuk membaca map
    int i;
    for(i=IdxMin;i<=P.Length;i++) {
        printf("%c", P.Map[i]);
    }
}
/*
char CheckPetak (Player P, IdxType i){
    return P.Map[i];
}

int GetCurrPlace (Player P) {
    return P.Curr;
}


void ChangeCurrPlace(Player P, IdxType idxAfter) {
    int temp;
    temp = P.Curr;
    P.Curr = idxAfter;
    P.Map[temp] = ".";
    P.Map[idxAfter] = "*";
}
*/
Player copyPlayer(Player Pawal) {
    Player Pfix;
    int i;
    (Pfix).Length = Pawal.Length;
    (Pfix).MaxRollAwal = Pawal.MaxRollAwal;
    for (i=IdxMin;i<=Pawal.Length;i++){
        (Pfix).Map[i] = (Pawal).Map[i];
    }
    return (Pfix);
}
Tele copyTele(Tele Tawal){
    Tele T;
    int i;
    (T).bykTele = Tawal.bykTele;
    for (i=IdxMin;i<=Tawal.bykTele;i++){
        (T).BeforeTele[i] = Tawal.BeforeTele[i];
        (T).AfterTele[i] = Tawal.AfterTele[i];
    }
    return (T);
}

void Inspect(Tele T, Player P){
    int X, i;
    char symbol;
    printf("Masukkan petak : "); scanf("%d",&X);

    i = 1;
    while (T.BeforeTele[i] != X && i <= T.bykTele){ //Mencari lokasi teleporter dan isi peta
        i = i + 1;
    }
    
    
    symbol = P.Map[X];

    if (symbol == '#'){
        printf("Petak %d merupakan petak terlarang.\n",X);
    } else { //symbol == '.'
        if (i <= T.bykTele){
            printf("Petak %d memiliki teleporter menuju %d\n",X,T.AfterTele[i]);
        } else { //i > U.P.Length  
            printf("Petak %d merupakan petak kosong.\n",X);
        }
    }

}

void commandMAP(User *U1, User *U2){
    printf("%s      : ", (*U1).Nama);
    outputPlayerMap((*U1).P);
    printf(" %d\n", Curr(*U1));
    printf("%s      : ", (*U2).Nama);
    outputPlayerMap((*U2).P);
    printf(" %d\n", Curr(*U2));
}