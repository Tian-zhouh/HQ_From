#include"head.h"
int main(){
    sequeue_t *p=CreateEmptySequeue();
    InSequeue(p,22);
    InSequeue(p,33);
    InSequeue(p,11);
    printf("length is %d\n",LengthSequeue(p));
    printf("Outsequeue num is %d\n",OutSequeue(p));
    printf("length is %d\n",LengthSequeue(p));
    ClearSequeue(p);
    printf("length is %d\n",LengthSequeue(p));ls
    free(p);
    return 0;
}