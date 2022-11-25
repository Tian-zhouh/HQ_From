#include "head.h"
void CreateEpLinkStack(linkstack_t **ptop)
{
    *ptop = NULL;
}
int PushLinkStack(linkstack_t **ptop, datatype data)
{
    linkstack_t *pnum = (linkstack_t *)malloc(sizeof(linkstack_t));
    if (pnum == NULL)
    {
        perror("malloc linkstack is error");
        return -1;
    }
    pnum->data=data;
    pnum->next=*ptop;
    *ptop=pnum;
    return 1;
}
int IsEpLinkStack(linkstack_t *top){
    return top==NULL;
}
datatype PopLinkStack(linkstack_t **ptop){
    if(IsEpLinkStack(*ptop)){
        perror("pop link stack is error");
        return -1;
    }
    linkstack_t *pdel=*ptop;
    *ptop=pdel->next;
    int num=pdel->data;
    free(pdel);
    pdel=NULL;
    return num;
}
void ClearLinkStack(linkstack_t **ptop){
    linkstack_t *pdel=NULL;
    while(*ptop){
        pdel=*ptop;
        *ptop=(*ptop)->next;
        free(pdel);
        pdel=NULL;
    }
    *ptop=NULL;
}
int LengthLinkStack(linkstack_t *top){
    int len=0;
    while(top){
        len++;
        top=top->next;
    }
    return len;
}
datatype GetTopLinkStack(linkstack_t *top){
    return top->data;
}