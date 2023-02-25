#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//想timefile.txt文件内部覆盖写入当前时间
int main()
{
    FILE *fd = fopen("./timefile.txt", "w");
    char len[20] = {0};
    if (fd < 0)
    {
        perror("create file err");
        exit(-1);
    }
    while (1)
    {
        sleep(1);
        time_t timep;
        time(&timep);

        struct tm *p;
        p = gmtime(&timep);
        snprintf(len, 20, "%4d-%2d-%2d %2d:%2d:%2d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
        fprintf(fd, "%s\n", len);
        fflush(fd);
    }
    fclose(fd);
}