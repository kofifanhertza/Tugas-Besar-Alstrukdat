/*
Nama    : Kofifan Hertza Haribowo   
NIM     : 18220022
Topik   : Variasi List */

#include "boolean.h"
#include "listdp.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty (List L) {
    return ((First(L) == Nil) && (Last(L) == Nil)) ;
}

void CreateEmpty (List *L) {
    First(*L) = Nil ;
    Last(*L) = Nil ; 
}

address Alokasi (infotype X){
    address result;
    result = (address) malloc (sizeof(ElmtList));
    if (result != Nil){
        Info(result) = X;
        Next(result) = Nil;
        Prev(result) = Nil ; 
    }
    return result;

}

void Dealokasi (address P){
    free(P);
}

address Search (List L, infotype X){
    address now = First(L);
    while(now != Nil && Info(now)!=X){
        now = Next(now);
    }
    return now;
}

void InsVFirst (List *L, infotype X) {
    address p ;
    address first = First(*L) ;
    p = Alokasi(X);
    if (p != Nil) {
        if (first == Nil) {
            Last(*L) = p ;
        } else {
            Prev(first) = p ;
        }

        Next(p) = first ;
        First(*L) = p ;
    }
}

void InsVLast (List *L, infotype X){
    address newlast = Alokasi(X);

    if (Last(*L) == Nil) {
        First(*L) = newlast ; 
    } else {
        address last = (Last(*L)) ; 
        Next(last) = newlast ;
        
    }
    Prev(newlast) = Last(*L) ; 
    Last(*L) = newlast ;
}

void DelVFirst (List *L, infotype *X) {
    address p ;
    p = First(*L) ;
    *X = Info(p) ;
    if (First(*L) == Last(*L)) {
        First(*L) = Nil ;
        Last(*L) = Nil ; 
        return ;
    }
    Prev(Next(p)) = Nil ;
    First(*L) = Next(p) ;
    Dealokasi(p) ;
}


void DelVLast (List *L, infotype *X){
    address deleted = Last(*L);
    *X = Info(deleted);
    if (First(*L) == Last(*L)){
        First(*L) = Nil;
        Last(*L) = Nil;
        return;
    }
    Next(Prev(deleted)) = Nil;
    Last(*L) = Prev(deleted);
    Dealokasi(deleted);
}

void InsertFirst (List *L, address P){
    address newfirst = P;
    if (First(*L) == Nil){
        Last(*L) = newfirst;
    } else {
        Prev(First(*L)) = newfirst;
    }
    Next(newfirst) = First(*L);
    First(*L) = newfirst;
}

void InsertLast (List *L, address P){
    address newlast = P;
    if (Last(*L) == Nil){
        First(*L) = newlast;
    } else {
        Next(Last(*L)) = newlast;
    }
    Prev(newlast) = Last(*L);
    Last(*L) = newlast;
}

void InsertAfter (List *L, address P, address Prec) {
    if (Next(Prec) == Nil) {
        InsertLast(L, P) ;
    } else {
    Next(P) = Next(Prec) ;
    Prev(Next(Prec)) = P;
    Prev(P) = Prec ;
    Next(Prec) = P ;
    }
}

void InsertBefore (List *L, address P, address Succ) {
    if (Prev(Succ) == Nil) {
        InsertFirst(L, P) ;
    } else {
        Prev(P) = Prev(Succ) ;
        Next(Prev(Succ)) = P ;
        Next(P) = Succ ;
        Prev(Succ) = P ;
    }
     
    
}

void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
    if (First(*L)==Nil){
        Last(*L) = Nil;
    } else {
        Prev(First(*L)) = Nil;
    }
}

void DelLast (List *L, address *P){
    *P = Last(*L);
    Last(*L) = Prev(*P);
    if(Last(*L)==Nil){
        First(*L) = Nil;
    } else {
        Next(Last(*L)) = Nil;
    }
}


void DelP (List *L, infotype X){
    address p = Search(*L, X);
    if (p != Nil){
        if (p == First(*L)){
            DelFirst(L, &p);
        } else if (p == Last(*L)){
            DelLast(L, &p);
        } else {
            address loc;
            DelAfter(L, &loc, Prev(p));
        }
    }
}


void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    if ((*Pdel) == First(*L)){
        DelFirst(L, Pdel);
    } else if ((*Pdel) == Last(*L)){
        DelLast(L, Pdel);
    } else {
        Prev(Next(*Pdel)) = Prec;
        Next(Prec) = Next(*Pdel);
    }
}



void DelBefore(List *L, address *Pdel, address Succ) {
    *Pdel = Prev(Succ) ;
    if (Prev(*Pdel) == Nil) {
        DelFirst(L, Pdel) ;
    } else {
        DelAfter(L, Pdel, Prev(*Pdel)) ;
    } 
}



void PrintForward (List L) {
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

void PrintBackward (List L) {
    printf("[");
    if (!IsEmpty(L)){
        address loc = Last(L);
        while (loc != Nil) {
            printf("%d", Info(loc));
            loc = Prev(loc);

            if (loc != Nil)
                printf(",");
        }
    }
    printf("]");
}