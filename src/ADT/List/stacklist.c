/*
Nama    : Kofifan Hertza Haribowo   
NIM     : 18220022
Topik   : Stack dan Queue dengan List*/

#include "boolean.h"
#include "stacklist.h"
#include <stdlib.h>
#include <stdio.h>

void Alokasi (address *P, infotype X){
    address result;
    result = (address) malloc (sizeof(ElmtStack));
    if (result != Nil){
        Info(result) = X;
        Next(result) = Nil;
    } else {
        result = Nil ;
    }
    *P = result ;
}

void Dealokasi (address P){
    free(P);
}

boolean IsEmpty (Stack S) {
    return (Top(S) == Nil) ;
}

void CreateEmpty (Stack *S) {
    Top(*S) = Nil ; 
}

void Push (Stack *S, infotype X) {
    address p ;
    Alokasi (&p, X);
    if (p != Nil) {
        Next(p) = Top(*S) ;
        Top(*S) = p ;
    }
}

void Pop (Stack *S, infotype *X) {
    address p ;
    *X = InfoTop(*S) ;
    p = Top(*S) ; 
    Top(*S) = Next(p) ; 
    Dealokasi(p) ;
}
