#include "head.h"
int main()
{
    seqstack_t *p = CreateEpSeqStack(100);
    PushStack(p,100);
    PushStack(p,200);
    PushStack(p,300);
    PushStack(p,180);
    PushStack(p,150);
    PushStack(p,220);
    printf("%d is pop\n",PopSeqStack(p));
    ClearSeqStack(p);
    PopSeqStack(p);
    printf("This stack length is %d\n",LengthSeqStack(p));
    free(p->data);
    p->data=NULL;
    free(p);
    p=NULL;
    return 0;
}