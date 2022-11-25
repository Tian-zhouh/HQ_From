#include "head.h"
seqstack_t *CreateEpSeqStack(int len)
{
    seqstack_t *p = (seqstack_t *)malloc(sizeof(seqstack_t));
    if (p == NULL)
    {
        perror("Seqstack melloc is error");
        return NULL;
    }
    p->maxlen = len;
    p->top = -1;
    p->data = (int *)malloc(sizeof(int) * len);
    if (p->data == NULL)
    {
        free(p);
        p = NULL;
        perror("malloc data error");
        return NULL;
    }
    return p;
}
int IsFullSeqStack(seqstack_t *p)
{
    return p->maxlen == p->top + 1;
}
int PushStack(seqstack_t *p, int data)
{
    if (IsFullSeqStack(p))
    {
        perror("push stack is error");
        return -1;
    }
    p->data[++(p->top)] = data;
    return 1;
}

int IsEpSeqStack(seqstack_t *p)
{
    return p->top == -1;
}
int PopSeqStack(seqstack_t *p)
{
    if (IsEpSeqStack(p))
    {
        perror("pop stack is error");
        return -1;
    }
    return p->data[p->top--];
}
void ClearSeqStack(seqstack_t *p){
    p->top=-1;
}
int GetTopSeqStack(seqstack_t *p){
    return p->data[p->top];
}
int LengthSeqStack(seqstack_t *p){
    return p->top+1;
}