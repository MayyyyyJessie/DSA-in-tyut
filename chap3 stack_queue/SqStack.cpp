#include <iostream>
#include "SqStack.h"
using namespace std;

void InitStack(SqStack* &S){
    S = (SqStack*) malloc(sizeof(SqStack));
    S->top = -1;
}

void DestroyStack(SqStack* &S){
    free(S);
}

bool StackEmpty(SqStack* S){
    return (S->top == -1);
}

bool Push(SqStack* &S,int e){
    if (S->top == MaxSize - 1) return false;
    S->top++;
    S->data[S->top] = e;
    return true;
}

bool Pop(SqStack* &S,int &e){
    if (S->top == -1) return false;
    e = S->data[S->top];
    S->top--;
    return true;
}

bool GetTop(SqStack* S,int &e){
    if (S->top == -1) return false;
    e = S->data[S->top];
    return true;
}

// 判断是否是对称字符串
bool symmetry(char str[]){
    SqStack* S = nullptr;
    InitStack(S);
    for (int i = 0; str[i] != '\0' ; ++i) {
        Push(S,str[i]);
    }
    int e;
    for (int i = 0; str[i] != '\0' ; ++i) {
        Pop(S,e);
        if (e != str[i]) {
            DestroyStack(S);
            return false;
        }
    }
    DestroyStack(S);
    return true;
    // 记得销毁栈
}

//int main(){
//    int e = 2;
//    SqStack* S = nullptr;
//    InitStack(S);
//    Push(S,e);
//    GetTop(S,e);
//    cout << e << StackEmpty(S) << endl;
//    Pop(S,e);
//    cout << e << StackEmpty(S) << endl;
//    cout << symmetry("abaaaba") << endl;
//    DestroyStack(S);
//}