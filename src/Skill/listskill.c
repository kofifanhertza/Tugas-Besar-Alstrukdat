#include"boolean.h" 
#include"stdlib.h"
#include"stdio.h"
#include"listdp.h"
#include"time.h"


int skillRandomizer () {
    int x,skill ;
    srand(time(NULL));
    x = rand() % 100 ;
    printf("%d\n", x) ;

    if (x > 0 && x <= 10) {
        skill = 1 ; /* Pintu Ga Ke Mana Mana */ 
    
    }

    else if (x > 10 && x <= 16) {
        skill = 2 ; /* Cermin Pengganda */
    
    }

    else if (x > 16 && x <= 31) {
        skill = 3 ; /* Senter Pembesar Hoki */
    
    }

    else if (x > 31 && x <= 46) {
        skill = 4 ; /* Senter Pengecil Hoki */
    }

    else if (x > 46 && x <= 50) {
        skill = 5 ; /* Mesin Penukar Posisi */  

    }

    else {
        skill = 0 ; /* No Gadget */
        
    }

    if (skill == 0 ) {
        printf("Anda tidak mendapatkan skill\n") ;
    } else {
        printf("Anda menemukan skill %d\n", skill) ;
    }
            
return skill ;
}

void UseSkill (List L,  int skill) {
    address addrSkill ;
    addrSkill = Search(L, skill) ;
    if (addrSkill == Nil) {
        if (skill == 1) {
            printf("Anda tidak memiliki skill Pintu Ga Ke Mana Mana\n") ;
        }
        if (skill == 2) {
            printf("Anda tidak memiliki skill Cermin Pengganda\n") ;
        }
        if (skill == 3) {
            printf("Anda tidak memiliki skill Senter Pembesar Hoki\n") ;
        }
        if (skill == 4) {
            printf("Anda tidak memiliki skill Senter Pengecil Hoki\n") ;
        }
        if (skill == 5) {
            printf("Anda tidak memiliki skill Mesin Penukar Posisi\n") ;
        }

    } else {
        if (skill == 1) {
            printf("Skill Pintu Ga Ke Mana Mana berhasil digunakan!\n") ;
        }
        if (skill == 2) {
            printf("Skill Cermin Pengganda berhasil digunakan!\n") ;
        }
        if (skill == 3) {
            printf("Skill Senter Pembesar Hoki berhasil digunakan!\n") ;
        }
        if (skill == 4) {
            printf("Skill Senter Pengecil Hoki berhasil digunakan!\n") ;
        }
        if (skill == 5) {
            printf("Skill Mesin Penukar Posisi berhasil digunakan!\n") ;
        }
        
    }
}



/* BAGIAN TESTING SKILL */

int main () {
    List skillP1, skillP2 ;
    CreateEmpty(&skillP1) ;
    CreateEmpty(&skillP2) ;

    int Input;
    scanf("%d",&Input);

    while (Input != 0) {
        if (Input == 1) {

            int skill ;
            skill = skillRandomizer() ;
            if (skill != 0) {
                InsVFirst(&skillP1, skill) ;
            }
            
            

        } 

        else if (Input == 2) {
            PrintForward(skillP1) ;
            printf("\n") ;
        }

        else if (Input == 3) {
            int skill ;
            printf("Skill yang akan digunakan : ") ;
            scanf("%d", &skill) ;
            UseSkill(skillP1, skill) ;
            DelP(&skillP1, skill) ;
        }
        scanf("%d",&Input);
    }
}
    

