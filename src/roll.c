#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int roll(Player P){
 int dice1;
 srand ( time(NULL) );
 dice1 = (rand()%Maxroll + 1);
 printf ("%s mendapatkan angka %d\n", Nama,dice1);
    if ((P.Curr+dice1 =='#') && (P.Curr-dice1=='#')){
         printf ("%s tidak dapat bergerak", Nama); }
    else {
        if ((P.Curr+dice1=='.') && (TI[curr-dice1]=='.')){
            printf ("%s dapat maju dan mundur\n", Nama);
            printf ("Ke mana %s mau bergerak : \n", Nama);
            printf ("1. %d\n", (curr+1-dice1));
            printf ("2. %d\n", (curr+1+dice1));
            int opsi;
            printf("Masukkan pilihan :\n");
            scanf ("%d", &opsi);
            if (opsi==1){
                printf ("%s mundur %d langkah\n", Nama,dice1);
                curr = (curr - dice1);}
            else if (opsi ==2){
                printf ("%s maju %d langkah\n", Nama,dice1);
                curr = (curr + dice1);}
            printf ("%s berada di petak %d\n", Nama,curr+1);}
        else if (((TI[curr+dice1]=='.') && (TI[curr-dice1]=='#')) || ((TI[curr+dice1]=='.') && (curr - dice1 < 0)) ){
            printf ("%s dapat maju\n", Nama);
            printf ("%s maju %d langkah\n", Nama,dice1);
            curr = (curr + dice1);
            printf ("%s berada di petak %d\n", Nama,curr+1); /*isi nanti
            if curr == Tele[i]{
                ISI NANTI}*/}
        else if ((TI[curr+dice1]=='#') && (TI[curr-dice1]=='.')){
            printf ("%s dapat mundur\n", Nama);
            printf ("%s mundur %d langkah\n",Nama,dice1);
            curr = (curr - dice1);
            printf ("%s berada di petak %d\n", Nama,curr+1); /*isi nanti
            if teleporter found {
                ISI NANTI}*/}
    }            
    return curr;
}


/*buat tes aja
int main(){
    int curr = roll(0,".....#..","Tan",4);
}
*/
