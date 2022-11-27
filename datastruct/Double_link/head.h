#ifndef __HEAD__
#define __HEAD__
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node
{
    datatype data;
    struct node *prior;
    struct node *next;
} link_node_t, *link_list_t;
typedef struct doublelink
{
    link_list_t head;
    link_list_t tail;
    int len;
} double_node_t, *double_list_t;

//1.创建一个空的双向链表
double_list_t createEmptyDoubleLinkList();
//2.向双向链表的指定位置插入数据 post位置， data数据
int insertIntoDoubleLinkList(double_list_t p, int post, datatype data);
//3.遍历双向链表
void showDoubleLinkList(double_list_t p, int num);
//4.删除双向链表指定位置的数据
int deletePostDoubleLinkList(double_list_t p, int post);
//5.判断双向链表是否为空
int isEmptyDoubleLinkList(double_list_t p);
//6.求双向链表的长度
int lengthDoubleLinkList(double_list_t p);
//7.查找指定数据出现的位置 data被查找的数据
int searchPostDoubleLinkList(double_list_t p, datatype data);
//8.修改指定位置的数据,post修改的位置 data被修改的数据
int changeDataDoubleLinkList(double_list_t p, int post, datatype data);
//9.删除双向链表中的指定数据 data代表删除所有出现的data数据
int deleteDataDoubleLinkList(double_list_t p, datatype data);
//清空双链表
void CleanDoubleLink(double_list_t p);
#endif