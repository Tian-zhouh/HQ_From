#include<stdio.h>
char str_list={"Mon","Tue","Wen","Thu","Fir","Sat","Sun"};
int main(){
    int i=0,j=0;
    char ck[10]={};
    while(ck[j]!='Y'||ck[j]!='y'){
        ck=getchar();
        j=i++;
    }
    return 0;
}
int check(*str1,**str2){
    int i=0,j=0;
    while(str1[i]){
        if(str1[i]==str2[i][j]){
            j++;
        }else{
            i++;
        }
    }
    if(str[i])
    return 0;
}