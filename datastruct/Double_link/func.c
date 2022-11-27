#include "head.h"

double_list_t createEmptyDoubleLinkList()
{
    double_list_t p = (double_list_t)malloc(sizeof(double_node_t));
    if (p == NULL)
    {
        perror("createEmptyDoubleLinkList() is error");
        return NULL;
    }
    p->head = p->tail = (link_list_t)malloc(sizeof(link_node_t));
    if (p->head == NULL)
    {
        perror("createEmptyDoubleLinkList() ->head is error");
        free(p);
        p = NULL;
        return NULL;
    }
    p->head->next = p->head->prior = NULL;

    return p;
}

int insertIntoDoubleLinkList(double_list_t p, int post, datatype data)
{
    int temp; //用于遍历
    link_list_t check = NULL;
    // printf("%s %s %d\n", __FILE__, __func__, __LINE__);//测试用
    if (post < 0 || post > p->len)
    {
        perror("insertIntoDoubleLinkList(args) is error");
        return -1;
    }
    link_list_t pnew = (link_list_t)malloc(sizeof(link_node_t));
    if (pnew == NULL)
    {
        perror("insertIntoDoubleLinkList(args)->pnew is error");
        return -1;
    }
    pnew->data = data;
    pnew->next = pnew->prior = NULL;

    if (post == p->len)
    {
        pnew->prior = p->tail;
        pnew->next = p->tail->next;
        p->tail->next = pnew;
        p->tail = pnew; //注意移动指针
        p->len++;
        return 0;
    }
    if (post < p->len / 2)
    {
        check = p->head;
        for (temp = 0; temp <= post; temp++)
        {
            check = check->next;
        }
    }
    else
    {
        check = p->tail;
        for (temp = p->len - 1; temp >= post; temp--)
        {
            check = check->prior;
        }
    }
    check->prior->next = pnew;
    pnew->prior = check->prior;
    pnew->next = check;
    check->prior = pnew;
    p->len++;

    return 0;
}

//正数正向遍历，非反向遍历
void showDoubleLinkList(double_list_t p, int num)
{
    link_list_t check = NULL;
    if (num > 0)
    {
        printf("正向遍历\n");
        check = p->head->next;
        while (check != NULL)
        {
            printf("%d\t", check->data);
            check = check->next;
        }
    }
    else
    {
        printf("反向遍历\n");
        check = p->tail;
        while (check->prior != NULL)
        {
            printf("%d\t", check->data);
            check = check->prior;
        }
    }

    puts("");
}

int deletePostDoubleLinkList(double_list_t p, int post)
{
    link_list_t pdel = NULL;
    link_list_t check = NULL;
    int num;  //返回被删除元素值,有bug
    int temp; //遍历使用

    if (post < 0 || post >= p->len || isEmptyDoubleLinkList(p))
    {
        perror("deletePostDoubleLinkList(args) is error");
        return -1;
    }
    if (post == p->len - 1)
    {
        pdel = p->tail;
        p->tail = p->tail->prior;
        p->tail->next = pdel->next;
        num = pdel->data;
        free(pdel);
        pdel = NULL;
        p->len--;
        return num;
    }
    if (post < p->len / 2)
    {
        check = p->head;
        for (temp = 0; temp <= post; temp++)
        {
            check = check->next;
        }
    }
    else
    {
        check = p->tail;
        for (temp = p->len - 1; temp >= post; temp--)
        {
            check = check->prior;
        }
    }
    pdel = check;
    check->next->prior = check->prior;
    check->prior->next = check->next;
    num = pdel->data;
    free(pdel);
    pdel = NULL;
    p->len--;

    return num;
}

int isEmptyDoubleLinkList(double_list_t p)
{
    return p->head == p->tail;
}

int lengthDoubleLinkList(double_list_t p)
{
    return p->len;
}

//只能返回正向查找，第一个符合条件的数据的索引
int searchPostDoubleLinkList(double_list_t p, datatype data)
{
    link_list_t check = p->head;
    int index = -1; //用于返回索引值
    while (check != NULL)
    {
        if (check->data == data)
        {
            return index;
        }
        check = check->next;
        index++;
    }

    return -1;
}

int changeDataDoubleLinkList(double_list_t p, int post, datatype data)
{
    link_list_t change = NULL;
    int temp; //遍历使用
    if (post < 0 || post > p->len - 1 || isEmptyDoubleLinkList(p))
    {
        perror("changeDataDoubleLinkList(args) is error");
        return -1;
    }
    if (post < p->len / 2)
    {
        change = p->head;
        for (temp = 0; temp <= post; temp++)
        {
            change = change->next;
        }
    }
    else
    {
        change = p->tail;
        for (temp = p->len - 1; temp >= post; temp--)
        {
            change = change->prior;
        }
    }
    change->data = data;

    return 0;
}

int deleteDataDoubleLinkList(double_list_t p, datatype data)
{
    link_list_t pdel = NULL;
    link_list_t check = p->head->next;
    int num = 0; //返回删除元素个数
    while (check->next != NULL)
    {
        if (check->data == data)
        {
            pdel = check;
            check->prior->next = check->next;
            check->next->prior = check->prior;
            free(pdel);
            pdel = NULL;
            num++;
            p->len--;
        }
        check = check->next;
    }
    if (p->tail->data == data)
    {
        pdel = p->tail;
        p->tail = p->tail->prior;
        p->tail->next = pdel->next;
        num++;
        p->len--;
    }

    return num;
}

void CleanDoubleLink(double_list_t p)
{
    link_list_t pdel = NULL;
    while (p->head != NULL)
    {
        pdel = p->head;
        p->head = p->head->next;
        free(pdel);
        pdel = NULL;
    }
}