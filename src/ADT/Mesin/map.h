#include "boolean.h"
#include "../../Skill/listlinier.h"

#ifndef ARRAY_H 
#define ARRAY_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1


/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef char ElType;

typedef struct
{
	ElType Map [IdxMax-IdxMin+1]; /* penyimpanan isi peta; "." atau "#" atau "*" */
	int Length;
	int MaxRollAwal;
} Player;

typedef struct
{
   int BeforeTele [IdxMax-IdxMin+1];
   int AfterTele [IdxMax-IdxMin+1];
   int bykTele;
} Tele;

typedef struct {
	char Nama[10];
	Player P;
	int Curr;
	int MaxRoll;
	List SkillList ;
	List ActiveSkill ;
} User;

void SetPlayer (Player P); /* untuk menginisialisasi player dengan peta kosong */
void outputPlayerMap(Player P); /*mengeluarkan peta player*/
Player copyPlayer(Player Pawal);
Tele copyTele(Tele Tawal);
void printConfig(Player *P, Tele *T);
/*
char CheckPetak (Player P, IdxType i); // mengecheck kondisi suatu petak dalam peta
int GetCurrPlace (Player P); //mengeluarkan indeks lokasi Player berada
void ChangeCurrPlace(Player P, IdxType idxAfter); //memindahkan posisi player
*/
#endif