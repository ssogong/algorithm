#include <stdio.h>
int main() {
    int re[42] = {0};
    int in, out = 0;
    for(int i = 0; i < 10; i++) {
        scanf("%d", &in);
        if(!re[in%42]) {
            re[in%42] = 1;
            out++;
        }
    }
    printf("%d", out);
    return 0;
}