#ifndef __HEAD__
#define __HEAD__
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node
{
    datatype data;
    struct node *next;
} linkqueue_node_t, *linkqueue_list_t;
typedef struct
{
    linkqueue_list_t front;
    linkqueue_list_t rear;
} linkqueue_t, *link_list_t;

//1.创建一个空的队列
linkqueue_t *CreateEmptyLinkQueue();
//2.入列 data代表入列的数据
int InLinkQueue(linkqueue_t *p, datatype data);
//3.出列
datatype OutLinkQueue(linkqueue_t *p);
//4.判断队列是否为空
int IsEmptyLinkQueue(linkqueue_t *p);
//5.求队列长度的函数
int LengthLinkQueue(linkqueue_t *p);
//6.清空队列
void ClearLinkQueue(linkqueue_t *p);
//遍历队列
void ShowSequeueLink(linkqueue_t *p);

#endif