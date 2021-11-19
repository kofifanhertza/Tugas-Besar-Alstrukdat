#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int roll(Player P, Tele T){
 int dice1;
 srand ( time(NULL) );
 dice1 = (rand()%Maxroll + 1);
 printf ("%s mendapatkan angka %d\n", P.Name,dice1);
    if ((P.Curr+dice1 =='#') && (P.Curr-dice1=='#')){
         printf ("%s tidak dapat bergerak", P.Name); }
    else {
        if ((P.Curr+dice1=='.') && (P.Curr-dice1=='.')){
            printf ("%s dapat maju dan mundur\n", P.Name);
            printf ("Ke mana %s mau bergerak : \n", P.Name);
            printf ("1. %d\n", P.Curr-dice1);
            printf ("2. %d\n", P.Curr+dice1);
            int opsi;
            printf("Masukkan pilihan :\n");
            scanf ("%d", &opsi);
            if (opsi==1){
                printf ("%s mundur %d langkah\n", P.Name,dice1);
                P.Curr = P.Curr-dice1;}
            else if (opsi ==2){
                printf ("%s maju %d langkah\n", P.Name,dice1);
                P.Curr = P.Curr+dice1;}
            printf ("%s berada di petak %d\n", P.Name,P.Curr);}
            if (P.Curr != T.BeforeTele[i]){
                printf("%s tidak menemukan teleporter", P.Name);}
            else if (P.Curr == T.BeforeTele[i]){
                printf("%s menemukan teleporter", P.Name);}//isi lagi nanti
        else if (((P.Curr+dice1=='.') && (P.Curr-dice1=='#')) || ((P.Curr+dice1=='.') && (P.Curr-dice1 < 0)) ){
            printf ("%s dapat maju\n", P.Name);
            printf ("%s maju %d langkah\n", P.Name,dice1);
            P.Curr = P.Curr+dice1;
            printf ("%s berada di petak %d\n", P.Name,P.Curr); 
            if (P.Curr != T.BeforeTele[i]){
                printf("%s tidak menemukan teleporter", P.Name);}
            else if (P.Curr == T.BeforeTele[i]){
                printf("%s menemukan teleporter", P.Name);}//isi lagi nanti
               
        else if ((P.Curr+dice1=='#') && (P.Curr-dice1]=='.')){
            printf ("%s dapat mundur\n", P.Name);
            printf ("%s mundur %d langkah\n",P.Name,dice1);
            P.Curr = P.Curr-dice1;
            printf ("%s berada di petak %d\n", P.Name,P.Curr);
            if (P.Curr != T.BeforeTele[i]){
                printf("%s tidak menemukan teleporter", P.Name);}
            else if (P.Curr == T.BeforeTele[i]){
                printf("%s menemukan teleporter", P.Name);}//isi lagi nanti
    }            
    return P.Curr;
}



