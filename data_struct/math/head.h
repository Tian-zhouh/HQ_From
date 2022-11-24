#ifndef __HEAD__
#define __HEAD__
#define N 100
#include <stdio.h>
#include <stdlib.h>
typedef int typedata;
typedef struct node_t
{
    typedata data;
    struct node_t *next;
} link_node_t, *link_list_t;
//1.创建一个空的单向链表(有头单向链表)
link_node_t *CreateEpLinkList();
//2.向单向链表的指定位置插入数据
//p保存链表的头指针 post 插入的位置 data插入的数据
typedata InserttypedataoPostLinkList(link_node_t *, typedata, typedata);
//3.遍历单向链表
void ShowLinkList(link_node_t *);
//4.求单向链表长度的函数
typedata LengthLinkList(link_node_t *);
//5.删除单向链表中指定位置的数据 post 代表的是删除的位置
typedata DeletePostLinkList(link_node_t *, typedata);
//6.判断单向链表是否为空 1代表空 0代表非空
typedata IsEpLinkList(link_node_t *);
//7.修改指定位置的数据 post 被修改的位置 data修改成的数据
typedata ChangePostLinkList(link_node_t *, typedata, typedata);
//8.查找指定数据出现的位置 data被查找的数据 //search 查找
typedata SearchDataLinkList(link_node_t *, typedata);
//9.删除单向链表中出现的指定数据,data代表将单向链表中出现的所有data数据删除
typedata DeleteDataLinkList(link_node_t *, typedata);
//10.转置链表
void ReverseLinkList(link_node_t *);
//11.清空单向链表
void ClearLinkList(link_node_t *);
link_node_t *SearchDataLinkListAll(link_node_t *, typedata);
link_node_t *SortList(link_node_t *, link_node_t *, link_node_t *);
#endif