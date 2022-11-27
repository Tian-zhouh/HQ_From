#include "head.h"

link_node_t *CreateEpLinkList()
{
    link_list_t p = (link_list_t)malloc(sizeof(link_node_t)); //有头链表
    if (p == NULL)
    {
        perror("CreateEpLinkList() is error");
        return NULL;
    }
    p->next = NULL;

    return p;
}

int InsertIntoPostLinkList(link_node_t *p, int post, datatype data)
{
    //链表不需要判满操作,但是需要判断post的合法性
    link_list_t pnew = NULL; //用于存储新链表
    int item;                //用于遍历
    if (post < 0 || post > LengthLinkList(p))
    {
        // printf("%d\n",LengthLinkList(p));
        perror("InsertIntoPostLinkList(args) is error");
        return -1;
    }
    pnew = (link_list_t)malloc(sizeof(link_node_t));
    pnew->data = data;
    pnew->next = NULL;
    for (item = 0; item < post; item++)
    {
        p = p->next;
    }
    pnew->next = p->next;
    p->next = pnew;

    return 0;
}

void ShowLinkList(link_node_t *p)
{
    p = p->next; //去头操作
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    puts("");
}

int LengthLinkList(link_node_t *p)
{
    int length = 0; //存储链表长度
    p = p->next;    //去头操作
    while (p != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}

int DeletePostLinkList(link_node_t *p, int post)
{
    int num;                 //用于记录返回值，有bug
    int item;                //用于遍历
    link_list_t pdel = NULL; //存储被删除元素
    p = p->next;             //去头操作
    if (post < 0 || post >= LengthLinkList(p) || IsEpLinkList(p))
    {
        perror("DeletePostLinkList(args) is error");
        return -1;
    }
    for (item = 0; item < post; item++)
    {
        p = p->next;
    }
    pdel = p->next;
    p->next = pdel->next;
    num = pdel->data;
    free(pdel);
    pdel = NULL;

    return num;
}

int IsEpLinkList(link_node_t *p)
{
    return p->next == NULL;
}

int ChangePostLinkList(link_node_t *p, int post, datatype data)
{
    int item; //用于遍历
    if (post < 0 || post >= LengthLinkList(p))
    {
        perror("ChangePostLinkList(args) is error");
        return -1;
    }
    for (item = 0; item <= post; item++)
    {
        p = p->next;
    }
    p->data = data;

    return 0;
}

/* 只能查找第一个符合条件的元素 */
int SearchDataLinkList(link_node_t *p, datatype data)
{
    int index = 0; //用于存储元素的下标
    p = p->next;   //去头操作
    while (p != NULL)
    {
        if (p->data == data)
        {
            return index;
        }
        index++;
    }

    return index;
}

int DeleteDataLinkList(link_node_t *p, datatype data)
{
    link_list_t pdel = NULL; //用于记录待删除节点
    int count = 0;           //记录删除元素个数
    while (p->next != NULL)
    {
        if (p->next->data == data)
        {
            pdel = p->next;
            p->next = p->next->next;
            free(pdel);
            pdel = NULL;
            count++;
        }
        // printf("%d\t", p->next->data);
        if (p->next != NULL)
        {
            p = p->next;
        }
    }

    return count;
}

void ReverseLinkList(link_node_t *p)
{
    link_list_t revr = NULL; //暂存结构体变量
    link_list_t q = p->next; //去头操作
    p->next = NULL;          //去其他节点操作
    while (q != NULL)
    {
        revr = q->next;
        q->next = p->next;
        p->next = q;
        q = revr;
    }
}

void ClearLinkList(link_node_t *p)
{
    link_list_t pdel = NULL; //用于暂村被删除节点
    p = p->next;             //去头操作
    while (p != NULL)
    {
        pdel = p;
        p = p->next;
        free(pdel);
        pdel = NULL;
    }
}
