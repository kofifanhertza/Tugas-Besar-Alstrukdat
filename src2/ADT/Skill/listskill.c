#include"stdlib.h"
#include"stdio.h"
#include"listskill.h"
#include"time.h"


int Randomizer (User U) {
    int skill, x;
    srand(time(NULL)) ;
    x = rand() % 100 + 1;
    x = rand() % 100 + 1;

    if (x > 0 && x <= 30) {
        skill = 1 ; // Pintu Ga Ke Mana Mana 
    
    }
    else if (x > 10 && x <= 16) {
        skill = 2 ; // Cermin Pengganda
    
    }

    else if (x > 16 && x <= 31) {
        skill = 3 ; // Senter Pengecil Hoki
    
    }

    else if (x > 31 && x <= 46) {
        skill = 4 ; // Senter Pembesar Hoki
    }

    else if (x > 46 && x <= 50) {
        skill = 5 ;  // Mesin Penukar Posisi

    }
    else if (x > 50 && x <= 60) {
        skill = 6 ; // Baling Baling Jambu
    }

    else if (x > 60 && x <= 70) {
        skill = 7 ; // Mesin Waktu
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
        }  else if (skill == 6) {
            printf("%s menemukan skill Baling Baling Jambu\n", Nama(U)) ;
        }  else if (skill == 7) {
            printf("%s menemukan skill Mesin Waktu\n", Nama(U)) ;
        }
    }
            
return skill ;
}

void BalingBaling(User *U, Tele T, Player P){  
    int dice1, i;   
    srand ( time(NULL) );
    dice1 = ((rand()%((*U).MaxRoll)) + 1) ;
    printf ("%s mendapatkan angka %d.\n", (*U).Nama,dice1); 
            if (P.Map[(*U).Curr+dice1] =='.') {
                
                    printf ("%s maju %d langkah.\n", (*U).Nama,dice1);
                    (*U).Curr = (*U).Curr+dice1;
                    printf ("%s berada di petak %d.\n", (*U).Nama,(*U).Curr);
                    i = search(T, &(*U));
                    if (i==-1){
                        printf("%s tidak menemukan teleporter\n", (*U).Nama);}
                    else if (i!=-1){
                        printf("%s menemukan teleporter\n", (*U).Nama);
                        if (Search((*U).SkillList, 1) != Nil){
                            printf("%s memiliki Pintu Ga Ke Mana Mana.\n", (*U).Nama);
                            printf("Apakah %s ingin menggunakan Skill Pintu Ga Ke Mana Mana (Y/N) ?\n", (*U).Nama);
                            int pilihan;
                            scanf ("%d", &pilihan);
                            if (pilihan==1){
                                printf("%s tidak teleport.\n", (*U).Nama);
                                DelP(&SkillList(*U), 1) ;
                                printf("Skill Pintu Ga Ke Mana Mana berhasil digunakan !\n") ;}
                                
                            else{
                                if (pilihan==0){
                                    printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                    (*U).Curr = T.AfterTele[i] ;
                                    if ((*U).Curr == (*U).P.Length){
                                    printf("%s berada di petak %d\n",(*U).Nama,(*U).P.Length);
                                    printf("%s telah mencapai ujung\n",(*U).Nama);
                                    printf("Pemenang game ini adalah %s\n",(*U).Nama);} 
                                     }}}
                        else if (Search((*U).SkillList, 1) == Nil){
                                printf("%s tidak memiliki Pintu Ga Ke Mana Mana.\n", (*U).Nama);
                                printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                // ChangeCurrPlace((*U), T.AfterTele[i]) ; 
                                (*U).Curr = T.AfterTele[i] ;
                                if ((*U).Curr == (*U).P.Length){
                                    printf("%s berada di petak %d\n",(*U).Nama,(*U).P.Length);
                                    printf("%s telah mencapai ujung\n",(*U).Nama);
                                    printf("Pemenang game ini adalah %s\n",(*U).Nama);} 
                            }}}
                 else if (P.Map[(*U).Curr+dice1] =='#' || P.Map[(*U).Curr+dice1] > (*U).P.Length){
                    printf ("%s tidak dapat bergerak.\n", (*U).Nama);
                }
        }


void MesinWaktu(User *U, Tele T, Player P){  
    int dice1, i;   
    srand ( time(NULL) );
    dice1 = ((rand()%((*U).MaxRoll)) + 1) ;
    printf ("%s mendapatkan angka %d.\n", (*U).Nama,dice1); 
            if (P.Map[(*U).Curr - dice1] =='.') {
                    printf ("%s mundur %d langkah.\n", (*U).Nama,dice1);
                    (*U).Curr = (*U).Curr - dice1;
                    printf ("%s berada di petak %d.\n", (*U).Nama,(*U).Curr);
                    i = search(T, &(*U));
                    if (i==-1){
                        printf("%s tidak menemukan teleporter\n", (*U).Nama);}
                    else if (i!=-1){
                        printf("%s menemukan teleporter\n", (*U).Nama);
                        if (Search((*U).SkillList, 1) != Nil){
                            printf("%s memiliki Pintu Ga Ke Mana Mana.\n", (*U).Nama);
                            printf("Apakah %s ingin menggunakan Skill Pintu Ga Ke Mana Mana (Y/N) ?\n", (*U).Nama);
                            int pilihan;
                            scanf ("%d", &pilihan);
                            if (pilihan==1){
                                printf("%s tidak teleport.\n", (*U).Nama);
                                DelP(&SkillList(*U), 1) ;
                                printf("Skill Pintu Ga Ke Mana Mana berhasil digunakan !\n") ;}
                                
                            else{
                                if (pilihan==0){
                                    printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                    (*U).Curr = T.AfterTele[i] ;
                                    if ((*U).Curr == (*U).P.Length){
                                    printf("%s berada di petak %d\n",(*U).Nama,(*U).P.Length);
                                    printf("%s telah mencapai ujung\n",(*U).Nama);
                                    printf("Pemenang game ini adalah %s\n",(*U).Nama);} 
                                     }}}
                        else if (Search((*U).SkillList, 1) == Nil){
                                printf("%s tidak memiliki Pintu Ga Ke Mana Mana.\n", (*U).Nama);
                                printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                // ChangeCurrPlace((*U), T.AfterTele[i]) ; 
                                (*U).Curr = T.AfterTele[i] ;
                                if ((*U).Curr == (*U).P.Length){
                                    printf("%s berada di petak %d\n",(*U).Nama,(*U).P.Length);
                                    printf("%s telah mencapai ujung\n",(*U).Nama);
                                    printf("Pemenang game ini adalah %s\n",(*U).Nama);} 
                            }}}
                 else if (P.Map[(*U).Curr - dice1] =='#' || P.Map[(*U).Curr - dice1] < 0 ){
                    printf ("%s tidak dapat bergerak.\n", (*U).Nama);
                }
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
    else if (skill == 6) {
        
    } 
    else if (skill == 7) {
        
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
        else if (Info(q) == 6) {
            printf("%d. Baling Baling Jambu\n", i) ;
        }
        else if (Info(q) == 7) {
            printf("%d. Mesin Waktu\n", i) ;
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

User SKILL (User U, User *U2, Player P, Tele T)  {
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
                            printf("%s berhasil menggunakan Skill Mesin Penukar Posisi !\n", Nama(U)) ;
                            (U).P = UpdateCurrPos(U);
                            (*U2).P = UpdateCurrPos(*U2);
                            printf("Posisi %s dan %s berhasil ditukar !\n", Nama(U), Nama(*U2)) ;
                            use = true ;

                        } else if  (IdxSkill(&SkillList(U), inputCommand) == 6) {
                            printf("%s berhasil menggunakan Baling Baling Jambu !\n", Nama(U)) ;
                            BalingBaling(&(*U2), T, P) ;
                            (*U2).P = UpdateCurrPos(*U2);
                            DelP(&SkillList(U), 6) ;
                            use = false ;

                        } else if  (IdxSkill(&SkillList(U), inputCommand) == 7) {
                            printf("%s berhasil menggunakan Mesin Waktu !\n", Nama(U)) ;
                            MesinWaktu(&(*U2), T, P) ;
                            (*U2).P = UpdateCurrPos(*U2);
                            DelP(&SkillList(U), 7) ;
                            use = false ;
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