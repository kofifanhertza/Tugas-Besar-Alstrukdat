#include "map.h"
#include "../Mesin/mesin_konf.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
User U1, U2;
Tele TP;
int main(){
    SetUser(&U1);
    SetUser(&U2);
    char fileconfig[] = "config.txt";
    printf("Index current U1: %d\n", GetCurrPlace (U1));
    printf("Index current U2: %d\n", GetCurrPlace (U2));
    Konfigurasi(fileconfig, &U1, &U2, &TP);
    U1.P.Map[Curr(U1)] = '*';
    U2.P.Map[Curr(U2)] = '*';
    commandMAP(&U1, &U2);
    U1.Curr += 1;
    U2.Curr += 1;
    U1.P = UpdateCurrPos(U1);
    U2.P = UpdateCurrPos(U2);
    commandMAP(&U1, &U2);
}