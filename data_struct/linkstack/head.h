#ifndef __HEAD__
#define __HEAD__
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct linkstack{
    int data;
    struct linkstack *next;
}linkstack_t;
//1.创建一个空的栈
void CreateEpLinkStack(linkstack_t **ptop);
//2.入栈   data是入栈的数据
// 参数上之所以采用二级指针，因为我们要随着入栈添加新的节点作为头，top需要永远指向当前链表的头，
// 那么修改main函数中的top，我们采用地址传递
int PushLinkStack(linkstack_t **ptop, datatype data);
//3.判断栈是否为空
int IsEpLinkStack(linkstack_t *top);
//4.出栈
datatype PopLinkStack(linkstack_t **ptop);
//5.清空栈
void ClearLinkStack(linkstack_t **ptop);//用二级指针，是因为清空后需要将main函数中的top变为NULL
//6.求栈的长度
int LengthLinkStack(linkstack_t *top);//用一级指针，是因为我只是求长度，不需要修改main函数中top指针的指向
//7.获取栈顶数据,不是出栈,不需要移动main函数中的top，所以用一级指针
datatype GetTopLinkStack(linkstack_t *top);
#endif