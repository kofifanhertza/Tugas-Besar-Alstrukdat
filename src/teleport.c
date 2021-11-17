#include <stdio.h>
#include <stdlib.h>
#include "listlinier.c"

int search (int *Tele1, int curr){
    int i=0;
    while (Tele1[i]!=curr){
        i = i + 1;}
    if (Tele1[i]==curr){
        return i;}
    else {
        return -1;}}

int teleport (int curr, int *Tele1, int *Tele2){
    int a = search(Tele1,curr);
    if (a!=-1){
        curr = Tele2[a];}
    return curr;}

/*int main(){
    int Tele1[]={1,2,5};
    int Tele2[]={6,7,8};
    int curr = teleport(,Tele1,Tele2);
    printf ("%d", curr);
}*/

