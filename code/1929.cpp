#include <iostream>
#include <cstdio>
using namespace std;
int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  int *a = new int[n+1]();
  if (m == 1) a[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i]) continue;
    for (int j = 2; i*j <= n; j++) {
      a[i*j] = 1;
    }
    if (i >= m) printf("%d\n", i);
  }
}