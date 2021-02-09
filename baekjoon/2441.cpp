#include <cstdio>
int main() {
    int t, i, j;
    char c;
    scanf("%d", &t);
    j = t;
    while(t--) {
        for(i=0, c=' ';i<j;i++) {
            if(i>j-t-2)
                c = '*';
            printf("%c", c);
        }
        printf("\n");
    }
}