#include "head.h"
link_node_t *CreateEpLinkList()
{
    link_list_t p = (link_list_t)malloc(sizeof(link_node_t));
    if (p == NULL)
    {
        perror("Malloc Error from Create");
        return NULL;
    }
    p->next = NULL;
    return p;
}
typedata LengthLinkList(link_node_t *p)
{
    int num = 0;
    p = p->next;
    while (p)
    {
        num++;
        p=p->next;
    }
    return num;
}
typedata InserttypedataoPostLinkList(link_node_t *p, typedata post, typedata data)
{
    if (post < 0 || post > LengthLinkList(p))
    {
        perror("Error post info");
        return -1;
    }
    link_list_t q = (link_list_t)malloc(sizeof(link_node_t));
    if (q == NULL)
    {
        perror("Malloc Error from Insert");
        return -1;
    }
    int i = 0;
    for (; i < post; i++)
    {
        p = p->next;
    }
    q->data=data;
    q->next = p->next;
    p->next = q;
    return 0;
}

void ShowLinkList(link_node_t *p)
{
    p = p->next;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    puts("");
}
typedata IsEpLinkList(link_node_t *p)
{
    return p->next == NULL;
}
typedata DeletePostLinkList(link_node_t *p, typedata post)
{
    if (post < 0 || post > LengthLinkList(p) || IsEpLinkList(p))
    {
        perror("Delet post error");
        return -1;
    }
    int i = 0;
    for (; i < post; i++)
    {
        p = p->next;
    }
    link_list_t q = p->next;
    p->next = q->next;
    free(q);
    q = NULL;
    return 0;
}
typedata ChangePostLinkList(link_node_t *p, typedata post, typedata data)
{
    if (post < 0 || post > LengthLinkList(p) || IsEpLinkList(p))
    {
        perror("Delet post error");
        return -1;
    }
    p = p->next;
    int i = 0;
    for (; i <= post; i++)
    {
        p = p->next;
    }
    p->data = data;
    return 0;
}
typedata SearchDataLinkList(link_node_t *p, typedata data)
{
    int i = 0;
    p = p->next;
    while (p)
    {
        if (p->data == data)
        {
            return i;
        }
        i++;
    }
    return -1;
}

link_node_t *SearchDataLinkListAll(link_node_t *p, typedata data)
{
    int i = 0;
    link_list_t q = (link_list_t)malloc(sizeof(link_node_t));
    q->next = NULL;
    p = p->next;
    while (p)
    {
        if (p->data == data)
        {
            link_list_t ms = (link_list_t)malloc(sizeof(link_node_t));
            ms->data = i;
            ms->next = q->next;
            q->next = ms;
        }
        i++;
        p=p->next;
    }
    return q;
}
typedata DeleteDataLinkList(link_node_t *p, typedata data)
{
    p = p->next;
    while (p)
    {
        if (p->data == data)
        {
            link_list_t ms = p;
            p = p->next;
            free(p);
            ms = NULL;
        }
    }
    return 0;
}
void ReverseLinkList(link_node_t *p)
{
    link_list_t q = p->next;
    p->next = NULL;
    link_list_t ms = NULL;
    while (q)
    {
        ms=q->next;
        q->next=p->next;
        p->next=q;
        q=ms;
    }
}
void ClearLinkList(link_node_t *p){
    p=p->next;
    while(p){
        link_list_t q=p;
        free(p);
        p=q->next;
    }
}
link_node_t * SortList(link_node_t *p,link_node_t *q,link_node_t *m){
    p=p->next;
    q=q->next;
    while(p&&q){
        if(p->data>q->data){
            m->next=q;
            q=q->next;
        }else
        {
            m->next=p;     
            p=p->next;                                                                                                       
        }
        m=m->next;
    }
    while (p)
    {
        m->next=p;
        m=m->next;
        p=p->next;
    }
    while(q){
        m->next=q;
        m=m->next;
        q=q->next;
    }
    return m;
}