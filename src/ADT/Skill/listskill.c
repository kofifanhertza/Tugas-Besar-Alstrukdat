#include"stdlib.h"
#include"stdio.h"
#include"listskill.h"
#include"time.h"


int Randomizer (User U) {
    int skill, x;
    srand(time(NULL)) ;
    x = rand() % 50 + 1;
    x = rand() % 50 + 1;

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
        printf("%s tidak mendapatkan skill\n", U.Nama) ;
    } else {
        if (skill == 1) {
            printf ("%s menemukan skill Pintu Ga Ke Mana Mana\n", U.Nama) ;
        } else if (skill == 2) {
            printf ("%s menemukan skill Cermin Pengganda\n", U.Nama) ;
        } else if(skill == 3) {
            printf ("%s menemukan skill Senter Pembesar Hoki\n", U.Nama) ;
        } else if (skill == 4) {
            printf("%s menemukan skill Senter Pengecil Hoki\n", U.Nama) ;
        } else if (skill == 5) {
            printf("%s menemukan skill Mesin Penukar Posisi\n", U.Nama) ;
        } 
    }
            
return skill ;
}


int UseIdxSkill (List *L,  int idx, User U) {
    int skill, i = 1 ;
    address addrSkill = First(*L) ;

    while (i != idx) {
        addrSkill = Next(addrSkill) ;
        i = i + 1 ;
    }
    skill = Info(addrSkill) ;

    if (skill == 1) {
        printf("%s berhasil digunakan Skill Pintu Ga Ke Mana Mana !\n", U.Nama) ;
    }
    else if (skill == 2) {
        
    }
    else if (skill == 3) {
        printf("%s berhasil digunakan Skill Senter Pembesar Hoki !\n", U.Nama) ;
    }
    else if (skill == 4) {
        printf("%s berhasil digunakan Skill Senter Pengecil Hoki !\n", U.Nama) ;
    }
    else if (skill == 5) {
        
    }

    return skill ;
    
}

int DelIdxSkill (List *L,  int idx, User U) {
    int skill, i = 1 ;
    address addrSkill = First(*L) ;

    while (i != idx) {
        addrSkill = Next(addrSkill) ;
        i = i + 1 ;
    }
    skill = Info(addrSkill) ;

    if (skill == 1) {
        printf("%s berhasil membuang Skill Pintu Ga Ke Mana Mana !\n", U.Nama) ;
    }
    else if (skill == 2) {
        printf("%s berhasil membuang Skill Cermin Pengganda !\n", U.Nama) ;

    }
    else if (skill == 3) {
        printf("%s berhasil membuang Skill Senter Pembesar Hoki !\n", U.Nama) ;
    }
    else if (skill == 4) {
        printf("%s berhasil membuang Skill Senter Pengecil Hoki !\n", U.Nama) ;
    }
    else if (skill == 5) {
        printf("%s berhasil membuang Skill Mesin Penukar Posisi !\n", U.Nama) ;
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

int PrintBuff (List L, User U) {
    if (IsEmpty(L)) {
        printf("%s tidak memiliki buff", U.Nama) ;
        return 0 ;
    }
    int i = 1 ;
    address q = First(L) ;
    printf("%s memiliki buff :\n", U.Nama) ;
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
        printf("%s tidak memiliki skill\n", U.Nama) ;
        return 0 ;
    }
    
    printf("%s memiliki Skill :\n", U.Nama) ;
    PrintSkill(U.SkillList) ;
    
    printf("\nTekan 0 untuk keluar\n\n") ;
    printf("Masukkan Skill : ") ;
    scanf("%d", &x) ;

    return x ;
}

List UseSkill (User U, int x) {
    int UsedSkill ;
    UsedSkill = UseIdxSkill(&U.SkillList, x, U) ;
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
    int skill  ;
    if (NbElmt(U.SkillList) < 10) {
        skill = Randomizer(U) ;
    }
    

    if (skill != 0) {
        if (NbElmt(U.SkillList) >= 10) {
            skill = Randomizer(U) ;
            if (skill != 0) {
                printf("Inventory skill anda sudah penuh!\n") ;
                printf("Apakah anda ingin membuang skill? [Y/N]\n") ;
                char option ;
                scanf("%c", option) ;
                if (option == 'Y') {
                    
                    PrintSkill(U.SkillList) ;
                    printf("Masukkan Skill yang akan dihapus : ") ;
                    int deleted ;
                    scanf("%d", &deleted) ;
                    DelIdxSkill (&U.SkillList, deleted, U) ;
                    U.SkillList = DelSkill(U, deleted) ;
                    InsVLast(&U.SkillList, skill) ; 
                    return U.SkillList ;
                }
                else if (option == 'N') {
                    return U.SkillList ;
                }
            }
            return U.SkillList ;
            
        }
        InsVLast(&U.SkillList, skill) ;     
        
        
    }
    return U.SkillList ;   
}

List EmptyBuff (User U) {
    address deleted ;
    while (!IsEmpty(U.ActiveSkill)) {
        DelFirst(&U.ActiveSkill, &deleted) ;
    }
    return U.ActiveSkill ;
}

User SKILL (User U, User *U2) {
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
                                printf("%s berhasil digunakan Skill Cermin Pengganda !\n", U.Nama) ;
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
                        } else if (IdxSkill(&U.SkillList, inputCommand) == 5) {
                            int tempCurr ; 
                            tempCurr = U.Curr ;
                            U.Curr = (*U2).Curr ;
                            (*U2).Curr = tempCurr ;
                            printf("%s berhasil digunakan Skill Mesin Penukar Posisi !\n", U.Nama) ;
                            printf("Posisi %s dan %s berhasil ditukar !\n", U.Nama, (*U2).Nama) ;
                            use = true ;

                        }

                        if (use == true) {
                            U.ActiveSkill = UseSkill(U, inputCommand) ;
                            U.SkillList = DelSkill(U, inputCommand) ;
                        }
                    }
        

                    
               } else if (inputCommand < 0) {
                    inputCommand = inputCommand * -1 ;
                    DelIdxSkill (&U.SkillList, inputCommand, U) ;
                    U.SkillList = DelSkill(U, inputCommand) ;
               }
           }
    return U ;
}