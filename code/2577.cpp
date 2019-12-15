#include <stdio.h>
int main() {
    int result = 1;
    int tmp;
    int arr[10] = {0};
    for(int i = 0; i < 3; i++) {
        scanf("%d", &tmp);
        result *= tmp;
    }
    while(result > 0) {
        tmp = result % 10;
        arr[tmp]++;
        result /= 10;
    }
    for(int i = 0; i <10; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}