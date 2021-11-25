#include <stdio.h>
#include "stackundo.h"
#include "boolean.h"
#include "../PlayerMap/map.h"
#include <string.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */

void CreateEmptyRound (Round *R) {
    (*R).P1.Curr = 0;
    (*R).P2.Curr = 0;
}


User AddU (User *U, User *U1) {
    (*U).Curr = (*U1).Curr;
    (*U).P = copyPlayer((*U1).P);
    strcpy((*U).Nama, (*U1).Nama);
    return (*U);
}

/* ************ Menghapus sebuah elemen Stack ************ */
/*void RemoveU (Stack * S, User P2) {
    (*P2) = (*S).T[(*S).TOP-1];
    (*S).TOP--;
}*/
void saveRound(User *U1, User *U2, Round *R, RoundStack *Game) {
    (*R).P1 = *U1 ;
    (*R).P2 = *U2 ;
    PushR(Game, R) ;
}