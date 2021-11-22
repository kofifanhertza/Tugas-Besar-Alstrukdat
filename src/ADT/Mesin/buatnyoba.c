#include <stdio.h>
#include "mesin_kata.h"
#include "mesin_kar.h"
#include "map.h"


void Inspect(Tele T, Player P){
    int X, i;
    char symbol;
    printf("Masukkan petak : "); scanf("%d",&X);

    i = 1;
    while (T.BeforeTele[i] != X && i <= T.bykTele){ //Mencari lokasi teleporter dan isi peta
        i = i + 1;
        symbol = P.Map[i];
    }
    
    if (symbol == '#'){
        printf("Petak %d merupakan petak terlarang.",X);
    } else { //symbol == '.'
        if (i <= P.Length){
            printf("Petak %d memiliki teleporter menuju %d",X,T.AfterTele[i]);
        } else { //i > U.P.Length  
            printf("Petak %d merupakan petak kosong.",X);
        }
    }

}


void commandMAP(){
    printf("%s      : ", U1.Nama);
    outputPlayerMap(U1.P);
    printf(" %d\n", Curr(U1));
    printf("%s      : ", U2.Nama);
    outputPlayerMap(U2.P);
    printf(" %d\n", Curr(U2));
}
int main(){
    int i;
    Tele T;
    Player User1;
    SetPlayer(User1);
    STARTKATA("config.txt");
    User1 = readPlayer(User1);
    /*
    printf("baca lagi: \n");
    printf("Panjang peta: %d\n", User1.Length);
    outputPlayerMap(User1);
    printf("MaxRoll:%d\n", User1.MaxRollAwal);
    */
    
    T = readTele(T);
    /*
    printf("Byk tele:%d\n", T.bykTele);
    printf("Before: ");
    for(i=1;i<=T.bykTele;i++) {   
        printf("%d ", T.BeforeTele[i]);}
    printf("\n");
    printf("After: ");
    for(i=1;i<=T.bykTele;i++) {
        printf("%d ", T.AfterTele[i]);
    }
    printf("\n");
    */
    Inspect(T,User1);
}
