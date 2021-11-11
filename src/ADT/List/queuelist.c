/*
Nama    : Kofifan Hertza Haribowo   
NIM     : 18220022
Topik   : Stack dan Queue dengan List*/

#include "boolean.h"
#include "queuelist.h"
#include <stdlib.h>
#include <stdio.h>

void Alokasi (address *P, infotype X){
    address result;
    result = (address) malloc (sizeof(ElmtQueue));
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

boolean IsEmpty (Queue Q) {
    return ((Head(Q) == Nil) && (Tail(Q) == Nil)) ;
}

int NbElmt (Queue Q) {
    int ctr = 0 ;
    if (IsEmpty(Q)) {
        return ctr ;
    } 
    address p ; 
    p = Head(Q) ;
    while ( p != Nil) {
        p = Next(p) ;
        ctr = ctr + 1 ; 
    }
    return ctr ;
}

void CreateEmpty(Queue *Q) {
    Head(*Q) = Nil ;
    Tail(*Q) = Nil ;
}

void Add (Queue *Q, infotype X) {
    address p ;
    Alokasi (&p, X);
    if (p != Nil) {
        if (IsEmpty(*Q)) {
            Head(*Q) = p ;
            Tail(*Q) = p ;
        } else {
            Next(Tail(*Q)) = p ;
            Tail(*Q) = p ;
            Next(p) = Nil ;
        }
    }
}

void Del (Queue *Q, infotype *X) {
    address p ;
    *X = InfoHead(*Q) ;
    p = Head(*Q) ;
    Head(*Q) = Next(p) ;
    if (Head(*Q) == Nil) {
        Tail(*Q) = Nil ;
    }
    Dealokasi(p) ;
}