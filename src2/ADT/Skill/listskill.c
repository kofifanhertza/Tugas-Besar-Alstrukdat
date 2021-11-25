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
        printf("%s tidak mendapatkan skill\n", Nama(U)) ;
    } else {
        if (skill == 1) {
            printf ("%s menemukan skill Pintu Ga Ke Mana Mana\n", Nama(U)) ;
        } else if (skill == 2) {
            printf ("%s menemukan skill Cermin Pengganda\n", Nama(U)) ;
        } else if(skill == 3) {
            printf ("%s menemukan skill Senter Pembesar Hoki\n", Nama(U)) ;
        } else if (skill == 4) {
            printf("%s menemukan skill Senter Pengecil Hoki\n", Nama(U)) ;
        } else if (skill == 5) {
            printf("%s menemukan skill Mesin Penukar Posisi\n", Nama(U)) ;
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
        printf("%s berhasil digunakan Skill Pintu Ga Ke Mana Mana !\n", Nama(U)) ;
    }
    else if (skill == 2) {
        
    }
    else if (skill == 3) {
        printf("%s berhasil digunakan Skill Senter Pembesar Hoki !\n", Nama(U)) ;
    }
    else if (skill == 4) {
        printf("%s berhasil digunakan Skill Senter Pengecil Hoki !\n", Nama(U)) ;
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
        printf("%s berhasil membuang Skill Pintu Ga Ke Mana Mana !\n", Nama(U)) ;
    }
    else if (skill == 2) {
        printf("%s berhasil membuang Skill Cermin Pengganda !\n", Nama(U)) ;

    }
    else if (skill == 3) {
        printf("%s berhasil membuang Skill Senter Pembesar Hoki !\n", Nama(U)) ;
    }
    else if (skill == 4) {
        printf("%s berhasil membuang Skill Senter Pengecil Hoki !\n", Nama(U)) ;
    }
    else if (skill == 5) {
        printf("%s berhasil membuang Skill Mesin Penukar Posisi !\n", Nama(U)) ;
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
        printf("%s tidak memiliki buff", Nama(U)) ;
        return 0 ;
    }
    int i = 1 ;
    address q = First(L) ;
    printf("%s memiliki buff :\n", Nama(U)) ;
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
    if (IsEmpty(SkillList(U))) {
        printf("%s tidak memiliki skill\n", Nama(U)) ;
        return 0 ;
    }
    
    printf("%s memiliki Skill :\n", Nama(U)) ;
    PrintSkill(SkillList(U)) ;
    
    printf("\nTekan 0 untuk keluar\n\n") ;
    printf("Masukkan Skill : ") ;
    scanf("%d", &x) ;

    return x ;
}

List UseSkill (User U, int x) {
    int UsedSkill ;
    UsedSkill = UseIdxSkill(&SkillList(U), x, U) ;
    InsVLast(&ActiveSkill(U), UsedSkill) ;   
    return ActiveSkill(U) ;

}

List DelSkill (User U, int x) {
    int DeletedSkill ;
    DeletedSkill = IdxSkill(&SkillList(U), x) ;
    DelP(&SkillList(U), DeletedSkill) ;    
    return SkillList(U) ;

} 

List SkillRandomizer (User U) {
    int skill  ;
    if (NbElmt(SkillList(U)) < 10) {
        skill = Randomizer(U) ;
    }
    

    if (skill != 0) {
        if (NbElmt(SkillList(U)) >= 10) {
            skill = Randomizer(U) ;
            if (skill != 0) {
                printf("Inventory skill anda sudah penuh!\n") ;
                printf("Apakah anda ingin membuang skill? [Y/N]\n") ;
                printf("1. Ya\n") ;
                printf("2. Tidak\n") ;
                int option ;
                scanf("%d", &option) ;
                if (option == 1) {
                    
                    PrintSkill(SkillList(U)) ;
                    printf("Masukkan Skill yang akan dihapus : ") ;
                    int deleted ;
                    scanf("%d", &deleted) ;
                    DelIdxSkill (&SkillList(U), deleted, U) ;
                    SkillList(U) = DelSkill(U, deleted) ;
                    InsVLast(&SkillList(U), skill) ; 
                    return SkillList(U) ;
                }
                else if (option == 0) {
                    return SkillList(U) ;
                }
            }
            return SkillList(U) ;
            
        }
        InsVLast(&SkillList(U), skill) ;     
        
        
    }
    return SkillList(U) ;   
}

List EmptyBuff (User U) {
    address deleted ;
    while (!IsEmpty(ActiveSkill(U))) {
        DelFirst(&ActiveSkill(U), &deleted) ;
    }
    return ActiveSkill(U) ;
}

User SKILL (User U, User *U2) {
int inputCommand = CommandSkill(U) ;
           if (inputCommand != 0) {
                if (inputCommand > 0) {

                    boolean use = true ;

                    if (Search(ActiveSkill(U), IdxSkill(&SkillList(U), inputCommand)) != Nil) {
                        printf("Gagal menggunakan, Skill sudah aktif!\n") ;
                    }  else {

                        if (IdxSkill(&SkillList(U), inputCommand) == 2) {
                            if (NbElmt(SkillList(U)) > 9) {
                                printf("Cermin Pengganda Gagal Digunakan\n") ;
                                use = false ;
                            } else {
                                printf("%s berhasil digunakan Skill Cermin Pengganda !\n", U.Nama) ;
                                SkillList(U) = SkillRandomizer(U) ;
                                SkillList(U) = SkillRandomizer(U) ;
                                use = true ;
                            }
                        }
                        if (IdxSkill(&SkillList(U), inputCommand) == 3) {
                            if (Search(ActiveSkill(U), 4) != Nil) {
                                printf("Gagal menggunakan skill, Skill Pembesar dan pengecil tidak bisa digunakan bersamaan!\n") ;
                                use = false ;
                            } 
                        } else if (IdxSkill(&SkillList(U), inputCommand) == 4) {
                            if (Search(ActiveSkill(U), 3) != Nil) {
                                printf("Gagal menggunakan skill, Skill Pembesar dan pengecil tidak bisa digunakan bersamaan!\n") ;
                                use = false ;
                            } 
                        } else if (IdxSkill(&SkillList(U), inputCommand) == 5) {
                            int tempCurr ; 
                            tempCurr = U.Curr ;
                            U.Curr = (*U2).Curr ;
                            (*U2).Curr = tempCurr ;
                            printf("%s berhasil digunakan Skill Mesin Penukar Posisi !\n", Nama(U)) ;
                            printf("Posisi %s dan %s berhasil ditukar !\n", Nama(U), Nama(*U2)) ;
                            use = true ;

                        }

                        if (use == true) {
                            ActiveSkill(U) = UseSkill(U, inputCommand) ;
                            SkillList(U) = DelSkill(U, inputCommand) ;
                        }
                    }
        

                    
               } else if (inputCommand < 0) {
                    inputCommand = inputCommand * -1 ;
                    DelIdxSkill (&SkillList(U), inputCommand, U) ;
                    SkillList(U) = DelSkill(U, inputCommand) ;
               }
           }
    return U ;
}