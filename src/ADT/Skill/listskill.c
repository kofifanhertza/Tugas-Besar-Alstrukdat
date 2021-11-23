#include"stdlib.h"
#include"stdio.h"
#include"listskill.h"
#include"time.h"


int Randomizer () {
    int skill, x;
    x = rand() % 100 + 1;
    x = rand() % 100 + 1;
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
        if (skill == 1) {
            printf ("Anda menemukan skill Pintu Ga Ke Mana Mana\n") ;
        } else if (skill == 2) {
            printf ("Anda menemukan skill Cermin Pengganda\n") ;
        } else if(skill == 3) {
            printf ("Anda menemukan skill Senter Pembesar Hoki\n") ;
        } else if (skill == 4) {
            printf("Anda menemukan skill Senter Pengecil Hoki\n") ;
        } else if (skill == 5) {
            printf("Anda menemukan skill Mesin Penukar Posisi\n") ;
        } 
    }
            
return skill ;
}


int UseIdxSkill (List *L,  int idx) {
    int skill, i = 1 ;
    address addrSkill = First(*L) ;

    while (i != idx) {
        addrSkill = Next(addrSkill) ;
        i = i + 1 ;
    }
    skill = Info(addrSkill) ;

    if (skill == 1) {
        printf("Skill Pintu Ga Ke Mana Mana berhasil digunakan!\n") ;
    }
    else if (skill == 2) {
        
    }
    else if (skill == 3) {
        printf("Skill Senter Pembesar Hoki berhasil digunakan!\n") ;
    }
    else if (skill == 4) {
        printf("Skill Senter Pengecil Hoki berhasil digunakan!\n") ;
    }
    else if (skill == 5) {
        printf("Skill Mesin Penukar Posisi berhasil digunakan!\n") ;
    }

    return skill ;
    
}

int DelIdxSkill (List *L,  int idx) {
    int skill, i = 1 ;
    address addrSkill = First(*L) ;

    while (i != idx) {
        addrSkill = Next(addrSkill) ;
        i = i + 1 ;
    }
    skill = Info(addrSkill) ;

    if (skill == 1) {
        printf("Skill Pintu Ga Ke Mana Mana berhasil dihapus!\n") ;
    }
    else if (skill == 2) {
        printf("Skill Cermin Pengganda berhasil dihapus!\n") ;

    }
    else if (skill == 3) {
        printf("Skill Senter Pembesar Hoki berhasil dihapus!\n") ;
    }
    else if (skill == 4) {
        printf("Skill Senter Pengecil Hoki berhasil dihapus!\n") ;
    }
    else if (skill == 5) {
        printf("Skill Mesin Penukar Posisi berhasil dihapus!\n") ;
    }

    return skill ;
    
}

int IdxSkill (List *L,  int idx) {
    int skill, i = 1 ;
    address addrSkill = First(*L) ;

    while (i != idx) {
        addrSkill = Next(addrSkill) ;
        i = i + 1 ;
    }
    skill = Info(addrSkill) ;

    return skill ;
    
}

int PrintSkill (List L) {
    if (IsEmpty(L)) {
        return 0;
    }
    int i = 1 ;
    address q = First(L) ;
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
        q = Next(q) ;
        i = i + 1 ;
        }
    return 0 ;
        
}

int PrintBuff (List L) {
    if (IsEmpty(L)) {
        printf("Anda tidak memiliki buff") ;
        return 0 ;
    }
    int i = 1 ;
    address q = First(L) ;
    printf("Anda memiliki buff :\n") ;
    while (q != Nil) {   
        if (Info(q) == 1) {
            printf("%d. Imunitas Teleport\n", i) ;    
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
        q = Next(q) ;
        i = i + 1 ;
        }
        return 0 ;
}

int CommandSkill (User U) {
    int x, UsedSkill = 0 ;
    if (IsEmpty(U.SkillList)) {
        printf("Anda tidak memiliki skill\n") ;
        return 0 ;
    }
    
    printf("Kamu memiliki Skill :\n") ;
    PrintSkill(U.SkillList) ;
    
    printf("\nTekan 0 untuk keluar\n\n") ;
    printf("Masukkan Skill : ") ;
    scanf("%d", &x) ;

    return x ;
}

List UseSkill (User U, int x) {
    int UsedSkill ;
    UsedSkill = UseIdxSkill(&U.SkillList, x) ;
    InsVLast(&U.ActiveSkill, UsedSkill) ;   
    return U.ActiveSkill ;

}

List DelSkill (User U, int x) {
    int DeletedSkill ;
    DeletedSkill = IdxSkill(&U.SkillList, x) ;
    DelP(&U.SkillList, DeletedSkill) ;    
    return U.SkillList ;

} 

List SkillRandomizer (User U) {
    int skill,random  ;
    if (NbElmt(U.SkillList) < 10) {
        skill = Randomizer(random) ;
    }
    

    if (skill != 0) {
        if (NbElmt(U.SkillList) >= 10) {
            skill = Randomizer(random) ;
            printf("Inventory skill anda sudah penuh!\n") ;
            printf("Apakah anda ingin membuang skill? [1/0]\n") ;
            printf("Tekan 0 apabila tidak ingin membuang skill\n") ;

            char option ;
            scanf("%d", &option) ;
            if (option == 1) {
                  
                PrintSkill(U.SkillList) ;
                printf("Masukkan Skill yang akan dihapus : ") ;
                int deleted ;
                scanf("%d", &deleted) ;
                DelIdxSkill (&U.SkillList, deleted) ;
                U.SkillList = DelSkill(U, deleted) ;
                InsVLast(&U.SkillList, skill) ; 
                return U.SkillList ;
            }
            else if (option == 0) {
                return U.SkillList ;
            }
            
        }
        InsVLast(&U.SkillList, skill) ;     
        
        
    }
    return U.SkillList ;   
}

User SKILL (User U) {
int inputCommand = CommandSkill(U) ;
           if (inputCommand != 0) {
                if (inputCommand > 0) {

                    boolean use = true ;

                    if (Search(U.ActiveSkill, IdxSkill(&U.SkillList, inputCommand)) != Nil) {
                        printf("Gagal menggunakan, Skill sudah aktif!\n") ;
                    }  else {

                        if (IdxSkill(&U.SkillList, inputCommand) == 2) {
                            if (NbElmt(U.SkillList) > 9) {
                                printf("Cermin Pengganda Gagal Digunakan\n") ;
                                use = false ;
                            } else {
                                printf("Skill Cermin Pengganda berhasil digunakan!\n") ;
                                U.SkillList = SkillRandomizer(U) ;
                                U.SkillList = SkillRandomizer(U) ;
                                use = true ;
                            }
                        }
                        if (IdxSkill(&U.SkillList, inputCommand) == 3) {
                            if (Search(U.ActiveSkill, 4) != Nil) {
                                printf("Gagal menggunakan skill, Skill Pembesar dan pengecil tidak bisa digunakan bersamaan!\n") ;
                                use = false ;
                            } 
                        } else if (IdxSkill(&U.SkillList, inputCommand) == 4) {
                            if (Search(U.ActiveSkill, 3) != Nil) {
                                printf("Gagal menggunakan skill, Skill Pembesar dan pengecil tidak bisa digunakan bersamaan!\n") ;
                                use = false ;
                            } 
                        }

                        if (use == true) {
                            U.ActiveSkill = UseSkill(U, inputCommand) ;
                            U.SkillList = DelSkill(U, inputCommand) ;
                        }
                    }
        

                    
               } else if (inputCommand < 0) {
                    inputCommand = inputCommand * -1 ;
                    DelIdxSkill (&U.SkillList, inputCommand) ;
                    U.SkillList = DelSkill(U, inputCommand) ;
               }
           }
    return U ;
}