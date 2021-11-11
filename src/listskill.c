#include"boolean.h" 
#include"stdlib.h"
#include"ADT/List/listdp.h"


int skillRandomizer () {
    int x ;
    char skill[100] ;
    x = rand() % 100 ;

    if (x < 10) {
        skill[100] = "Pintu Ga Ke Mana Mana" ;
    }

    if (x < 16) {
        skill[100] = "Cermin Pengganda" ;
    }

    if (x < 31) {
        skill[100] = "Senter Pembesar Hoki" ;
    }

    if (x < 46) {
        skill[100] = "Senter Pengecil Hoki" ;
    }

    if (x < 50) {
        skill[100] = "Mesin Penukar Posisi" ;
    }

    return skill ;
}

void CreateListSkill (int nPlayer) {
    /* Create skill dijalankan diawal permainan */

    address skillP1, skillP2 ;
    CreateEmpty(&skillP1) ;
    CreateEmpty(&skillP2) ;

    if (nPlayer == 3) {
        address skillP3 ;
        CreateEmpty(&skillP3) ;
    }

    if (nPlayer == 4) {
        address skillP4 ;
        CreateEmpty(&skillP4) ;
    }
}

