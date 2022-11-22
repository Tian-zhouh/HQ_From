#include<stdio.h>
int main(){
    int i,j,chg=0;
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            if(i%2==0&&j%2==0||i%2!=0&&j%2!=0){
                chg=1;
            }else{
                chg=0;
            }
            if(chg){
                printf("%c%c",219,219);
            }else
            {
                printf("  ");
            }
            
        }
        printf("\n");
    }
    return 0;
}