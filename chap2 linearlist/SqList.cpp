/*
 * 线性表: 由具有相同特性的零个或多个数据元素构成的有限序列
 * ADT: 初始化 销毁 empty 长度 遍历 取值 按值查找 增 删
 */
#include <iostream>
#include "SqList.h"

using namespace std;

// 补充: 创建顺序表
void CreateList(SqList * &L, int nums[], int l){
    L = (SqList*)malloc(sizeof(SqList));
    for (int i = 0; i < l; ++i) {
        L->data[i] = nums[i];
    }
    L->length = l;
}

// 传入的是结构体指针
void InitList(SqList * &L){
    L = (SqList *) malloc(sizeof(SqList)); // 函数的返回值是void *的指针(地址)
    L->length = 0;
}

void DestroyList(SqList * &L){
    free(L);
}

bool ListEmpty(SqList *L){
    return (L->length == 0);
}

int ListLength(SqList *L){
    return L->length;
}

void DispList(SqList *L){
    for (int i = 0; i < L->length; ++i)
        cout << L->data[i] << endl;
}

bool GetElem(SqList * L,int i,int &e){
    if (i < 1 || i > L->length){ // i是逻辑序号
        cout << "invalid position" << endl;
        return false;
    }
    e = L->data[i - 1];
    return true;

}

int LocateElem(SqList *L,int e){
    for (int i = 0; i < L->length; ++i) {
        if(L->data[i] == e){
            return i + 1; // 逻辑序号
        }
    }
    return 0;
};

bool ListInsert(SqList * &L,int i,int e){
    if(i < 1 || i > L->length || L->length == MaxSize)
        return false;
    i--;
    L->length++; // 长度先加一 才能保证后面元素移动正确
    for (int j = L->length-1; j > i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i] = e;
    return true;
}

bool ListDelete(SqList *&L,int i,int &e){
    if(i < 1 || i > L->length){ // 不用写length == 0
        cout << "invalid position" << endl;
        return false;
    }
    i--; // 转化成下标
    e = L->data[i];
    for (int j = i; j < L->length-1; ++j) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return true;
}



//int main() {
//    SqList* L = NULL;
//
//    cout << "L is:" << L << endl;
//    int nums[4] = {10,11,12,13};
//    CreateList(L,nums,4);
//    cout << "L is:" << L << endl;
//    DispList(L);
//
//    cout << "insert:"<< endl;
//    int e = 5;
//    ListInsert(L,2,e);
//    DispList(L);
//
//    cout << "location is:" << LocateElem(L,11)<< endl;
//
//    cout << "delete:" << endl;
//    ListDelete(L,3,e);
//    DispList(L);
//    cout << "e is:" << e << endl;
//
//    DestroyList(L);
//    return 0;
//}
