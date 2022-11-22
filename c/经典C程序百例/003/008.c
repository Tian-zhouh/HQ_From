#include<stdio.h>
int func(int);
int main(){
    printf("%d\n",func(5));
    return 0;
}

int func(int num){
    if(num==1){
        return 2;
    }else{
        return func(num-1)+2;
    }
}