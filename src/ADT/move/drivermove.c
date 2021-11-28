#include "../PlayerMap/map.h"
#include "move.h"
#include "../Skill/listlinier.h"
#include <string.h>
#include <stdio.h>

int main(){
    Tele T;
    User U1,U2;
    (U1).Curr = 2;
    // strcpy((P.Map),"....##..") ;
    (U1).P.Map[1]='.';
    (U1).P.Map[2]='.';
    (U1).P.Map[3]='.';
    (U1).P.Map[4]='.';
    (U1).P.Map[5]='.';
    (U1).P.Map[6]='#';
    (U1).P.Map[7]='#';
    (U1).P.Map[8]='.';
    (U1).P.Map[9]='.';
    (U1).P.Map[8]='.';
    T.BeforeTele[0]= 1;
    T.BeforeTele[1]= 2;
    T.AfterTele[0] = 3;
    T.AfterTele[1] = 5;
    (U1).MaxRoll = 6;
    int num;
    scanf("%d",&num);
    printf("%d\n",num);
    if (num==1){
        printf("mampus\n");
        roll2((&U1),(&U2),T,(U1).P);
        printf("yu bisa yu");}
    else {
        return 0;}
}
