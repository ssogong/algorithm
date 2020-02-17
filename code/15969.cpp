#include <cstdio>
int main() {
    int n, x, min = 1002, max = -1;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        if(x > max) max = x;
        if(x < min) min = x;
    }
    printf("%d", max-min);
}
