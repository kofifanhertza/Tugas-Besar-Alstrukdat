#include"stdlib.h"
#include"stdio.h"
#include"listskill.h"
#include"time.h"


int skillRandomizer () {
    int skill, x;
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

int UseSkill (List L,  int idx) {
    int skill, i = 1 ;
    address addrSkill = Last(L) ;

    while (i != idx) {
        addrSkill = Prev(addrSkill) ;
        i = i + 1 ;
    }
    skill = Info(addrSkill) ;

    if (skill == 1) {
        printf("Skill Pintu Ga Ke Mana Mana berhasil digunakan!\n") ;
    }
    if (skill == 2) {
    int nSkill ;
        nSkill = NbSkill(L) ;
        if (nSkill > 9) {
            printf("Anda tidak bisa menggunakan skill Cermin Pengganda!\n(Jumlah skill > 9)\n") ;
            return 0;
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

void PrintSkill (List L) {
    int i = 1 ;
    address q = Last(L) ;
    while (q != Nil) {   
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

void CommandSkill (List L) {
    int x ;
    printf("Kamu memiliki Skill :\n") ;
    PrintSkill(L) ;
    
    printf("\nTekan 0 untuk keluar\n\n") ;
    printf("Masukkan Skill : ") ;
    
    scanf("%d", &x) ;
    if (x != 0) {
        int UsedSkill = UseSkill(L, x) ;
        DelP(&L, UsedSkill) ;
    }
    
}


