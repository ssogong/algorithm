#include <cstdio>
#include <cmath>
int main() {
  while(1) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == 0) return 0;
    int tmp;
    if (a > c) {
      tmp = a;
      a = c;
      c = tmp;
    }
    if (b > c) {
      tmp = b;
      b = c;
      c = tmp;
    }
    if (c*c == a*a + b*b) {
      printf("right\n");
    } else {
      printf("wrong\n");
    }
  }
}