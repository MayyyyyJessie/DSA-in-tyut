#include <iostream>
#include "LinkNode.h"
using namespace std;

// 拆分成两个链表 一个正序 一个逆序
// 第一个算法实现了一个链表裂成两个 都是正序
//void split(LinkNode* &L,LinkNode* &N){
//    LinkNode* temp = L;
//    LinkNode* Ntemp = N;
//    int n = 1;
//    while (temp != NULL) {
//        if (n % 2 == 0) {
//            LinkNode* q = temp->next;
//            if (q == NULL) return;
//            temp->next = q->next;
//            n--; // 调整因删除而减少的序号
//            // 尾插法
//            q->next = NULL;
//            Ntemp->next = q;
//            Ntemp = Ntemp->next;
//        }
//        temp = temp->next;
//        n++;
//    }
//}
// 实际跑的时候跑不出来 segmentation fault
void split(LinkNode* &L,LinkNode* &L1,LinkNode* &L2) {
    L1 = L;
    LinkNode* temp = L->next;
    LinkNode* L1temp = L1;
    LinkNode* q = NULL;
    while (temp != NULL) {
        L1temp->next = temp;
        L1temp = temp;
        temp = temp->next;

        q = temp->next; // 保存下一个结点
        temp->next = L2->next;
        L2->next = temp;
        temp = q;
    }
    L1temp->next = NULL;
}

// 删除最大元素的结点 ps:使用nullptr代替NULL
void delmaxnode(LinkNode* &L){
    LinkNode* temp = L;
    LinkNode* maxp = nullptr;
    LinkNode* f = nullptr;
    int mx = 10e-6;
    while (temp != nullptr) {
        if (temp->next == nullptr) break;
        if (temp->next->data > mx) {
            mx = temp->next->data;
            maxp = temp;
        }
        temp = temp->next;
    }
    if (maxp->next->next == nullptr) maxp->next = nullptr;
    else{
        f = maxp->next;
        maxp->next = maxp->next->next;
    }
    free(f); // free掉合适的地方!!
}

// 有序递增
void sort(LinkNode* &L) {
    LinkNode* p = L->next->next;
    LinkNode* q = nullptr;
    LinkNode* pre = nullptr;
    L->next->next = nullptr; // 建立了只有一个数据结点的单链表
    while (p != nullptr) {
        q = p->next; // 存储下一结点
        pre = L; // 从头遍历
        while (pre->next != nullptr && pre->next->data < p->data) pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}
//int main(){
//    LinkNode* L =NULL;
//    int nums[10] = {9,8,7,6,5,4,3,2,1};
//    CreateListR(L,nums,5);
//    cout << "L ======================" << endl;
//    DispList(L);

//    LinkNode* L1 = NULL;
//    LinkNode* L2 = NULL;
//    InitList(L2);
//    split(L,L1,L2);
//    split(L,L1);
//    delmaxnode(L);
//    sort(L);
//    cout << "after L  ======================" << endl;
//    DispList(L);
//    cout << "L2 ======================" << endl;
//    DispList(L2);
//}