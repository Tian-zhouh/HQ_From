#include<stdio.h>
/*
    题目：判断101-200之间有多少个素数，并输出所有素数。
    素数：
 */
int main(){
    int i,j,count=0;
    short bol=1;
    for(i=101;i<200;i++){
        bol=1;
        for(j=2;j<(i/2+1);j++){
            if(i%j==0){
                bol=0;
            }
        }
        if(bol){
            printf("%d is prime number\n",i);
            count++;
        }
    }
    printf("have %d prime number\n",count);
    return 0;
}