#ifndef DATASTRUCTURE_SQQUEUE_H
#define DATASTRUCTURE_SQQUEUE_H
#include <iostream>
#define MaxSize 50
using namespace std;

typedef struct{
    int data[MaxSize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue* &q);
void DestroyQueue(SqQueue* &q);
bool QueueEmpty(SqQueue* q);
bool enQueue(SqQueue* &q);
bool deQueue(SqQueue* &q);
#endif //DATASTRUCTURE_SQQUEUE_H
