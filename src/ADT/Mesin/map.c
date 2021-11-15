#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void MakeEmpty (Map *M){
    (*M).Length = 0;
}

int MapLength (Map M){
    return M.Length;
}

int MaxNbEl (Map M){
    return IdxMax;
}

IdxType GetFirstIdx (Map M){
    return IdxMin;
}

IdxType GetLastIdx (Map M){
    return M.Length;
}

ElType GetElmt (Map M, IdxType i){
    return M.TI[i];
}

ElType GetCurrPlace (Map M) {
    return M.curr;
}

void outputMap(Map M) { 
    // untuk membaca map
    int i;
    for(i=0;i<M.Length;i++) {
        printf("%c", M.TI[i]);
    }
    printf("\n");
}

void ChangeCurrPlace(Map M, IdxType idxAfter) {
    int temp;
    temp = M.curr;
    M.curr = idxAfter;
    M.TI[temp] = ".";
    M.TI[idxAfter] = "*";
}
boolean isPlaceAvailable(Map M, IdxType i) {
    return ((M.TI[i] == "." ) || (M.TI[i] == "*")); 
    /* Kalau M.TI[i] == "#", nanti return false, terus nanti akan ada fungsi yang nentuin bakal gimana jalannya, kalau dapet roll dadu yang menghasilkan i untuk M.TI[i] == "#"*/
}