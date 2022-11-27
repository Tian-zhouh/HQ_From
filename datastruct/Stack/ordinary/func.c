#include "head.h"

seqstack_t *CreateEpSeqStack(int len)
{
    seqstack_list_t p = (seqstack_list_t)malloc(sizeof(seqstack_t));
    if (p == NULL)
    {
        perror("CreateEpSeqStack(int) is error");
        return NULL;
    }
    p->data = (datatype *)malloc(sizeof(datatype) * len);
    if (p->data == NULL)
    {
        perror("CreateEpSeqStack p->data is error");
        free(p);
        p = NULL;
        return NULL;
    }
    p->maxlen = len;
    p->top = -1;

    return p;
}

int IsFullSeqStack(seqstack_t *p)
{
    return p->top + 1 == p->maxlen;
}

int PushStack(seqstack_t *p, datatype data)
{
    if (IsFullSeqStack(p))
    {
        perror("PushStack(args) is error");
        return -1;
    }
    p->data[++(p->top)] = data;

    return 0;
}

int IsEpSeqStack(seqstack_t *p)
{
    return p->top == -1;
}

datatype PopSeqStack(seqstack_t *p)
{
    if (IsEpSeqStack(p))
    {
        perror("PopSeqStack(args) is error");
        return -1;
    }

    return p->data[(p->top)--]; //这里有bug
}

void ClearSeqStack(seqstack_t *p)
{
    p->top = -1;
}

int GetTopSeqStack(seqstack_t *p)
{
    if (IsEpSeqStack(p))
    {
        perror("Stack is Null,can't find");
        return -1;
    }

    return p->data[p->top];
}

int LengthSeqStack(seqstack_t *p)
{
    return p->maxlen;
}

void ShowStack(seqstack_t *p)
{
    int item; //用于遍历使用
    for (item = 0; item < p->top; item++)
    {
        printf("%d\t", p->data[item]);
    }
    puts("");
}