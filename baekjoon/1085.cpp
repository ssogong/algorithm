#include <cstdio>
int main() {
  int x, y, w, h;
  scanf("%d%d%d%d", &x, &y, &w, &h);
  int minX, minY;
  minX = w-x < x ? w-x : x;
  minY = h-y < y ? h-y : y;
  printf("%d", minX < minY ? minX :minY);
}