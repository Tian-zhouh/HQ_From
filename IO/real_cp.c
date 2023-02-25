#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//简单实现cp功能
int main(int argc, const char *argv[])
{
    if (argc < 3)
    {
        perror("please input <oldfile> <newfile>");
    }

    FILE *ofp = fopen(argv[1], "r");
    FILE *nfp = fopen(argv[2], "a");
    if (ofp < 0 || nfp < 0)
    {
        perror("open file err");
        exit(-1);
    }

    char res[32] = {0};
    size_t len = 0;
    while ((len = fread(res, sizeof(char), sizeof(res), ofp)) !=0)
    {
        fwrite(res, sizeof(char), len, nfp);
        memset(res, 0, sizeof(res));
        fflush(ofp);
        fflush(nfp);
    }

    fclose(nfp);
    fclose(ofp);
    return 0;
}