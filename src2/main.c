
//#include "./ADT/List/boolean.h"
//#include "./ADT/List/listdp.h"
//#include "./ADT/List/listlinier.h"
//#include "./ADT/List/queuelist.h"
//#include "./ADT/List/stacklist.h"
#include "ADT/PlayerMap/map.h"
#include "ADT/Mesin/mesin_konf.h"
#include "ADT/Skill/listlinier.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
boolean endGame;
int rondeKe;
User U1, U2;
//User U1, U2;

/*void Inspectt(Tele T, Player P){
    int X, i;
    char symbol;
    printf("Masukkan petak : "); scanf("%d",&X);

    i = 1;
 
    while (T.BeforeTele[i] != X && i <= T.bykTele){ //Mencari lokasi teleporter dan isi peta
    
        i = i + 1;
    }
    
    
    symbol = P.Map[X];
 
    if (symbol == '#'){
        printf("Petak %d merupakan petak terlarang.\n",X);
    } else { //symbol == '.'
        if (i <= T.bykTele){
            printf("Petak %d memiliki teleporter menuju %d\n",X,T.AfterTele[i]);
        } else { //i > U.P.Length  
            printf("Petak %d merupakan petak kosong.\n",X);
        }
    }

}*/

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
    printf("\n");
    printf("                             /^\\/^\\                                              \n"); 
    printf("                           _|__|  O|                                              \n"); 
    printf("                  \\/     /~     \\_/ \\                                           \n"); 
    printf("                   \\____|__________/  \\                                          \n"); 
    printf("                          \\_______      \\                                        \n"); 
    printf("                                  `\\     \\                 \\                    \n"); 
    printf("                                    |     |                  \\                    \n"); 
    printf("                                   /      /                    \\                  \n"); 
    printf("                                  /     /                       \\                \n"); 
    printf("                                /      /                         \\ \\             \n"); 
    printf("                               /     /                            \\  \\           \n"); 
    printf("                             /     /             _----_            \\   \\         \n"); 
    printf("                            /     /           _-~      ~-_         |   |          \n"); 
    printf("                           (      (        _-~    _--_    ~-_     _/   |          \n"); 
    printf("                            \\      ~-____-~    _-~    ~-_    ~-_-~    /          \n"); 
    printf("                              ~-_           _-~          ~-_       _-~            \n"); 
    printf("                                 ~--______-~                ~-___-~               \n"); 
    printf("\n");
    printf("        __  ___      __    _ __                                   ______                   \n");
    printf("       /  |/  /___  / /_  (_) /_____ _____  ____ _____ _____ _   / ____/___ _____ ___  ___ \n");
    printf("      / /|_/ / __ \\/ __ \\/ / __/ __ `/ __ \\/ __ `/ __ `/ __ `/  / / __/ __ `/ __ `__ \\/ _ \\\n");
    printf("     / /  / / /_/ / /_/ / / /_/ /_/ / / / / /_/ / /_/ / /_/ /  / /_/ / /_/ / / / / / /  __/\n");
    printf("    /_/  /_/\\____/_.___/_/\\__/\\__,_/_/ /_/\\__, /\\__, /\\__,_/   \\____/\\__,_/_/ /_/ /_/\\___/\n");
    printf("                                         /____//____/                                     \n");
    printf("                                                                                          \n");
    printf("     **********************************************************************************   \n");
    printf("     ****                               ==MAIN MENU==                              ****   \n");
    printf("     ****                                1. New Game                               ****   \n");
    printf("     ****                                2. Exit                                   ****   \n");
    printf("     ****                                3. Load Game                              ****   \n");
    printf("     **********************************************************************************   \n");
}

void MainMenu(int *inputmenu){
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
/*
void readConfig(User *U, Tele *T, char fileconfig[]){
    int i;
    SetUser(U);

    STARTKATA(fileconfig);
    (*U).P = readPlayer((*U).P);
    
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

/*
void Konfigurasi(char fileconfig[], User *U1, User *U2, Tele *TP){
    //Memulai permainan
    /*
    int nplayer;
    scanf("Masukkan jumlah pemain: %d", &nplayer);

    for(int i = 0;i<nplayer;i++){
        char name;scanf("Masukkan nama pemain: %s",name);
        Player P1;
        Tele TP1;
        readConfig(&P,&TP); 
    }
    
    printf("Masukkan Nama Player 1 : ");scanf("%s", ((*U1).Nama));
    printf("\nMasukkan Nama Player 2 : ");scanf("%s", ((*U2).Nama));
    readConfig(&(*U1),&(*TP), fileconfig);
    printf("*****************************\n");
    printf("\n\n");
    (*U1).MaxRoll = (*U1).P.MaxRollAwal;
    printf("Player 1 : %s\n", (*U1).Nama);
    printConfig(&((*U1).P), &(*TP));
    printf("MaxRoll Player 1 saat ini: %d\n", (*U1).MaxRoll); //MaxRoll seorang user dapat berubah di tengah permainan
    ((*U2).P) = copyPlayer((*U1).P);
    
    //TPdup = copyTele(TP1);
    printf("\n\n");
    (*U2).MaxRoll = (*U2).P.MaxRollAwal;
    printf("Player 2 : %s\n", (*U2).Nama);
    printConfig(&((*U2).P), &(*TP));
    printf("MaxRoll Player 2 saat ini: %d\n", (*U2).MaxRoll);
}*/
/*
void printConfig(Player *P, Tele *T){

    printf("Panjang peta: %d\n", (*P).Length);
    
    outputPlayerMap((*P));printf("\n");
    
    printf("MaxRoll Awal:%d\n", (*P).MaxRollAwal); //MaxRollAwal sesuai dengan file konfigurasi

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
*/

void startTurn(User *U1, User *U2, Tele T){
    printf("Giliran %s Nih...\n", (*U1).Nama);
    (*U1).ActiveSkill = EmptyBuff(*U1) ;
    (*U1).SkillList = SkillRandomizer(*U1) ;
    commandMAP(U1, U2);
    char input[10];
    boolean endTurn = false;
    while (!endTurn){
        
        printf("Masukkan Command: ");
        scanf(" %s", input);

        if (strcmp(input, "SKILL") == 0) {
            *U1 = SKILL((*U1), &(*U2));
        } else if (strcmp(input, "MAP") == 0){
            commandMAP(U1, U2);
        } else if (strcmp(input, "BUFF") == 0){
            PrintBuff((*U1).ActiveSkill, (*U1));
            printf("\n");
        } else if (strcmp(input, "INSPECT") == 0){
            Inspectt(T, (*U1).P) ;
        } else if (strcmp(input, "ROLL") == 0){
            roll2(&(*U1), T, (*U1).P);
            printf("%d\n",(*U1).Curr);
            (*U1).P = UpdateCurrPos(*U1);
            commandMAP(U1, U2);
        } else if (strcmp(input, "SAVE") == 0){
            //bismillah
        } else if (strcmp(input, "UNDO") == 0){
            //bismillah
        } else if (strcmp(input, "ENDTURN") == 0){
            endTurn = true;
            break;
        } else if (strcmp(input, "EXIT") == 0){
            endTurn = true;
            endGame = true;
            exit(0);
        } else {
            printf("Error! command is not correct.\n");
        }
    }
    //setiap turn memunculkan konfigurasi peta, 
    //buff Cermin Pengganda, Senter Pembesar Hoki dan Senter Pengecil Hoki akan di-reset, 
    //serta pemain akan mendapatkan 1 skill secara random.
}


void startRonde(int n, User *U1, User *U2, Tele T){
    int ronde;//not yet complete
    boolean endGame = false;
   
    printf("Teng teng... Ronde ke-%d dimulaii \n",n);
    startTurn(U1,U2,T);
    startTurn(U2,U1,T);
    
}
boolean isWExist(User U1, User U2) {
    // Permainan akan berakhir jika sudah ada satu pemain yang mencapai petak N.
    return (Curr(U1) >= U1.P.Length || Curr(U2) >= U2.P.Length);
}
void permainanBerlangsung(int n, User U1, User U2, Tele T){
    int lanjut;
    printf("Apakah Anda ingin lanjut ke ronde berikutnya? Ketik 'Y' untuk 'Ya,' dan 'N' untuk 'Tidak': ");scanf("%d", &lanjut);
    if (lanjut == 0) {
        endGame = true;
        exit(0) ;
    }
    else {
    while (!isWExist(U1,U2) && !endGame  && lanjut != 0) {
        printf("Apakah Anda ingin lanjut ke ronde berikutnya? Ketik 'Y' untuk 'Ya,' dan 'N' untuk 'Tidak': ");scanf("%d", &lanjut); 
        if (lanjut == 1) {
                startRonde(n, &U1, &U2, T); 
                n++;
        } else if (lanjut == 0) {
            endGame == true;
        } else {
            printf("\nMasukkan salah. Ulangi lagi\n");
        }
     }        
  }

};
void awalPermainan(int inputmenu, User U1, User U2, Tele T){
    
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

        U1.Curr = IdxMin;
        U2.Curr = IdxMin;
        char fileConfig[10];
        printf("Masukkan nama file konfigurasi level: "); scanf("%s",fileConfig);
        Konfigurasi(fileConfig, &U1, &U2, &T);
        U1.P.Map[1] = '*';
        U2.P.Map[1] = '*';
        rondeKe = 1;
        startRonde(rondeKe, &U1, &U2, T); //Ronde pertama
        rondeKe++;
        

    } else if (inputmenu == 2){
        endGame = true;
        printf("Keluar dari game, break all process.\n");
        
        //Keluar dari game.

        
    } else if (inputmenu == 3){
        printf("Mengakses file konfigurasi dan save yang menyimpan state sebelumnya. \nSave juga bisa menyimpan konfigurasi level, jadi tidak perlu file konfigurasi lagi.\n");
        
                
        char fileConfig[10];
        scanf("Masukkan nama file konfigurasi level yang telah disimpan: %s",fileConfig);
        Konfigurasi(fileConfig, &U1, &U2,&T);

    }
}
int main(){
    loading(3);
    delay(250);
    Logo();
    printf("\n");
    delay(250);
    Tele TP;
    int inputmenu;
    MainMenu(&inputmenu);
    awalPermainan(inputmenu, U1, U2, TP);
    permainanBerlangsung(rondeKe, U1, U2, TP);



}