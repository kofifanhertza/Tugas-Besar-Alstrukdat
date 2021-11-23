#include "ADT/Mesin/map.h"
#include "ADT/Mesin/mesin_kata.h"
#include "ADT/Skill/listlinier.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>    

void roll2(User U, Tele T, Player P){  
    int dice1, i;   
    srand ( time(NULL) );
    if (Search(U.ActiveSkill, 3) != Nil){ 
        dice1 = (rand()%(U.MaxRoll-(U.MaxRoll/2)+1)) + (U.MaxRoll/2);
    }
    else if (Search(U.ActiveSkill, 4) != Nil){
        dice1 = (rand()%(U.MaxRoll/2)) + 1;
    }
    else{ 
    dice1 = ((rand()%(U.MaxRoll)) + 1);}
    printf ("%s mendapatkan angka %d.\n", U.Nama,dice1); 
        if ((U.Curr - dice1) <= 0) {
            if (P.Map[U.Curr+dice1] =='.') {
                printf ("%s dapat maju.\n", U.Nama);
                    printf ("%s maju %d langkah.\n", U.Nama,dice1);
                    U.Curr = U.Curr+dice1;
                    printf ("%s berada di petak %d.\n", U.Nama,U.Curr);
                    i = search(T, U);
                    if (U.Curr != T.BeforeTele[i]){
                        printf("%s tidak menemukan teleporter\n", U.Nama);}
                    else if (U.Curr == T.BeforeTele[i]){
                        printf("%s menemukan teleporter", U.Nama);}
                        if (Search(U.ActiveSkill, 1) != Nil){
                            printf("%s memiliki imunitas teleport.\n", U.Nama);
                            printf("Apakah %s ingin teleport (Y/N) ?\n", U.Nama);
                            char pilihan;
                            scanf ("%c", &pilihan);
                            if (pilihan=='N'){
                                printf("%s tidak teleport.\n", U.Nama);
                                printf("Buff imunitas teleport hilang.\n");}
                            else{
                                if (pilihan=='Y'){
                                    printf("%s teleport ke petak %d.\n", U.Nama, T.AfterTele[i]);}}}
                        else if (Search(U.ActiveSkill, 1) == Nil){
                        printf("%s tidak memiliki imunitas teleport.\n", U.Nama);
                        printf("%s teleport ke petak %d.\n", U.Nama, T.AfterTele[i]); 
                            }
                } else if (P.Map[U.Curr+dice1] =='#'){
                    printf ("%s tidak dapat bergerak.\n", U.Nama);
                }
            }
        }