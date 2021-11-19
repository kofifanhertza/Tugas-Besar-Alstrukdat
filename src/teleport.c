#include <stdio.h>
#include <stdlib.h>
#include "listlinier.c"
#include "map.h"

int search (Tele T,Player P){
    int i=0;
    while (T.BeforeTele[i] != P.Curr){
        i = i + 1;}
    if (T.BeforeTele[i] == P.Curr){
        return i;}
    else {
        return -1;}}

int teleport (Tele T, Player P){
    int a = search(T, P);
    if (a!=-1){
        P.Curr = T.AfterTele[a];}
    return P.Curr;}

