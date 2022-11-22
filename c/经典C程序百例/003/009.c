#include<stdio.h>
int func(int);
int main(){
    printf("\n%d\n",func(100101));
    return 0;
}

int count=0;
int func(int num){
    if(num!=0){
        count++;
        func(num/10);
    }
    printf("%d",num%10);
    return count;
}