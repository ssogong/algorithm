#include <stdio.h>
int main() {
    int t, h, w ,n, r;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &h, &w, &n);
        if(n%h == 0)
            r = h*100+n/h;
        else
            r = (n%h)*100+n/h+1;
        printf("%d\n", r);
    }
}