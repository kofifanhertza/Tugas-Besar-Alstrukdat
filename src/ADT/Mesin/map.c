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