#include<stdio.h>

int fact(int);

int main(){
    printf("%d\n",fact(5));
    return 0;
}


int fact(int num){
    if(num==1){
        return 1;
    }else{
        return num*fact(num-1);
    }
}