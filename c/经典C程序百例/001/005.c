#include<stdio.h>
#define N 3
/*
    题目：输入三个整数x,y,z，请把这三个数由小到大输出。
*/
int main(){
    //使用冒泡排序方式实现
    int lists[N]={};
    int i,j,p;
    printf("please input 3 numbers>>>");
    for(i=0;i<N;i++){
        scanf("%d",&lists[i]);
    }
    for(i=0;i<N-1;i++){
        for(j=0;j<N-1-i;j++){
            if(lists[j]>lists[j+1]){//注意排序顺序
                p=lists[j];
                lists[j]=lists[j+1];
                lists[j+1]=p;
            }
        }
    }
    for(i=0;i<N;i++){
        printf("%d ",lists[i]);
    }
    puts("");
    return 0;
}