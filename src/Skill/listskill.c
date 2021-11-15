#include"boolean.h" 
#include"stdlib.h"
#include"stdio.h"
#include"listdp.h"
#include"time.h"


int skillRandomizer (int x) {
    int skill ;
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

int NbSkill (List L) {
    int count = 0 ;
    if (!IsEmpty(L)) {
        address p = First(L) ;
        while (p != Nil) {
            p = Next(p) ;
            count = count + 1 ;
        }
    }
    return count ;   
}

int UseSkill (List L,  int skill) {
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
        return 0 ;

    } else {
        if (skill == 1) {
            printf("Skill Pintu Ga Ke Mana Mana berhasil digunakan!\n") ;
        }
        if (skill == 2) {
            int nSkill ;
            nSkill = NbSkill(L) ;

            if (nSkill > 9) {
                printf("Anda tidak bisa menggunakan skill Cermin Pengganda!\n(Jumlah skill > 9)\n") ;
                return 0 ;
            } else {
            printf("Skill Cermin Pengganda berhasil digunakan!\n") ;
            }
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
        return skill ;
    }
}

void PrintSkill (List L) {
    address q = Last(L) ;
    while (q != Nil) {   
        int i = 1 ;
        if (Info(q) == 1) {
            printf("%d. Pintu Ga Ke Mana Mana\n", i) ;    
        } 
        else if (Info(q) == 2) {
            printf("%d. Cermin Pengganda\n", i) ;
        }
        else if (Info(q) == 3) {
            printf("%d. Senter Pembesar Hoki\n", i) ;
       }
        else if (Info(q) == 4) {
            printf("%d. Senter Pengecil Hoki\n", i) ; 
        }
        else if (Info(q) == 5) {
            printf("%d. Mesin Penukar Posisi\n", i) ;
        }
        q = Prev(q) ;
        i = i + 1 ;
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

            int skill,random  ;
            srand(time(NULL));
            random = rand() % 100 ;
            skill = skillRandomizer(random) ;
            if (skill != 0) {
                InsVFirst(&skillP1, skill) ;
            }
        } 

        else if (Input == 2) {
            PrintSkill(skillP1) ;
        }

        else if (Input == 3) {
            int skill, Used ;
            printf("Skill yang akan digunakan : ") ;
            scanf("%d", &skill) ;
            Used = UseSkill(skillP1, skill) ;
            DelP(&skillP1, skill) ;
            if (Used == 2) {

                int x,random, y  ;
                srand(time(NULL));
                random = rand() % 100 ;

                x = skillRandomizer(random) ;
                if (x != 0) {
                    InsVFirst(&skillP1, x) ;
                }

                srand(time(NULL));
                random = rand() % 100 ;
                y = skillRandomizer(random) ;
                if (y != 0) {
                    InsVFirst(&skillP1, y) ;
                }
            }
        }

        scanf("%d",&Input);
    }
    return 0 ;
}
    

