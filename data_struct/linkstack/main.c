#include"head.h"
int main(){
    linkstack_t *ptop;
    CreateEpLinkStack(&ptop);
    PushLinkStack(&ptop,22);
    PushLinkStack(&ptop,33);
    PushLinkStack(&ptop,11);
    PushLinkStack(&ptop,55);
    PushLinkStack(&ptop,32);
    printf("pop num is %d \n",PopLinkStack(&ptop));
    printf("pop num is %d \n",PopLinkStack(&ptop));
    printf("pop num is %d \n",PopLinkStack(&ptop));
    printf("link stack length is %d\n",LengthLinkStack(ptop));
    ClearLinkStack(&ptop);
    return 0;
}