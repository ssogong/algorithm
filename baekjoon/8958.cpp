#include <stdio.h>
int main() {
    int n, re, add;
    char *ptr, str[80];
    scanf("%d", &n);
    while(n--) {
        scanf("%s", str);
        ptr = str;
        re = add = 0;
        while(*ptr != '\0') {
            if(*ptr == 'O') 
                re += ++add;
            else
                add = 0;
            ptr++;
        }
        printf("%d\n", re);
    }
    return 0;
}