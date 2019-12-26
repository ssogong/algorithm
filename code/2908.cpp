#include <stdio.h>
int main(){
    char a[2][4];
    char (*p)[4]=a;
    scanf("%s%s",a,a[1]);
    if((*a[0]-*a[1]+(a[0][1]-a[1][1])*10+(a[0][2]-a[1][2])*100)<0)p++;
    printf("%d",**p+*(*p+1)*10+*(*p+2)*100-5328);
}