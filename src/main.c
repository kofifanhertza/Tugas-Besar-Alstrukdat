
//#include "./ADT/List/boolean.h"
//#include "./ADT/List/listdp.h"
//#include "./ADT/List/listlinier.h"
//#include "./ADT/List/queuelist.h"
//#include "./ADT/List/stacklist.h"
#include "ADT/Mesin/map.h"
#include "ADT/Mesin/mesin_kata.h"
//#include "./Skill/listdp.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void InputAngka(int *angka)
/* Membaca input angka dari user */
/* Nanti ini dimasukkin ADT Mesin Karakter aja*/
{
    scanf("%d", angka);
}

/*
void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}*/

void delay(int milli_seconds)
{
    // Converting time into milli_seconds
    /*int milli_seconds = 1000 * number_of_seconds;*/
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void loading(int n){
    printf("loading");
    for(int i = 0;i<n;i++){
        delay(200);
        printf(".");    
    }
    printf("\n");
    delay(1000);
    printf("[");
    for(int i = 0;i<30;i++){
        delay(50);
        printf("|");    
    }
    printf("]\n");

}
  

void Logo(){
    printf(" ___________ \n");
    printf("|           |\n");
    printf("|     I     |\n");
    printf("|     N     |\n");
    printf("|     I     |\n");
    printf("|           |\n");
    printf("|     L     |\n");
    printf("|     O     |\n");
    printf("|     G     |\n");
    printf("|     O     |\n");
    printf("|___________|\n");
}

void MainMenu(int *inputmenu){
    printf("MAIN MENU:\n");
    printf("     1. NEW GAME\n");
    printf("     2. EXIT\n");
    printf("     3. LOAD GAME\n");
    printf("Masukkan command :\n>");
    printf("\x1b[1m"); //bold
    InputAngka(inputmenu);
    printf("\x1b[0m");
    while (*inputmenu!=1 && *inputmenu!=2 && *inputmenu!=3){
        printf("Input tidak terdefinisi, silahkan masukan angka menu\n");
        printf("Masukkan command :\n>");
        printf("\x1b[1m"); //bold
        InputAngka(inputmenu);
        printf("\x1b[0m");
    }
} 

void readConfig(Player *P, Tele *T){
    int i;
    SetPlayer(*P);

    STARTKATA();
    *P = readPlayer(*P);
    
    *T = readTele(*T);
}

/*
void Teleport(Tele *T){
    *T = readTele(*T);
    printf("Byk tele:%d\n", (*T).bykTele);
    
    printf("Before: ");
    for(int i=1;i<=(*T).bykTele;i++) {   
        printf("%d ", (*T).BeforeTele[i]);}
    printf("\n");
    
    printf("After: ");
    for(int i=1;i<=(*T).bykTele;i++) {   
        printf("%d ", (*T).AfterTele[i]);
    }
    printf("\n");
}*/


void Konfigurasi(char fileconfig){
    //Memulai permainan
    /*
    int nplayer;
    scanf("Masukkan jumlah pemain: %d", &nplayer);

    for(int i = 0;i<nplayer;i++){
        char name;scanf("Masukkan nama pemain: %s",name);
        Player P1;
        Tele TP1;
        readConfig(&P,&TP); 
    }*/
    User U1, U2;
    printf("Masukkan Nama Player 1 : ");scanf("%s", (U1.Nama));
    printf("\nMasukkan Nama Player 2 : ");scanf("%s", (U2.Nama));
    Tele TP1, TP2;
    readConfig(&(U1.P),&(TP1));
    printf("*****************************\n");
    printf("\n\n");
    (U1).MaxRoll = U1.P.MaxRollAwal;
    printf("Player 1 : %s\n", (U1).Nama);
    printConfig(&(U1.P), &(TP1));
    printf("MaxRoll Player 1 saat ini: %d\n", U1.MaxRoll);
    (U2.P) = copyPlayer(U1.P);
    TP2 = copyTele(TP1);
    printf("\n\n");
    (U2).MaxRoll = U2.P.MaxRollAwal;
    printf("Player 2 : %s\n", (U2).Nama);
    printConfig(&(U2.P), &(TP2));
    printf("MaxRoll Player 2 saat ini: %d\n", U2.MaxRoll);
}

void printConfig(Player *P, Tele *T){

    printf("Panjang peta: %d\n", (*P).Length);
    
    outputPlayerMap((*P));
    
    printf("MaxRoll Awal:%d\n", (*P).MaxRollAwal);

    printf("Byk tele:%d\n", (*T).bykTele);
    
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
/*
void startTurn(Player *P){
    char input;
    scanf("Masukkan command: %s",input);

    switch(input)
    {
        case 'SKILL':
            //panggil fungsi untuk menggunakan atau membuang skill
        case 'MAP':
            //panggil prosedur untuk mencetak MAP di layar dan menunjukkan posisi setiap player
        case 'BUFF':
            //panggil prosedur untuk menampilkan daftar buff yang sedang dimiliki pemain
        case 'INSPECT':
            //menerawang petak 'x' untuk menunjukkan keberadaan teleporter
        case 'ROLL':
            //melakukan giliran rolling dadu untuk bergerak
            //kalo player sampai finish, endGame = true
        case 'SAVE':
            //panggil fungsi untuk menggunakan atau membuang skill
        case 'UNDO':
            //panggil fungsi untuk menggunakan atau membuang skill
        case 'ENDTURN':
            //panggil fungsi untuk menggunakan atau membuang skill
        default:
            printf("Error! command is not correct.");
    }
}


void startRonde(int n, Player *P1, Player *P2){
    int ronde;//not yet complete
    boolean endGame = false;
    while (!endGame){
        startTurn(P1);
        startTurn(P2);
    }
}
*/

int main(){
    loading(3);
    delay(250);
    Logo();
    printf("\n");
    delay(250);

    int inputmenu;
    MainMenu(&inputmenu);
    if (inputmenu == 1){
        printf("Selanjutnya Konfigurasi Map (meminta input nama file konfigurasi map)\n ");

        //Jalankan game dengan metode new game
        //Meminta input nama file konfigurasi level
        //KonfigurasiMap(Nama File Konfigurasi level)

        //Input n jumlah pemain (2-4)
        //Input nama-nama pemain

        //Start Game --> Command() 
        //Prosedur Start Game akan menjalankan permainan mulai dari Ronde 1 turn orang ke-1...orang ke-n dengan memanggil prosedur Command() dan menampilkan peta

        //Prosedur Command() akan meminta input command dari player yang sedang bermain(seperti Skill, Map, Buff, Inspect, Roll, Save, hingga player memasukkan EndTurn/Undo)
        //Prosedur Command() akan terus berjalan hingga terdapat satu pemenang (setiap ronde berakhir akan memanggil prosedur savestate, ronde berakhir ketika semua pemain telah menyelesaikan turn atau ketika terdapat pemenang)
        //Ketika terdapat pemain yang mencapai garis finish, memanggil prosedur Finish() yang akan menampilkan nama pemenang berdasarkan peringkat dan informasi bahwa game telah berakhir
        //kembali ke MainMenu


        char fileConfig;
        scanf("Masukkan nama file konfigurasi level: %s",fileConfig);
        Konfigurasi(fileConfig);

        //startRonde();
        



    } else if (inputmenu == 2){
        printf("Keluar dari game, break all process.\n");
        

        //Keluar dari game.

        
    } else if (inputmenu == 3){
        printf("Mengakses file konfigurasi dan save yang menyimpan state sebelumnya. \nSave juga bisa menyimpan konfigurasi level, jadi tidak perlu file konfigurasi lagi.\n");
        
        //Jalankan game dengan metode load game
        //KonfigurasiMap(Nama File Konfigurasi level) dan file eksternal (savestate terakhir yang pernah dimainkan oleh n pemain)
        //Memanggil prosedur Load() dan memberikan informasi bila load game berhasil atau gagal

        //Start Game --> Command()  (jika load berhasil)
        //Prosedur Start Game akan menjalankan permainan mulai dari savestate terakhir dengan menampilkan peta dan memulai turn sesuai urutan yang ada(urutan ditentukan/dirandom(?))

        //Prosedur Command() akan meminta input command dari player yang sedang bermain(seperti Skill, Map, Buff, Inspect, Roll, Save, hingga player memasukkan EndTurn/Undo)
        //Prosedur Command() akan terus berjalan hingga terdapat satu pemenang (setiap ronde berakhir akan memanggil prosedur savestate, ronde berakhir ketika semua pemain telah menyelesaikan turn atau ketika terdapat pemenang)
        //Ketika terdapat pemain yang mencapai garis finish, memanggil prosedur Finish() yang akan menampilkan nama pemenang berdasarkan peringkat dan informasi bahwa game telah berakhir
        //kembali ke MainMenu        
                
                
        char fileConfig;
        scanf("Masukkan nama file konfigurasi level yang telah disimpan: %s",fileConfig);
        Konfigurasi(fileConfig);

    }
}