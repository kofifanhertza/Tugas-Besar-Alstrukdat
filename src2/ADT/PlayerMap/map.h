#include "../Mesin/boolean.h"
#include "../Skill/listlinier.h"


#ifndef ARRAY_H 
#define ARRAY_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1


/* Definisi elemen dan koleksi objek */
//typedef int IdxType;
//typedef char ElType;
typedef int IdxType;
typedef char ElType;


typedef struct
{
	ElType Map [IdxMax-IdxMin+1]; /* penyimpanan isi peta; "." atau "#" atau "*" */
	int Length;
	int MaxRollAwal;
} Player;
typedef struct {
	char Nama[10];
	Player P;
	int Curr;
	int MaxRoll;
	List SkillList ;
	List ActiveSkill;
} User;

extern User U1, U2;

 //di-extern supaya bisa diakses di semua file yang include map.h

typedef int IdxType;
typedef char ElType;
typedef struct
{
   int BeforeTele [IdxMax-IdxMin+1];
   int AfterTele [IdxMax-IdxMin+1];
   int bykTele;
} Tele;
#define Curr(U) (U).Curr
#define Nama(U) (U).Nama
// #define Map(U) (U).P.Map
#define Length(U) (U).P.Length
#define Map(P) (P).Map



/* untuk menginisialisasi player dengan peta kosong */
void outputPlayerMap(Player P); /*mengeluarkan peta player*/
Player copyPlayer(Player Pawal);
void commandMAP(User *U1, User *U2);
Player UpdateCurrPos(User U);
void SetUser(User *U);

int GetCurrPlace (User U);

#endif