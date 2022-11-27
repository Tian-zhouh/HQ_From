#include "head.h"
int main(int argc, const char *argv[])
{
    link_list_t p = CreateEpLinkList();
    int randing[3] = {}; //随机种子使用
    int tmp;             //用于遍历
    int num = 0;
    srand(time(0)); //设置随机种子
    for (tmp = 0; tmp < 20; tmp++)
    {
        num = tmp;
        if (num % 5 == 0)
        {
            num = tmp - num;
        }
        InsertIntoPostLinkList(p, num, rand() % 10000 + 1);
    }
    ShowLinkList(p);
    for (tmp = 0; tmp < 3; tmp++)
    { //删除测试，可能产生非法数据
        randing[tmp] = rand() % 30 + 1;
        printf("del p->data[%d]==%d\n", randing[tmp] - 1, DeletePostLinkList(p, randing[tmp] - 1));
    }
    printf("Length is %d\n", LengthLinkList(p));
    ChangePostLinkList(p, 15,99999);
    ShowLinkList(p);
    DeleteDataLinkList(p, 99999);
    ReverseLinkList(p);
    ShowLinkList(p);
    ClearLinkList(p);
    free(p);

    return 0;
}