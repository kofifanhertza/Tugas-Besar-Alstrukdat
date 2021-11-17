#include"stdlib.h"
#include"stdio.h"
#include"listskill.h"
#include"time.h"


int main () {
    Player P1 ;
    CreateEmpty(&P1.SkillList) ;

    int Input;
    scanf("%d",&Input);

    while (Input != 0) {
        if (Input == 1) {

            int skill,random  ;
            skill = skillRandomizer(random) ;
            if (skill != 0) {
                InsVFirst(&P1.SkillList, skill) ;
            }
        } 

        else if (Input == 2) {
            CommandSkill(P1) ;
        }


        scanf("%d",&Input);
    }
    return 0 ;
}
    