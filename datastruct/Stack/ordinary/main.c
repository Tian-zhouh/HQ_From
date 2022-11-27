#include "head.h"
int main(int argc, const char *argv[])
{
    seqstack_list_t p = CreateEpSeqStack(10);
    int item;
    for (item = 0; item < 13; item++)
    {
        PushStack(p, item);
    }
    ShowStack(p);
    PopSeqStack(p);
    PopSeqStack(p);
    ShowStack(p);
    
    free(p->data);
    p->data = NULL;
    free(p);
    p = NULL;
    return 0;
}