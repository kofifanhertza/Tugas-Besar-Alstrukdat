#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void SetPlayer (Player P){
    (P).Length = 0;
}

void outputPlayerMap(Player P) {
    // untuk membaca map
    int i;
    for(i=IdxMin;i<=P.Length;i++) {
        printf("%c", P.Map[i]);
    }
    printf("\n");
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