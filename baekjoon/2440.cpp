#include <cstdio>
int main() {
    int t, i;
    scanf("%d", &t);
    while(t) {
        i = t--;
        while(i--) {
            printf("*");
        }
        printf("\n");
    }
}