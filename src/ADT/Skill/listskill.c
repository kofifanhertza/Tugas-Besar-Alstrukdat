#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include"listskill.h"
#include"time.h"



int Randomizer (User U) {
    int skill, x, superRandom ;
    srand(time(NULL)) ;

    x = rand() % 100 + 1;
    x = rand() % 100 + 1;

    if (x > 0 && x <= 10) {
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

void BalingBaling(User *U, User *U2, Tele T, Player P){  
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
                            printf("Apakah %s ingin menggunakan Skill Pintu Ga Ke Mana Mana ?\n", (*U).Nama);
                            printf("1. Ya\n") ;
                            printf("2. Tidak\n") ;
                            int pilihan;
                            printf("Pilihan : ") ;scanf ("%d", &pilihan);
                            if (pilihan==1){
                                printf("%s tidak teleport.\n", (*U).Nama);
                                DelP(&SkillList(*U), 1) ;
                                printf("Skill Pintu Ga Ke Mana Mana berhasil digunakan !\n") ;}
                                
                            else{
                                if (pilihan==2){
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
                                cekPemenang(*U, *U2) ;
                            }}}
                 else if (P.Map[(*U).Curr+dice1] =='#' || P.Map[(*U).Curr+dice1] > (*U).P.Length){
                    printf ("%s tidak dapat bergerak.\n", (*U).Nama);
                }
        }

void MesinWaktu(User *U, User *U2, Tele T, Player P){  
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
                printf("Apakah %s ingin menggunakan Skill Pintu Ga Ke Mana Mana ?\n", (*U).Nama);
                printf("1. Ya\n") ;
                printf("2. Tidak\n") ;
                printf("Pilihan : ") ;int pilihan;
                scanf ("%d", &pilihan);
                if (pilihan==1){
                    printf("%s tidak teleport.\n", (*U).Nama);
                    DelP(&SkillList(*U), 1) ;
                    printf("Skill Pintu Ga Ke Mana Mana berhasil digunakan !\n") ;
                } else if (pilihan==2){
                    printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                    (*U).Curr = T.AfterTele[i] ;
                    if ((*U).Curr == (*U).P.Length){
                        printf("%s berada di petak %d\n",(*U).Nama,(*U).P.Length);
                        printf("%s telah mencapai ujung\n",(*U).Nama);
                        printf("Pemenang game ini adalah %s\n",(*U).Nama);
                    } 
                }
            } else if (Search((*U).SkillList, 1) == Nil){
                        printf("%s tidak memiliki Pintu Ga Ke Mana Mana.\n", (*U).Nama);
                        printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                        (*U).Curr = T.AfterTele[i] ;
                        cekPemenang(*U, *U2) ;
                    }
        }
    }
    else if ((P.Map[(*U).Curr - dice1] =='#') || (P.Map[(*U).Curr - dice1] < 0) ){
                printf ("%s tidak dapat bergerak.\n", (*U).Nama);
            }
}


void UseIdxSkill (int idx, User *U) {
    int skill, i = 1 ;
    address addrSkill = First((*U).SkillList) ;

    while (i != idx) {
        addrSkill = Next(addrSkill) ;
        i = i + 1 ;
    }
    skill = Info(addrSkill) ;

    if (skill == 1) {
        printf("%s berhasil digunakan Skill Pintu Ga Ke Mana Mana !\n", Nama(*U)) ;
        InsVLast(&ActiveSkill(*U), skill) ; 
    }
    else if (skill == 2) {
        InsVLast(&ActiveSkill(*U), skill) ;  
    }
    else if (skill == 3) {
        printf("%s berhasil digunakan Skill Senter Pembesar Hoki !\n", Nama(*U)) ;
        InsVLast(&ActiveSkill(*U), skill) ;  
    }
    else if (skill == 4) {
        printf("%s berhasil digunakan Skill Senter Pengecil Hoki !\n", Nama(*U)) ;
        InsVLast(&ActiveSkill(*U), skill) ;  
    }
    else if (skill == 5) {
        
    } 
    else if (skill == 6) {
        
    } 
    else if (skill == 7) {
        
    } 
    DelP(&SkillList(*U), skill) ;   
     
    
}

void DelIdxSkill (int idx, User *U) {
    int skill, i = 1 ;
    address addrSkill = First((*U).SkillList) ;

    while (i != idx) {
        addrSkill = Next(addrSkill) ;
        i = i + 1 ;
    }
    skill = Info(addrSkill) ;

    if (skill == 1) {
        printf("%s berhasil membuang Skill Pintu Ga Ke Mana Mana !\n", Nama(*U)) ;
    }
    else if (skill == 2) {
        printf("%s berhasil membuang Skill Cermin Pengganda !\n", Nama(*U)) ;

    }
    else if (skill == 3) {
        printf("%s berhasil membuang Skill Senter Pembesar Hoki !\n", Nama(*U)) ;
    }
    else if (skill == 4) {
        printf("%s berhasil membuang Skill Senter Pengecil Hoki !\n", Nama(*U)) ;
    }
    else if (skill == 5) {
        printf("%s berhasil membuang Skill Mesin Penukar Posisi !\n", Nama(*U)) ;
    }
    else if (skill == 6) {
        printf("%s berhasil membuang Skill Baling Baling Jambu !\n", Nama(*U)) ;
    }
    else if (skill == 7) {
        printf("%s berhasil membuang Skill Mesin Waktu !\n", Nama(*U)) ;
    }

    DelP(&SkillList(*U), skill) ;  
    
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

void PrintSkill (List L) {
    if (IsEmpty(L)) {
        return ;
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
    return  ;
        
}

void PrintBuff (List L, User U) {
    if (IsEmpty(L)) {
        printf("%s tidak memiliki buff", Nama(U)) ;
        return  ;
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
        q = Next(q) ;
        i = i + 1 ;
        }
        return  ;
}

void PrintDesc () {
    int i ;
    printf("Pilih skill yang ingin diketahui deskripsinya\n") ;
    printf("1. Pintu Ga Ke Mana Mana\n") ;
    printf("2. Cermin Pengganda\n") ;
    printf("3. Senter Pengecil Hoki\n") ;
    printf("4. Senter Pembesar Hoki\n") ;
    printf("5. Mesin Penukar Posisi\n") ;
    printf("6. Baling Baling Jambu\n") ;
    printf("7. Mesin Waktu\n") ;
    printf("Pilihan : ") ; 
    scanf("%d", &i) ;

    if (i == 1) {
        printf("\nPINTU GA KE MANA MANA\n") ;
        printf("Chance  : 10%%\n") ;
        printf("Desc    : Gunakan skill ini untuk mendapatkan imunitas teleporter!\n\n") ;
    
    } else if (i == 2){
        printf("\nCERMIN PENGGANDA\n") ;
        printf("Chance  : 6%%\n") ;
        printf("Desc    : Gunakan skill ini untuk mendapatkan 2 skill secara random!\n\n") ;
    
    } else if (i == 3){
        printf("\nSENTER PENGECIL HOKI\n") ;
        printf("Chance  : 15%%\n") ;
        printf("Desc    : Gunakan skill ini untuk memperkecil keluaran dadu!\n\n") ;
    
    } else if (i == 4){
        printf("\nSENTER PEMBESAR HOKI\n") ;
        printf("Chance  : 15%%\n") ;
        printf("Desc    : Gunakan skill ini untuk memperbesar keluaran dadu!\n\n") ;
            
    } else if (i == 5){
        printf("\nMESIN PENUKAR POSISI\n") ;
        printf("Chance  : 4%%\n") ;
        printf("Desc    : Gunakan skill ini untuk menukar posisi dengan pemain lain!\n\n") ;
            
    } else if (i == 6){
        printf("\nBALING BALING JAMBU\n") ;
        printf("Chance  : 10%%\n") ;
        printf("Desc    : Gunakan skill ini untuk membuat pemain lawan maju sebanyak keluaran dadu!\n\n") ;
            
    } else if (i == 7){
        printf("\nMESIN WAKTU\n") ;
        printf("Chance  : 10%%\n") ;
        printf("Desc    : Gunakan skill ini untuk membuat pemain lawan mundur sebanyak keluaran dadu!\n\n") ;
            
    } else {
        printf("\nERROR! Pilihan tidak valid !\n\n") ;
    }
}

int CommandSkill (User U) {
    int x, UsedSkill = 0 ;
    if (IsEmpty(SkillList(U))) {
        printf("%s tidak memiliki skill\n", Nama(U)) ;
        return 0 ;
    }
    
    printf("\n%s memiliki Skill :\n", Nama(U)) ;
    PrintSkill(SkillList(U)) ;
    
    printf("\nMasukkan angka 0 apabila ingin keluar\n") ;
    printf("Masukkan angka negatif apabila ingin membuang skill\n\n") ;
    printf("Masukkan Skill : ") ;
    scanf("%d", &x) ;

    return x ;
}

void CerminPengganda (User *U) {
    int skill1, skill2 ;
    skill1 = Randomizer(*U) ;
    skill2 = Randomizer(*U) ;
    InsVLast(&(*U).SkillList, skill1) ;
    InsVLast(&(*U).SkillList, skill2) ;    
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
                    DelIdxSkill(deleted, &U) ;
    
                    InsVLast(&SkillList(U), skill) ; 
                    return SkillList(U) ;
                }
                else if (option == 2) {
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
    if (!IsEmpty(U.ActiveSkill)) {
        if (Search(U.ActiveSkill, 1) == Nil) {
            while (!IsEmpty(U.ActiveSkill))
            {
                DelFirst(&ActiveSkill(U), &deleted) ;
            }
            
        } else {
            while (Info(First(U.ActiveSkill)) != 1 ) {
                DelFirst(&ActiveSkill(U), &deleted) ;
            }
            while (Next(First(U.ActiveSkill)) != Nil ) {
                DelLast(&ActiveSkill(U), &deleted) ;
            }
        }
    }
    return ActiveSkill(U) ;
}

void SKILL (User *U, User *U2, Player P, Tele T)  {
    int inputCommand = CommandSkill(*U) ;
    if (inputCommand != 0) {
        if (inputCommand > 0) {
            if (inputCommand > NbElmt(SkillList(*U))) {
                printf("Command Error!\n") ;
                return ;
            }
            boolean use = true ;
            if (Search(ActiveSkill(*U), IdxSkill(&SkillList(*U), inputCommand)) != Nil) {
                printf("Gagal menggunakan, Skill sudah aktif!\n") ;
            } else {
                if (IdxSkill(&SkillList(*U), inputCommand) == 2) {
                    if (NbElmt(SkillList(*U)) > 9) {
                        printf("Cermin Pengganda Gagal Digunakan\n") ;
                        use = false ;
                    } else {
                        printf("%s berhasil digunakan Skill Cermin Pengganda !\n", (*U).Nama) ;
                        CerminPengganda(U) ;
                        use = true ;
                    }
                }
                if (IdxSkill(&SkillList(*U), inputCommand) == 3) {
                    if (Search(ActiveSkill(*U), 4) != Nil) {
                        printf("Gagal menggunakan skill, Skill Pembesar dan pengecil tidak bisa digunakan bersamaan!\n") ;
                        use = false ;
                    } 
                } else if (IdxSkill(&SkillList(*U), inputCommand) == 4) {
                    if (Search(ActiveSkill(*U), 3) != Nil) {
                        printf("Gagal menggunakan skill, Skill Pembesar dan pengecil tidak bisa digunakan bersamaan!\n") ;
                        use = false ;
                    } 
                } else if (IdxSkill(&SkillList(*U), inputCommand) == 5) {
                    int tempCurr ; 
                    tempCurr = (*U).Curr ;
                    (*U).Curr = (*U2).Curr ;
                    (*U2).Curr = tempCurr ;
                    printf("%s berhasil menggunakan Skill Mesin Penukar Posisi !\n", Nama(*U)) ;
                    (*U).P = UpdateCurrPos(*U);
                    (*U2).P = UpdateCurrPos(*U2);
                    printf("Posisi %s dan %s berhasil ditukar !\n", Nama(*U), Nama(*U2)) ;
                    DelP(&SkillList(*U), 5) ;
                    use = false ;

                } else if  (IdxSkill(&SkillList(*U), inputCommand) == 6) {
                    printf("%s berhasil menggunakan Baling Baling Jambu !\n", Nama(*U)) ;
                    BalingBaling(&(*U2),&(*U), T, P) ;
                    (*U2).P = UpdateCurrPos(*U2);
                    DelP(&SkillList(*U), 6) ;
                    use = false ;

                } else if  (IdxSkill(&SkillList(*U), inputCommand) == 7) {
                    printf("%s berhasil menggunakan Mesin Waktu !\n", Nama(*U)) ;
                    MesinWaktu(&(*U2),&(*U), T, P) ;
                    (*U2).P = UpdateCurrPos(*U2);
                    DelP(&SkillList(*U), 7) ;
                    use = false ;
                }
                if (use == true) {
                    UseIdxSkill(inputCommand, U) ;
                }
            }      
        } else if (inputCommand < 0) {
            inputCommand = inputCommand * -1 ;
            if (inputCommand > NbElmt(SkillList(*U))) {
                printf("Command Error!\n") ;
                return ;
            }
            DelIdxSkill(inputCommand, U) ;
        }
    }
}