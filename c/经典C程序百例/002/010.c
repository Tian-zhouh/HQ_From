#include<stdio.h>
/*
    题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在
　　　第10次落地时，共经过多少米？第10次反弹多高？
 */
int main(){
    float length=100,longer=0;
    int i;
    for(i=0;i<10;i++){
        longer+=length;
        length/=2;
        if(i!=10-1)
            longer+=length;
    }
    printf("all %5.2f M\n",longer);
    printf("this ball have %5.2f length in 10 jumps\n",length);
    return 0;
}