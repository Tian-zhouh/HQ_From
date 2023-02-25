#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//简单实现wc功能
int main(int argc, const char *argv[])
{
    if (argc < 3)
    {
        perror("please input -l filename");
        exit(-1);
    }

    if (strcmp(argv[1], "-l"))
    {
        perror("unknow function,please input -l filename");
        exit(-1);
    }

    FILE *fp = fopen(argv[2], "r");
    if (fp < 0)
    {
        perror("open file err");
    }
    char info[64] = {0};
    int num = 0;
    while (fgets(info, sizeof(info), fp) != NULL)
    {
        if (info[strlen(info) - 1] == '\n')
        {
            num++;
        }
    }
    printf("%d %s\n", num, argv[2]);
}