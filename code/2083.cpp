#include <cstdio>
int main () {
    int age, weight;
    char name[11];
    while(1) {
        scanf("%s%d%d", name, &age, &weight);
        if(name[0] == '#') {
            break;
        }
        if(age > 17 || weight > 80) {
            printf("%s Senior\n", name);
        }
        else {
            printf("%s Junior\n", name);
        }
    }
}