#include "head.h"
int main(int argc, const char *argv[])
{
    link_list_t p;
    CreateEpLinkStack(&p);
    int temp; //用于遍历
    for (temp = 0; temp < 10; temp++)
    {
        PushLinkStack(&p, temp);
    }
    ShowLinkStack(p);
    PopLinkStack(&p);
    PopLinkStack(&p);
    PopLinkStack(&p);
    ShowLinkStack(p);
    ClearLinkStack(&p);
    return 0;
}