#include <cstdio>
int main() {
    float a, b, c;
    float i, j, k;
    float tmp, tmp2;
    scanf("%f%f%f%f%f%f", &a, &b, &c, &i, &j, &k);
    tmp = a/i < b/j ? (a/i < c/k ? 0 : b/j < c/k ? 1 : 2) : b/j < c/k ? 1 : 2 ;
    switch((int)tmp) {
        case 0:
            tmp = (i+j+k) / i;
            tmp2 = (int)a%(int)i;
            printf("0 %f %f", tmp2*tmp*j, tmp2*tmp*k);
            break;
        case 1:
            tmp = (i+j+k) / j;
            tmp2 = (int)b%(int)j;
            printf("%f 0 %f", tmp2*tmp*i, tmp2*tmp*k);
            break; 
        defalut:
            tmp = (i+j+k) / k;
            tmp2 = (int)c%(int)k;
            printf("%f %f 0", tmp2*tmp*i, tmp2*tmp*j);
            break; 
    }
 }