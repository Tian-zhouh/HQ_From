#include "head.h"

int main(int argc, const char *argv[])
{
    int item; //遍历使用
    int num = 0;
    int randing[3] = {}; //随机种子使用
    srand(time(0));      //设置随机种子
    seqlist_t *p = CreateEpSeqlist();
    for (item = 0; item < 23; item++)
    { //测试合法插入和非法插入
        num = item;
        if (item % 5 == 0)
        {
            num = item - num;
        }
        InsertIntoSeqlist(p, num, rand() % 10000 + 1);
    }
    ShowSeqlist(p); //查看插入结果
    for (item = 0; item < 3; item++)
    {
        randing[item] = rand() % 30 + 1; //有概率出现非法数据，用于验证非法删除
        printf("del p->data[%d] = %d;\n", randing[item], DeletePostSeqlist(p, randing[item]));
    }
    ShowSeqlist(p);
    ChangePostSeqList(p, 5, 99999);
    ShowSeqlist(p);

    free(p);
    p = NULL;

    return 0;
}