#include"stdlib.h"
#include"stdio.h"
#include"listskill.h"
#include"time.h"
#include "../PlayerMap/map.h"


int main () {
    User U, U2 ;
    Tele T ;
    Player P ;
    
    printf("Masukkan Nama Player 1 : ");scanf("%s", ((U).Nama));
    printf("\nMasukkan Nama Player 2 : ");scanf("%s", ((U2).Nama));

    CreateEmpty(&U.SkillList) ;
    CreateEmpty(&U.ActiveSkill) ;
    CreateEmpty(&U2.SkillList) ;
    CreateEmpty(&U2.ActiveSkill) ;

    int Input = 1;

    while (Input != 0) {
        U.SkillList = SkillRandomizer(U) ;
        scanf("%d",&Input);
        if (Input == 1) {
            SKILL(&U, &U2, P, T);
        } 
        else if (Input == 2) {
            PrintDesc() ;
        } else if (Input == 3) {
            PrintSkill(U.SkillList) ;
        }
        else if (Input == 4) {
            PrintBuff(U.ActiveSkill, U) ;
        }
        printf("\n") ;

        
    }
    return 0 ;
}
    