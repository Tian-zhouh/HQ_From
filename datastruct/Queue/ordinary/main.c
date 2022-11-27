#include "head.h"
int main(int argc, const char *argv[])
{
    seque_list_t p = CreateEmptySequeue();
    int temp; //遍历使用
    for (temp = 0; temp < 25; temp++)
    {
        InSequeue(p, temp);
    }
    ShowSeque(p);
    OutSequeue(p);
    OutSequeue(p);
    OutSequeue(p);
    InSequeue(p, 100);
    InSequeue(p, 200);
    InSequeue(p, 4500);
    ShowSeque(p);
    free(p);
    return 0;
}