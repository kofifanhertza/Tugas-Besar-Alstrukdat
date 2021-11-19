#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void SetPlayer (Player P){
    (P).Length = 0;
    (P).MaxRoll = 0;
    (P).Curr = IdxMin;
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