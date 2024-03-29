#include "../Skill/listlinier.h"
#include "../PlayerMap/map.h"
#include "../Mesin/boolean.h"
#include "move.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>    
#include <math.h>


int search (Tele T,User *U){
    int i=0;
    while (T.BeforeTele[i] != (*U).Curr && i <= T.bykTele){
        i = i + 1;}
    if (T.BeforeTele[i] == (*U).Curr && T.AfterTele[i] > 0 && T.AfterTele[i] <= (*U).P.Length){
        return i;}
    else if (T.AfterTele[i] <= 0 || T.AfterTele[i] > (*U).P.Length ){
        return -1;}}

/*Inpect Teleport*/
void Inspectt(Tele T, Player P){
    int X, i;
    char symbol;
    printf("Masukkan petak : "); scanf("%d",&X);

    i = 1;
 
    while (T.BeforeTele[i] != X && i <= T.bykTele){ //Mencari lokasi teleporter dan isi peta
    
        i = i + 1;
    }
    
    
    symbol = P.Map[X];
 
    if (symbol == '#'){
        printf("Petak %d merupakan petak terlarang.\n",X);
    } else { //symbol == '.'
        if (i <= T.bykTele){
            printf("Petak %d memiliki teleporter menuju %d\n",X,T.AfterTele[i]);
        } else { //i > U.P.Length  
            printf("Petak %d merupakan petak kosong.\n",X);
        }
    }

}


Tele copyTele(Tele Tawal){
    Tele T;
    int i;
    (T).bykTele = Tawal.bykTele;
    for (i=IdxMin;i<=Tawal.bykTele;i++){
        (T).BeforeTele[i] = Tawal.BeforeTele[i];
        (T).AfterTele[i] = Tawal.AfterTele[i];
    }
    return (T);
}

void majuin(User *U, int dice){
    Curr(*U) = Curr(*U) + dice;
}

void mundurin(User *U, int dice){
    Curr(*U) = Curr(*U) - dice;
}

void teleporting(User *U, Tele T, int i){
    Curr(*U) = T.AfterTele[i];
}

/*
boolean bisamaju(User *U, int dice){
    int posisi = (*U).Curr;
    posisi += dice;
    if ((*U).P.Map[posisi] == "."){
        return true;
    } else {
        return false;
    }
}

boolean bisamundur(User *U, int dice){
    int posisi = (*U).Curr;
    posisi -= dice;
    if ((*U).P.Map[posisi] == "."){
        return true;
    } else {
        return false;
    }
}
*/

void cekPemenang(User U, User U2){
    if (Curr(U) == Length(U)){
        printf("%s telah mencapai ujung! Permainan selesai.\n", Nama(U));
        printf("Posisi akhir :\n");
        printf("%s berada di petak %d\n", Nama(U),Curr(U));
        printf("%s berada di petak %d\n", Nama(U2),Curr(U2));
        printf("   *********************************************   \n");
        printf("                   .-=========-.      \n");
        printf("                   \\'-=======-'/      \n");
        printf("                   _|   .=.   |_      \n");
        printf("                  ((|  {{1}}  |))     \n");
        printf("                   \\|   /|\\   |/     \n");
        printf("                    \\__ '`' __/      \n");
        printf("                      _`) (`_         \n");
        printf("                    _/_______\\_      \n");
        printf("                   /___________\\     \n");
        printf("   *********************************************   \n");
        printf("        Pemenang game ini adalah %s\n", Nama(U));
        printf("        Peringkat kedua adalah %s\n", Nama(U2));
        printf("   *********************************************   \n");
        //for loop ketika pemain lebih dari 1
        exit(0);
    } else if (Curr(U2) == Length(U2)){
        printf("%s telah mencapai ujung! Permainan selesai. \n", Nama(U));
        printf("Posisi akhir :\n");
        printf("%s berada di petak %d\n", Nama(U2),Curr(U2));
        printf("%s berada di petak %d\n", Nama(U),Curr(U));
        printf("   *********************************************   \n");
        printf("                   .-=========-.      \n");
        printf("                   \\'-=======-'/      \n");
        printf("                   _|   .=.   |_      \n");
        printf("                  ((|  {{1}}  |))     \n");
        printf("                   \\|   /|\\   |/     \n");
        printf("                    \\__ '`' __/      \n");
        printf("                      _`) (`_         \n");
        printf("                    _/_______\\_      \n");
        printf("                   /___________\\     \n");
        printf("   *********************************************   \n");
        printf("        Pemenang game ini adalah %s\n", Nama(U2));
        printf("        Peringkat kedua adalah %s\n", Nama(U));
        printf("   *********************************************   \n");
        //for loop ketika pemain lebih dari 1
        exit(0);
    }
}

void checkTele(User *U, Tele T, int i){
     if (i==-1){
        printf("%s tidak menemukan teleporter\n", Nama(*U));
    } else {
        printf("%s menemukan teleporter\n",  Nama(*U));

        if (Search((*U).ActiveSkill, 1) != Nil){
            int pilihan;
            printf("%s memiliki imunitas teleport.\n",  Nama(*U));
            printf("Apakah %s ingin teleport?\n",  Nama(*U));
            printf("Masukan angka 1 untuk teleport\n") ;
            printf("Masukan angka 0 tidak teleport\n") ;
            printf("Pilihan : ");scanf ("%d", &pilihan);
            if (pilihan==0){
                printf("%s tidak teleport.\n",  Nama(*U));
                printf("Buff imunitas teleport hilang.\n");
            } else {
                if (pilihan==1){
                    printf("%s teleport ke petak %d.\n",  Nama(*U), T.AfterTele[i]);
                    teleporting(&(*U),T,i);
                }
            }
        } else if (Search((*U).ActiveSkill, 1) == Nil){
            printf("%s tidak memiliki imunitas teleport.\n",  Nama(*U));
            printf("%s teleport ke petak %d.\n",  Nama(*U), T.AfterTele[i]);
            teleporting(&(*U),T,i);
        }
    }
}

void roll2(User *U, User *U2, Tele T, Player P){  
    int dice1, i;   
    srand ( time(NULL) );
    int fl;
    fl = floor(((*U).MaxRoll/2));
    if (Search((*U).ActiveSkill, 3) != Nil){ 
        dice1 = (rand()%((*U).MaxRoll-fl+1) + fl);
    } else if (Search((*U).ActiveSkill, 4) != Nil){
        dice1 = (rand()%(fl)) + 1;
    } else{ 
        dice1 =  (rand()%((*U).MaxRoll)) + 1 ; 
    }
    printf ("%s mendapatkan angka %d.\n", (*U).Nama,dice1); 

    //Mengubah posisi berdasarkan map
    //Arena bermain yaitu petak 1 - Length
    //Pemain tidak bisa berpindah pada petak berisi "#" alih-alih "."


    if ((Curr(*U) - dice1) <= 0) { 
        //ketika current position < dice

        if (P.Map[(*U).Curr + dice1] =='#') {
            //Ketika tujuan adalah petak terlarang
            printf ("%s tidak dapat bergerak.\n", Nama(*U));
        } else {
            //Tujuan bukan petak terlarang
            printf ("%s dapat maju.\n", Nama(*U));
            printf ("%s maju %d langkah.\n", Nama(*U),dice1);
            majuin(&(*U),dice1); 
            printf ("%s berada di petak %d.\n", Nama(*U),(*U).Curr);
            
            //Player telah bergerak ke petak tujuan, periksa teleport
            checkTele(&(*U),T,search(T, &(*U)));
            //jika menemukan teleport, akan berpindah tempat kecuali memiliki imunitas  

            cekPemenang(*U, *U2);
        }   
    } else {
        //ketika current position > dice (dapat maju dan dapat mundur)

        //Ketika Current position + dice > finish maka kondisional gagal
        //Solusi : 

        if (Curr(*U) + dice1 <= Length(*U)){
            if ((P.Map[(*U).Curr+dice1] =='#') && (P.Map[(*U).Curr-dice1]=='#')){
                
                //kasus pertama ketika tujuan depan belakang adalah petak terlarang
                printf ("%s tidak dapat bergerak.\n", (*U).Nama); 

            } else if ((P.Map[(*U).Curr+dice1]=='.') && (P.Map[(*U).Curr-dice1]=='.')){

                //kasus kedua ketika tujuan depan belakang adalah petak kosong
                int opsi;
                //pilih tujuan

                printf ("%s dapat maju dan mundur.\n", (*U).Nama);
                printf ("Ke mana %s mau bergerak : \n", (*U).Nama);
                printf ("1. %d\n", (*U).Curr-dice1);
                printf ("2. %d\n", (*U).Curr+dice1);
                
                printf("Masukkan pilihan :\n");scanf ("%d", &opsi);

                if (opsi==1){
                    printf ("%s mundur %d langkah.\n", (*U).Nama,dice1);
                    mundurin(&(*U),dice1);
                } else if (opsi ==2){
                    printf ("%s maju %d langkah.\n", (*U).Nama,dice1);
                    majuin(&(*U),dice1);
                }
                
                
                //informasi update position
                printf ("%s berada di petak %d.\n", (*U).Nama,(*U).Curr);

                //Player telah bergerak ke petak tujuan, periksa teleport
                checkTele(&(*U),T,search(T, &(*U)));
                //jika menemukan teleport, akan berpindah tempat kecuali memiliki imunitas
                
                cekPemenang(*U, *U2);

            } else if ((P.Map[(*U).Curr+dice1]=='.') && (P.Map[(*U).Curr-dice1]=='#')) {

                //kasus ketiga ketika tujuan depan adalah petak kosong dan belakang adalah petak terlarang
                printf ("%s dapat maju.\n", (*U).Nama);
                printf ("%s maju %d langkah.\n", (*U).Nama,dice1);
                majuin(&(*U),dice1);
            
                //informasi update position
                printf ("%s berada di petak %d.\n", (*U).Nama,(*U).Curr);

                //Player telah bergerak ke petak tujuan, periksa teleport
                checkTele(&(*U),T,search(T, &(*U)));
                //jika menemukan teleport, akan berpindah tempat kecuali memiliki imunitas
            
                cekPemenang(*U, *U2);
                
            } else if ((P.Map[(*U).Curr+dice1]=='#') && (P.Map[(*U).Curr-dice1]=='.')){
                
                //kasus keempat ketika tujuan depan adalah petak terlarang dan belakang adalah petak kosong
                //tidak perlu kasus ketika mundur melibihi garis start karena di awal sudah diperiksa 
                printf ("%s dapat mundur\n", (*U).Nama);
                printf ("%s mundur %d langkah\n",(*U).Nama,dice1);
                mundurin(&(*U),dice1);
                //informasi update position
                printf ("%s berada di petak %d.\n", (*U).Nama,(*U).Curr);

                //Player telah bergerak ke petak tujuan, periksa teleport
                checkTele(&(*U),T,search(T, &(*U)));
                //jika menemukan teleport, akan berpindah tempat kecuali memiliki imunitas
            
                cekPemenang(*U, *U2);
            }
        } else {
            //Ketika tujuan melebihi garis finish

            if (P.Map[(*U).Curr-dice1]=='#'){

                //Kasus ketika tujuan belakang adalah petak terlarang
                printf ("%s tidak dapat bergerak.\n", (*U).Nama);
                
            } else {

                //Kasus ketika tujuan belakang adalah petak kosong

                printf ("%s dapat mundur\n", (*U).Nama);
                printf ("%s mundur %d langkah\n",(*U).Nama,dice1);
                mundurin(&(*U),dice1);

                //informasi update position
                printf ("%s berada di petak %d.\n", (*U).Nama,(*U).Curr);

                //Player telah bergerak ke petak tujuan, periksa teleport
                checkTele(&(*U),T,search(T, &(*U)));
                //jika menemukan teleport, akan berpindah tempat kecuali memiliki imunitas
            
                cekPemenang(*U, *U2);
            }
        }
    }
}