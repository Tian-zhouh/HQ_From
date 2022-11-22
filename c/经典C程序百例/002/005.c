#include<stdio.h>
/*
    题目：利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，
　　　60分以下的用C表示。
 */
int main(){
    int num;
    char grade=' ';
    printf("please input your score>>>");
    scanf("%d",&num);
    if(num>100||num<0){
        printf("Error,please input right score.\n");
    }else
    {
        if(num>=90){
            grade='A';
        }else if(num>=60)
        {
            grade='B';
        }else
        {
            grade='C';
        }        
    }
    if(grade!=' '){
        printf("Your grade is %c\n",grade);
    }
    
    return 0;
}