#include <stdio.h>
int main() {
    char* output[3] = {"ascending", "descending", "mixed"};
    int pre, now, re;
    scanf("%d%d", &pre, &now);
    re = pre < now ? 0 : 1;
    for(int i = 2; i < 8; i++) {
        pre = now;
        scanf("%d", &now);
        if(re != (pre > now)) {
            re = 2;
            break;
        }
    }
    printf("%s", output[re]);
    return 0;
}