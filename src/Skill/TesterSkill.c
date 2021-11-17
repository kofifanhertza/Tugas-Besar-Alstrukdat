#include"stdlib.h"
#include"stdio.h"
#include"listskill.h"
#include"time.h"


int main () {
    List skillP1, skillP2 ;
    CreateEmpty(&skillP1) ;
    CreateEmpty(&skillP2) ;

    int Input;
    scanf("%d",&Input);

    while (Input != 0) {
        if (Input == 1) {

            int skill,random  ;
            skill = skillRandomizer(random) ;
            if (skill != 0) {
                InsVFirst(&skillP1, skill) ;
            }
        } 

        else if (Input == 2) {
            CommandSkill(skillP1) ;
        }


        scanf("%d",&Input);
    }
    return 0 ;
}
    