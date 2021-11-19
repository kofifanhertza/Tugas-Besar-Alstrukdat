#include"stdlib.h"
#include"stdio.h"
#include"listskill.h"
#include"time.h"


int main () {
    User U ;
    CreateEmpty(&U.SkillList) ;
    CreateEmpty(&U.ActiveSkill) ;

    int Input;
    scanf("%d",&Input);

    while (Input != 0) {
        if (Input == 1) {

            int skill,random  ;
            skill = Randomizer(random) ;

            // Work in progress

            /* if (NbElmt(P1.SkillList) >= 9) {
                printf("Inventory skill anda sudah penuh!\n") ;
                printf("Apakah anda ingin membuang skill? [Y/N]\n") ;
                char option ;
                scanf("%c", &option) ;
                if (option == 'Y') {
                    PrintSkill(P1.SkillList) ;
                    printf("Masukkan Skill yang akan dihapus : ") ;
                    int deleted ;
                    scanf("%d", &deleted) ;
                    DelIdxSkill (&P1.SkillList, deleted) ;
                    P1.SkillList = DelSkill(P1, deleted) ;
                }
                else if (option == 'N') {
                    skill = 0 ;
                } 
            } */
            if (skill != 0) {
                InsVLast(&U.SkillList, skill) ;
            }   
        } 

        else if (Input == 2) {
           int inputCommand = CommandSkill(U) ;
           if (inputCommand != 0) {
               if (inputCommand > 0) {
                    U.ActiveSkill = UseSkill(U, inputCommand) ;
                    U.SkillList = DelSkill(U, inputCommand) ;
               } else if (inputCommand < 0) {
                    inputCommand = inputCommand * -1 ;
                    DelIdxSkill (&U.SkillList, inputCommand) ;
                    U.SkillList = DelSkill(U, inputCommand) ;
               }
               
    
           }
           
        }

        else if (Input == 3) {
            int nSkill = NbElmt(U.SkillList) ;
            printf("%d\n", nSkill) ;
        }

        else if (Input == 4) {
            PrintBuff(U.ActiveSkill) ;
        }

        scanf("%d",&Input);
    }
    return 0 ;
}
    