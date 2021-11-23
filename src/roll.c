#include "ADT/Mesin/map.h"
#include "ADT/Mesin/mesin_kata.h"
#include "ADT/Skill/listlinier.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll(User U, Tele T, Player P){
    int i;
    int dice1;
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
        // tidak dapat bergerak
        if ((P.Map[U.Curr+dice1] =='#') && (P.Map[U.Curr-dice1]=='#')){
            printf ("%s tidak dapat bergerak.\n", U.Nama); }
        else {
            //dapat gereak ke dua petak
            if ((P.Map[U.Curr+dice1]=='.') && (P.Map[U.Curr-dice1]=='.')){
                printf ("%s dapat maju dan mundur.\n", U.Nama);
                printf ("Ke mana %s mau bergerak : \n", U.Nama);
                printf ("1. %d\n", U.Curr-dice1);
                printf ("2. %d\n", U.Curr+dice1);
                int opsi;
                printf("Masukkan pilihan :\n");
                scanf ("%d", &opsi);
                if (opsi==1){
                    printf ("%s mundur %d langkah.\n", U.Nama,dice1);
                    U.Curr = U.Curr-dice1;}
                else if (opsi ==2){
                    printf ("%s maju %d langkah.\n", U.Nama,dice1);
                    U.Curr = U.Curr+dice1;}
                printf ("%s berada di petak %d.\n", U.Nama,U.Curr);}
                // tidak menemukan teleport
                if (P.Map[U.Curr] != T.BeforeTele[i]){
                    printf("%s tidak menemukan teleporter.\n", U.Nama);}
                // ketemu teleport
                else if (P.Map[U.Curr] == T.BeforeTele[i]){
                    printf("%s menemukan teleporter.\n", U.Nama);}
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
            //dapat bergerak ke satu petak (maju) / mundur
            else if (((P.Map[U.Curr+dice1]=='.') && (P.Map[U.Curr-dice1]=='#')) || ((P.Map[U.Curr+dice1]=='.') && (P.Map[U.Curr-dice1] < 0)) ){
                    printf ("%s dapat maju.\n", U.Nama);
                    printf ("%s maju %d langkah.\n", U.Nama,dice1);
                    U.Curr = U.Curr+dice1;
                    printf ("%s berada di petak %d.\n", U.Nama,U.Curr); 
                    if (P.Map[U.Curr] != T.BeforeTele[i]){
                        printf("%s tidak menemukan teleporter", U.Nama);}
                    else if (P.Map[U.Curr] == T.BeforeTele[i]){
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
                            }}
                //dapat bergerak ke satu petak (mundur)  
                else if ((P.Map[U.Curr+dice1]=='#') && (P.Map[U.Curr-dice1]=='.')){
                    printf ("%s dapat mundur\n", U.Nama);
                    printf ("%s mundur %d langkah\n",U.Nama,dice1);
                    U.Curr = U.Curr-dice1;
                    printf ("%s berada di petak %d\n", U.Nama,U.Curr);
                    if (P.Map[U.Curr] != T.BeforeTele[i]){
                        printf("%s tidak menemukan teleporter", U.Nama);}
                    else if (P.Map[U.Curr] == T.BeforeTele[i]){
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
                        else{
                        printf("%s tidak memiliki imunitas teleport.\n", U.Nama);
                        printf("%s teleport ke petak %d.\n", U.Nama, T.AfterTele[i]);  
                                }}
                    else if (P.Map[U.Curr] ==  P.Length ){
                        printf("%s telah mencapai ujung", U.Nama);
                        printf("Pemenang game ini adalah %s", U.Nama);

                    } 
        }   
    return U.Curr;
}
