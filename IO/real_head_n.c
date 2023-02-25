#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//简单实现head功能
int main(int argc, const char *argv[])
{
    if (argc < 3)
    {
        perror("please input -num <filename>");
        exit(-1);
    }

    int len = atoi(argv[1]);
    if (len < 0)
    {
        len *= -1;
    }

    FILE *fp = fopen(argv[2], "r");
    if (fp < 0)
    {
        perror("open file err");
        exit(-1);
    }
    int size = 0;
    int lens = 0;
    char info[32] = {0};
    while (fgets(info, sizeof(info), fp) != NULL)
    {
        printf("%s", info);
        lens++;
        if (lens >= len)
        {
            break;
        }
        memset(info, 0, size);
    }

    fclose(fp);
    return 0;
}