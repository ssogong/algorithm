#include <stdio.h>
int a, b, c, i=0;
int main() {
    scanf("%d%d%d", &a, &b, &c);
    if(c < 0 || b < 0 || c <= b) {
        printf("-1");
        return 0;
    }

    printf("%d", a/(c-b)+1);
    return 0;
}
