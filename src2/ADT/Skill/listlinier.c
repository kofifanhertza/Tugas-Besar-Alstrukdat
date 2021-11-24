/*
Nama    : Kofifan Hertza Haribowo   
NIM     : 18220022
Topik   : ADT Linked list linier*/

#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty (List L) {
    return First(L) == Nil ;
}

void CreateEmpty (List *L) {
    First(*L) = Nil ;
}

address Alokasi (infotype X){
    address result;
    result = (address) malloc (sizeof(ElmtList));
    if (result != Nil){
        Info(result) = X;
        Next(result) = Nil;
    }
    return result;

}

void Dealokasi (address *P){
    free(*P);
}


address Search (List L, infotype X) {
    address p ;
    if (IsEmpty(L)) {
        return Nil ;
    }
    p = First(L) ; 
    while (p != Nil) {
        if (Info(p) == X) {
            return p ;
        }
        p = Next(p) ;
    }
}

void InsVFirst (List *L, infotype X) {
    address p ;
    p = Alokasi(X);
    if (p != Nil) {
        Next(p) = First(*L) ;
        First(*L) = p ;
    }
}

void InsVLast (List *L, infotype X){
    address newlast = Alokasi(X);
    if (newlast == Nil) return;

    if (IsEmpty(*L)){
        InsVFirst(L, X);
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = newlast;
        Next(Next(now)) = Nil;
    }
}

void DelVFirst (List *L, infotype *X) {
    address p ;
    p = First(*L) ;
    *X = Info(p) ;
    First(*L) = Next(p) ;
    Dealokasi(&p) ;
}

void DelVLast (List *L, infotype *X){
    address now = First(*L);
    if(Next(now) != Nil){
        while(Next(Next(now)) != Nil){
            now = Next(now);
        }
        *X = Info(Next(now));
        Dealokasi(&Next(now));
        Next(now) = Nil;
    }else{
        DelVFirst(L, X);
    }
}

void InsertFirst (List *L, address P) {
    address first ;
    first = First(*L);
    Next(P) = first ;
    First(*L) = P ;
}

void InsertAfter (List *L, address P, address Prec) {
    Next(P) = Next(Prec) ;
    Next(Prec) = P ;
}

void InsertLast (List *L, address P) {

    if (IsEmpty(*L)) {
        First(*L) = P ;
    }
    else {
    address loc = First(*L) ;
    while (Next(loc) != Nil) {
        loc = Next(loc) ;
    }
    Next(loc) = P ;
    Next(P) = Nil;
    }
}

void DelFirst (List *L, address *P) {
    address loc ; 
    loc = First(*L) ;
    *P = loc ;
    First(*L) = Next(loc) ;
}

void DelP (List *L, infotype X){
    if(!IsEmpty(*L)){
        address now = First(*L);
        address loc;
        if(Info(now) == X){
            DelFirst(L, &loc);
        }else{
            while(Next(now) != Nil && Info(Next(now)) != X){
                now = Next(now);
            }
            if(Next(now) != Nil){
                DelAfter(L, &loc, now);
            }
        }
    }
}

void DelLast (List *L, address *P){
    address loc = First(*L);
    if(Next(loc) == Nil){
        DelFirst(L, P);
    }else{
        while(Next(Next(loc)) != Nil){
            loc = Next(loc);
        }
        DelAfter(L, P, loc);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){

    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}


void PrintInfo (List L){
    printf("[");
    if (!IsEmpty(L)){
        address loc = First(L);
        while (loc != Nil) {
            printf("%d", Info(loc));
            loc = Next(loc);

            if (loc != Nil)
                printf(",");
        }
    }
    printf("]");
}

int NbElmt (List L) {
    int count = 0 ;
    if (!IsEmpty(L)) {
        address p = First(L) ;
        while (p != Nil) {
            p = Next(p) ;
            count = count + 1 ;
        }
    }
    return count ;
}

infotype Max (List L) {
    address p = First(L) ;
    infotype x = Info(p) ;
    while (Next(p) != Nil) {
        p = Next(p) ;
        if (x < Info(p)) {
            x = Info(p) ;
        }
    }
    return x ;

}

void Konkat1 (List *L1, List *L2, List *L3){
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    First(*L1) = Nil;
    if (IsEmpty(*L3)){
        First(*L3) = First(*L2);
    } else {
        address now = First(*L3);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = First(*L2);
    }
    First(*L2) = Nil;
}