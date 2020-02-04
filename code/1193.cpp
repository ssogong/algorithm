#include <stdio.h>
int main() {
    int x, i, r, tmp = 0;
    scanf("%d", &x);
    for(i = 1; tmp < x; i++) {
        tmp += i;
    }
    r = x+(--i)-tmp;
    if(i%2 > 0)
        printf("%d/%d", i+1-r, r);
    else
        printf("%d/%d", r, i+1-r);
}