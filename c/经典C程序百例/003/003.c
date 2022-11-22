#include<stdio.h>
int main(){
    int i,j;
    for(i=0;i<=8;i++){
        if(i<=4){
            for(j=4;j>i;j--)
                printf(" ");
            for(j=0;j<=i*2;j++){
                printf("*");
            }
        }else{
            for(j=4;j<i;j++){
                printf(" ");
            }
            for(j=0;j<=(8-i)*2;j++){
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}