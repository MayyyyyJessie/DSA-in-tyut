#include <iostream>
#include "LinkStNode.h"
using namespace std;

void InitStack(LinkStNode * &S){
    S = (LinkStNode *) malloc(sizeof(LinkStNode));
    S->next = nullptr;
}

void DestroyStack(LinkStNode* &S){
//    if (S->next == nullptr) free(S);
//    else{
//        while (S->next != nullptr) {
//            LinkStNode* del = nullptr;
//            del = S->next;
//            S->next = del->next;
//            free(del);
//        }
//        free(S);
//    }
    // 还有一种解法
    LinkStNode* pre = S;
    LinkStNode* p = S->next;
    while (p != nullptr) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

bool StackEmpty(LinkStNode* S){
    return (S->next == nullptr);
}

bool Push(LinkStNode* &S,int e){
    LinkStNode* newp = nullptr;
    newp = (LinkStNode *) malloc(sizeof(LinkStNode));
    newp->data = e;
    newp->next = S->next;
    S->next = newp;
    return true;
}

bool Pop(LinkStNode* &S,int &e){
    if (S->next == nullptr) return false;
    LinkStNode* del = nullptr;
    del = S->next;
    e = del->data;
    S->next = del->next;
    free(del);
    return true;
}

bool GetTop(LinkStNode* S,int &e){
    if (S->next == nullptr) return false;
    e = S->next->data;
    return true;
}

// 判断表达式中括号是否匹配
bool Match(char exp[],int n){
    int e;
    LinkStNode* S = nullptr;
    InitStack(S);
    for (int i = 0; i < n; ++i) {
        if (exp[i] == '(') Push(S,exp[i]); // 栈内只放左括号
        if (exp[i] == ')') {
            bool res = Pop(S,e);
            if (res == false) return false;
        }
    }
    if (StackEmpty(S)) {
        DestroyStack(S);
        return true;
    }
    else {
        DestroyStack(S);
        return false;
    }

}

//int main(){
//    LinkStNode* S = nullptr;
//    InitStack(S);
//    cout << Match("(()ab()",8) << endl;
//    DestroyStack(S);
//}