#include "head.h"

sequeue_t *CreateEmptySequeue()
{
    seque_list_t p = (seque_list_t)malloc(sizeof(sequeue_t));
    if (p == NULL)
    {
        perror("CreateEmptySequeue() is error");
        return NULL;
    }
    p->front = 0;
    p->rear = 0;

    return p;
}

int InSequeue(sequeue_t *p, datatype data)
{
    if (IsFullSequeue(p))
    {
        perror("InSequeue(args) is error");
        return -1;
    }

    p->data[p->rear] = data;
    p->rear = (p->rear + 1) % N;

    return 0;
}

int IsFullSequeue(sequeue_t *p)
{
    return (p->rear + 1) % N == p->front;
}

int IsEmptySequeue(sequeue_t *p)
{
    return p->rear == p->front;
}

datatype OutSequeue(sequeue_t *p)
{
    int index; //存储数据地址
    if (IsEmptySequeue(p))
    {
        perror("OutSequeue(*) is error");
        return -1;
    }
    index = p->front;
    p->front = (p->front + 1) % N;

    return p->data[index];
}

int LengthSequeue(sequeue_t *p)
{
    return (p->rear - p->front + N) % N;
}

void ClearSequeue(sequeue_t *p)
{
    p->front = p->rear;
}

void ShowSeque(sequeue_t *p)
{
    int num = p->front; //用于保证front固定不动
    while (num != p->rear)
    {
        printf("%d\t", p->data[num]);
        num = (num + 1) % N;
    }
    puts("");
}