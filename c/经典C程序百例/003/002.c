#include<stdio.h>
int main(){
    char user01[]="abc";
    char user02[]="xyz";
    int i=0,j=0;
    while (user01[i])
    {
        while (user02[j])
        {
            if(user01[i]=='a'){
                if(user02[j]=='x'){
                    j++;
                    continue;
                }
            }
            if(user01[i]=='c'){
                if(user02[j]=='z'||user02[j]=='x'){
                    j++;
                    continue;
                }
            }
            printf("%c PK %c\n",user01[i],user02[j]);
            j++;
        }
        i++;j=0;
    }
    
    return 0;
}