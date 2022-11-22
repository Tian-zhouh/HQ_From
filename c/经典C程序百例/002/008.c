#include<stdio.h>
/*
    题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时
　　　共有5个数相加)，几个数相加有键盘控制。
 */
int main(){
    printf("please input int number and how many>>>");
    int num,num0,count,i,j,sum=0;
    scanf("%d %d",&num,&count);
    num0=num;
    if(count<=0){
        printf("Error infomation.\n");
    }else{
        for(i=0;i<count;i++){
            num=num0;
            for(j=0;j<=i;j++){
                if(j>0)
                    num=(num*10+num0);
            }
            if(i!=count-1)
                printf("%d+",num);
            else 
                printf("%d",num);
            sum+=num;
        }
        printf("=%d",sum);
    }
    puts("");
    return 0;
}