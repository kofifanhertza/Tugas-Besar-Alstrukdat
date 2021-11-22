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
void Inspect(Tele T, User U){
    int X, i;
    char symbol;
    printf("Masukkan petak : "); scanf("%s",X);

    i = 1;
    while (T.BeforeTele[i] != X && i <= U.P.Length){ //Mencari lokasi teleporter
        i = i + 1;
        symbol = U.P.Map[i];
    }

    if (symbol == '#'){
        printf("Petak %d merupakan petak terlarang.",X);
    } else { //symbol == '.'
        if (i <= U.P.Length){
            printf("Petak %d memiliki teleporter menuju %d",X,T.AfterTele[i]);
        } else { //i > U.P.Length  
            printf("Petak %d merupakan petak kosong.",X);
        }
    }

}
