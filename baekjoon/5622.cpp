#include <stdio.h>
int main() {
    char c;
    int r=0;
    while(~scanf("%c",&c)&&c>='A'){
        c=='S'||c=='V'||c=='Y'||c=='Z'?r+=(c-65)/3+2:r+=(c-65)/3+3;
    }
    printf("%d",r);
}