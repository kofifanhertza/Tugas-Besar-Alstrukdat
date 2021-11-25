#include <stdio.h>
#include <stdlib.h>
#include "ADT/Skill/listlinier.h"
#include "ADT/PlayerMap/map.h"


int search (Tele T,User P);
void Inspectt(Tele T, Player P);
Tele copyTele(Tele Tawal);


int search (Tele T,User *U){
    int i=0;
    while (T.BeforeTele[i] != (*U).Curr){
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

