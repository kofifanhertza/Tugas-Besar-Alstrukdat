// BARU RANCANGAN, JANLUP DELETE KOMEN NNT KALO UDH FIX
// Setiap kali permainan, kondisi state setiap pemain harus dimasukkan ke Stack State
// Command UNDO dijalankan
// ceritanya lagi main
#include "../ADT/Mesin/map.h"
#include "stackundo.h"
#include "stacklist.h"
/*
typedef struct {
	char Nama[10];
	Player P;
	int Curr;
	int MaxRoll;
	List SkillList ;
	List ActiveSkill ;
} User;
*/

Round saveRound(User P1, User P2/*.Player *P3*/) {
    Stack TP1;
    Stack TP2;
    Round R;
    /*Stack P3;*/
    PushU(&TP1, P1);
    PushU(&TP2, P2);
    /*Push(&P3, P3);*/
    R.P1 = TP1;
    R.P2 = TP2;
    return R;
}

//di main.c, ceritanya
int main(){
    //AWAL MAIN
    RoundStack Game;
    User P1;
    User P2;
    CreateEmptyRS(&Game);
    //lagi main
    // selama belum ada yg nge undo, bakalan belakangan aja (pas semuanya udh turn) di saveround
    //tapi pas ada yg nge undo:
    Round R = saveRound(P1, P2);
    PushR(&Game, R);
    //COMMAND = UNDO
    PopR(&Game, &R);

}