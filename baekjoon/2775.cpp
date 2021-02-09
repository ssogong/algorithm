#include <cstdio>
int main() {
    int t, k, n;
    scanf("%d", &t);
    while(t--) {
        int a[14]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};
        scanf("%d%d", &k, &n);
        for(int i = 0; i < k; i++) {
            for(int j = 1; j < n; j++){
               a[j]=a[j-1]+a[j]; 
            } 
        }
        printf("%d\n", a[n-1]);
    }
}
