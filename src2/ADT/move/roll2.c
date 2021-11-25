#include "ADT/PlayerMap/map.h"
#include "ADT/Skill/listlinier.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>    

void roll2(User *U, Tele T, Player P){  
    int dice1, i;   
    srand ( time(NULL) );
    if (Search((*U).ActiveSkill, 3) != Nil){ 
        dice1 = (rand()%((*U).MaxRoll-((*U).MaxRoll/2)+1)) + ((*U).MaxRoll/2);
    }
    else if (Search((*U).ActiveSkill, 4) != Nil){
        dice1 = (rand()%((*U).MaxRoll/2)) + 1;
    }
    else{ 
    dice1 = 3 ;}

    printf ("%s mendapatkan angka %d.\n", (*U).Nama,dice1); 
        if (((*U).Curr - dice1) <= 0) {
            if (P.Map[(*U).Curr+dice1] =='.') {
                printf ("%s dapat maju.\n", (*U).Nama);
                    printf ("%s maju %d langkah.\n", (*U).Nama,dice1);
                    (*U).Curr = (*U).Curr+dice1;
                    printf ("%s berada di petak %d.\n", (*U).Nama,(*U).Curr);
                    i = search(T, &(*U));
                    if (i==-1){
                        printf("%s tidak menemukan teleporter\n", (*U).Nama);}
                    else if (i!=-1){
                        printf("%s menemukan teleporter\n", (*U).Nama);
                        if (Search((*U).ActiveSkill, 1) != Nil){
                            printf("%s memiliki imunitas teleport.\n", (*U).Nama);
                            printf("Apakah %s ingin teleport (Y/N) ?\n", (*U).Nama);
                            int pilihan;
                            scanf ("%d", &pilihan);
                            if (pilihan==1){
                                printf("%s tidak teleport.\n", (*U).Nama);
                                printf("Buff imunitas teleport hilang.\n");}
                            else{
                                if (pilihan==0){
                                    printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                    (*U).Curr = T.AfterTele[i] ; }}}
                        else if (Search((*U).ActiveSkill, 1) == Nil){
                                printf("%s tidak memiliki imunitas teleport.\n", (*U).Nama);
                                printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                // ChangeCurrPlace((*U), T.AfterTele[i]) ; 
                                (*U).Curr = T.AfterTele[i] ; 
                            }}}
                 else if (P.Map[(*U).Curr+dice1] =='#'){
                    printf ("%s tidak dapat bergerak.\n", (*U).Nama);
                }
            }
            else {
                if ((P.Map[(*U).Curr+dice1] =='#') && (P.Map[(*U).Curr-dice1]=='#')){
                    printf ("%s tidak dapat bergerak.\n", (*U).Nama); }
                
                else if ((P.Map[(*U).Curr+dice1]=='.') && (P.Map[(*U).Curr-dice1]=='.')){
                        printf ("%s dapat maju dan mundur.\n", (*U).Nama);
                        printf ("Ke mana %s mau bergerak : \n", (*U).Nama);
                        printf ("1. %d\n", (*U).Curr-dice1);
                        printf ("2. %d\n", (*U).Curr+dice1);
                        int opsi;
                        printf("Masukkan pilihan :\n");
                        scanf ("%d", &opsi);
                        if (opsi==1){
                            printf ("%s mundur %d langkah.\n", (*U).Nama,dice1);
                            (*U).Curr = (*U).Curr-dice1;}
                        else if (opsi ==2){
                            printf ("%s maju %d langkah.\n", (*U).Nama,dice1);
                            (*U).Curr = (*U).Curr+dice1;}
                        printf ("%s berada di petak %d.\n", (*U).Nama,(*U).Curr);
                        i = search(T, &(*U));
                            if (i==-1){
                                printf("%s tidak menemukan teleporter\n", (*U).Nama);}
                            else if (i!=-1){
                                printf("%s menemukan teleporter\n", (*U).Nama);
                                if (Search((*U).ActiveSkill, 1) != Nil){
                                    printf("%s memiliki imunitas teleport.\n", (*U).Nama);
                                    printf("Apakah %s ingin teleport (Y/N) ?\n", (*U).Nama);
                                    int pilihan;
                                    scanf ("%d", &pilihan);
                                    if (pilihan==1){
                                        printf("%s tidak teleport.\n", (*U).Nama);
                                        printf("Buff imunitas teleport hilang.\n");}
                                    else{
                                        if (pilihan==0){
                                            printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                            (*U).Curr = T.AfterTele[i] ; }}}
                                else if (Search((*U).ActiveSkill, 1) == Nil){
                                        printf("%s tidak memiliki imunitas teleport.\n", (*U).Nama);
                                        printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                        // ChangeCurrPlace((*U), T.AfterTele[i]) ; 
                                        (*U).Curr = T.AfterTele[i] ; 
                            }}}
                    else if ((P.Map[(*U).Curr+dice1]=='.') && (P.Map[(*U).Curr-dice1]=='#')) {
                            printf ("%s dapat maju.\n", (*U).Nama);
                            printf ("%s maju %d langkah.\n", (*U).Nama,dice1);
                            (*U).Curr = (*U).Curr+dice1;
                            printf ("%s berada di petak %d.\n", (*U).Nama,(*U).Curr); 
                            i = search(T, U);
                            if (i==-1){
                                printf("%s tidak menemukan teleporter\n", (*U).Nama);}
                            else if (i!=-1){
                                printf("%s menemukan teleporter\n", (*U).Nama);
                                if (Search((*U).ActiveSkill, 1) != Nil){
                                    printf("%s memiliki imunitas teleport.\n", (*U).Nama);
                                    printf("Apakah %s ingin teleport (Y/N) ?\n", (*U).Nama);
                                    int pilihan;
                                    scanf ("%d", &pilihan);
                                    if (pilihan==1){
                                        printf("%s tidak teleport.\n", (*U).Nama);
                                        printf("Buff imunitas teleport hilang.\n");}
                                    else{
                                        if (pilihan==0){
                                            printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                            (*U).Curr = T.AfterTele[i] ; }}}
                                else if (Search((*U).ActiveSkill, 1) == Nil){
                                        printf("%s tidak memiliki imunitas teleport.\n", (*U).Nama);
                                        printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                        // ChangeCurrPlace((*U), T.AfterTele[i]) ; 
                                        (*U).Curr = T.AfterTele[i] ; 
                            }}}
                        //dapat bergerak ke satu petak (mundur)  

                    else if ((P.Map[(*U).Curr+dice1]=='#') && (P.Map[(*U).Curr-dice1]=='.')){
                        printf ("%s dapat mundur\n", (*U).Nama);
                        printf ("%s mundur %d langkah\n",(*U).Nama,dice1);
                        (*U).Curr = (*U).Curr-dice1;
                        printf ("%s berada di petak %d\n", (*U).Nama,(*U).Curr);
                        i = search(T, &(*U));
                        if (i==-1){
                            printf("%s tidak menemukan teleporter\n", (*U).Nama);}
                        else if (i!=-1){
                            printf("%s menemukan teleporter\n", (*U).Nama);
                            if (Search((*U).ActiveSkill, 1) != Nil){
                                printf("%s memiliki imunitas teleport.\n", (*U).Nama);
                                printf("Apakah %s ingin teleport (Y/N) ?\n", (*U).Nama);
                                int pilihan;
                                scanf ("%d", &pilihan);
                                if (pilihan== 1){
                                    printf("%s tidak teleport.\n", (*U).Nama);
                                    printf("Buff imunitas teleport hilang.\n");}
                                else{
                                    if (pilihan== 0){
                                        printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                        (*U).Curr = T.AfterTele[i] ; }}}
                            else if (Search((*U).ActiveSkill, 1) == Nil){
                                    printf("%s tidak memiliki imunitas teleport.\n", (*U).Nama);
                                    printf("%s teleport ke petak %d.\n", (*U).Nama, T.AfterTele[i]);
                                    // ChangeCurrPlace((*U), T.AfterTele[i]) ; 
                                    (*U).Curr = T.AfterTele[i] ; 
                            }}}
                    
            

    
         else if ((*U).Curr == (*U).P.Length){
                        printf("%s berada di petak %d\n",(*U).Nama,(*U).P.Length);
                        printf("%s telah mencapai ujung\n",(*U).Nama);
                        printf("Pemenang game ini adalah %s\n",(*U).Nama);
}}
            
}
 