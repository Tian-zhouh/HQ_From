#include<stdio.h>
int main(){
    int i,j;
    long sum=0,ag=1;
    for(i=1;i<20;i++){
        for(j=1;j<=i;j++){
            ag*=j;
        }
        sum+=ag;
    }
    printf("%ld\n",sum);
    return 0;
}