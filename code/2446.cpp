#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  for (int i = -n+1; i < n; i++) {
    int k = i < 0 ? i+n : n-i;
    for (int j = 1; j < k; j++) {
      printf(" ");
    }
    int m = i < 0 ? -i * 2 + 1 : i * 2 + 1;
    for (int j = 0; j < m; j++) {
      printf("*");
    }
    printf("\n");
  }
}