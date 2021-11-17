#include <stdio.h>
#include "mesin_kata.h"

#include <stdio.h>
#include "mesin_kata.h"

int main(){
    Map User1;
    MakeEmpty(&User1);
    STARTKATA();
    User1 = readConfig(User1);
    printf("baca lagi: \n");
    printf("Panjang peta: %d\n", User1.Length);
    outputMap(User1);
    printf("Panjang Maxroll: %d\n", User1.MaxRoll);
    printf("%d\n", User1.MaxRoll);

}
