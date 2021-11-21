#include <stdio.h>
#include "mesin_kata.c"
#include "mesin_kar.c"
#include "map.c"

int main(){
    int i;
    Tele T;
    Player User1;
    SetPlayer(User1);
    STARTKATA();
    User1 = readPlayer(User1);
    printf("baca lagi: \n");
    printf("Panjang peta: %d\n", User1.Length);
    outputPlayerMap(User1);
    printf("MaxRoll:%d\n", User1.MaxRollAwal);

    
    T = readTele(T);
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
}
