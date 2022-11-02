#include <iostream>
#include "DLinkNode.h"
using namespace std;

// 创建语法大差不差 重要的是把prior指针域赋值
void CreateListF(DLinkNode* &L,int nums[],int l){
    L = (DLinkNode*) malloc(sizeof(DLinkNode));
    L->prior = L->next = nullptr;
    DLinkNode* newp = nullptr;
    for (int i = 0; i < l; ++i) {
        newp = (DLinkNode*) malloc(sizeof(DLinkNode));
        newp->data = nums[i];
        newp->next = L->next;
        if (L->next != NULL) L->next->prior = newp; // 如果L后有数据 需要改变它的前驱是newp
        newp->prior = L;
        L->next = newp;
    }
}
void CreateListR(DLinkNode* &L,int nums[],int l){
    L = (DLinkNode*) malloc(sizeof(DLinkNode));
    L->prior = L->next = nullptr;
    DLinkNode* temp = L;
    DLinkNode* newp = nullptr;
    for (int i = 0; i < l; ++i) {
        newp = (DLinkNode*) malloc(sizeof(DLinkNode));
        newp->data = nums[i];
        temp->next = newp;
        newp->prior = temp;
        temp = newp;
    }
    temp->next = nullptr; // 补充最后一个结点的后继结点
}
bool ListInsert(DLinkNode* &L,int i,int e){
    DLinkNode* temp = L;
    if (i <= 0) return false;
    int j = 1;
    while (temp != nullptr && j < i) {
        temp = temp->next;
        j++;
    }
    if (temp == nullptr) return false;
    DLinkNode* newp = nullptr;
    newp = (DLinkNode*) malloc(sizeof(DLinkNode));

    newp->data = e;
    temp->next->prior = newp;
    newp->next = temp->next;
    temp->next = newp;
    newp->prior = temp;
}
bool ListDelete(DLinkNode* &L,int i,int &e){
    DLinkNode* temp = L;
    if (i <= 0) return false;
    int j = 1;
    while (temp->next != nullptr && j < i) {
        temp = temp->next;
        j++;
    }
    if (temp == nullptr) return false;
    DLinkNode* q = temp->next;
    if (q == nullptr) return false;

    e = q->data;
    temp->next = q->next;
    if (temp->next != nullptr) temp->next->prior = temp;
    free(q); // q就是要删除的结点 记得释放
    return true;
}

// 以下代码cv自单链表
void DispList(DLinkNode* L) {
    DLinkNode* temp = L->next;
    while(temp != NULL){
        cout << temp->data <<endl;
        temp = temp->next;
    }
}

//int main(){
//    DLinkNode* L =NULL;
//    int nums[10] = {9,8,7,6,5,4,3,2,1};
//    CreateListF(L,nums,5);
//    DispList(L);
//}