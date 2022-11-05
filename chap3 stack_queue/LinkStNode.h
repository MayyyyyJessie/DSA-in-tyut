#ifndef DATASTRUCTURE_LINKSTNODE_H
#define DATASTRUCTURE_LINKSTNODE_H
#include <iostream>
using namespace std;

typedef struct linknode{
    int data;
    struct linknode* next;
}LinkStNode;

void InitStack(LinkStNode * &S);
void DestroyStack(LinkStNode* &S);
bool StackEmpty(LinkStNode* S);
bool Push(LinkStNode* &S,int e);
bool Pop(LinkStNode* &S,int &e);
bool GetTop(LinkStNode* S,int &e);
#endif //DATASTRUCTURE_LINKSTNODE_H
