#ifndef DATASTRUCTURE_DLINKNODE_H
#define DATASTRUCTURE_DLINKNODE_H
typedef struct Node{
    int data;
    struct Node *prior;
    struct Node *next;
}DLinkNode;

void CreateListF(DLinkNode* &L,int nums[],int l);
void CreateListR(DLinkNode* &L,int nums[],int l);
bool ListInsert(DLinkNode* &L,int i,int e);
bool ListDelete(DLinkNode* &L,int i,int &e);

// 以下函数不作实现
void InitList(DLinkNode* &L);
void DestroyList(DLinkNode* &L);
bool ListEmpty(DLinkNode* L);
int ListLength(DLinkNode* L);
void DispList(DLinkNode* L);
bool GetElem(DLinkNode* L,int i,int &e);
int LocateElem(DLinkNode* L,int e);

#endif //DATASTRUCTURE_DLINKNODE_H
