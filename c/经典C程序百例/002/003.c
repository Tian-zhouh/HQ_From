#include<stdio.h>
/*
    题目：打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数
　　　本身。例如：153是一个“水仙花数”，因为153=1的三次方＋5的三次方＋3的三次方。
 */
int main(){
    int i;
    int hu,te,a;
    for(i=100;i<1000;i++){
        hu=i/100;
        te=i/10%10;
        a=i%10;
        if(hu*hu*hu+te*te*te+a*a*a==i){
            printf("%d is daffodils flowers.\n",i);
        }
    }
    return 0;
}