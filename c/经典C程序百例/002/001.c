#include<stdio.h>
/*
    题目：古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月
　　　后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？
 */
int main(){
    long long little_rab=1,old_rab=0,middal_rab=0;
    int mounth=1;
    for(;mounth<20;mounth++){
        if(mounth==1){
            little_rab=1;
        }else if (mounth==2)
        {
            middal_rab=little_rab;
            little_rab=old_rab;
        }else
        {
            old_rab+=middal_rab;
            middal_rab=little_rab;
            little_rab=old_rab;
        }
        printf("little:%lld\nmiddle:%lld\nbig:%lld\n",little_rab,middal_rab,old_rab);
        printf("%d mounth have %lld rab\n",mounth,little_rab+middal_rab+old_rab);
    }
    return 0;
}