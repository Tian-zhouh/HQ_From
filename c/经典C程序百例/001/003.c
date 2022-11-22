#include<stdio.h>
/*
    题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
 */
int main(){
    int i,j,k,lists[2000]={};
    for(i=0;i<2000;i++){
        lists[i]=i*i;
    }
    for(i=0;i<2000;i++){
        for(j=0;j<2000;j++){
            if(i+100==lists[j]){
                for(k=0;k<2000;k++){
                    if((lists[j]+168)==lists[k]){
                        printf("this number is %d\n",i);
                    }
                }
            }
        }
    }
    
}