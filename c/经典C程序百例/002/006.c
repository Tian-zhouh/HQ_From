#include<stdio.h>
/*
    题目：输入两个正整数m和n，求其最大公约数和最小公倍数。
 */
int main(){
    printf("please input 2 nums(nums>0)>>>");
    int num1,num2;
    int i,mul1=1;
    scanf("%d %d",&num1,&num2);
    if(num1<0||num2<0){
        printf("Error information\n");
    }else
    {
        //最大公约数
        for(i=2;num1!=1&&num2!=1;){
            if(num1%i==0&&num2%i==0){
                num1/=i;
                num2/=i;
                mul1*=i;
            }else
            {
                i++;
            }
            
        }
        printf("Highest Common Factor is %d\n",mul1);
        //最小公倍数
        printf("Least common multiple is %d\n",mul1*num1*num2);
    }
    
    return 0;
}