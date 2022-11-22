#include<stdio.h>
#include<string.h>
void prin(char *);
int main(){
    char sub[]="sghwqqshq";
    prin(sub);
    return 0;
}

void prin(char * str1){
    if(!*str1) return;
    prin(str1+1);
    printf("%c", *str1);
 }



