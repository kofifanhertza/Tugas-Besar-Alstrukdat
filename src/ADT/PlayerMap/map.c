#include <stdio.h>
#include <stdlib.h>
#include "map.h"


void outputPlayerMap(Player P) {
    // untuk membaca map
    int i;
    for(i=IdxMin;i<=P.Length;i++) {
        printf("%c", Map(P)[i] );
    }
}


Player UpdateCurrPos(User U) {
    int i;
    for(i=IdxMin;i<=(U).P.Length;i++){
        if ((U).P.Map[i] == '*') {
            (U).P.Map[i] = '.';
        }
    }
    (U).P.Map[(U).Curr] = '*';
    return U.P;
}

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



void commandMAP(User *U1, User *U2){
    printf("%s      : ", (*U1).Nama);
    outputPlayerMap((*U1).P);
    printf(" %d\n", Curr(*U1));
    printf("%s      : ", (*U2).Nama);
    outputPlayerMap((*U2).P);
    printf(" %d\n", Curr(*U2));
}
//////////////////////////////////////////////////////////
void SetUser(User *U){
    (*U).P.Length = 0;
    (*U).Curr = IdxMin;
}

int GetCurrPlace (User U) {
    return U.Curr;
}


