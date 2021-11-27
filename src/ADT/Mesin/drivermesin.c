#include "mesin_konf.h"
#include <stdio.h>
#include <stdlib.h>

#include "../PlayerMap/map.h"
#include "mesin_konf.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
Tele TP;
User U1, U2;
void printConfig(Player *P, Tele *T);
void printConfig(Player *P, Tele *T){

    printf("Panjang peta: %d\n", (*P).Length);
    
    outputPlayerMap((*P));printf("\n");
    
    printf("MaxRoll Awal:%d\n", (*P).MaxRollAwal); //MaxRollAwal sesuai dengan file konfigurasi

    printf("Banyak tele:%d\n", (*T).bykTele);
    
    printf("Before: ");
    for(int i=1;i<=(*T).bykTele;i++) {   
        printf("%d ", (*T).BeforeTele[i]);}
    printf("\n");
    
    printf("After: ");
    for(int i=1;i<=(*T).bykTele;i++) {   
        printf("%d ", (*T).AfterTele[i]);
    }
    
    printf("\n");
    
}
int main(){
    char fileConfig[] = "config.txt";
    Konfigurasi(fileConfig, &U1, &U2, &TP);
    printf("\n%s lawan %s\n", U1.Nama, U2.Nama);
    (U1).P.Map[1] = '*';
    (U2).P.Map[1] = '*';
    printConfig(&(U1.P), &TP);
    printConfig(&(U2.P), &TP);


}
