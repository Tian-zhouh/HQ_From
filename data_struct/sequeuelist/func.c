#include "head.h"
sequeue_t *CreateEmptySequeue()
{
    sequeue_t *seq = (sequeue_t *)malloc(sizeof(sequeue_t));
    if (seq == NULL)
    {
        perror("malloc sequeue is error");
        return NULL;
    }
    seq->rear = 0;
    seq->front = 0;
    return seq;
}
int IsFullSequeue(sequeue_t *p)
{
    return (p->rear + 1) % N == p->front;
}
int InSequeue(sequeue_t *p, datatype data)
{
    if (IsFullSequeue(p))
    {
        perror("InSequeue is error");
        return -1;
    }
    p->data[p->rear++] = data;
    return 0;
}
int IsEmptySequeue(sequeue_t *p)
{
    return p->rear == p->front;
}
datatype OutSequeue(sequeue_t *p){
    if(IsEmptySequeue(p)){
        perror("OutSequeue is error");
        return -1;
    }
    int num=p->data[p->front];
    p->front=(p->front+1)%N;
    return num;
}
int LengthSequeue(sequeue_t *p){
    return (p->rear)%N-(p->front)%N;
}
void ClearSequeue(sequeue_t *p){
    p->front=p->rear;
}