#include<stdio.h>

//有1、2、3、4个数字，能组成多少个互不相同且无重
//复数字的三位数？都是多少？
int main(){
	int th,hu,te,a;
	for(th=1;th<=4;th++){
		for(hu=1;hu<=4;hu++){
			for(te=1;te<=4;te++){
				for(a=1;a<=4;a++){
					if(th==hu||th==te||th==a||hu==te||hu==a||te==a){
						continue;
					}
					printf("%d\n",th*1000+hu*100+te*10+a);
				}
			}
		}
	}
	return 0;
}