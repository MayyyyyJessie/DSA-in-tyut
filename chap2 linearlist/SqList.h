#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H

#include <iostream>
using namespace std;
#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int length;
}SqList;

void CreateList(SqList * &L, int nums[], int l);
void InitList(SqList * &L);
void DestroyList(SqList * &L);
bool ListEmpty(SqList *L);
int ListLength(SqList *L);
void DispList(SqList *L);
bool GetElem(SqList * L,int i,int &e);
int LocateElem(SqList *L,int e);
bool ListInsert(SqList * &L,int i,int e);
bool ListDelete(SqList *&L,int i,int &e);

#endif //DATASTRUCTURE_SQLIST_H
