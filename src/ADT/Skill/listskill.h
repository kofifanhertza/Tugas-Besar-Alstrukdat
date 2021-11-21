#include"listlinier.h"
#include"boolean.h" 
#include"../Mesin/map.h"

int Randomizer () ;
/* Mengenerate Random Skill berbentuk integer*/


int UseIdxSkill(List *L, int idx) ;
/* Mendapatkan skill pada ke idx dari List L */

int IdxSkill (List *L,  int idx) ;

int DelIdxSkill (List *L,  int idx) ;

int PrintSkill(List L) ;
/* Menampilkan skill yang ada di List*/

int PrintBuff (List L) ;

int CommandSkill (User U) ;

List UseSkill (User U, int x) ;

List DelSkill (User U, int x) ;

List SkillRandomizer (User U) ;

User SKILL (User U) ;