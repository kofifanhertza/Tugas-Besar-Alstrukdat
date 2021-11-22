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

        U = SKILL(U);

        } else if (Input == 3) {
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
    