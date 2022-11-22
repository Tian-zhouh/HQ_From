#include<stdio.h>
/*
    题目：输入某年某月某日，判断这一天是这一年的第几天？
 */
int main(){
    printf("please input year month day>>>");
    int year,month,day,day2=28,date;
    short bol=0;//判断使用，0为假
    scanf("%d %d %d",&year,&month,&day);
    if(year<=0){
        bol=1;
    }else{
        if(year%400==0||(year%4==0&&year%100!=0)){
            day2=29;
        }
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            if(day>31||day<0){
                bol=1;
            }
        }else if(month==4||month==6||month==9||month==11){
            if(day>30||day<0){
               bol=1;
            }
        }else if(month==2){
            if(day>day2||day<0){
                bol=1;
            }
        }else{
            bol=1;
        }
    }
   
    if(bol==1){
        printf("Error date infomation\n");
    }else{
        date=day;
        switch(month){
            case 12:day+=30;
            case 11:day+=31;
            case 10:day+=30;
            case 9:day+=31;
            case 8:day+=31;
            case 7:day+=30;
            case 6:day+=31;
            case 5:day+=30;
            case 4:day+=31;
            case 3:day+=day2;
            case 2:day+=31;
            case 1:break;
            default:day=-1;
        }
        if(day==-1){
            printf("sorry unknow Error\n");
        }else{
            printf("%d - %d - %d is this years %d day\n",year,month,date,day);
        }
    }
    
    
    return 0;
}