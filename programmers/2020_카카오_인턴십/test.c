#include <stdio.h>
void show(int, int);
int main() {
  struct paint
  {
    /* data */
    int type;
    int color;
  }p;
  p.type = 1;
  p.color = 5;
  show(p.type, p.color);
  return 0;
}
void show(int a, int b) {
  printf("%d %d", a, b);
}