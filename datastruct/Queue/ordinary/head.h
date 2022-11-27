#ifndef __HEAD__
#define __HEAD__
#include <stdio.h>
#include <stdlib.h>
#define N 20

typedef int datatype;
typedef struct sequeue
{
    datatype data[N];
    int rear;
    int front;
} sequeue_t, *seque_list_t;

//1.创建一个空的队列
sequeue_t *CreateEmptySequeue();
//2.入列 data代表入列的数据
int InSequeue(sequeue_t *p, datatype data);
//3.判断队列是否为满
int IsFullSequeue(sequeue_t *p);
//4.判断队列是否为空
int IsEmptySequeue(sequeue_t *p);
//5.出列
datatype OutSequeue(sequeue_t *p);
//6.求队列的长度
int LengthSequeue(sequeue_t *p);
//7.清空队列函数
void ClearSequeue(sequeue_t *p);
//遍历队列
void ShowSeque(sequeue_t *p);
#endif