#include<stdio.h>
#define N 256

/*
    题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
 */
int main(){
    printf("please input a string(press enter to end input)>>>");
    char str[N]={};
    int i=0;
    int eng=0,num=0,space=0,other=0;
    scanf("%[^\n]",str);
    while (str[i])
    {
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&& str[i]<='Z'))
            eng++;
        else if(str[i]>='0'&& str[i]<='9')
            num++;
        else if(str[i]==' ')
            space++;
        else
            other++;
        i++;
    }
    printf("English:%3d\n",eng);
    printf("number:%3d\n",num);
    printf("space:%3d\n",space);
    printf("other:%3d\n",other);
    return 0;
}