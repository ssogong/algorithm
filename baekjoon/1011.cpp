#include <cstdio>
int main() {
    int t, x, y, d, i, r;
    scanf("%d", &t);
    while(t--){
        i = 1;
        scanf("%d%d", &x, &y);
        d = y-x;
        while(d > i*i)
            i++;
        i*i-d < i ? r=2*i-1 : r=2*i-2;
        printf("%d\n", r);
    }
}