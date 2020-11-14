#include <cstdio>
int main() {
    int n, re=1;
    scanf("%d", &n);
    while(n > 1) {
        re *= n--;
    }
    printf("%d", re);
}