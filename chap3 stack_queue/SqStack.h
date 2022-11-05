#ifndef DATASTRUCTURE_SQSTACK_H
#define DATASTRUCTURE_SQSTACK_H
#include <iostream>
#define MaxSize 50
using namespace std;
typedef struct{
    int data[MaxSize];
    int top;
}SqStack;

// 共享栈
typedef struct{
    int data[MaxSize];
    int top1,top2;
}DStack;

void InitStack(SqStack* &S);
void DestroyStack(SqStack* &S);
bool StackEmpty(SqStack* S);
bool Push(SqStack* &S,int e);
bool Pop(SqStack* &S,int &e);
bool GetTop(SqStack* S,int &e);
#endif //DATASTRUCTURE_SQSTACK_H
