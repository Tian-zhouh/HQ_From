#include <stdio.h>
#include <stdlib.h>
#define N 100
int maloccheck = 0;
int length = 0;
//这是一个长度为100的整型数组，可以实现仿顺序表的增删改查操作
int *create_List();
int *free_List(int *);
int insert_List(int *, int, int);
int del_List(int *, int);
void find_List(int *);

int main()
{
    int *num=create_List();
    int i=0;
    for(;i<20;i++){
        insert_List(num,0,i*i);
        if(i%5==0){
            printf("%d\n",del_List(num,0));
        }
    }
    find_List(num);
    free_List(num);
    return 0;
}

//创建一个长度为100的整型数组,只允许创建一个
int *create_List()
{
    int *p = (int *)malloc(sizeof(int) * N);
    if (NULL == p || maloccheck)
    {
        perror("malloc memary is Error,please remake");
        return NULL;
    }
    maloccheck = 1;
    return p;
}
//释放使用的动态空间
int *free_List(int *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    free(p);
    p = NULL;
    return p;
}

//插入数据,成功返回存储位置,失败返回-1
int insert_List(int *p, int post, int data)
{
    if (post >= 100 || post < 0)
    {
        perror("Error area with post");
        return -1;
    }
    int i = length;
    for (; i >= post; i--)
    {
        *(p + i + 1) = *(p + i);
    }
    *(p + post) = data;
    length++;
    return length - 1;
}
//删除数据，成功返回删除的元素值，失败返回-1
int del_List(int *p, int post)
{
    if (post >= 100 || post < 0)
    {
        perror("Error area with post");
        return -1;
    }
    int i = post;
    int num = *(p + post);
    for (; i < length; i++)
    {
        *(p + i) = *(p + i + 1);
    }
    length--;
    return num;
}
//遍历数组
void find_List(int *p)
{
    int i = 0;
    if (length == 0)
    {
        printf("This list is empty\n");
        return;
    }
    for (; i < length; i++)
    {
        printf("%d\t", *(p + i));
    }
    printf("\n");
}