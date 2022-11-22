#include<stdio.h>
int main(){
    int i;
    float sum,k=1,j=2,o;
    for(i=0;i<20;i++){
        sum+=(k/j);
        o=k;
        k+=j;
        j=o;
    }
    printf("%.2f\n",sum);
    return 0;
}