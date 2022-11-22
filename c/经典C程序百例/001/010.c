#include<stdio.h>
#define N 10
/*
    题目：打印楼梯，同时在楼梯上方打印两个笑脸。 
 */
int main(){
    int i,j;
    printf("%c%c\n",'c','c');
    for(i=0;i<N;i++){
        for(j=0;j<N-i;j++){
            printf("  ");
        }
        for(j=0;j<=i;j++){
            printf("%c%c",219,219);
        }
        printf("\n");
    }
    return 0;
}