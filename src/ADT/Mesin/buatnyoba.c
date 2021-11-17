#include <stdio.h>
#include "mesin_kata.h"

int main(){
    Map User1;
    MakeEmpty(&User1);
    STARTKATA();
    readConfig(User1);
}
