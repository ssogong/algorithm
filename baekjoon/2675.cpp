#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int a;
        char str[21];
        char *p = str;
        scanf("%d%s", &a, str);
        while(*p != '\0') {
            for(int i = 0; i < a; i++) {
                printf("%c", *p);
            }
            p++;
        }
        printf("\n");
    }
}