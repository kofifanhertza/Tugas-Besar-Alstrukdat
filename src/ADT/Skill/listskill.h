#include"listlinier.h"
#include"boolean.h" 
#include"../PlayerMap/map.h"
#include "../move/move.h"

int Randomizer (User U) ;
// Mengenerate random skil berbentuk integer

void BalingBaling(User *U, User *U2, Tele T, Player P) ;
// Implementasi dari skill baling baling jambu

void MesinWaktu(User *U,User *U2, Tele T, Player P) ;
// Implementasi dari Mesin Waktu

void UseIdxSkill (int idx, User *U) ;
// Menggunakan skill pada ke indeks ke idx dari sebuah SkillList

int IdxSkill (List *L,  int idx) ;
// Mendapatkan skill pada indeks ke idx dari sebuah SkillList

void DelIdxSkill (int idx, User *U) ;
// Menghapus skill pada indeks ke idx dari SkillList

void PrintSkill(List L) ;
// Menampilkan skill yang ada di List

void PrintDesc () ;
// Menampilkan deskripsi setiap skill

void PrintBuff (List L, User U) ;
// Mendapatkan buff yang dimiliki user

int CommandSkill (User U) ;
// Mengatur inputan untuk menggunakan/menghapus skill

List SkillRandomizer (User U) ;
// Menghasilkan Skilllist setelah terjadi randomizer

List EmptyBuff (User U) ;
// Menghapus buff yang sudah dipakai

void SKILL (User *U, User *U2, Player P, Tele T) ;
// Implementasi commnad skill, menggunakan semua fungsi yang ada diatas