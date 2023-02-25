#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

char stats[] = {'r', 'w', 'x', '-'};

int getSingleFile(const char *filename);
void openDir(int argc, const char *argv);

int main(int argc, const char *argv[])
{
    if (argc < 1)
    {
        perror("please input -l or -l filename");
        exit(-1);
    }
    if (argc == 3)
    {
        getSingleFile(argv[2]);
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "-l") == 0)
        {
            openDir(2, "./");
        }
        else
        {
            perror("Unknow input information");
            exit(-1);
        }
    }
    else if (argc = 1)
    {
        openDir(1, "./");
    }
    else
    {
        perror("Unknow input information");
        exit(-1);
    }
    return 0;
}

int getSingleFile(const char *filename)
{
    struct stat buf;
    struct group *gro;
    struct tm *tms;
    if (stat(filename, &buf) == 0)
    {
        //检查文件属性
        switch (buf.st_mode & S_IFMT)
        {
        case __S_IFSOCK:
            putchar('s');
            break;
        case __S_IFLNK:
            putchar('l');
            break;
        case __S_IFREG:
            putchar('-');
            break;
        case __S_IFBLK:
            putchar('b');
            break;
        case __S_IFDIR:
            putchar('s');
            break;
        case __S_IFCHR:
            putchar('c');
            break;
        case __S_IFIFO:
            putchar('p');
            break;
        }
        //检查文件权限
        for (int i = 0; i < 9; i++)
        {
            if (buf.st_mode & S_IRUSR)
            {
                printf("%c", stats[i % 3]);
            }
            else
            {
                printf("%c", stats[3]);
            }
            buf.st_mode = buf.st_mode << 1;
        }
        //硬链接数
        printf("%2d", buf.st_nlink);
        //用户ID
        printf("%4s", getgrgid(buf.st_gid)->gr_name);
        //组id
        printf("%4s", getpwuid(buf.st_uid)->pw_name);
        //文件大小
        int size = buf.st_size;
        printf("%6d", size);
        //创建详细时间
        tms = gmtime(&buf.st_mtime);
        printf("%3d月 %4d", tms->tm_mon + 1, tms->tm_mday);
        printf("%3d:%2d ", tms->tm_hour + 8, tms->tm_min);
        //打印文件名称
        printf(" %s\n", filename);
    }
}

void openDir(int argc, const char *argv)
{
    DIR *dir = opendir(argv);

    struct dirent *dinf = NULL;

    if (dir == NULL)
    {
        perror("open dir is err");
        exit(-1);
    }

    if (argc == 2)
    {
        while ((dinf = readdir(dir)) != NULL)
        {
            getSingleFile(dinf->d_name);
        }
    }
    else
    {
        while ((dinf = readdir(dir)) != NULL)
        {
            printf("%s\t",dinf->d_name);
        }
        printf("\n");
    }

    closedir(dir);
}
