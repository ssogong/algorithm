#include <cstdio>
int main() {
    int n, i, j, k;
    scanf("%d", &n);
    for(i=1; i<=2*n-1; i++) {
        i>n ? k=2*n-i : k=i;
        for(j=0;j<n-k;j++){printf(" ");}
        for(j=0;j<2*k-1;j++){printf("*");}
        printf("\n");
    }
}