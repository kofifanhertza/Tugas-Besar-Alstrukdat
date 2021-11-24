#include"listlinier.h"
#include"boolean.h" 
#include"../Mesin/map.h"

int Randomizer (User U) ;
/* Mengenerate Random Skill berbentuk integer*/


int UseIdxSkill(List *L, int idx, User U) ;
/* Mendapatkan skill pada ke idx dari List L */

int IdxSkill (List *L,  int idx) ;

int DelIdxSkill (List *L,  int idx, User U) ;

int PrintSkill(List L) ;
/* Menampilkan skill yang ada di List*/

int PrintBuff (List L, User U) ;

int CommandSkill (User U) ;

List UseSkill (User U, int x) ;

List DelSkill (User U, int x) ;

List SkillRandomizer (User U) ;

List EmptyBuff (User U) ;

User SKILL (User U, User *U2) ;