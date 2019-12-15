#include <stdio.h>
int a[20000] = {0};
void d(int n) {
    int sum = n;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    a[sum]++;
}

int main() {
    for(int i = 1; i <= 10000; i++) {
        d(i);
    }
    for(int i = 1; i <= 10000; i++) {
        if(!a[i])
            printf("%d\n", i);
    }
    return 0;
}