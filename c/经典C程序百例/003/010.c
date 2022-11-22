#include<stdio.h>
int func(int);
int main(){
    // int i,j;
    int num=12321;
    int o,t,f,fi;
    o=num/10000;
    t=num/1000%10;
    f=num/10%10;
    fi=num%10;
    if(o==fi&&t==f){
        printf("true\n");
    }else{
        printf("false\n");
    }
    return 0;
}
