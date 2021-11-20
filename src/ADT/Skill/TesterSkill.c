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
            U.SkillList = SkillRandomizer(U) ;
        } 

        else if (Input == 2) {
           int inputCommand = CommandSkill(U) ;
           if (inputCommand != 0) {
                if (inputCommand > 0) {


            
                        if (Search(U.ActiveSkill, IdxSkill(&U.SkillList, inputCommand)) != Nil) {
                            printf("Gagal menggunakan, Skill sudah aktif!\n") ;
                        }  else {
                            U.ActiveSkill = UseSkill(U, inputCommand) ;
                            U.SkillList = DelSkill(U, inputCommand) ;
                        }
        

                    
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
    