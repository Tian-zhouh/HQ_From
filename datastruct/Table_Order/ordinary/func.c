#include "head.h"

seqlist_t *CreateEpSeqlist()
{
    seqlist_t *p = (seqlist_t *)malloc(sizeof(seqlist_t));
    if (p == NULL)
    {
        perror("CreateEpSeqlist() is error");
        return NULL;
    }
    p->last = -1;

    return p;
}

int InsertIntoSeqlist(seqlist_t *p, int post, datatype data)
{
    int item; //遍历使用
    if (post < 0 || post > p->last + 1 || IsFullSeqlist(p))
    {
        perror("InsertIntoSeqlist(args) is error");
        return -1;
    }
    for (item = p->last; item >= post; item--)
    {
        p->data[item + 1] = p->data[item];
    }
    p->data[post] = data;
    p->last++;

    return 0;
}

void ShowSeqlist(seqlist_t *p)
{
    int item; //遍历使用
    if (IsEpSeqlist(p))
    {
        printf("Seqlist is Null.");
    }
    for (item = 0; item <= p->last; item++)
    {
        printf("%d\t", p->data[item]);
    }
    puts(""); //换行
}

int IsFullSeqlist(seqlist_t *p)
{
    return p->last == N;
}

int IsEpSeqlist(seqlist_t *p)
{
    return p->last == -1;
}

int DeletePostSeqlist(seqlist_t *p, int post)
{
    int item; //遍历使用
    if (post < 0 || post > p->last || IsEpSeqlist(p))
    {
        perror("DeletePostSeqlist(args) is error");
        return -1;
    }
    for (item = post; item < p->last; item++)
    {
        p->data[item] = p->data[item + 1];
    }
    p->last--;

    return 0;
}

void ClearSeqList(seqlist_t *p)
{
    p->last = -1;
}

int ChangePostSeqList(seqlist_t *p, int post, datatype data)
{
    int num; //存储返回值,有bug，p->data不能等于-1
    if (post < 0 || post > p->last || IsEpSeqlist(p))
    {
        perror("ChangePostSeqList(args) is error");
        return -1;
    }
    num = p->data[post];
    p->data[post] = data;

    return num;
}

/* 只查找顺序表中第一个符合条件的数据 */
int SearchDataSeqList(seqlist_t *p, datatype data)
{
    int item;       //遍历使用
    int index = -1; //返回值，用于控制return数量
    for (item = 0; item <= p->last; item++)
    {
        if (p->data[item] == data)
        {
            index = p->data[item];
        }
    }

    return index;
}