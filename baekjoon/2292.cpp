#include <stdio.h>
int main() {
    int n, r = 1;
    scanf("%d", &n);
    int i = 0, tmp = 2;
    while(1) {
       tmp += 6 * i;
       if(n < tmp) 
           break;
       i++;
    }
    printf("%d", r+i);
}
