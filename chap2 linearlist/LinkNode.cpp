#include <iostream>
#include "LinkNode.h"
using namespace std;
/*
 * 链表: 均带头结点
 * ADT: 初始化 销毁 empty 长度 遍历 取值 按值查找 增 删
 */
void CreateListF(LinkNode* &L,int nums[],int l) {
    // 创建好头结点
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;

    for (int i = 0; i < l; ++i) {
        LinkNode* newp = NULL;
        newp = (LinkNode*)malloc(sizeof(LinkNode));
        newp->data = nums[i];
        // newp L 两步走
        newp->next = L->next;
        L->next = newp;
    }
}
void CreateListR(LinkNode* &L,int nums[],int l) {
    //先分配内存 再使用temp!
    L = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode* temp = L;
    LinkNode* newp = NULL;
    for (int i = 0; i < l; ++i) {
        newp = (LinkNode*)malloc(sizeof(LinkNode));
        newp->data = nums[i];
        temp->next = newp; // 接了一个新的结点
        temp = newp; //向后移动一个结点
    }
    temp->next =NULL;
}

void InitList(LinkNode* &L) {
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next =NULL;
}

// 先预设好两个相邻的结点 再执行:保存一个删一个
void DestroyList(LinkNode* &L) {
    LinkNode* pre = L;
    LinkNode* temp = L->next;
    while(temp != NULL){
        free(pre);
        pre=temp;
        temp=temp->next;
    }
    delete(pre);// 补充由于限制条件 会少删除最后一个的漏洞
}
//void DestroyList(LinkNode* &L) {
//    if(L == NULL) return;
//    DestroyList(L->next);
//    free(L);
//}

bool ListEmpty(LinkNode* L) {
    return (L->next == NULL);
}

int ListLength(LinkNode* L) {
    LinkNode* temp = L;
    int n = 0;
    while (temp->next != NULL) { // 不计头结点!
        temp = temp->next;
        n++;
    }
    return n;
}

void DispList(LinkNode* L) {
    LinkNode* temp = L->next;
    while(temp != NULL){
        cout << temp->data <<endl;
        temp = temp->next;
    }
}

bool GetElem(LinkNode* L,int i,int &e) {
    LinkNode* temp = L;
    int j = 0;
    if (i <= 0) return false; // 补充条件!
    while (temp != NULL && j < i) {
        temp = temp->next;
        j++;
    }
    if (temp == NULL) return false;
    e = temp->data;
    return true;
}

int LocateElem(LinkNode* L,int e) {
    LinkNode* temp = L->next; // 从第一个开始找
    int id = 1;
    while (temp != NULL) {
        if (temp->data == e) {
            return id;
        }
        id++;
        temp = temp->next;
    }
    return -1;
}

bool ListInsert(LinkNode* &L,int i,int e) {
    LinkNode* temp = L;
    int j = 1;
    if (i <= 0) return false;
    while (temp != NULL && j < i) {
        temp = temp->next;
        j++;
    }
    if (temp == NULL) return false;
    LinkNode* newp = NULL;
    newp = (LinkNode*) malloc(sizeof(LinkNode));

    newp->data = e;
    newp->next = temp->next;
    temp->next = newp;
    return true;
}

bool ListDelete(LinkNode* &L,int i,int &e) {
    LinkNode* temp = L;
    int j = 1;
    if (i <= 0) return false;
    while (temp != NULL && j < i) {
        temp = temp->next;
        j++;
    }
    if (temp == NULL) return false; // 得到的temp是上一个结点
    LinkNode* q = temp->next; // q是要删除的结点 这样写逻辑会清晰!
    if (q == NULL) return false;
    e = q->data;
    temp->next = q->next;
    free(q); // 完全删除 避免内存泄露
}