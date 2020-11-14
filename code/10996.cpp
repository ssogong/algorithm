#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < 2*n; i++) {
    for(int j = 0; j < n; j++) {
      if ((i % 2) ^ (j % 2)) printf(" ");
      else printf("*");
    }
    printf("\n");
  }
}