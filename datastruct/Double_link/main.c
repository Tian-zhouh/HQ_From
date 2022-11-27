#include "head.h"

int main(int argc, const char *argv[])
{
    double_list_t p = createEmptyDoubleLinkList();
    int temp = 0; //用于遍历
    for (temp = 0; temp < 20; temp++)
    {
        insertIntoDoubleLinkList(p, temp, temp);
    }
    showDoubleLinkList(p, 1);
    deletePostDoubleLinkList(p, 19);
    deletePostDoubleLinkList(p, 0);

    deleteDataDoubleLinkList(p, 18);
    deleteDataDoubleLinkList(p, 14);
    showDoubleLinkList(p, 1);

    printf("%d num area is %d\n", 11, searchPostDoubleLinkList(p, 11));
    printf("%d num area is %d\n", 17, searchPostDoubleLinkList(p, 17));
    printf("%d num area is %d\n", 2, searchPostDoubleLinkList(p, 2));

    changeDataDoubleLinkList(p, 9, 10000);
    changeDataDoubleLinkList(p, 15, 9999);
    changeDataDoubleLinkList(p, 0, 88888);
    showDoubleLinkList(p, 1);
    showDoubleLinkList(p, -1);

    CleanDoubleLink(p);
    free(p->head);
    p->head = NULL;
    free(p);
    p = NULL;
    return 0;
}