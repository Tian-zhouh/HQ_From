#include "head.h"

void CreateEpLinkStack(linkstack_t **ptop)
{
    *ptop = NULL;//创建无头链表
}

int PushLinkStack(linkstack_t **ptop, datatype data)
{
    link_list_t pnew = (link_list_t)malloc(sizeof(linkstack_t));
    if (pnew == NULL)
    {
        perror("PushLinkStack(args) is error");
        return -1;
    }
    pnew->data = data;
    pnew->next = *ptop;
    *ptop = pnew;

    return 0;
}

int IsEpLinkStack(linkstack_t *top)
{
    return top == NULL;
}

datatype PopLinkStack(linkstack_t **ptop)
{
    link_list_t pdel = NULL;
    datatype num; //用于存储出栈数据
    if (IsEpLinkStack(*ptop))
    {
        perror("PopLinkStack(**) is error");
        return -1;
    }
    pdel = *ptop;
    *ptop = pdel->next;
    num = pdel->data;
    free(pdel);
    pdel = NULL;

    return num;
}

void ClearLinkStack(linkstack_t **ptop)
{
    while (*ptop != NULL)
    {
        PopLinkStack(ptop);
    }
}

int LengthLinkStack(linkstack_t *top)
{
    int length = 0; //用于存储栈长度
    while (top != NULL)
    {
        top = top->next;
        length++;
    }

    return length;
}

datatype GetTopLinkStack(linkstack_t *top)
{
    return top->data;
}

void ShowLinkStack(linkstack_t *top)
{
    while (top != NULL)
    {
        printf("%d\t", top->data);
        top=top->next;
    }
    puts("");
}