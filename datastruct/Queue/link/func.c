#include "head.h"

linkqueue_t *CreateEmptyLinkQueue()
{
    link_list_t p = (link_list_t)malloc(sizeof(linkqueue_t));
    if (p == NULL)
    {
        perror("CreateEmptyLinkQueue() is error");
        return NULL;
    }
    p->front = p->rear = (linkqueue_list_t)malloc(sizeof(linkqueue_node_t));
    if (p->front == NULL)
    {
        perror("CreateEmptyLinkQueue()->front error");
        free(p);
        p = NULL;
        return NULL;
    }
    p->front->next = NULL;

    return p;
}

int InLinkQueue(linkqueue_t *p, datatype data)
{
    linkqueue_list_t pnew = (linkqueue_list_t)malloc(sizeof(linkqueue_node_t));
    if (pnew == NULL)
    {
        perror("InLinkQueue(args) is error");
        return -1;
    }
    pnew->data = data;
    pnew->next = NULL;
    p->rear->next = pnew;
    p->rear = pnew;

    return 0;
}

datatype OutLinkQueue(linkqueue_t *p)
{
    int num; //用于返回出队元素值;有bug
    linkqueue_list_t pdel = NULL;
    if (IsEmptyLinkQueue(p))
    {
        perror("OutLinkQueue(*) is error");
        return -1;
    }
    num = p->front->data;
    pdel = p->front;
    p->front = p->front->next;
    free(pdel);
    pdel = NULL;

    return num;
}

int IsEmptyLinkQueue(linkqueue_t *p)
{
    return p->front == p->rear;
}

int LengthLinkQueue(linkqueue_t *p)
{
    int length = 0; //用于存储队列长度
    linkqueue_list_t check = p->front;
    while (check != p->rear)
    {
        check = check->next;
        length++;
    }

    return length;
}

void ClearLinkQueue(linkqueue_t *p)
{
    while (p->front != p->rear)
    {
        OutLinkQueue(p);
    }
}

void ShowSequeueLink(linkqueue_t *p)
{
    linkqueue_list_t check = p->front;
    while (check != p->rear)
    {
        printf("%d\t", check->next->data);
        check = check->next;
    }
    puts("");
}