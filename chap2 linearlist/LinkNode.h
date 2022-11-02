#ifndef DATASTRUCTURE_LINKNODE_H
#define DATASTRUCTURE_LINKNODE_H
typedef struct node{
    int data;
    struct node *next;
}LinkNode;

void CreateListF(LinkNode* &L,int nums[],int l);
void CreateListR(LinkNode* &L,int nums[],int l);
void InitList(LinkNode* &L);
void DestroyList(LinkNode* &L);
bool ListEmpty(LinkNode* L);
int ListLength(LinkNode* L);
void DispList(LinkNode* L);
bool GetElem(LinkNode* L,int i,int &e);
int LocateElem(LinkNode* L,int e);
bool ListInsert(LinkNode* &L,int i,int e);
bool ListDelete(LinkNode* &L,int i,int &e);

#endif //DATASTRUCTURE_LINKNODE_H
