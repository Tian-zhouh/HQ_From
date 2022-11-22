#include<stdio.h>
/*
    题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
 */
int main(){
    int num;
    int i;
    printf("please input one number>>>");
    scanf("%d",&num);
    printf("%d=",num);
    for(i=2;num!=1;){
        if(num%i==0){
            num/=i;
            if(num!=1)
                printf("%d*",i);
            else
                printf("%d",i);
        }else
        {
            i++;
        }
    }
    puts("");
    return 0;
}