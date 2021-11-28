#include "../PlayerMap/map.h"
#include "../Mesin/mesin_konf.h"
#include "../Skill/listskill.h"
#include "../Stack/stacklist.h"
#include "boolean.h"
#include "move.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
boolean endGame = false;
int rondeKe;
User U1, U2;
Tele TP;

void startTurn(roundInfo *R,Tele *T, Round *Game){
    int count=1;
    printf("\nGiliran %s Nih...\n", ((*R).Player[0]).Nama); 
    CopyList(&(*R).Player[0].SkillList, &(Game->TOP->Info.Player[0].SkillList));
    CopyList(&(*R).Player[1].SkillList, &(Game->TOP->Info.Player[1].SkillList));
    (*R).Player[0].ActiveSkill = EmptyBuff((*R).Player[0]) ;
    (*R).Player[0].SkillList = SkillRandomizer((*R).Player[0]) ;
    commandMAP(&(*R).Player[0], &(*R).Player[1]) ;
    char input[10];
    boolean endTurn = false;
    boolean roll = false ;
    while (!endTurn){       
        printf("Masukkan Command 'ROLL': ");
        scanf(" %s", input);
        if (strcmp(input, "ROLL") == 0) {
            if (count < 2) {
            roll2(&((*R).Player[0]), &((*R).Player[1]), *T, ((*R).Player[0]).P);
            ((*R).Player[0]).P = UpdateCurrPos((*R).Player[0]);
            count += 1;
            commandMAP(&(*R).Player[0], &(*R).Player[1]) ;
            roll = true ;                
            } else {
                printf("Tidak boleh roll lagi! \n");
            }
        }              
     }
}


void startRonde(Tele *T, Round *Game){
    boolean endGame = false;
    boolean undo = false;
    roundInfo R ;
    R = Game->TOP->Info ;
    int n = R.rondeKe ;
    printf("\n Ronde ke-%d dimulaii \n",n);
    startTurn(&R,T, Game);
}

boolean isWExist(User *U1, User *U2) {
    // Permainan akan berakhir jika sudah ada satu pemain yang mencapai petak N.
    return (Curr(*U1) == (*U1).P.Length || Curr(*U2) == (*U2).P.Length);
}


void awalPermainan(int inputmenu, User *U1, User *U2, Tele *T, Round *Game){
        if (inputmenu == 1){
        (*U1).Curr = IdxMin;
        (*U2).Curr = IdxMin;
        char fileConfig[10];
        printf("Masukkan nama file konfigurasi level: "); scanf("%s",fileConfig);
        Konfigurasi(fileConfig, U1, U2, T);
        (*U1).P.Map[1] = '*';
        (*U2).P.Map[1] = '*';
        roundInfo R;
        R.rondeKe = 1;
        R.Player[0] = *U1;
        R.Player[1] = *U2;
        PushR(Game,R);
        printf("%d\n",Game->TOP->Info.rondeKe);
        printf("%d\n",Game->TOP->Info.Player->P.MaxRollAwal);
    } else if (inputmenu == 2){
        endGame = true;
        printf("Berhasil keluar dari game.\n"); 
    } 
}

void InputAngka(int *angka){
    scanf("%d", angka);
}


void MainMenu(int *inputmenu){
    printf("Masukkan command :\n>");
    printf("\x1b[1m"); //bold
    InputAngka(inputmenu);
    printf("\x1b[0m");
    while (*inputmenu!=1 && *inputmenu!=2 && *inputmenu!=3){
        printf("Input tidak terdefinisi, silahkan masukan angka menu\n");
        printf("Masukkan command :\n> ");
        printf("\x1b[1m"); //bold
        InputAngka(inputmenu);
        printf("\x1b[0m");
    }
} 


int main(){
    int inputmenu;
    MainMenu(&inputmenu);
    rondeKe = 0;
    Round Game;
    CreateEmptyRS(&Game);
    awalPermainan(inputmenu, &U1, &U2, &TP, &Game);
    while (isWExist(&U1, &U2) != true && endGame != true) {
        startRonde(&TP, &Game);
    }
    printf("Roll Berhasil\n");
}
