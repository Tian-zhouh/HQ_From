#include<stdio.h>
/*
题目：企业发放的奖金根据利润提成。
	利润(I)低于或等于10万元时，奖金可提10%；
	利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可可提
　　成7.5%；
	20万到40万之间时，高于20万元的部分，可提成5%；
	40万到60万之间时高于40万元的部分，可提成3%；
	60万到100万之间时，高于60万元的部分，可提成1.5%，
	高于100万元时，超过100万元的部分按1%提成，从键盘输入当月利润I，求应发放奖金总数？

*/
int main(){
	int i,per,sets;
	float money=0.0;
	scanf("%d",&i);
	per=i;
	if(per%10==0){
		per=per-1;
	}
	if (per/10>10){
		per=100;
	}
	switch(per/10){
		case 10:sets=i-100;i=100;money+=(sets)*0.01;printf("%lf\n",money);
		case 9:
		case 8:
		case 7:
		case 6:sets=i-60;i=60;money+=(sets)*0.015;
		case 5:
		case 4:sets=i-40;i=40;money+=(sets)*0.03;
		case 3:
		case 2:sets=i-20;i=20;money+=(sets)*0.05;
		case 1:sets=i-10;i=10;money+=(sets)*0.075;
		case 0:sets=i;money+=(sets)*0.1;break;
		default:
		printf("%d",per/10);
			money=-1;
	}
	if(money>0){
		printf("you have %5.2f W perfect\n",money);
	}else{
		printf("Error information.\n");
	}
}