#include <iostream>
#include "SqQueue.h"
using namespace std;

void InitQueue(SqQueue* &q){
    q = (SqQueue*) malloc(sizeof(SqQueue));
//    q->front = q->rear = -1;
    q->front = q->rear = 0;
}
void DestroyQueue(SqQueue* &q){
    free(q);
}
bool QueueEmpty(SqQueue* q){
    return (q->front == q->rear);
}
bool enQueue(SqQueue* &q,int e){
//    if (q->rear == MaxSize - 1) return false;
    if ((q->rear+ 1)%MaxSize == q->front) return false;
//    q->rear++;
    q->rear = (q->rear+ 1)%MaxSize;
    q->data[q->rear] = e;
    return true;
}
bool deQueue(SqQueue* &q,int &e){
    if (q->front == q->rear) return false;
//    q->front++;
    q->front = (q->front + 1)%MaxSize;
    e = q->data[q->front];
    return true;
}

//int main(){
//    SqQueue* q = nullptr;
//    InitQueue(q);
//    int e = 3;
//    enQueue(q,2);
//    enQueue(q,e);
//    deQueue(q,e);
//    cout << e << QueueEmpty(q) << endl;
//    DestroyQueue(q);
//}