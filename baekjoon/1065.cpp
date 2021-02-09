#include <stdio.h>
int func(int a) {
    int pre = a % 10;
    a /= 10;
    int now = a % 10;
    int dec = pre - now;
    a /= 10;
    while(a > 0) {
        pre = now;
        now = a % 10;
        if(dec != pre - now)
            return 0;
        a /= 10;
    }
    return 1;
}

int main() {
    int n, re = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        if(func(i)) re++;
    }
    printf("%d", re);
    return 0;
}