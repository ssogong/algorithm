#include <cstdio>
#include <cmath>
int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    int x1, y1, r1, x2, y2, r2;
    scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
    int dis = (int) sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
    int rDis = r1 > r2 ? r1-r2 : r2-r1;
    rDis = rDis * rDis;
    if (dis == 0 || r1 == r2) {
      printf("-1\n");
    } else if (dis > r1+r2) {
      printf("0\n");
    } else if (dis == r1 + r2) {
      printf("1\n");
    } else if (r1-r2 == dis || r2-r1 == dis) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
}