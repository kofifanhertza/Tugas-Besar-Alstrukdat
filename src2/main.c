
#include "ADT/PlayerMap/map.h"
#include "ADT/Mesin/mesin_konf.h"
#include "ADT/Skill/listskill.h"
#include "ADT/Stack/stacklist.h"
#include "ADT/move/move.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

boolean endGame=false;
int rondeKe;
User U1, U2;
Tele TP;
//User U1, U2;



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
    // printf("     ****                                3. Load Game                              ****   \n");
    printf("     **********************************************************************************   \n");
}

void MainMenu(int *inputmenu){
    printf("Masukkan command :\n>");
    printf("\x1b[1m"); //bold
    InputAngka(inputmenu);
    printf("\x1b[0m");
    while (*inputmenu!=1 && *inputmenu!=2 && *inputmenu!=3){
        printf("Input tidak terdefinisi, silahkan masukan angka menu\n");
        printf("Masukkan command :\n> ");
        printf("\x1b[1m"); //bold
        InputAngka(inputmenu);
        printf("\x1b[0m");
    }
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




void startTurn(roundInfo *R,Tele *T, Round *Game){
    int count=1;
    printf("\nGiliran %s Nih...\n", ((*R).Player[0]).Nama);

    (*R).Player[0].ActiveSkill = EmptyBuff((*R).Player[0]) ;
    (*R).Player[0].SkillList = SkillRandomizer((*R).Player[0]) ;
    commandMAP(&(*R).Player[0], &(*R).Player[1]) ;
    char input[10];
    boolean endTurn = false;
    boolean roll = false ;
    while (!endTurn){
        
        printf("Masukkan Command: ");
        scanf(" %s", input);

        if (strcmp(input, "SKILL") == 0) {
            if (!roll) {
                SKILL(&((*R).Player[0]), &((*R).Player[1]),((*R).Player[0]).P, *T);
            } else {
                printf("%s tidak bisa menggunakan skill karena sudah bergerak!\n", Nama((*R).Player[0])) ;
            }
        } else if (strcmp(input, "MAP") == 0){
            commandMAP(&(*R).Player[0], &(*R).Player[1]) ;
        } else if (strcmp(input, "DESC") == 0) {
            PrintDesc() ;
        } else if (strcmp(input, "BUFF") == 0){
            PrintBuff(((*R).Player[0]).ActiveSkill, ((*R).Player[0]));
            printf("\n");
        } else if (strcmp(input, "INSPECT") == 0){
            Inspectt(*T, ((*R).Player[0]).P) ;
        } else if (strcmp(input, "ROLL") == 0){
            if (count < 2) {
            roll2(&((*R).Player[0]), &((*R).Player[1]), *T, ((*R).Player[0]).P);
            ((*R).Player[0]).P = UpdateCurrPos((*R).Player[0]);
            count += 1;
            commandMAP(&(*R).Player[0], &(*R).Player[1]) ;
            roll = true ;                
            } else {
                printf("Tidak boleh roll lagi! \n");
            }

        } else if (strcmp(input, "SAVE") == 0){
            //bismillah
        } else if (strcmp(input, "UNDO") == 0){
            if (R->rondeKe != 1) {
                PopR(Game, R);
            }
        
            endTurn = true ;

        } else if (strcmp(input, "ENDTURN") == 0){
            if (roll == false) {
                printf("Belum roll, tidak boleh endturn!\n");
            }
            else {
                int count=1;
                printf("\nGiliran %s Nih...\n", ((*R).Player[1]).Nama);
                ((*R).Player[1]).ActiveSkill = EmptyBuff((*R).Player[1]) ;
                ((*R).Player[1]).SkillList = SkillRandomizer((*R).Player[1]) ;
                commandMAP(&(*R).Player[0], &(*R).Player[1]) ;
                char input[10];
                boolean endTurn = false;
                boolean roll = false ;
                while (!endTurn){
                    
                    printf("Masukkan Command: ");
                    scanf(" %s", input);

                    if (strcmp(input, "SKILL") == 0) {
                        if (!roll) {
                            SKILL(&((*R).Player[1]), &((*R).Player[0]),((*R).Player[1]).P, *T);
                        } else {
                            printf("%s tidak bisa menggunakan skill karena sudah bergerak!\n", Nama((*R).Player[1])) ;
                        }
                    } else if (strcmp(input, "MAP") == 0){
                        commandMAP(&(*R).Player[0], &(*R).Player[1]) ;
                    } else if (strcmp(input, "DESC") == 0) {
                        PrintDesc() ;
                    } else if (strcmp(input, "BUFF") == 0){
                        PrintBuff(((*R).Player[1]).ActiveSkill, ((*R).Player[1]));
                        printf("\n");
                    } else if (strcmp(input, "INSPECT") == 0){
                        Inspectt(*T, ((*R).Player[1]).P) ;
                    } else if (strcmp(input, "ROLL") == 0){
                        if (count < 2) {
                        roll2(&((*R).Player[1]), &((*R).Player[0]), *T, ((*R).Player[1]).P);
                        ((*R).Player[1]).P = UpdateCurrPos((*R).Player[1]);
                        count += 1;
                        commandMAP(&(*R).Player[0], &(*R).Player[1]) ;
                        roll = true ;                
                        } else {
                            printf("Tidak boleh roll lagi! \n");
                        }

                    } else if (strcmp(input, "SAVE") == 0){
                        //bismillah
                    } else if (strcmp(input, "UNDO") == 0){
                        endTurn = true ;

                    } else if (strcmp(input, "ENDTURN") == 0){
                        if (roll == false) {
                            printf("Belum roll, tidak boleh endturn!\n");
                            endTurn = false ;
                        }
                        else {
                            printf("\n*********************\n") ;
                            PrintSkill((*R).Player[0].SkillList) ;
                            PrintSkill((*R).Player[1].SkillList) ;
                            printf("\n*********************\n") ;
                            R->rondeKe = R->rondeKe + 1 ;
                            PushR(Game, *R);
                            endTurn = true;
                            
                        }
                    } else if (strcmp(input, "EXIT") == 0){
                        printf("Keluar dari game\n") ;
                        endTurn = true;
                        endGame = true;
                        exit(0);
                    } else {
                        printf("Error! command is not correct.\n");
                    }
                }
                
            } 
            
            if (roll!= false){
                endTurn = true ;
            } else {
                endTurn = false ;
            }
        
        } else if (strcmp(input, "EXIT") == 0){
            printf("Keluar dari game\n") ;
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


void startRonde(Tele *T, Round *Game){
    boolean endGame = false;
    boolean undo = false;
    
    roundInfo R ;
    R = Game->TOP->Info ;
    int n = R.rondeKe ;

   
    printf("\nTeng teng... Ronde ke-%d dimulaii \n",n);
    
    startTurn(&R,T, Game);
 
    
}

boolean isWExist(User *U1, User *U2) {
    // Permainan akan berakhir jika sudah ada satu pemain yang mencapai petak N.
    return (Curr(*U1) == (*U1).P.Length || Curr(*U2) == (*U2).P.Length);
}

/* void permainanBerlangsung(int n, User *U1, User *U2, Tele *T, Round *Game){
    int lanjut;
    printf("Apakah Anda ingin lanjut ke ronde berikutnya? Ketik '1' untuk 'Ya,' dan '0' untuk 'Tidak': ");scanf("%d", &lanjut);
    while ((lanjut != 1) && (lanjut != 0)) {
        printf("Masukkan salah. Ulangi lagi!\n");
        printf("Apakah Anda ingin lanjut ke ronde berikutnya? Ketik '1' untuk 'Ya,' dan '0' untuk 'Tidak': ");scanf("%d", &lanjut);
        }
    if (lanjut == 0) {
        endGame = true;
        exit(0) ;}
    else if (lanjut == 1) {
            printf("Curr: %d  %d\n", (*U1).Curr, (*U2).Curr);
            //PrintSkill()
            startRonde(n, U1, U2, T, Game);
    }
} */

void awalPermainan(int inputmenu, User *U1, User *U2, Tele *T, Round *Game){
    
        if (inputmenu == 1){
        printf("Selanjutnya Konfigurasi Map (meminta input nama file konfigurasi map)\n");

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

        (*U1).Curr = IdxMin;
        (*U2).Curr = IdxMin;
        char fileConfig[10];
        printf("Masukkan nama file konfigurasi level: "); scanf("%s",fileConfig);
        Konfigurasi(fileConfig, U1, U2, T);
        (*U1).P.Map[1] = '*';
        (*U2).P.Map[1] = '*';
        roundInfo R;
        R.rondeKe = 1;
        R.Player[0] = *U1;
        R.Player[1] = *U2;
        PushR(Game,R);

        

        

    } else if (inputmenu == 2){
        endGame = true;
        printf("Berhasil keluar dari game.\n");
        
        //Keluar dari game.

        
    } else if (inputmenu == 3){
        printf("Mengakses file konfigurasi dan save yang menyimpan state sebelumnya. \nSave juga bisa menyimpan konfigurasi level, jadi tidak perlu file konfigurasi lagi.\n");
        
                
        char fileConfig[10];
        scanf("Masukkan nama file konfigurasi level yang telah disimpan: %s",fileConfig);
        Konfigurasi(fileConfig, U1, U2,T);

    }
}

void saveRound(User *U1, User *U2, Round *Game, int n) {
    printf("ini adalah metode save:\n");
    roundInfo R;
    R.Player[0] = *U1 ;
    R.Player[1] = *U2 ;
    R.rondeKe = n;
    PushR(Game, R);
}

int main(){
    loading(3);
    delay(250);
    Logo();
    printf("\n");
    delay(250);
    int inputmenu;
    MainMenu(&inputmenu);
    rondeKe = 0;
    Round Game;
    CreateEmptyRS(&Game);
    awalPermainan(inputmenu, &U1, &U2, &TP, &Game);
    //printf("Curr Player 1 : %d", Game.TOP->Info.Player[0].Curr);
    while (isWExist(&U1, &U2) != true && endGame != true) {
        //printf("Curr: %d  %d\n", (U1).Curr, (U2).Curr);
        //CreateEmptyRound(&R);

        
        startRonde(&TP, &Game);
        //saveRound(&U1, &U2,&Game,rondeKe);
        


        /*
        User save1,save2;
        save1 = CurrRonde(Game).Player[0];
        save2 = CurrRonde(Game).Player[1];
        printf("Curr : %d %d", Curr(save1),Curr(save2));*/
    }
    printf("Permainan berakhir\n");
}