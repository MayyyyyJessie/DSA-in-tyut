#ifndef DATASTRUCTURE_LINKQUNODE_H
#define DATASTRUCTURE_LINKQUNODE_H
using namespace std;

typedef struct qnode{
    int data;
    struct qnode* next;
}DataNode;

typedef struct{
    DataNode* front;
    DataNode* rear;
}LinkQuNode;

//void InitStack(LinkStNode * &S);
//void DestroyStack(LinkStNode* &S);
//bool StackEmpty(LinkStNode* S);
//bool Push(LinkStNode* &S,int e);
//bool Pop(LinkStNode* &S,int &e);
//bool GetTop(LinkStNode* S,int &e);

#endif //DATASTRUCTURE_LINKQUNODE_H
