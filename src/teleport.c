#include <stdio.h>
#include <stdlib.h>
#include "listlinier.c"
#include "map.h"

int search (Tele T,User P){
    int i=0;
    while (T.BeforeTele[i] != P.Curr){
        i = i + 1;}
    if (T.BeforeTele[i] == P.Curr){
        return i;}
    else {
        return -1;}}

int teleport (Tele T, User P){
    int a = search(T, P);
    if (a!=-1){
        P.Curr = T.AfterTele[a];}
    return P.Curr;}

/*Inpect Teleport*/
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
