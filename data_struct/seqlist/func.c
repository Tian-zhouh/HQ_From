#include "head.h"
seqlist_t *CreateEpSeqlist()
{
    seqlist_t *p = (seqlist_t *)malloc(sizeof(seqlist_t));
    if (p == NULL)
    {
        perror("malloc seqlist error");
        return NULL;
    }
    p->last = -1;
    return p;
}

int IsFullSeqlist(seqlist_t *p)
{
    return p->last + 1 == N;
}

int InsertIntoSeqlist(seqlist_t *p, int post, int data)
{
    if (post < 0 || post > p->last + 1 || IsFullSeqlist(p))
    {
        perror("Insert value is error");
        return -1;
    }
    int tmp = p->last;
    for (; tmp >= post; tmp--)
    {
        p->data[tmp+1] = p->data[tmp];
    }
    p->data[post] = data;
    p->last++;
    return 0;
}

void ShowSeqlist(seqlist_t *p)
{
    int i = 0;
    for (i = 0; i <= p->last; i++)
    {
        printf("%d\t", p->data[i]);
    }
    puts("");
}
int IsEpSeqlist(seqlist_t *p)
{
    return p->last == -1;
}
int DeletePostSeqlist(seqlist_t *p, int post)
{
    if (post < 0 || post > p->last || IsEpSeqlist(p))
    {
        perror("Delete is Error");
        return -1;
    }
    int tmp = post;
    int num = p->data[post];
    for (; tmp < p->last; tmp++)
    {
        p->data[tmp] = p->data[tmp + 1];
    }
    p->last--;
    return num;
}
void ClearSeqList(seqlist_t *p)
{
    p->last = -1;
}
int ChangePostSeqList(seqlist_t *p, int post, int data)
{
    p->data[post] = data;
    return 1;
}
int *SearchDataSeqListAll(seqlist_t *p,int data){
    int *num=(int *)malloc(sizeof(int)*N);
    num[0]=0;
    int tmp=0;
    for(;tmp<=p->last;tmp++){
        if(p->data[tmp]==data){
            num[0]++;
            num[num[0]]=tmp;
        }
    }
    return num;
}
int SearchDataSeqList(seqlist_t *p,int data){
    int i=0;
    for(;i<=p->last;i++){
        if(data==p->data[i])
            return i;
    }
    return -1;
}
void findlist(int *num){
    int i=1;
    for(;i<num[0];i++){
        printf("%d\t",num[i]);
    }
    puts("");
    free(num);
}

seqlist_t * Or(seqlist_t *p,seqlist_t*q){
    int i,j,num;
    for(i=0;i<=p->last;i++){
        if(SearchDataSeqList(q,p->data[i])==-1){
            InsertIntoSeqlist(q,q->last+1,p->data[i]);
        }
    }
    return q;
}