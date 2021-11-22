#include "map.h"
#include "mesin_kata.h"
#include "ADT/Skill/listlinier.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int roll(User P, Tele T, Player U){
    int i;
    int dice1;
    srand ( time(NULL) );
    if (Search(P.ActiveSkill, 3) != Nil){ 
        dice1 = (rand()%(P.MaxRoll-(P.MaxRoll/2)+1)) + (P.MaxRoll/2);
        DelP(&P.ActiveSkill, 3) ;
    }
    else if (Search(P.ActiveSkill, 4) != Nil){
        dice1 = (rand()%(P.MaxRoll/2)) + 1;
        DelP(&P.ActiveSkill, 4) ;
    }
    else{
        dice1 = (rand()%(P.MaxRoll)) + 1;}
    printf ("%s mendapatkan angka %d.\n", P.Nama,dice1);
        // tidak dapat bergerak
        if ((P.Curr+dice1 =='#') && (P.Curr-dice1=='#')){
            printf ("%s tidak dapat bergerak.\n", P.Nama); }
        else {
            //dapat gereak ke dua petak
            if ((P.Curr+dice1=='.') && (P.Curr-dice1=='.')){
                printf ("%s dapat maju dan mundur.\n", P.Nama);
                printf ("Ke mana %s mau bergerak : \n", P.Nama);
                printf ("1. %d\n", P.Curr-dice1);
                printf ("2. %d\n", P.Curr+dice1);
                int opsi;
                printf("Masukkan pilihan :\n");
                scanf ("%d", &opsi);
                if (opsi==1){
                    printf ("%s mundur %d langkah.\n", P.Nama,dice1);
                    P.Curr = P.Curr-dice1;}
                else if (opsi ==2){
                    printf ("%s maju %d langkah.\n", P.Nama,dice1);
                    P.Curr = P.Curr+dice1;}
                printf ("%s berada di petak %d.\n", P.Nama,P.Curr);}
                // tidak menemukan teleport
                if (P.Curr != T.BeforeTele[i]){
                    printf("%s tidak menemukan teleporter.\n", P.Nama);}
                // ketemu teleport
                else if (P.Curr == T.BeforeTele[i]){
                    printf("%s menemukan teleporter.\n", P.Nama);}
                    if (Search(P.ActiveSkill, 1) != Nil){
                        printf("%s memiliki imunitas teleport.\n", P.Nama);
                        printf("Apakah %s ingin teleport (Y/N) ?\n", P.Nama);
                        char pilihan;
                        scanf ("%c", &pilihan);
                        if (pilihan=='N'){
                            printf("%s tidak teleport.\n", P.Nama);
                            printf("Buff imunitas teleport hilang.\n");}
                        else{
                            if (pilihan=='Y'){
                                printf("%s teleport ke petak %d.\n", P.Nama, T.AfterTele[i]);}}}
                    else if (Search(P.ActiveSkill, 1) == Nil){
                    printf("%s tidak memiliki imunitas teleport.\n", P.Nama);
                    printf("%s teleport ke petak %d.\n", P.Nama, T.AfterTele[i]);  
                        }
            //dapat bergerak ke satu petak (maju) / mundur
            else if (((P.Curr+dice1=='.') && (P.Curr-dice1=='#')) || ((P.Curr+dice1=='.') && (P.Curr-dice1 < 0)) ){
                    printf ("%s dapat maju.\n", P.Nama);
                    printf ("%s maju %d langkah.\n", P.Nama,dice1);
                    P.Curr = P.Curr+dice1;
                    printf ("%s berada di petak %d.\n", P.Nama,P.Curr); 
                    if (P.Curr != T.BeforeTele[i]){
                        printf("%s tidak menemukan teleporter", P.Nama);}
                    else if (P.Curr == T.BeforeTele[i]){
                        printf("%s menemukan teleporter", P.Nama);}
                        if (Search(P.ActiveSkill, 1) != Nil){
                            printf("%s memiliki imunitas teleport.\n", P.Nama);
                            printf("Apakah %s ingin teleport (Y/N) ?\n", P.Nama);
                            char pilihan;
                            scanf ("%c", &pilihan);
                            if (pilihan=='N'){
                                printf("%s tidak teleport.\n", P.Nama);
                                printf("Buff imunitas teleport hilang.\n");}
                            else{
                                if (pilihan=='Y'){
                                    printf("%s teleport ke petak %d.\n", P.Nama, T.AfterTele[i]);}}}
                        else{
                        printf("%s tidak memiliki imunitas teleport.\n", P.Nama);
                        printf("%s teleport ke petak %d.\n", P.Nama, T.AfterTele[i]); 
                            }}
                //dapat bergerak ke satu petak (mundur)  
                else if ((P.Curr+dice1=='#') && (P.Curr-dice1=='.')){
                    printf ("%s dapat mundur\n", P.Nama);
                    printf ("%s mundur %d langkah\n",P.Nama,dice1);
                    P.Curr = P.Curr-dice1;
                    printf ("%s berada di petak %d\n", P.Nama,P.Curr);
                    if (P.Curr != T.BeforeTele[i]){
                        printf("%s tidak menemukan teleporter", P.Nama);}
                    else if (P.Curr == T.BeforeTele[i]){
                        printf("%s menemukan teleporter", P.Nama);}
                        if (Search(P.ActiveSkill, 1) != Nil){
                            printf("%s memiliki imunitas teleport.\n", P.Nama);
                            printf("Apakah %s ingin teleport (Y/N) ?\n", P.Nama);
                            char pilihan;
                            scanf ("%c", &pilihan);
                            if (pilihan=='N'){
                                printf("%s tidak teleport.\n", P.Nama);
                                printf("Buff imunitas teleport hilang.\n");}
                            else{
                                if (pilihan=='Y'){
                                    printf("%s teleport ke petak %d.\n", P.Nama, T.AfterTele[i]);}}}
                        else{
                        printf("%s tidak memiliki imunitas teleport.\n", P.Nama);
                        printf("%s teleport ke petak %d.\n", P.Nama, T.AfterTele[i]);  
                                }}
                    else if (P.Curr ==  U.Length ){
                        printf("%s telah mencapai ujung", P.Nama);
                        printf("Pemenang game ini adalah %s", P.Nama);

                    } 
                    
                    }
        return P.Curr;
}
