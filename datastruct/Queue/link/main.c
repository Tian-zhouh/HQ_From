#include "head.h"
int main(int argc, const char *argv[])
{
    link_list_t p = CreateEmptyLinkQueue();
    int temp;
    for (temp = 0; temp < 20; temp++)
    {
        InLinkQueue(p, temp);
    }
    ShowSequeueLink(p);
    OutLinkQueue(p);
    OutLinkQueue(p);
    OutLinkQueue(p);
    ShowSequeueLink(p);
    ClearLinkQueue(p);
    ShowSequeueLink(p);
    free(p->front);
    p->front = NULL;
    free(p);
    p = NULL;
    return 0;
}